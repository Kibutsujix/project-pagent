#ifndef STRUCT_DATABASE_H
#define STRUCT_DATABASE_H
#define GENRE 5
#define BOOKS_PER_GENRE 4

struct issue {
    int day;
    int month;
    int year;
    int status;
};

// struct database containing attributes of a book
typedef struct {
	int price;
	int genre;
    struct issue ISSUE;
	char id[6];
	char book_name[50];
	char author_name[50];
} BOOK;

typedef struct {
    int i;
    int j;
} INDEX;

extern const char* genre_list[];

/* using a double dimension struct array (array of structures, but 2D) where
each row represents a shelf containing books pertaining to a specific genre */

extern BOOK catalog[GENRE][BOOKS_PER_GENRE];

extern int books_occupied[5];

extern int ADMIN;

#endif
