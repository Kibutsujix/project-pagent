#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include<database.h>
#include<functions.h>
#include<utilities.h>

void modify();
void switch_choices(int i,int temp);

void switch_choices(int i,int temp)
{
    int ch;
    printf("enter field to be modified\n");
    printf("1.id\n2.book name\n3.price\n");
    scanf("%d",&ch);
    switch(ch)
    {
        case 1 :
        printf("enter new id\n");
        scanf("%s",catalog[i][temp].id);
        printbooks(i,temp);
        break;
        case 2 :
        printf("enter new book name \n");
        scanf("%s",catalog[i][temp].book_name);
        printbooks(i,temp);
        break;
        case 3 :
        printf("enter new price\n");
        scanf("%d",&catalog[i][temp].price);
        printbooks(i,temp);
        break;
        default : printf("enter valid input (1-3)\n");
    }
}

void modify()
{
    char id[6];
    int i=0,temp;
    pprint();
    printf("enter the genre to be modified (choose integer only)\n");
    for(;;)
    {
        for(i=0;i<GENRE;i++)
            printf("%d.%s\n",(i+1),genre_list[i]);
        printf("enter your genre\n");
        scanf("%d",&i);
        printf("Enter id to be modified\n");
        scanf("%s",id);
        temp = search(id,3);
        switch(i)
        {
            case 1 :
            if(temp != -1)
                switch_choices((i-1),temp);
            break;
            case 2 :
           if(temp != -1)
                switch_choices((i-1),temp);

            break;
            case 3 :
            if(temp != -1)
                switch_choices((i-1),temp);

            break;
            case 4 :
            if(temp != -1)
                switch_choices((i-1),temp);
            break;
            case 5 :
            if(temp != -1)
                switch_choices((i-1),temp);
            break;
            case 6 :
            return;
            default :
            printf("enter valid input between 1-6\n");
            break;
            
        }
    }
}
//DRIVER CODE
int main()
{
    modify();
    return 0;
}
