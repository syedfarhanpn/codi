#include<stdio.h>
#include<stdlib.h>
#include<string.h>


struct person
{
    char name[30];
    char country_code[4];
    char phone_no[15];
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
                    break;
            case 2: add_person();
                    getchar();
                    break;
            case 3: search_person();
                    getchar();
                    break;
            case 4: remove_person();
                    getchar();
                    break;
            case 5: update_person();
                    getchar();
                    break;
            case 6: remove_all();
                    getchar();
                    break;
            case 7: system("cls");
                    printf("Thanks for using the Phone Book\n");
                    exit(1);     
            default:printf("Invalid option try again!\n");
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
        printf("Press Enter to continue....\n");
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
        printf("Record added successfully\n");
        printf("Press Enter to continue....\n");
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
    scanf("%s",&p->phone_no);
    
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
        printf("Press Enter to continue....\n");
        return;
    }
    else
    {
        person p;
        printf("*********************************************************************************************************************************\n");
        printf("*                                                 Here Is All Recorded Contacts                                                 *\n");
        printf("*********************************************************************************************************************************\n");
        printf("NO\tNAME\t\t\t\tCOUNTRY CODE\tPHONE NO\t\t SEX \t\t MAIL\n");
        printf("---------------------------------------------------------------------------------------------------------------------------------\n");
        while(fread(&p, sizeof(p), 1, fp)==1)
        {
            int i;
            
            int len1 = 32 - strlen(p.name);
            int len2 = 16 - strlen(p.country_code);
            int len3 = 25 - strlen(p.phone_no);
            int len4 = 16 - strlen(p.sex);

            printf("%s",p.name);
            for(i=0;i<len1;i++)
                printf(" ");

            printf("%s",p.country_code);
            for(i=0;i<len2;i++)
                printf(" ");
        
            printf("%s",p.phone_no);
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
        printf("\n\n Press Enter to continue....\n");
    }
}

void search_person()
{
    system("cls");
    char phone[15];
    printf("Enter the phone number of the person you want to find: ");
    scanf("%s",phone);

    FILE *fp;
    fp = fopen("phonebook_db","rb");
    if (fp==NULL)
    {
        printf("Error In File Opening,Please Try Again! \n");
        printf("Press Enter to continue....\n");
        return;
    }
    else
    {
        int flag=0,l=0;
        person p;
        while(fread(&p,sizeof(p), 1, fp) == 1)
        {
            l=strcmp(phone,p.phone_no);
            if(l==0)
            {
                printf("\n");
                printf("No\tNAME\t\t\t\tCOUNTRY CODE\tPHONE NO\t\t SEX \t\t MAIL\n");
                printf("---------------------------------------------------------------------------------------------------------------------------------\n");
                int i;
                int len1 = 32 - strlen(p.name);
                int len2 = 16 - strlen(p.country_code);
                int len3 = 25 - strlen(p.phone_no);
                int len4 = 16 - strlen(p.sex);
                

                printf("%s",p.name);
                for(i=0;i<len1;i++)
                    printf(" ");

                printf("%s",p.country_code);
                for(i=0;i<len2;i++)
                    printf(" ");

                printf("%s",p.phone_no);
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
        printf("Press Enter to continue....\n");
    }
}

void update_person()
{
    system("cls");
    char phone[15];
    printf("Enter the mobile no of the person you want to update : ");
    scanf("%s",phone);

    FILE *fp,*temp;
    fp = fopen("phonebook_db", "rb");
    temp = fopen("temp", "wb");

    if(fp == NULL)
    {
        printf("Error in file opening, Please try again!\n");
        printf("Press Enter to continue....\n");
        return;
    }
    else
    {
        int flag=0,l=0;
        person p;
        while(fread(&p, sizeof(p), 1, fp) == 1)
        {
            l=strcmp(phone,p.phone_no);
            if(l==0)
            {
                take_input(&p);
                fwrite(&p, sizeof(p), 1, temp);
                system("cls");
                printf("Data updated successfully\n");
                flag=1;
            }
            else
                fwrite(&p, sizeof(p), 1, temp);
            fflush(stdin);            
        }
        if(flag == 0)
        {
            system("cls");
            printf("No record found on %s number",phone);
        }
        fclose(fp);
        fclose(temp);
        remove("phonebook_db");
        rename("temp", "phonebook_db");
        fflush(stdin);
        printf("Press Enter to continue....\n");
    }
}

void remove_person()
{
    system("cls");
    char phone[15];
    printf("Enter the mobile number you need to remove : ");
    scanf("%s", phone);
    
    FILE *fp;
    fp = fopen("phonebook_db", "wb+");
    
    if(fp == NULL)
    {
        printf("Error in file opening, Please try again!\n");
        printf("Press Enter to continue....\n");
        return;
    }
    else
    {
        int flag=0,l=0;
        person p;
        while(fread(&p, sizeof(p), 1, fp) == 1)
        {
            l=strcmp(phone,p.phone_no);
            if(l==0)
            {
                // remove("p");
                system("cls");
                printf("Person has been removed successfully\n");
                flag=1;
            }
            else continue;           
        }
        if(flag == 0)
        {
            system("cls");
            printf("No record found on %s number\n",phone);
        }
        fflush(stdin);
        fclose(fp);
        printf("Press Enter to continue....\n");
    }
}

void remove_all()
{
    char choice;
    system("cls");
    remove("./phonebook_db");
    printf("All data in the phonebook deleted successfully\n");
    printf("Press Enter to continue....\n");
}