#include "student.h"

void stud_del(struct student **ptr)
{
    struct student *temp, *prev;
    int roll;
    char ch, name[50];

    if(*ptr == NULL)
    {
        printf("List is empty\n");
        return;
    }

    printf("R : Delete by roll number\n");
    printf("N : Delete by name\n");

    scanf(" %c", &ch);

    if(ch == 'r' || ch == 'R')
    {
        printf("Enter roll number: ");
        scanf("%d", &roll);
    }
    else if(ch == 'n' || ch == 'N')
    {
        printf("Enter name: ");
        scanf(" %[^\n]", name);

        temp = *ptr;

        while(temp != NULL)
        {
            if(strcmp(temp->name, name) == 0)
            {
                printf("Roll: %d Name: %s\n",
                       temp->rollno, temp->name);
            }

            temp = temp->next;
        }

        printf("Enter roll number to delete: ");
        scanf("%d", &roll);
    }
    else
    {
        printf("Invalid choice\n");
        return;
    }

    temp = *ptr;
    prev = NULL;

    while(temp != NULL)
    {
        if(temp->rollno == roll)
        {
            if(prev == NULL)
                *ptr = temp->next;
            else
                prev->next = temp->next;

            free(temp);

            printf("Record deleted successfully\n");
            return;
        }

        prev = temp;
        temp = temp->next;
    }

    printf("Record not found\n");
}
