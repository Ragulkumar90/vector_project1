#include "student.h"

void stud_add(struct student **ptr)
{
    struct student *new, *temp;
    int roll = 1, found;

    new = malloc(sizeof(struct student));

    if(new == NULL)
    {
        printf("Memory allocation failed\n");
        return;
    }

    // Generate smallest available roll number

    while(1)
    {
        found = 0;
        temp = *ptr;

        while(temp != NULL)
        {
            if(temp->rollno == roll)
            {
                found = 1;
                break;
            }

            temp = temp->next;
        }

        if(found == 0)
            break;

        roll++;
    }

    new->rollno = roll;

    printf("Enter student name: ");
    scanf("%[^\n]", new->name);

    if(strlen(new->name) == 0)
    {
        printf("Name cannot be empty\n");
        free(new);
        return;
    }

    printf("Enter percentage: ");
    scanf("%f", &new->percentage);

    if(new->percentage < 0 || new->percentage > 100)
    {
        printf("Invalid percentage\n");
        free(new);
        return;
    }

    new->next = NULL;

    if(*ptr == NULL)
    {
        *ptr = new;
    }
    else
    {
        temp = *ptr;

        while(temp->next != NULL)
        {
            temp = temp->next;
        }

        temp->next = new;
    }

    printf("Student added successfully\n");
    printf("Roll number: %d\n", roll);
}
