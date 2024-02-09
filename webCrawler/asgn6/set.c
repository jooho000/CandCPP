#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "set.h"



set_t *set_new(void) {

    set_t *tempSet = (set_t*)malloc(sizeof(set_t));
    tempSet->count = 0;
    tempSet->head = NULL;
    tempSet->firstElement = NULL;
    return tempSet;
}

static bool check_repetition(set_t *set, const char *key) {

    Node *curr = set->head;

    while (curr != NULL) {
        if (strcmp(key,curr->key) == 0) {
            return true;
        }
        curr = curr->next;
    }
 
    return false;
}

bool set_insert(set_t *set, const char *key, void *item) {
    
    if (check_repetition(set,key) || key == NULL || set == NULL) {
        return false;
    }

    Node *newNode = malloc(sizeof(Node*));
    if (newNode == NULL) {
        return false;
    }

    newNode->key = strdup(key);
    newNode->item = item;
    newNode->next = NULL;
    if (set->count == 0) {
        set->firstElement = newNode;
        set->head = newNode;
    } else {
        set->firstElement->next = newNode;
        set->firstElement = newNode;
    }
    set->count++;
    return true;
}


void set_delete(set_t *set) {

    if (set == NULL) {
        return;
    }

    Node *curr = set->head;

    while (curr != NULL) {
        Node *tempNode = curr;
        curr = curr->next;
        free(tempNode->key);
        free(tempNode);
    }

    free(set);
}

Node *fetchNode(set_t *set) {
    if (set == NULL) {
        printf("ERROR: bag is null in fetch");
        exit(EXIT_FAILURE);
    }
    Node *tempNode;
    tempNode = set->head;
    if (set->head == NULL) {
        printf("ERROR: set head == null");
        exit(EXIT_FAILURE);
    }
    set->head = set->head->next;
    set->count--;
    if (set->count == 0) {
        set->firstElement = NULL;
        set->head = NULL;
    }
    return tempNode;
}

