/***
* Jooho Lee
* jlee897
* 2024 Winter CSE101 PA2
* List.c
* List ADT
***/ 
#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include "List.h"

typedef struct NodeObj {
    int data;
    struct NodeObj* next;
    struct NodeObj* previous;
} NodeObj;

typedef NodeObj* Node;

Node newNode(int data) {
    Node tempNode = malloc(sizeof(NodeObj));
    if (tempNode == NULL) {
        printf("Error: malloc() returned null in newNode() at List.c\n");
        exit(EXIT_FAILURE);
    }
    tempNode->data = data;
    tempNode->next = NULL;
    tempNode->previous = NULL;
    return tempNode;
}

static void freeNode(Node* pN) {
	if( pN!=NULL && *pN!=NULL ){
      free(*pN);
      *pN = NULL;
   }
}

typedef struct ListObj {
    int length;
    int currentIndex;
    Node front;
    Node back;
    Node cursor;
} ListObj;

List newList(void) {
    List tempList = malloc(sizeof(ListObj));
    if (tempList == NULL) {
        printf("Error: malloc() returned null in newList() in List.c\n");
        exit(EXIT_FAILURE);
    }
    tempList->back = NULL;
    tempList->cursor = NULL;
    tempList->front = NULL;
    tempList->length = 0;
    tempList->currentIndex= -1;
    return tempList;
}

void freeList(List* pL) {
    if (pL == NULL && *pL == NULL) {
        printf("Error: freeList() parameter is null in List.c\n");
        exit(EXIT_FAILURE);
    }
    clear(*pL);
    free(*pL);
    *pL = NULL;
}

int length(List L) {
    if (L == NULL) {
        printf("Error: L parameter in length() is null at List.c\n");
        exit(EXIT_FAILURE);
    }
    return L->length;
}

int index(List L) {
    if (L == NULL) {
        printf("Error; L parameter in index() is null in List.c\n");
        exit(EXIT_FAILURE);
    }
    if (L->cursor == NULL) {
        return -1;
    }
    return L->currentIndex;
}

int front(List L) {
    if (L == NULL) {
        printf("Error; L parameter in front() is null in List.c\n");
        exit(EXIT_FAILURE);
    }
    if (L->length < 0) {
        printf("Error: negative length for L in front() in List.c");
        exit(EXIT_FAILURE);
    }
    return L->front->data;
}

int back(List L) {
    if (L == NULL) {
        printf("Error; L parameter in back() is null in List.c\n");
        exit(EXIT_FAILURE);
    }
    if (L->length < 0) {
        printf("Error: negative length for L in back() in List.c");
        exit(EXIT_FAILURE);
    }
    return L->back->data;
}

int get(List L) {
    if (L == NULL) {
        printf("Error; L parameter in get() is null in List.c\n");
        exit(EXIT_FAILURE);
    }
    if (L->currentIndex < 0 || L->length < 0) {
        printf("Error: negative length or index for L in get() in List.c\n");
        exit(EXIT_FAILURE);
    }
    return L->cursor->data;
}

bool equals(List A, List B) {
    if (A == NULL || B == NULL) {
        printf("ERROR: Parameter A or B in equals() is null in List.c\n");
        exit(EXIT_FAILURE);
    }
    int countForEquals;
    bool equalState = (A->length == B->length);
    Node currNode = A->front;
    Node nodeToCompare = B->front;

    for (countForEquals = 0; equalState && (countForEquals < A->length); countForEquals++) {
        equalState = (currNode->data == nodeToCompare->data);
        currNode = currNode->next;
        nodeToCompare = nodeToCompare->next;
    }
    return equalState;
}

void clear(List L) {
    if (L == NULL) {
        printf("Error: clear() parameter is null in List.c\n");
        exit(EXIT_FAILURE);
    }
    if (L->length == 0) {
        return;
    }
    int clearCount;
    Node tempNode;
    for (clearCount = 0; clearCount < L->length; clearCount++) {
        tempNode = L->front;
        L->front = L->front->next;
        freeNode(&tempNode);
    }
    L->currentIndex = -1;
    L->front = NULL;
    L->back = NULL;
    L->cursor = NULL;
    L->length = 0;
    tempNode = NULL;
}

void set(List L, int x) {
    if (L == NULL) {
        printf("Error: paramenter in set() is null in List.c\n");
        exit(EXIT_FAILURE);
    }
    if (L->length < 0 || L->currentIndex < 0) {
        printf("Error: length or index in L at set() is less than 0 in List.c\n");
        exit(EXIT_FAILURE);
    }
    L->cursor->data = x;
}

