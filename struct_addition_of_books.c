#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define GENERE 5
#define BOOKS_PER_GENERE 4

typedef enum {Mystery, Thriller, Horror, Fiction, Romance} genre;

struct issue {
    int day;
    int time;
    int year;
    int status;
} issue;

typedef struct {
    int price;
    int genre;
    struct issue ISSUE;
    char id[6];
    char book_name[50];
    char author_name[50];
} BOOK;

BOOK catalog[GENERE][BOOKS_PER_GENERE] = {

    { {1000,0,{ 27,12,2021,0 },"82734","Gone Girl","Gillian Flynn"}, {2332,0,{ 17,10,2021,0 },"32434","The Hound of the Baskervilles","Sir Arthur Conan Doyle"} },

    { {3423,1,{ 22,03,2021,0 },"34212","The Guest List","Lucy Foley"}, {4433,1,{ 03,05,2021,1 },"43253","The Girl on the Train","Paula Hawkins"} },

    { {4221,2,{ 21,11,2021,1 },"24353","The Haunting of Hill House","Shirley Jackson"}, {1212,2,{ 15,12,2021,0 },"43522","The Shining","Stephen King"} },

    { {1234,3,{ 25,01,2022,1 },"53212","The Great Gatsby","F. Scott Fitzgerald"}, {5435,3,{ 12,07,2021,0 },"22853","Nineteen Eighty-Four","Eric Arthur Blair"} },

    { {982,4,{ 23,04,2021,1 },"43255","It Ends with Us","Colleen Hoover"}, {342,4,{ 07,12,2021,1 },"31232","Pride and Prejudice","Jane Austen"} }

};
int books_occupied[] = {2, 2, 2, 2, 2};
void add_books();
void pretty_print();
char genre_list[5][100] = {"Mystery", "Thriller", "Horror", "Fiction", "Romance"};
int main()
{
    int ch;
    printf("****Addition of books*****\n");
    add_books();
    pretty_print();
    return 0;
}

void add_books()
{
    int genre_books;
    for(;;)
    {
    printf("Enter the genre for which books are to be added:\n");
    printf("1.Mystery 2.Thriller 3.Horror 4.Fiction 5.Romance 6.Exit\n");
    scanf("%d",&genre_books);
    switch(genre_books)
    {
    case 1:
       if(books_occupied[Mystery]<=5)
       {
       scanf("%s %s %s %d %s", catalog[0][books_occupied[Mystery]].id, catalog[0][books_occupied[Mystery]].book_name, catalog[0][books_occupied[Mystery]].author_name, &catalog[0][books_occupied[Mystery]].price, genre_list[0]);
       books_occupied[Mystery]++;
       break;
       }
       break;
    
       
    
    case 2:
    if(books_occupied[Thriller]<=5)
    {
      scanf("%s %s %s %d %s", catalog[1][books_occupied[Thriller]].id, catalog[1][books_occupied[Thriller]].book_name, catalog[1][books_occupied[Thriller]].author_name, &catalog[1][books_occupied[Thriller]].price, genre_list[1]);
      books_occupied[Thriller]++;
      break; 
    }
    break;
    
    case 3:
    if(books_occupied[Horror]<=5)
    {
        scanf("%s %s %s %d %s", catalog[2][books_occupied[Horror]].id, catalog[2][books_occupied[Horror]].book_name, catalog[2][books_occupied[Horror]].author_name, &catalog[2][books_occupied[Horror]].price, genre_list[2]);
        books_occupied[Horror]++;
        break;
    }
    break;
    case 4:
    if(books_occupied[Fiction]<=5)
    {
         scanf("%s %s %s %d %s", catalog[3][books_occupied[Fiction]].id, catalog[3][books_occupied[Fiction]].book_name, catalog[3][books_occupied[Fiction]].author_name, &catalog[3][books_occupied[Fiction]].price, genre_list[3]);
         books_occupied[Fiction]++;
         break;
    }
    break;
    
    case 5:
    if(books_occupied[Romance]<=5)
    {
            scanf("%s %s %s %d %s", catalog[4][books_occupied[Romance]].id, catalog[4][books_occupied[Romance]].book_name, catalog[4][books_occupied[Romance]].author_name, &catalog[4][books_occupied[Romance]].price, genre_list[4]);
            books_occupied[Romance]++;
            break;
    }
    break;
    
    case 6:
    return;
    default:
    printf("Enter a valid choice\n");
    break;
    }
    }
  return;
}
void pretty_print(){

    int i, j;
    printf("\n\t+---------------------------------------------------------------------------------------+\n");
    printf("\tID\t NAME\t\t\t AUTHOR\t\t\t PRICE\t\t GENRE\n");
    printf("\t+---------------------------------------------------------------------------------------+\n");
    for(i=0; i<GENERE; i++){
        for(j=0; j<books_occupied[i]; j++){
            if(strlen(catalog[i][j].book_name)>10)
                printf("\t| %s\t | %.15s...\t | %.15s...\t | %d\t\t | %s\n", catalog[i][j].id, catalog[i][j].book_name, catalog[i][j].author_name, catalog[i][j].price, genre_list[i]);
            else
                printf("\t| %s\t | %s\t\t | %s\t | %d\t\t | %s\n", catalog[i][j].id, catalog[i][j].book_name, catalog[i][j].author_name, catalog[i][j].price, genre_list[i]);
        }
    }            
}