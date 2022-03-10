#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "database.h"
#include "utilities.h"

void printbooks(int i, int j){

	printf("\nID: %s\nName: %s\nAuthor: %s\nGenre: %s\nPrice: %d\n\n", catalog[i][j].id, catalog[i][j].book_name, \
			catalog[i][j].author_name, genre_list[i], catalog[i][j].price);
}

void pprint(){

    int i, j;
    printf("\n\t+---------------------------------------------------------------------------------------+\n");
    printf("\tID\t NAME\t\t\t AUTHOR\t\t\t PRICE\t\t GENRE\n");
    printf("\t+---------------------------------------------------------------------------------------+\n");
    for(i=0; i<GENRE; i++){
        for(j=0; j<books_occupied[i]; j++){
            if(ADMIN == 1 || catalog[i][j].ISSUE.status != 1){

                if(strlen(catalog[i][j].book_name)>10)
                    printf("\t| %s\t | %.15s...\t | %.15s...\t | %d\t\t | %s\n", catalog[i][j].id, catalog[i][j].book_name, catalog[i][j].author_name, catalog[i][j].price, genre_list[i]);
                else
                    printf("\t| %s\t | %s\t\t | %s\t | %d\t\t | %s\n", catalog[i][j].id, catalog[i][j].book_name, catalog[i][j].author_name, catalog[i][j].price, genre_list[i]);
            }
        }
    }
}

void s_swap(int i, int j, int k){

    BOOK temp;

    temp = catalog[i][j];
    catalog[i][j] = catalog[i][k];
    catalog[i][k] = temp;

}

char* to_lower(char* str){

    int i=0;
	char* temp = (char*)malloc(sizeof(char)*50);

	while(str[i]!='\0')
	{
		if(str[i]>='A' && str[i]<='Z')
			temp[i]=str[i]+32;
		else
			temp[i]=str[i];
	   ++i;
	}

	temp[i]='\0';
	return temp;
}

int hashcmp(const char* h1, const char* h2){

    int i=0;

    if(strlen(h1)!=strlen(h2))
        return -1;
    else{
        while(h1[i] != '\0'){

            if(h1[i]!=h2[i])
                return -1;
            else
                i++;
        }
    }

    return 0;
}
