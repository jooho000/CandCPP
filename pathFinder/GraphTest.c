/***
* Jooho Lee
* jlee897
* 2024 Winter CSE101 PA2
* GraphTest.c
* Test cases for Graph.c
***/ 
#include "Graph.h"
#include <stdlib.h>
#include <stdio.h>

int main() {

    Graph A = newGraph(99);
    List C = newList();
    List L = newList();

    addEdge(A, 64, 4);
    addEdge(A, 64, 3);
    addEdge(A, 42, 2);
    addEdge(A, 2, 64);
    addEdge(A, 4, 2);
    addEdge(A, 3, 42);
    BFS(A, 3);
    getPath(L, A, 64);
    append(C, 3);
    append(C, 64);
    if (!equals(L, C)) {printf("error 1\n");}

    moveFront(L);
    BFS(A, 2);
    getPath(L, A, 2);
    append(C, 2);
    if (!equals(L, C)) {printf("error 2\n");}
    getPath(L, A, 99);
    if (equals(L, C)) {printf("error 3\n");}
    clear(L);
    clear(C);
    append(C, NIL);
    BFS(A, 99);
    getPath(L, A, 2);
    if (!equals(C, L)) {printf("error 4\n");}

    Graph A1 = newGraph(99);
    List C1 = newList();
    List L1 = newList();

    addArc(A1, 64, 4);
    addArc(A1, 64, 3);
    addArc(A1, 42, 2);
    addArc(A1, 2, 64);
    addArc(A1, 4, 2);
    addArc(A1, 3, 42);
    BFS(A1, 3);
    getPath(L1, A1, 64);
    append(C1, 3);
    append(C1, 42);
    append(C1, 2);
    append(C1, 64);
    if (!equals(L1, C1)) {printf("error 5\n");}
    moveFront(L1);
    BFS(A1, 2);
    getPath(L1, A1, 2);
    append(C1, 2);
    if (!equals(L1, C1)) {printf("error 6\n");}
    getPath(L1, A1, 99);
    if (equals(L1, C1)) {printf("error 7\n");}
    clear(L1);
    clear(C1);
    append(C1, NIL);
    BFS(A1, 99);
    getPath(L, A1, 2);
    if (!equals(C1, L1)) {printf("error 8\n");}

    exit(EXIT_SUCCESS);
}