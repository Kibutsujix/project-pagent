#ifndef UTILITIES_H
#define UTILITIES_H

// print a specific book belonging to a genre
void printbooks(int i, int j);

// pretty print function used to print all books in the database
void pprint();

// swap two "struct" elements in the array
void s_swap(int i, int j, int k);

/* converts a given string to lower case by allocating memory
for a new string from heap and returning it's address */

// once used, it must be freed back into the heap
char* to_lower(char* str);

// compares two given hashes
int hashcmp(const char* h1, const char* h2);

#endif
