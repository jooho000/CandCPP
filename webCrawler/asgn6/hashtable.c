#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "hashtable.h"

hashtable_t *hashtable_new(const int num_slots) {

    hashtable_t *temp = malloc(sizeof(hashtable_t));
    temp->myArray = malloc(sizeof(set_t*)*num_slots);
    if (temp == NULL) {
        return NULL;
    }
    for (int i = 0; i < num_slots; i++) {
        temp->myArray[i]= set_new();
    }
    temp->size = num_slots;
    temp->currSize = 0;

    return temp;
}

static int getHash(const char *key, int size) {

    int sum = 0, length = strlen(key);
    for (int i = 0; i < length; i++) {
        sum += key[i];
    }
    
    return sum % size;
}

bool hashtable_insert(hashtable_t *ht, const char *key, void *item) {
    if (ht == NULL || key == NULL) {
        return false;
    }
    ht->currSize++;
    return set_insert(ht->myArray[getHash(key,ht->size)],key,item);
}


void hashtable_delete(hashtable_t *ht) {
    if (ht == NULL) {
        return;
    }
    for (int i = 0; i < ht->size; i++) {
        set_delete(ht->myArray[i]);
    }
    free(ht->myArray);
    free(ht);
}

