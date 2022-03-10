#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#include "database.h"
#include "functions.h"
#include "utilities.h"

const char* genre_list[] = {"Mystery", "Thriller", "Horror", "Fiction", "Romance"};

BOOK catalog[GENRE][BOOKS_PER_GENRE] = {

    { {1000,0,{ 27,12,2021,0 },"82734","Gone Girl","Gillian Flynn"}, {2332,0,{ 17,10,2021,0 },"32434","The Hound of the Baskervilles","Sir Arthur Conan Doyle"} },

    { {3423,1,{ 22,03,2021,0 },"34212","The Guest List","Lucy Foley"}, {4433,1,{ 03,05,2021,1 },"43253","The Girl on the Train","Paula Hawkins"} },

    { {4221,2,{ 21,11,2021,0 },"24353","The Haunting of Hill House","Shirley Jackson"}, {1212,2,{ 15,12,2021,0 },"43522","The Shining","Stephen King"} },

    { {1234,3,{ 25,01,2022,1 },"53212","The Great Gatsby","Scott Fitzgerald"}, {5435,3,{ 12,07,2021,0 },"22853","Nineteen Eighty Four","Eric Arthur Blair"} },

    { {1982,4,{ 23,04,2021,0 },"43255","It Ends with Us","Colleen Hoover"}, {3432,4,{ 07,12,2021,1 },"31232","Pride and Prejudice","Jane Austen"} }

};

int books_occupied[5] = {2, 2, 2, 2, 2};

int ADMIN = 0;

INDEX search(char* args, int choice){

	int i, j;
	char* temp=NULL;
    INDEX dd_index = { -1, -1 };

	switch(choice){

		// search by author name
		case 1:
			for(i=0;i<GENRE;i++){
				for(j=0;j<books_occupied[i];j++){
					if(strcmp(args, temp=to_lower(catalog[i][j].author_name))==0 && (ADMIN == 1 || catalog[i][j].ISSUE.status==0)){
                        printf("\nBook found.\n");
						printbooks(i, j);
						free(temp);
                        return dd_index;
					}
					else
						free(temp);
				}
			}
			break;

		// search by book name
		case 2:
			for(i=0;i<GENRE;i++){
				for(j=0;j<books_occupied[i];j++){
					if(strcmp(args, temp=to_lower(catalog[i][j].book_name))==0 && (ADMIN == 1 || catalog[i][j].ISSUE.status==0)){
	                    printf("\nBook found.\n");
						printbooks(i, j);
						free(temp);
						return dd_index;
					}
					else
						free(temp);
				}
			}
			break;

		// search by ID
		case 3:
			for(i=0;i<GENRE;i++){
				for(j=0;j<books_occupied[i];j++){
					if(atoi(args) == atoi(catalog[i][j].id) && (ADMIN == 1 || catalog[i][j].ISSUE.status==0)){
                    	printf("\nBook found.\n");
						printbooks(i, j);
                        dd_index.i = i; dd_index.j = j;
                        return dd_index;
					}
				}
			}
			break;
		}

    printf("Book Issued/Not found.\n");
	return dd_index;
  }


void search_books(){
	int choice;
	char args[50], *temp;

    for(;;)
	{
		printf("\nSearch by:\n\n1. Author name\n2. Book name\n3. Book ID\n\n");
		printf("Enter a choice/Enter 4 to exit search: ");
		scanf("%d", &choice);
		getchar();

		switch(choice)
		{
			case 1:
				printf("Enter the author's name: ");
				scanf("%[^\n]s", args);
				search(temp=to_lower(args), choice);
				free(temp);
				break;

			case 2:
				printf("Enter the book name: ");
				scanf("%[^\n]s", args);
				search(temp=to_lower(args), choice);
				free(temp);
				break;

			case 3:
				printf("Enter the ID of the book: ");
				scanf("%[^\n]s", args);
				search(args, choice);
				break;

			case 4:
				return;

			default:
				printf("Enter a choice between 1-4 only.\n");
		}
	}
}

void sort(int choice){

    int i, j, k, min;

    switch(choice) {

        // sort by ID
        case 1:
            for(i=0; i<GENRE; i++){
                for(j=0; j<books_occupied[i]-1; j++){
                    min = j;
                    for(k=j+1; k<books_occupied[i]; k++){
                        if(atoi(catalog[i][k].id) < atoi(catalog[i][min].id))
                            min = k;
                    }
                    if(min != j)
                        s_swap(i, min, j);
                }
            }
            break;

        // sort by book name
        case 2:
            for(i=0; i<GENRE; i++){
                for(j=0; j<books_occupied[i]-1; j++){
                    min = j;
                    for(k=j+1; k<books_occupied[i]; k++){
                        if(strcmp(catalog[i][k].book_name, catalog[i][min].book_name)<0)
                            min = k;
                    }
                    if(min != j)
                        s_swap(i, min, j);
                }
            }
            break;

        // sort by author name
        case 3:
            for(i=0; i<GENRE; i++){
                for(j=0; j<books_occupied[i]-1; j++){
                    min = j;
                    for(k=j+1; k<books_occupied[i]; k++){
                        if(strcmp(catalog[i][k].author_name, catalog[i][min].author_name)<0)
                            min = k;
                    }
                    if(min != j)
                        s_swap(i, min, j);
                }
            }
            break;

        // sort by price
        case 4:
            for(i=0; i<GENRE; i++){
                for(j=0; j<books_occupied[i]-1; j++){
                    min = j;
                    for(k=j+1; k<books_occupied[i]; k++){
                        if(catalog[i][k].price < catalog[i][min].price)
                            min = k;
                    }
                    if(min != j)
                        s_swap(i, min, j);
                }
            }
            break;
    }
}

