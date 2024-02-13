#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include "List.h"

int main(void) {
    List myList = newList();
    append(myList,11);
    append(myList,32);
    append(myList,44);
    append(myList,90);
    append(myList,69);
    moveFront(myList);
    moveNext(myList);
    moveNext(myList);
    moveNext(myList);
    moveFront(myList);
    moveNext(myList);
    printf("element in cursor: %d\n", get(myList));
    moveNext(myList);
    printf("element in cursor: %d\n", get(myList));
    printf("index for cursor: %d\n", index(myList));
    printf("element in front: %d\n", front(myList));
    printf("element in back: %d\n", back(myList));
    printf("length of list: %d\n", length(myList));
    prepend(myList, 200);
    printf("element in cursor: %d\n", get(myList));
    moveBack(myList);
    printf("element in cursor: %d\n", get(myList));
    moveFront(myList);
    moveNext(myList);
    moveNext(myList);
    insertAfter(myList,37);
    insertBefore(myList, 77);

    printf("\n\nprinting elements in List:\n");
    moveFront(myList);

    for (int i = 0; i < length(myList); i++) {
        printf("element in cursor: %d\n", get(myList));
        moveNext(myList);
    }
    printf("\n\n");

    printf("element in front: %d\n", front(myList));
    printf("element in back: %d\n", back(myList));
    printf("length of list: %d\n", length(myList));

    deleteFront(myList);
    deleteBack(myList);

    printf("\n\nprinting elements in List after deletion:\n");
    moveFront(myList);

    for (int i = 0; i < length(myList); i++) {
        printf("element in cursor: %d\n", get(myList));
        moveNext(myList);
    }
    printf("\n\n");

    printf("element in front: %d\n", front(myList));
    printf("element in back: %d\n", back(myList));
    printf("length of list: %d\n", length(myList));

    clear(myList);
    printf("length of list after clear: %d\n", length(myList));



    //test case for making program crash
    //moveFront(myList);
    //movePrev(myList);
    //printf("element in cursor: %d\n", get(myList));

    printf("\nlistTest stuff: \n");
    List listTest = newList();
    append(listTest, 12);
    append(listTest, 13);
    append(listTest, 14);
    deleteFront(listTest);
    moveFront(listTest);
    delete(listTest);
    printf("element in front: %d\n", front(listTest));
    printf("element in back: %d\n", back(listTest));
    printf("length of list: %d\n", length(listTest));
    printf("index: %d\n\n", index(listTest));



    freeList(&myList);
    freeList(&listTest);

    List A = newList();
    List B = newList();
    append(A, 1);
    append(B, 1);
    append(A, 2);
    moveFront(B);
    insertAfter(B, 2);
    if (!equals(A, B)) {
        printf("first qeual does not equal\n");
    }
    append(B, 3);
    moveBack(A);
    insertAfter(A, 3);
    if (!equals(A, B)) {
        printf("second equal does not equal\n");
    }

    printf("printing stuff for A: \n");
    printf("element in front: %d\n", front(A));
    printf("element in back: %d\n", back(A));
    printf("length of list: %d\n", length(A));
    printf("index: %d\n", index(A));

    printf("\nprinting stuff for B: \n");
    printf("element in front: %d\n", front(B));
    printf("element in back: %d\n", back(B));
    printf("length of list: %d\n", length(B));
    printf("index: %d\n", index(B));
    freeList(&A);
    freeList(&B);
    return EXIT_SUCCESS;
}
