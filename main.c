#include <check.h>
#include "dictionary.h"
#include <stdlib.h>

#define DICTIONARY "wordlist.txt"
#define TESTDICT "test_worlist.txt"

int
main(void)
{
    hashmap_t hashtable[HASH_SIZE];
    char* misspelled[MAX_MISSPELLED];
    load_dictionary(DICTIONARY, hashtable);
    FILE* file_p = fopen(TESTDICT, "r");
    if (file_p == NULL) {
        fprintf(stderr, "Couldn't open test file");
        exit(EXIT_FAILURE);
    }
    fprintf(stderr, "got here for sure---!\n");
    int n = check_words(file_p, hashtable, misspelled);
    fprintf(stderr, "got here for sure!\n");
    printf("Done executing... %d misspelled\n", n);
}

