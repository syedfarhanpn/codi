#include<stdio.h>
    
void menu();
void add_task();
void remove_task();
void view_task();
void update_task();
void remove_all();
void input_task();

void main()
{
    int choice;
    while(1)
    {
        menu();
        scanf("%d",&choice);
        switch(choice)
        {
            case 1: add_task();
                    getchar();
                    break;
            case 2: view_task();
                    getchar();
                    break;
            case 3: remove_task();
                    getchar();
                    break;
            case 4: update_task();
                    getchar();
                    break;
            case 5: remove_all();
                    getchar();
                    break;
            case 6: system("cls");
                    printf("Be Productive By coming back\n");
                    exit(1);
            default:printf("Invalid Option, Try Again!\n");
        }
    }
}

void menu()
{
    system("cls");
    printf("\t\t**********************************************************************\n");
    printf("\t\t*                             TO-DO LIST                             *\n");
    printf("\t\t*                             ~~~~~~~~~~                             *\n");
    printf("\t\t**********************************************************************\n");
    printf("\t\t\t1) View Tasks\n\n");
    printf("\t\t\t2) Add Task\n\n");
    printf("\t\t\t3) Remove Task\n\n");
    printf("\t\t\t4) Update task\n\n");
    printf("\t\t\t5) Delete all tasks\n\n");
    printf("\t\t\t6) Exit\n\n");

        printf("\t\t\t\tEnter Your Choice : ");
}

void view_task()
{
    
}