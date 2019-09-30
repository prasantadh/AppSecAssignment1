#include <check.h>
#include "dictionary.h"
#include <stdlib.h>
#include <string.h>

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
    int n = check_words(file_p, hashtable, misspelled);
    free(misspelled[0]);
    for (int i = 0; i < MAX_MISSPELLED; ++i) {
        misspelled[i] = NULL;
    }
    for(int i = 0; i < HASH_SIZE; ++i) {
        // printf("%d\n", i);
        if (hashtable[i] == 0) continue;
        node* head = hashtable[i];
        node* temp = NULL;
        while (head != NULL) {
            temp = head->next;
            free(head);
            head = temp;
        } 
        head = NULL; temp = NULL;
    }
    fclose(file_p);
    printf("Done executing... %d misspelled\n", n);
}

