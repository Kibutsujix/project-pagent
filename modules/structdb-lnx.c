#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#include "database.h"
#include "functions.h"
#include "utilities.h"

int main(){

    int choice;
    char *passwd, *inputpass;
    const char* hash_admin = "$5$$4I52KnO8UmJKSvLeadDezMFnanE4RT2jETM3BL8JdZ9";
    const char* hash_user = "$5$$yg9yLWG0Gf0O6UgG8YwIrxiaqLUeq0Lpm.W1Lm56uMC";

    for(;;){

        printf("\nLogin:\n\n1. ADMIN\n2. USER\n3. EXIT\n\n");
        printf("Enter a choice/Enter 3 to exit: ");
        scanf("%d", &choice);
        getchar();

        if(choice == 1 || choice == 2){

            passwd=strdup(getpass("Enter password: "));

            if(choice == 1 && hashcmp(inputpass=strdup(crypt(passwd, "$5$")), hash_admin)==0){

                ADMIN = 1;

                for(;;){

                    printf("\nBook Operations:\n\n1. Add\n2. Delete\n3. Modify\n4. Search\n5. Sort\n6. List\n\n");
                    printf("Enter a choice/Enter 7 to logout: ");
                    scanf("%d", &choice);

                    if(choice==2 || choice==3)
                        book_ops(choice);
                    else{
                        switch(choice){

                            case 1:
                                add();
                                break;

                            case 4:
                                search_books();
                                break;

                            case 5:
                                sort_books();
                                break;

                            case 6:
                                pprint();
                                break;

                            case 7:
                                free(inputpass);
                                free(passwd);
                                goto logout;

                            default:
                                printf("Enter a choice between 1-7 only.\n");
                        }
                    }
                }
            }
            else if(choice == 2 && hashcmp(inputpass=strdup(crypt(passwd, "$5$")), hash_user)==0){

                ADMIN = 0;

                for(;;){

                    printf("\nBook Operations:\n\n1. Search\n2. Sort\n3. List\n4. Issue\n\n");
                    printf("Enter a choice/Enter 5 to logout: ");
                    scanf("%d", &choice);

                    switch(choice){

                        case 1:
                            search_books();
                            break;

                        case 2:
                            sort_books();
                            break;

                        case 3:
                            pprint();
                            break;

                        case 4:
                            free(inputpass);
                            if(hashcmp(inputpass=strdup(crypt(getpass("Enter ADMIN password to issue book: "), "$5$")), hash_admin)==0)
                                book_ops(choice);
                            else
                                printf("Wrong password.\n");
                            break;

                        case 5:
                            free(inputpass);
                            free(passwd);
                            goto logout;

                        default:
                            printf("Enter a choice between 1-4 only.\n");
                    }
                }
            }
            else{

                printf("Invalid Credentials.\n");
                free(inputpass);
            }
        }
        else if(choice == 3)
            return 0;

        else
            printf("Invalid Login.\n");

        logout:
            printf(" ");
    }
}