void sort_books(){

    int choice;

    for(;;){

        printf("\nSort by:\n\n1. ID\n2. Book Name\n3. Author Name\n4. Price\n\n");
        printf("Enter a choice/Enter 5 to exit sort: ");
        scanf("%d", &choice);

        if(choice<5 && choice>0){
            sort(choice);
            pprint();
        }
        else if(choice == 5)
            return;
        else
            printf("Enter a choice between 1-5 only.\n\n");
    }
}

void modify(int i, int j)
{
    int choice;

    printf("Modify:\n\n1. ID\n2. Book Name\n3. Author's Name\n4. Price\n");
    printf("\nEnter a field: ");
    scanf("%d", &choice);
    getchar();

    printf("Enter new value: ");

    switch(choice){

        case 1:
            scanf("%[^\n]s", catalog[i][j].id);
            break;

        case 2:
            scanf("%[^\n]s", catalog[i][j].book_name);
            break;

        case 3:
            scanf("%[^\n]s", catalog[i][j].author_name);
            break;

        case 4:
            scanf("%d", &catalog[i][j].price);
            break;

        default:
            printf("Enter an choice between 1-5 only.\n");
            return;
    }

    printf("\nUpdated details: \n");
    printbooks(i, j);
}

void b_issue(int i, int j){

    static int count = 0;

    if(count<3){
        time_t t = time(NULL);
        struct tm date = *localtime(&t);

        catalog[i][j].ISSUE.day =  date.tm_mday;
        catalog[i][j].ISSUE.month = date.tm_mon + 1;
        catalog[i][j].ISSUE.year = date.tm_year + 1900;
        catalog[i][j].ISSUE.status = 1;

        printf("Issued on: %d-%02d-%02d", catalog[i][j].ISSUE.day, catalog[i][j].ISSUE.month, catalog[i][j].ISSUE.year);
        printf(" at %02d:%02d:%02d.\n", date.tm_hour, date.tm_min, date.tm_sec);
        ++count;
    }
    else
        printf("You can borrow upto 3 books. Book not ISSUED.\n");
}

void add(){

  int i;

  printf("\n");
  for(i=0;i<GENRE;i++)
    printf("%d. %s\n", i+1, genre_list[i]);
  printf("\nEnter a genre: ");
  scanf("%d", &i);
  getchar();

  if(i>0 && i<6){

    if(books_occupied[i-1]<=3){

        // using this method to make it an interactive session
        printf("ID: ");
        scanf("%[^\n]s", catalog[i-1][books_occupied[i-1]].id);
        getchar();

        printf("Name: ");
        scanf("%[^\n]s", catalog[i-1][books_occupied[i-1]].book_name);
        getchar();

        printf("Author Name: ");
        scanf("%[^\n]s", catalog[i-1][books_occupied[i-1]].author_name);
        getchar();

        printf("Price: ");
        scanf("%d", &catalog[i-1][books_occupied[i-1]].price);
        getchar();

        catalog[i-1][books_occupied[i-1]].genre = i-1;

        ++books_occupied[i-1];
        printf("\nBook details:\n");
        printbooks(i-1, books_occupied[i-1]-1);

    }
    else
      printf("Database with %s genre is full. Try something else.\n", genre_list[i-1]);
  }
  else
    printf("Enter a valid genre.\n");
}


void delete(int i, int x){

    int j;
    for (j=x; j<books_occupied[i]-1; j++)
        catalog[i][j] = catalog[i][j+1];

    --books_occupied[i];
    printf("BOOK DELETED.\n");
}

void book_ops(int choice){

    INDEX dd_index;
    char id[6];

    pprint();

    // accept ID of a book to perform a specified operation
    printf("\nEnter the ID of the book: ");
    scanf("%s", id);
    dd_index = search(id, 3);
    if(dd_index.i != -1){

        switch(choice){

            case 2:
                delete(dd_index.i, dd_index.j);
                break;

            case 3:
                modify(dd_index.i, dd_index.j);
                break;

            case 4:
                b_issue(dd_index.i, dd_index.j);
                return;
        }
    }
}
