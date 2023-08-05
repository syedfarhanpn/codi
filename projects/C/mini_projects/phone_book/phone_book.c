#include<stdio.h>
#include<stdlib.h>
#include<string.h>


struct person
{
    char name[30];
    char country_code[4];
    int phone_no;
    char sex[6];
    char mail[100];
};

typedef struct person person;

//function declarations
void remove_all();
void print_menu();
void add_person();
void list_record();
void search_person();
void remove_person();
void update_person();
void take_input(person *p);

void main()
{
    int choice;
    while(1)
    {
        print_menu();
        scanf("%d",&choice);
        switch(choice)
        {
            case 1: list_record();
                    getchar();
                    getchar();
                    break;
            case 2: add_person();
                    getchar();
                    getchar();
                    break;
            case 3: search_person();
                    getchar();
                    getchar();
                    break;
            case 4: remove_person();
                    getchar();
                    getchar();
                    break;
            case 5: update_person();
                    getchar();
                    getchar();
                    break;
            default:system("cls");
                    printf("Thenks for using thE Phone Book");
                    getchar();
                    getchar();
                    exit(1);        
        }
    }
}

void print_menu()
{
    system("cls");
    printf("\t\t*********************************************************************\n");
    printf("\t\t*                 Welcome To The Phone Book                         *\n");
    printf("\t\t*********************************************************************\n");
    printf("\t\t\t1) List Record\n\n");
    printf("\t\t\t2) Add Person\n\n");
    printf("\t\t\t3) Search Person Details\n\n");
    printf("\t\t\t4) Remove Person\n\n");
    printf("\t\t\t5) Update Person\n\n");
    printf("\t\t\t6) Delete all contacts\n\n");
    printf("\t\t\t7) Exit\n\n");

    printf("\t\t\t\tEnter Your Choice : ");
}

void add_person()
{
    system("cls");
    FILE *fp;
    fp = fopen("phonebook_db","ab+");
    if(fp==NULL)
    {
        printf("Error In File Opening,Please Try Again! \n");
        printf("Press any key to continue....\n");
        return;
    }
    else
    {
        person p;
        take_input(&p);
        fwrite(&p, sizeof(p), 1, fp);
        fflush(stdin);
        fclose(fp);
        system("cls");
        printf("Record added successfully");
        printf("Press any key to continue....\n");
    }
}

void take_input(person *p)
{
    system("cls");
    
    printf("Enter Name : ");
    scanf("%s",p->name);
    
    printf("Enter Country Code : ");
    scanf("%s",p->country_code);
    
    printf("Enter Mobile No : ");
    scanf("%s",p->phone_no);
    
    printf("Enter sex : ");
    scanf("%s",p->sex);
    
    printf("Enter mail : ");
    scanf("%s",p->mail);
}