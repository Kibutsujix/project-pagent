#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#if !defined _WIN32
    #include <unistd.h>
#endif

#include "modules/database.h"
#include "modules/functions.h"
#include "modules/utilities.h"
#include "modules/sha256.h"

int main(void){
    int choice;
    // 0 is an additional null-byte
    char hash[65] = {0};

    #if !defined _WIN32
        char *original = NULL;
    #endif

    const char* admin_prompt = "Enter ADMIN password to issue book: ";
    // plain text: admindbpassword
    const char* hash_admin = "281ced949d94a42ac81476ab651a22bce940fb920a380af549412a6cba2e9d69";
    // plain text: userdbpassword
    const char* hash_user = "9cc6499fb998ff8faf54bc6a2e3007b90c679ffb844619684beb80d91959ecc8";

    #ifdef _WIN32
        // stack smashing error is raised if a password greater than 20 characters is entered
        // although the error doesn't show up, the program abruptly exits
        char passwd[20];
    #else
        char *passwd = NULL;
    #endif

    for(;;){
        printf("\nLogin:\n\n1. ADMIN\n2. USER\n3. EXIT\n\n");
        printf("Enter a choice/Enter 3 to exit: ");
        scanf("%d", &choice);
        getchar();

        if(choice == 1 || choice == 2){
            #ifdef _WIN32
                printf("Enter password: ");
                echo_off(passwd);
                getchar();
            #else
                // string returned by getpass is duplicated as it uses a static buffer
                passwd = strdup(getpass("Enter password: "));
            #endif

            sha256_easy_hash_hex(passwd, strlen(passwd), hash);
            if(choice == 1 && !strcmp(hash, hash_admin)){
                ADMIN = 1;

                for(;;){
                    printf("\nBook Operations:\n\n1. Add\n2. Delete\n3. Modify\n4. Search\n5. Sort\n6. List\n\n");
                    printf("Enter a choice/Enter 7 to logout: ");
                    scanf("%d", &choice);
                    #ifdef _WIN32
                        getchar();
                    #endif

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
                            #if !defined _WIN32
                                free(passwd);
                            #endif
                            goto logout;

                            default:
                                printf("Enter a choice between 1-7 only.\n");
                        }
                    }
                }
            }
            else if(choice == 2 && !strcmp(hash, hash_user)){
                ADMIN = 0;

                for(;;){
                    printf("\nBook Operations:\n\n1. Search\n2. Sort\n3. List\n4. Issue\n\n");
                    printf("Enter a choice/Enter 5 to logout: ");
                    scanf("%d", &choice);
                    #ifdef _WIN32
                        getchar();
                    #endif

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
                            #ifdef _WIN32
                                puts(admin_prompt);
                                echo_off(passwd);
                                getchar();
                            #else
                                original = passwd;
                                passwd = strdup(getpass(admin_prompt));
                            #endif
                            sha256_easy_hash_hex(passwd, strlen(passwd), hash);
                            if(!strcmp(hash, hash_admin)){
                                book_ops(choice);
                            }
                            else{
                                printf("Wrong password.\n");
                            }
                            #if !defined _WIN32
                                free(passwd);
                                passwd = original;
                            #endif
                            break;

                        case 5:
                            #if !defined _WIN32
                                free(passwd);
                            #endif
                            goto logout;

                        default:
                            printf("Enter a choice between 1-4 only.\n");
                    }
                }
            }
            else{
                printf("Invalid Credentials.\n");
                #if !defined _WIN32
                    free(passwd);
                #endif
            }
        }
        else if(choice == 3)
            return 0;
        else
            printf("Invalid Login.\n");
        logout:;
    }
}
