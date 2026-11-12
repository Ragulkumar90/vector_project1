#include "student.h"

int main()
{
    struct student *head = NULL;
    char choice, ch;

    stud_load(&head);

    while(1)
    {
        printf("\n******** STUDENT RECORD MENU ********\n");

        printf("a/A : Add new record\n");
        printf("d/D : Delete record\n");
        printf("s/S : Show records\n");
        printf("m/M : Modify record\n");
        printf("v/V : Save records\n");
        printf("t/T : Sort records\n");
        printf("l/L : Delete all records\n");
        printf("r/R : Reverse list\n");
        printf("e/E : Exit\n");

        printf("Enter your choice: ");
        scanf(" %c", &choice);

        switch(choice)
        {
            case 'a':
            case 'A':
                stud_add(&head);
                break;

            case 'd':
            case 'D':
                stud_del(&head);
                break;

            case 's':
            case 'S':
                stud_show(head);
                break;

            case 'm':
            case 'M':
                stud_mod(head);
                break;

            case 'v':
            case 'V':
                stud_save(head);
                break;

            case 't':
            case 'T':
                stud_sort(head);
                break;

            case 'r':
            case 'R':
                stud_reverse(&head);
                break;

            case 'l':
            case 'L':
                stud_free(&head);
                printf("All records deleted\n");
                break;

            case 'e':
            case 'E':

                printf("S : Save and Exit\n");
                printf("E : Exit without saving\n");

                scanf(" %c", &ch);

                if(ch == 's' || ch == 'S')
                    stud_save(head);

                stud_free(&head);

                printf("Program terminated\n");
                return 0;

            default:
                printf("Invalid choice\n");
        }
    }
}
