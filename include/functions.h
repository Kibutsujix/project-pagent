#ifndef FUNCTIONS_H
#define FUNCTIONS_H

// sorts the database based on an user's choice
void sort(int choice);

/* searches the database for a particular book and
returns it's index based on the genre */

int search(char* args, int choice);

// issues a book to an user
void b_issue(int i, int j);

// generic function to perform an operation on a book
void book_ops(int choice);

// modifies a given field in the database
void modify(int i, int j);

void search_books();

void sort_books();

#endif
