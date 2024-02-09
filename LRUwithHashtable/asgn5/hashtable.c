#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "hashtable.h"

hashtable_t *hashtable_new(const int num_slots) {

    hashtable_t *temp = (hashtable_t*)malloc(sizeof(hashtable_t));
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
    if (ht == NULL || key == NULL || item == NULL) {
        return false;
    }
    if (ht->currSize < ht->size) {
        ht->currSize++;
        return set_insert(ht->myArray[getHash(key,ht->size)],key,item);
    }
    return false;
}

void *hashtable_find(hashtable_t *ht, const char *key) {
    if (ht == NULL || key == NULL) {
        return NULL;
    }
    return set_find(ht->myArray[getHash(key,ht->size)],key);
}

void hashtable_print(hashtable_t *ht, FILE *fp, void (*itemprint)(FILE *fp, const char *key, void *item)) {
    if (fp == NULL) {
        return;
    } 
    for (int i = 0; i < ht->size; i++) {
        set_print(ht->myArray[i], fp, itemprint);
    }
}

void hashtable_iterate(hashtable_t *ht, void *arg, void (*itemfunc)(void *arg, const char *key, void *item) ) {
    if (ht == NULL || itemfunc == NULL) {
        return;
    }
    for (int i = 0; i < ht->size; i++) {
        set_iterate(ht->myArray[i], arg, itemfunc);
    }
}

void hashtable_delete(hashtable_t *ht, void (*itemdelete)(void *item) ) {
    if (ht == NULL) {
        return;
    }
    for (int i = 0; i < ht->size; i++) {
        set_delete(ht->myArray[i],itemdelete);
    }
    free(ht);
}

