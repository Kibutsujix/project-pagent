#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "database.h"
#include "functions.h"
#include "utilities.h"

int main(){

    int choice;

    // stack smashing error is raised if a password greater than 20 characters is entered
    // although the error doesn't show up, the program abruptly exits
    char passwd[20];
    const char* pass_admin = "admindbpassword";
    const char* pass_user = "userdbpassword";

    for(;;){
        printf("\nLogin:\n\n1. ADMIN\n2. USER\n3. EXIT\n\n");
        printf("Enter a choice/Enter 3 to exit: ");
        scanf("%d", &choice);
        getchar();

        if(choice == 1 || choice == 2){

            // couldn't find any alternative for getpass() in windows
            // therefore password is visible in plain text
            printf("Enter password: ");
            scanf("%[^\n]s", passwd);
            getchar();

            if(choice == 1 && hashcmp(passwd, pass_admin)==0){

                ADMIN = 1;

                for(;;){

                    printf("\nBook Operations:\n\n1. Add\n2. Delete\n3. Modify\n4. Search\n5. Sort\n6. List\n\n");
                    printf("Enter a choice/Enter 7 to logout: ");
                    scanf("%d", &choice);
                    getchar();

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
                                goto logout;

                            default:
                                printf("Enter a choice between 1-7 only.\n");
                        }
                    }
                }
            }
            else if(choice == 2 && hashcmp(passwd, pass_user)==0){

                ADMIN = 0;

                for(;;){

                    printf("\nBook Operations:\n\n1. Search\n2. Sort\n3. List\n4. Issue\n\n");
                    printf("Enter a choice/Enter 5 to logout: ");
                    scanf("%d", &choice);
                    getchar();

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
                            printf("Enter ADMIN password to issue book: ");
                            scanf("%[^\n]s", passwd);
                            getchar();

                            if(hashcmp(passwd, pass_admin)==0)
                                book_ops(choice);
                            else
                                printf("Wrong password.\n");
                            break;

                        case 5:
                            goto logout;

                        default:
                            printf("Enter a choice between 1-4 only.\n");
                    }
                }
            }
            else
                printf("Invalid Credentials.\n");
        }
        else if(choice == 3)
            return 0;

        else
            printf("Invalid Login.\n");

        logout:
            printf(" ");
    }
}
