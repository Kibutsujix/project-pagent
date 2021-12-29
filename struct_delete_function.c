#include <stdio.h>
#include <stdlib.h>
#include<string.h>
typedef enum
{
    Mystery,
    Thriller,
    Horror,
    Fiction,
    Romance
} genre;

struct issue
{
    int day;
    int time;
    int year;
    int status;
} ISSUE;

typedef struct
{
    int price;
    int genre;
    struct issue ISSUE;
    char id[6];
    char book_name[50];
    char author_name[50];
} LIBRARY;
void del_books(LIBRARY books[5][4], int m,int n)
{
    int k,i,p;
    LIBRARY del_item, j;
    struct issue ISSUE;
    ISSUE.status=0;
    printf("Enter the details of the book to be deleted in the PRICE GENRE ID BOOK NAME AUTHOR NAME format\n");
    scanf("%d %d %s %d %f", &del_item.price, &del_item.genre,
          del_item.id, &del_item.book_name, &del_item.author_name);
    for (i = 0; i < m; i++)
    {
        for ( p = 0; p < n; p++)
        {
            if (strcmp(books[i][p].id,del_item.id)==0)
            {
                j = books[i][p];
                ISSUE.status=1;
                n--;
                for (int k = 0; k < n; k++)
                {
                    books[i][p] = books[i][p+1];
                    p++;
                }
                break;
            }
        }
    }
}
int main()
{
    LIBRARY catalog[5][4] = {

    { {1000,0,{ 27,12,2021,0 },"82734","Gone Girl","Gillian Flynn"}, {2332,0,{ 17,10,2021,0 },"32434","The Hound of the Baskervilles","Sir Arthur Conan Doyle"} },

    { {3423,1,{ 22,03,2021,0 },"34212","The Guest List","Lucy Foley"}, {4433,1,{ 03,05,2021,1 },"43253","The Girl on the Train","Paula Hawkins"} },

    { {4221,2,{ 21,11,2021,1 },"24353","The Haunting of Hill House","Shirley Jackson"}, {1212,2,{ 15,12,2021,0 },"43522","The Shining","Stephen King"} },

    { {1234,3,{ 25,01,2022,1 },"53212","The Great Gatsby","Scott Fitzgerald"}, {5435,3,{ 12,07,2021,0 },"22853","Nineteen Eighty Four","Eric Arthur Blair"} },

    { {1982,4,{ 23,04,2021,1 },"43255","It Ends with Us","Colleen Hoover"}, {3432,4,{ 07,12,2021,1 },"31232","Pride and Prejudice","Jane Austen"} }

};
    del_books(catalog, 5,4);
    return 0;
}