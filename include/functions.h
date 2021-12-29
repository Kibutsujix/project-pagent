#ifndef FUNCTIONS_H
#define FUNCTIONS_H

// sorts the database based on an user's choice
void sort(int choice);

/* searches the database for a particular book and
returns it's index based on the genre */

int search(char* args, int choice);

void search_books();

void sort_books();

void del_books(int m,int n);
#endif
