#ifndef STRUCT_DATABASE_H
#define STRUCT_DATABASE_H
#define GENRE 5
#define BOOKS_PER_GENRE 4

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

extern genre GENERES;
extern const char* genre_list[5];

extern BOOK catalog[GENRE][BOOKS_PER_GENRE];

int books_occupied[5];

#endif
