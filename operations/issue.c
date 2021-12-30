struct issue
{
    int day;
    int time;
    int year;
    int status;
};
typedef struct
{
    int price;
    int genre;
    struct issue ISSUE;
    char id[6];
    char book_name[50];
    char author_name[50];
}BOOK;
BOOK catalog[GENERE][BOOKS_PER_GENERE] = {

    { {1000,0,{ 27,12,2021,0 },"82734","Gone Girl","Gillian Flynn"}, {2332,0,{ 17,10,2021,0 },"32434","The Hound of the Baskervilles","Sir Arthur Conan Doyle"} },

    { {3423,1,{ 22,03,2021,0 },"34212","The Guest List","Lucy Foley"}, {4433,1,{ 03,05,2021,1 },"43253","The Girl on the Train","Paula Hawkins"} },

    { {4221,2,{ 21,11,2021,1 },"24353","The Haunting of Hill House","Shirley Jackson"}, {1212,2,{ 15,12,2021,0 },"43522","The Shining","Stephen King"} },

    { {1234,3,{ 25,01,2022,1 },"53212","The Great Gatsby","F. Scott Fitzgerald"}, {5435,3,{ 12,07,2021,0 },"22853","Nineteen Eighty-Four","Eric Arthur Blair"} },

    { {982,4,{ 23,04,2021,1 },"43255","It Ends with Us","Colleen Hoover"}, {342,4,{ 07,12,2021,1 },"31232","Pride and Prejudice","Jane Austen"} }
};
void issue();
int search(char book[]);
int main()
{
    issue();
}
int search(char book[])
{
    for(int i=0;i<(GENERE);i++)
    {
        for(int j=0;j<(BOOKS_PER_GENERE);j++)
        {
            if(strcmp((catalog[i][j].book_name),book)==0)
            {
                catalog[i][j].ISSUE.status = 1;
                printf("The book being issued is:\n");
                printf("NAME \t\t\t ID \t\t AUTHOR \n");
                printf("%s \t\t\ %s \t\t %s \n",catalog[i][j].book_name,catalog[i][j].id,catalog[i][j].author_name);
                printf("Issued on \t %d . %d . %d \n",catalog[i][j].ISSUE.day,catalog[i][j].ISSUE.time,catalog[i][j].ISSUE.year);
                return 0;
            }
        }
    }
    return 1;
}
void issue()
{
    int flag = 0;
    char issue_book[50];
    printf("Please enter the name of the book you wish to take \n");
    gets(issue_book);
    flag = search(issue_book);
    if(flag)
        printf("Sorry the book is not available \n");
}
}