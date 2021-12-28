#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <database.h>
#include <functions.h>
#include <utilities.h>

const char* genre_list[5] = {"Mystery", "Thriller", "Horror", "Fiction", "Romance"};

BOOK catalog[GENRE][BOOKS_PER_GENRE] = {

    { {1000,0,{ 27,12,2021,0 },"82734","Gone Girl","Gillian Flynn"}, {2332,0,{ 17,10,2021,0 },"32434","The Hound of the Baskervilles","Sir Arthur Conan Doyle"} },

    { {3423,1,{ 22,03,2021,0 },"34212","The Guest List","Lucy Foley"}, {4433,1,{ 03,05,2021,1 },"43253","The Girl on the Train","Paula Hawkins"} },

    { {4221,2,{ 21,11,2021,1 },"24353","The Haunting of Hill House","Shirley Jackson"}, {1212,2,{ 15,12,2021,0 },"43522","The Shining","Stephen King"} },

    { {1234,3,{ 25,01,2022,1 },"53212","The Great Gatsby","Scott Fitzgerald"}, {5435,3,{ 12,07,2021,0 },"22853","Nineteen Eighty Four","Eric Arthur Blair"} },

    { {1982,4,{ 23,04,2021,1 },"43255","It Ends with Us","Colleen Hoover"}, {3432,4,{ 07,12,2021,1 },"31232","Pride and Prejudice","Jane Austen"} }

};

int books_occupied[5] = {2, 2, 2, 2, 2};

int search(char* args, int choice){

	int i, j;
	char* temp=NULL;

	switch(choice){

		// search by author name
		case 1:
			for(i=0;i<GENRE;i++){
				for(j=0;j<books_occupied[i];j++){
					if(strcmp(args, temp=to_lower(catalog[i][j].author_name))==0 && catalog[i][j].ISSUE.status==0){
						printbooks(i, j);
						free(temp);
						return j;
					}
					else
						free(temp);
				}
			}
			break;

		// search by book name
		case 2:
			for(int i=0;i<GENRE;i++){
				for(int j=0;j<books_occupied[i];j++){
					if(strcmp(args, temp=to_lower(catalog[i][j].book_name))==0 && catalog[i][j].ISSUE.status==0){
						printbooks(i, j);
						free(temp);
						return j;
					}
					else
						free(temp);
				}
			}
			break;

		// search by ID
		case 3:
			for(int i=0;i<GENRE;i++){
				for(int j=0;j<books_occupied[i];j++){
					if(atoi(args) == atoi(catalog[i][j].id) && catalog[i][j].ISSUE.status==0){
						printbooks(i, j);
						return j;
					}
				}
			}
			break;
		}

	return -1;
  }


void search_books(){
	int choice, p;
	char author[50], bookname[50], se_id[6], *temp;
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
				scanf("%[^\n]s", author);
				p=search(temp=to_lower(author), choice);
				free(temp);
				break;

			case 2:
				printf("Enter the book name: ");
				scanf("%[^\n]s",bookname);
				search(temp=to_lower(bookname), choice);
				free(temp);
				break;

			case 3:
				printf("Enter the ID of the book: ");
				scanf("%[^\n]s", se_id);
				search(se_id, choice);
				break;

			case 4:
				return;

			default:
				printf("Enter a choice between 1 & 4 only.\n");
		}
	}
}

void sort(int choice){

    int h, i, j, k, min;
    BOOK temp;
    switch(choice) {

        // sort by ID
        case 1:
            for(i=0; i<GENRE; i++){
                for(j=0; j<books_occupied[i]-1; j++){
                    min = j;
                    for(k=j+1;k<books_occupied[i];k++){
                        if(atoi(catalog[i][k].id) < atoi(catalog[i][min].id)){
                            min = k;
                            scopy(i, min, j);
                        }
                    }
                }
            }
            break;

        // sort by book name
        case 2:
            for(i=0; i<GENRE; i++){
                for(j=0; j<books_occupied[i]-1; j++){
                    min = j;
                    for(k=j+1;k<books_occupied[i];k++){
                        if(strcmp(catalog[i][k].book_name, catalog[i][min].book_name)<0){
                            min = k;
                            scopy(i, min, j);
                        }
                    }
                }
            }
            break;

        // sort by author name
        case 3:
            for(i=0; i<GENRE; i++){
                for(j=0; j<books_occupied[i]-1; j++){
                    min = j;
                    for(k=j+1;k<books_occupied[i];k++){
                        if(strcmp(catalog[i][k].author_name, catalog[i][min].author_name)<0){
                            min = k;
                            scopy(i, min, j);
                        }
                    }
                }
            }
            break;

        // sort by price
        case 4:
            for(i=0; i<GENRE; i++){
                for(j=0; j<books_occupied[i]-1; j++){
                    min = j;
                    for(k=j+1;k<books_occupied[i];k++){
                        if(catalog[i][k].price < catalog[i][min].price){
                            min = k;
                            scopy(i, min, j);
                        }
                    }
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
            printf("Enter a choice between 1 & 5 only.\n\n");
    }
}