void moveFront(List L) {
    if (L == NULL) {
        printf("Error: L in moveFront() is null in List.c\n");
        exit(EXIT_FAILURE);
    }
    if (L->length < 1) {
        printf("Error: given List has no elements in moveFront in List.c\n");
        exit(EXIT_FAILURE);
    }
    L->cursor = L->front;
    L->currentIndex = 0;
}

void moveBack(List L) {
    if (L == NULL) {
        printf("Error: L in moveBack() is null in List.c\n");
        exit(EXIT_FAILURE);
    }
    if (L->length < 1) {
        printf("Error: given List has no elements in moveBack() in List.c\n");
        exit(EXIT_FAILURE);
    }
    L->cursor = L->back;
    L->currentIndex = L->length - 1;
}

void movePrev(List L) {
    if (L == NULL) {
        printf("Error: L in moveBack() is null in List.c\n");
        exit(EXIT_FAILURE);
    }
    if (L->length < 1) {
        printf("Error: given List has no elements in moveBack() in List.c\n");
        exit(EXIT_FAILURE);
    }
    if (L->cursor == NULL) {
        return;
    }
    if (L->cursor == L->front) {
        L->cursor = NULL;
        L->currentIndex = -1;
        return;
    }
    L->cursor = L->cursor->previous;
    L->currentIndex--;
}

void moveNext(List L) {
    if (L == NULL) {
        printf("Error: L in moveNext() is null in List.c\n");
        exit(EXIT_FAILURE);
    }
    if (L->length < 1) {
        printf("Error: given List has no elements in moveNext() in List.c\n");
        exit(EXIT_FAILURE);
    }
    if (L->cursor == NULL) {
        return;
    }
    if (L->cursor == L->back) {
        L->cursor = NULL;
        L->currentIndex = -1;
        return;
    }
    L->cursor = L->cursor->next;
    L->currentIndex++;
}

void prepend(List L, int x) {
    if (L == NULL) {
        printf("Error: L in prepend() is null in List.c\n");
        exit(EXIT_FAILURE);
    }
    Node tempNode = newNode(x);
    if (L->length == 0) {
        L->back = tempNode;
        L->front = tempNode;
        L->length++;
        return;
    }
    if (L->currentIndex >= 0 && L->cursor != NULL) {
        L->currentIndex++;
    }
    tempNode->next = L->front;
    L->front->previous = tempNode;
    L->front = tempNode;
    L->length++;
}

void append(List L, int x) {
    if (L == NULL) {
        printf("Error: L in append() is null in List.c\n");
        exit(EXIT_FAILURE);
    }
    Node tempNode = newNode(x);
    if (L->length == 0) {
        L->back = tempNode;
        L->front = tempNode;
        L->length++;
        return;
    }
    tempNode->previous = L->back;
    L->back->next = tempNode;
    L->back = tempNode;
    L->length++;
}

void insertBefore(List L, int x) {
    if (L == NULL) {
        printf("Error: L in insertBefore() is null in List.c\n");
        exit(EXIT_FAILURE);
    }
    if (L->length < 1 || index < 0) {
        printf("Error: length or index in L is negative in List.c\n");
        exit(EXIT_FAILURE);
    }
    if (L->cursor == NULL) {
        printf("Error: cursor is null in insertBefore() in List.c\n");
        exit(EXIT_FAILURE);
    }
    Node nodeToAdd = newNode(x);
    Node tempNode;
    if (L->cursor == L->front) {
        L->front->previous = nodeToAdd;
        nodeToAdd->next = L->front;
        L->front = nodeToAdd;
        L->length++;
        L->currentIndex++;
        return;
    }
    if (L->cursor == L->back) {
        tempNode = L->back->previous;
        tempNode->next = nodeToAdd;
        nodeToAdd->previous = tempNode;
        nodeToAdd->next = L->back;
        L->back->previous = nodeToAdd;
        L->length++;
        L->currentIndex++;
        return;
    }
    tempNode = L->cursor->previous;
    tempNode->next = nodeToAdd;
    nodeToAdd->previous = tempNode;
    nodeToAdd->next = L->cursor;
    L->cursor->previous = nodeToAdd;
    L->currentIndex++;
    L->length++;
}

