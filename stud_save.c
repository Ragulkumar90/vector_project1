#include "student.h"

void stud_save(struct student *ptr)
{
    FILE *fp;

    fp = fopen("student.dat", "w");

    if(fp == NULL)
    {
        printf("File opening failed\n");
        return;
    }

    while(ptr != NULL)
{
    fprintf(fp, "%d %s %.2f\n",
            ptr->rollno,
            ptr->name,
            ptr->percentage);

    ptr = ptr->next;
}

    fclose(fp);

    printf("Records saved successfully\n");
}


// LOAD FUNCTION

void stud_load(struct student **ptr)
{
    FILE *fp;
    struct student *new, *temp;

    int roll;
    char name[50];
    float percentage;

    fp = fopen("student.dat", "r");

    if(fp == NULL)
        return;

    while(fscanf(fp, "%d %49s %f",
             &roll, name, &percentage) == 3)
{

        new = malloc(sizeof(struct student));

        if(new == NULL)
            break;

        new->rollno = roll;
        strcpy(new->name, name);
        new->percentage = percentage;
        new->next = NULL;

        if(*ptr == NULL)
        {
            *ptr = new;
        }
        else
        {
            temp = *ptr;

            while(temp->next != NULL)
                temp = temp->next;

            temp->next = new;
        }
    }

    fclose(fp);

    printf("Records loaded successfully\n");
}


// FREE FUNCTION

void stud_free(struct student **ptr)
{
    struct student *temp;

    while(*ptr != NULL)
    {
        temp = *ptr;

        *ptr = (*ptr)->next;

        free(temp);
    }

    *ptr = NULL;
}
