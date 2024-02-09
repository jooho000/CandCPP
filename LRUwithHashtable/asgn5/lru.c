#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "lru.h"

lru_t *lru_new(const int capacity) {
    lru_t *temp = (lru_t*)malloc(sizeof(lru_t));
    temp->head = NULL;
    temp->tail = NULL;
    temp->numOfElements = 0;
    temp->maxNum = capacity;
    return temp;
}

static bool isInLRU(lru_t *ht, const char *key) {

    if (key == NULL || ht == NULL) {
        return false;
    }

    Node *curr = ht->tail;
    while (curr != NULL) {
        if (strcmp(curr->key, key) == 0) {
            return true;
        }
        curr = curr->next;
    }return false;
}

static void addWhenFull(lru_t *ht, Node *nodeToAdd) {
    Node *tempNode = ht->tail;
    ht->tail = ht->tail->next;
    ht->tail->previous = NULL;
    free(tempNode);

    ht->head->next = nodeToAdd;
    nodeToAdd->previous = ht->head;
    ht->head = nodeToAdd;
    ht->head->next = NULL;
}
    

bool lru_insert(lru_t *ht, const char *key, void *item) {

    if (isInLRU(ht,key) || ht == NULL || key == NULL || item == NULL) {
        return false;
    }

    Node *newNode = (Node*)malloc(sizeof(Node*));
    newNode->key = strdup(key);
    newNode->item = item;
    newNode->next = NULL;
    newNode->previous = NULL;

    if (ht->numOfElements == 0) {
        newNode->next = NULL;
        newNode->previous = NULL;
        ht->head = newNode;
        ht->tail = newNode;
        ht->numOfElements++;
        return true;
    }

    if (ht->numOfElements >= ht->maxNum) {
        addWhenFull(ht,newNode);
        return true;
    }

    ht->head->next = newNode;
    newNode->previous = ht->head;
    ht->head = newNode;
    ht->numOfElements++;
    ht->head->next = NULL;
    return true;
}

static void modifyHead(lru_t *ht, Node *nodeToModify) {

    Node *tempNode;
    if (nodeToModify == ht->head) {
        return;
    } if (nodeToModify == ht->tail) {
        tempNode = ht->tail;
        ht->tail = ht->tail->next;
        ht->tail->previous = NULL;

        ht->head->next = tempNode;
        tempNode->previous = ht->head;
        ht->head = tempNode;
        ht->head->next = NULL;
        return;
    }
    
    tempNode = nodeToModify->previous;
    tempNode->next = nodeToModify->next;
    tempNode = nodeToModify->next;
    tempNode->previous = nodeToModify->previous;

    ht->head->next = nodeToModify;
    nodeToModify->previous = ht->head;
    ht->head = nodeToModify;
    ht->head->next = NULL;
}

void *lru_find(lru_t *ht, const char *key) {

    if (ht == NULL || key == NULL) {
        return NULL;
    } 
    if (!isInLRU(ht,key)) {
        return NULL;
    }

    Node *curr = ht->tail;
    while (curr != NULL) {
        if (strcmp(key,curr->key) == 0) {
            modifyHead(ht,curr);
            return curr->item;
        }
        curr = curr->next;
    }
    return NULL;
}

void lru_print(lru_t *ht, FILE *fp, void (*itemprint)(FILE *fp, const char *key, void *item)) {

    if (fp == NULL) {
        return;
    } else if (ht == NULL) {
        fprintf(fp,"%p",NULL);
    }

    Node *curr = ht->tail;
    if (itemprint == NULL) {
        while (curr != NULL) {
            fprintf(fp,"%s\n",curr->key);
        }  
    } else {
        while (curr != NULL) {
            itemprint(fp,curr->key,curr->item);
            curr = curr->next;
        }
    }
}

void lru_iterate(lru_t *ht, void *arg, void (*itemfunc)(void *arg, const char *key, void *item) ) {

    if (ht == NULL || itemfunc == NULL) {
        return;
    }

    Node *curr = ht->tail;
    while (curr != NULL) {
        itemfunc(arg,curr->key,curr->item);
        curr = curr->next;
    }
}

void lru_delete(lru_t *ht, void (*itemdelete)(void *item) ) {
    if (ht == NULL) {
        return;
    }
    Node *curr = ht->tail;
    while (curr != NULL) {
        Node *temp;
        if (itemdelete != NULL) {
            itemdelete(curr->item);
        }
        temp = curr;
        curr = curr->next;
        free(temp);
    }
    free(ht);
}

