#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct student
{
    int rollno;
    char name[50];
    float percentage;
    struct student *next;
};

void stud_add(struct student **);
void stud_del(struct student **);
void stud_show(struct student *);
void stud_mod(struct student *);
void stud_sort(struct student *);
void stud_reverse(struct student **);

void stud_save(struct student *);
void stud_load(struct student **);
void stud_free(struct student **);
