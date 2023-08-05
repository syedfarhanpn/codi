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

void list_record()
{
    system("cls");
    FILE *fp;
    fp = fopen("phonebook_db","rb");
    if(fp==NULL)
    {
        printf("Error In File Opening,Please Try Again! \n");
        printf("Press any key to continue....\n");
        return;
    }
    else
    {
        person p;
        printf("\t\t*********************************************************************\n");
        printf("\t\t*                   Here Is All Recorded Contacts                   *\n");
        printf("\t\t*********************************************************************\n");
        printf("\t\t NAME \t\t\t COUNTRY CODE \t\t PHONE NO \t\t\t SEX \t\t\t MAIL\n");
        PRINTF("-------------------------------------------------------------------------\n");
        while(fread(&p, sizeof(p), 1, fp)==1)
        {
            int i;
            int len1 = 40 - strlen(p.name);
            int len2 = 19 - strlen(p.country_code);
            int len3 = 15;
            int len4 = 21 - strlen(p.sex);
           
            printf("%s",p.name);
            for(i=0;i<len1;i++)
                printf(" ");

            printf("%s",p.country_code);
            for(i=0;i<len2;i++)
                printf(" ");

            printf("%d",p.phone_no);
            for(i=0;i<len3;i++)
                printf(" ");
            
            printf("%s",p.sex);
            for(i=0;i<len4;i++)
                printf(" ");
            
            printf("%s",p.mail);
            printf("\n");
            fflush(stdin);
        }
        fflush(stdin);
        fclose(fp);
        printf("\n\n Pressany key to continue....\n");
    }
}

void search_person()
{
    system("cls");
    int phone;
    printf("Enter the phone number of the person you want to find: ");
    scanf("%d",&phone);

    FILE *fp;
    fp = open("phonebook_db","rb");
    if (fp==NULL)
    {
        printf("Error In File Opening,Please Try Again! \n");
        printf("Press any key to continue....\n");
        return;
    }
    else
    {
        int flag=0;
        person p;
        while(fread(&p,sizeof(p), 1, fp) == 1)
        {
            if(p.phone_no == phone)
            {
                printf("\t NAME \t\t\t\t COUNTRY CODE \t\t\t\t PHONE NO \t\t\t\t SEX \t\t\t\t MAIL \n");
                printf("---------------------------------------------------------------------------\n");
                int i;
                int len1 = 40 - strlen(p.name);
                int len2 = 19 - strlen(p.country_code);
                int len3 = 15;
                int len4 = 21 - strlen(p.sex);
            
                printf("%s",p.name);
                for(i=0;i<len1;i++)
                    printf(" ");

                printf("%s",p.country_code);
                for(i=0;i<len2;i++)
                    printf(" ");

                printf("%d",p.phone_no);
                for(i=0;i<len3;i++)
                    printf(" ");
                
                printf("%s",p.sex);
                for(i=0;i<len4;i++)
                    printf(" ");
                
                printf("%s",p.mail);
                printf("\n");
                
                flag=1;
                break;
            }
            else continue;
        }
        if(flag==0)
        {
            system("cls");
            printf("Person Is Not In The Phone Book\n");
        }
        fflush(stdin);
        fclose(fp);
        printf("\n\n Pressany key to continue....\n");
    }
}