#include "student.h"

void stud_mod(struct student *ptr)
{
    struct student *temp;
    int roll;
    char ch, name[50];
    float percentage;

    if(ptr == NULL)
    {
        printf("List is empty\n");
        return;
    }

    printf("R : Search by roll number\n");
    printf("N : Search by name\n");
    printf("P : Search by percentage\n");

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

        printf("Enter roll number: ");
        scanf("%d", &roll);
    }
    else if(ch == 'p' || ch == 'P')
    {
        printf("Enter percentage: ");
        scanf("%f", &percentage);

        printf("Enter roll number: ");
        scanf("%d", &roll);
    }
    else
    {
        printf("Invalid choice\n");
        return;
    }

    temp = ptr;

    while(temp != NULL)
    {
        if(temp->rollno == roll)
        {
            printf("Current name: %s\n", temp->name);
            printf("Current percentage: %.2f\n",
                   temp->percentage);

            printf("Enter new name: ");
            scanf(" %49[^\n]", temp->name);

            printf("Enter new percentage: ");
            scanf("%f", &temp->percentage);

            if(temp->percentage < 0 ||
               temp->percentage > 100)
            {
                printf("Invalid percentage\n");
                return;
            }

            printf("Record modified successfully\n");
            return;
        }

        temp = temp->next;
    }

    printf("Record not found\n");
}


// SORT FUNCTION

void stud_sort(struct student *ptr)
{
    struct student *temp, *p;
    int roll;
    char name[50];
    float percentage;
    char ch;

    if(ptr == NULL)
    {
        printf("List is empty\n");
        return;
    }

    printf("N : Sort by name\n");
    printf("P : Sort by percentage\n");

    scanf(" %c", &ch);

    for(temp = ptr; temp != NULL; temp = temp->next)
    {
        for(p = temp->next; p != NULL; p = p->next)
        {
            int swap = 0;

            if(ch == 'n' || ch == 'N')
            {
                if(strcmp(temp->name, p->name) > 0)
                    swap = 1;
            }
            else if(ch == 'p' || ch == 'P')
            {
                if(temp->percentage < p->percentage)
                    swap = 1;
            }
            else
            {
                printf("Invalid choice\n");
                return;
            }

            if(swap)
            {
                roll = temp->rollno;
                temp->rollno = p->rollno;
                p->rollno = roll;

                strcpy(name, temp->name);
                strcpy(temp->name, p->name);
                strcpy(p->name, name);

                percentage = temp->percentage;
                temp->percentage = p->percentage;
                p->percentage = percentage;
            }
        }
    }

    printf("Sorting completed\n");
}


// REVERSE FUNCTION

void stud_reverse(struct student **ptr)

{

    struct student *p, *q, *r;

    p = *ptr;

    q = NULL;

    while(p != NULL)

    {

        r = p->next;

        p->next = q;

        q = p;

        p = r;

    }

    *ptr = q;

    printf("List reversed successfully\n");

}
