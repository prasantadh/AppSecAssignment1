#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <errno.h>
#include <ctype.h>
#include "dictionary.h"

void err_and_exit(const char* err_msg) {
    fprintf(stderr, "error: %s\n", err_msg);
    exit(EXIT_FAILURE);
}

int check_words(FILE* fp, hashmap_t hashtable[], char* misspelled[]) {
    return 1;
}

bool check_word(const char* word, hashmap_t hashtable[]) {
    return false;
}

hashmap_t* alloc_hashtable() {
    hashmap_t* hashtable = (hashmap_t*) malloc(sizeof(hashmap_t)*HASH_SIZE);
    if (hashtable == NULL) 
        err_and_exit("couldn't allocate space for dictionary");
    memset((void *)  hashtable, 0, sizeof(hashtable));
    return hashtable;
}

void add_word_to_table(char *word, hashmap_t* hashtable) {
    if (word == NULL || hashtable == NULL)
        err_and_exit("empty param to add_word_to_hashtable");

    node* node_p = (node*) malloc(sizeof(node));
    if (node_p == NULL)
        err_and_exit(strerror(errno));

    int bucket = hash_function(word);
    char ch; int i = 0;
    while ((ch = word[i]) != '\0')
        node_p->word[i++] = ch;
    node_p->next = hashtable[bucket];
    hashtable[bucket] = node_p;
}

/* function defn for prototype in dictionary.h */
bool load_dictionary(const char* dictionary_file, hashmap_t hashtable[]) {
    // avoid this function being called multiple times
    static int firstcall = true;
    if (!firstcall) 
        err_and_exit("multiple dictionaries not supported");
    hashtable = alloc_hashtable();
    
    FILE* file_p = fopen(dictionary_file, "r");
    if (file_p == NULL)
        err_and_exit(strerror(errno));
    
    // read and add word to dictionary
    char ch; int i = 0; char word[LENGTH + 1] = {'\0'};
    while ((ch = fgetc(file_p)) != EOF) {
        word[i++] = tolower(ch);
        if (isspace(ch) || i == LENGTH) {
            add_word_to_table(word, hashtable);
            i = 0;
        }
    }

    // clean up
    if (fclose(file_p))
        err_and_exit(strerror(errno));
    firstcall = false;
    return true;
}

