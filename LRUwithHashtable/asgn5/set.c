#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "set.h"


set_t *set_new(void) {

    set_t *tempSet = (set_t*)malloc(sizeof(set_t));
    tempSet->head = NULL;
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
    
    if (check_repetition(set,key) || key == NULL || item == NULL || set == NULL) {
        return false;
    }

    Node *newNode = (Node*)malloc(sizeof(Node*));
    if (newNode == NULL) {
        return false;
    }

    newNode->key = strdup(key);
    newNode->item = item;
    newNode->next = set->head;
    set->head = newNode;


    return true;
}

void *set_find(set_t *set, const char *key) {

    if (set == NULL || key == NULL || !check_repetition(set,key)) {
        return NULL;
    }

    Node *curr = set->head;
    while (curr != NULL) {
        if (strcmp(curr->key, key) == 0) {
            return curr->item;
        }
        curr = curr->next;
    }

    return NULL;
}

void set_print(set_t *set, FILE *fp, void (*itemprint)(FILE *fp, const char *key, void *item) ) {

    if (fp == NULL) {
        return;
    } else if (set == NULL) {
        fprintf(fp,"%p",NULL);
    }

    Node *curr = set->head;
    if (itemprint == NULL) {
        while (curr != NULL) {
            fprintf(fp,"%s\n",curr->key);
        }  
    } else {
        while (curr != NULL) {
            if (curr->key != NULL) {
                itemprint(fp, curr->key, curr->item);
                curr = curr->next;
            }
        }
    }
}

void set_iterate(set_t *set, void *arg, void (*itemfunc)(void *arg, const char *key, void *item) ) {

    if (itemfunc == NULL || set == NULL) {
        return;
    }

    Node *curr = set->head;
    while (curr != NULL) {
        itemfunc(arg, curr->key, curr->item);
        curr = curr->next;
    }
}

void set_delete(set_t *set, void (*itemdelete)(void *item) ) {

    if (set == NULL) {
        return;
    }

    Node *curr = set->head;

    while (curr != NULL) {
        Node *tempNode = curr;
        curr = curr->next;
        if (itemdelete != NULL) {
            itemdelete(tempNode->item);
        }
        free(tempNode);
    }

    free(set);
}

