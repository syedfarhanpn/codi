#include <stdio.h>
#include <windows.h>

void main()
{
    int h,m,s;
    int d=1000;
    printf("Enter hr:m:s\n");
    scanf("%d%d%d",&h,&m,&s);
    if(h>12 || m>59 || s>59)
    {
        printf("Invalid Input");
        exit(0);
    }
    while(1)
    {
        s++;
        if(s>59)
        {
            s=0;
            m++;
        }
        if(m>59)
        {
            m=0;
            h++;
        }
        if(h>12)
        {
            h=1;
        }
        printf("\n \t\t\t\t\t\t\t\t\t\tClock:");
        printf("%02d:%02d:%02d",h,m,s);
        Sleep(d);
        system("cls");
    }
}