#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "dictionary.h"

void err_and_exit(const char* err_msg) {
    fprintf(stderr, "err_msg");
    exit(EXIT_FAILURE);
}

int check_words(FILE* fp, hashmap_t hashtable[], char* misspelled[]) {
    return 0;
}

bool load_dictionary(const char* dictionary_file, hashmap_t hashtable[]) {
    return false;
}

bool check_word(const char* word, hashmap_t hashtable[]) {
    return false;
}