void insertAfter(List L, int x) {
    if (L == NULL) {
        printf("Error: L in insertAfter() is null in List.c\n");
        exit(EXIT_FAILURE);
    }
    if (L->length < 1 || index < 0) {
        printf("Error: length or index in L is out of bounds  in insertAfter() in List.c\n");
        exit(EXIT_FAILURE);
    }
    if (L->cursor == NULL) {
        printf("Error: cursor is null in insertAfter() in List.c\n");
        exit(EXIT_FAILURE);
    }
    Node nodeToAdd = newNode(x);
    Node tempNode;
    if (L->back == L->cursor) {
        L->cursor->next = nodeToAdd;
        nodeToAdd->previous = L->back;
        L->back = nodeToAdd;
        L->length++;
        return;
    }
    tempNode = L->cursor->next;
    L->cursor->next = nodeToAdd;
    nodeToAdd->previous = L->cursor;
    nodeToAdd->next = tempNode;
    tempNode->previous = nodeToAdd;
    L->length++;
}

void deleteFront(List L) {
    if (L == NULL) {
        printf("Error: L deleteFront() is null in List.c\n");
        exit(EXIT_FAILURE);
    }
    if (L->length < 1) {
        printf("Error: length is out of bounds in deleteFront() in List.c\n");
        exit(EXIT_FAILURE);
    }
    if (L->length == 1) {
        clear(L);
        return;
    }
    Node tempNode = L->front;
    if (L->cursor == L->front) {
        L->front = L->front->next;
        L->front->previous = NULL;
        freeNode(&tempNode);
        tempNode = NULL;
        L->cursor = NULL;
        L->currentIndex = -1;
        L->length--;
        return;
    }
    L->front = L->front->next;
    L->currentIndex--;
    freeNode(&tempNode);
    tempNode = NULL;
    L->length--;
}

void deleteBack(List L) {
    if (L == NULL) {
        printf("Error: L deleteBack() is null in List.c\n");
        exit(EXIT_FAILURE);
    }
    if (L->length < 1) {
        printf("Error: length is out of bounds in deleteBack() in List.c\n");
        exit(EXIT_FAILURE);
    }
    if (L->length == 1) {
        clear(L);
        return;
    }
    Node tempNode = L->back;
    if (L->cursor == L->back) {
        L->back = L->back->previous;
        L->back->next = NULL;
        freeNode(&tempNode);
        tempNode = NULL;
        L->currentIndex = -1;
        L->length--;
        L->cursor = NULL;
        return;
    }
    L->back = L->back->previous;
    freeNode(&tempNode);
    tempNode = NULL;
    L->back->next = NULL;
    L->length--;
}

void delete(List L) {
    if (L == NULL) {
        printf("Error: L delete() is null in List.c\n");
        exit(EXIT_FAILURE);
    }
    if (L->length < 1 || L->currentIndex < 0) {
        printf("Error: length or index is out of bounds in delete() in List.c\n");
        exit(EXIT_FAILURE);
    }
    if (L->cursor == NULL) {
        printf("Error: cursor is null in delete() in List.c\n");
        exit(EXIT_FAILURE);
    }
    Node tempNode;
    if (L->length==1) {
	    clear(L);
        return;
	}
    if (L->cursor == L->front) {
        deleteFront(L);
        return;
    }
    if (L->cursor == L->back) {
        deleteBack(L);
        return;
    }
    tempNode = L->cursor;
    L->cursor->previous->next = L->cursor->next;
    L->cursor->next->previous = L->cursor->previous;
    freeNode(&tempNode);
    L->currentIndex = -1;
    L->cursor = NULL;
    L->length--;
}

void printList(FILE* out, List L) {
    if (out == NULL || L == NULL) {
        printf("Error: out file or L in printList() is null in List.c");
        exit(EXIT_FAILURE);
    }
    Node tempNode = L->front;
    while (tempNode != NULL) {
        fprintf(out, "%d  ", tempNode->data);
        tempNode = tempNode->next;
    }
}

List copyList(List L) {
    if (L == NULL) {
        printf("Error: L in copyList() is null in List.c");
        exit(EXIT_FAILURE);
    }
    List tempList = newList();
    Node tempNode = L->front;
    while (tempNode != NULL) {
        append(tempList,tempNode->data);
        tempNode = tempNode->next;
    }
    return tempList;
}

List concatList(List A, List B) {
    if (A == NULL || B == NULL) {
        printf("Error: one of the parameters in concatList() is null in List.c");
        exit(EXIT_FAILURE);
    }
    Node tempNode = A->front;
    List tempList = newList();
    while (tempNode != NULL) {
        append(tempList, tempNode->data);
        tempNode = tempNode->next;
    }
    tempNode = B->front;
    while (tempNode != NULL) {
        append(tempList, tempNode->data);
        tempNode = tempNode->next;
    }
    return tempList;
}