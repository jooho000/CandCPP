/***
* Jooho Lee
* jlee897
* 2024 Winter CSE101 PA2
* FindPath.c
* main file for Graph.c 
***/ 
#include "Graph.h"
#include <stdio.h>
#include <stdlib.h>

static void getNumbers(FILE* fp, List L) {
    int tempInt = 0;
    while (!feof(fp)) {
        fscanf(fp, "%d", &tempInt);
        append(L,tempInt);
    }
}

int main(int argc, char** argv) {

    //checks number of arguements
    if (argc != 3) {
        printf("ERROR: wrong number of arguements for FindPath.c\n");
        exit(EXIT_FAILURE);
    }

    //opens files for reading and writing
    char* inFileString = argv[1];
    char* outFileString = argv[2];
    FILE *inFile = fopen(inFileString, "r");
    FILE *outFile = fopen(outFileString, "w");
    if (inFile == NULL) {
        printf("ERROR: inFile does not exit //FindPath.c\n");
        exit(EXIT_FAILURE);
    }
    if (outFile == NULL) {
        printf("ERROR: outFile does not exit //FindPath.c\n");
        exit(EXIT_FAILURE);
    }

    //Makes List of the numbers for program to work with
    List clientNumbers = newList();
    getNumbers(inFile, clientNumbers);
    deleteBack(clientNumbers);

    //sets graphcand prints graph to outFile
    Graph clientGraph = newGraph(front(clientNumbers));
    deleteFront(clientNumbers);
    int vertex1 = front(clientNumbers);
    deleteFront(clientNumbers);
    int vertex2 = front(clientNumbers);
    deleteFront(clientNumbers);
    while (vertex1 != 0 || vertex2 != 0) {
        addEdge(clientGraph,vertex1,vertex2);
        vertex1 = front(clientNumbers);
        deleteFront(clientNumbers);
        vertex2 = front(clientNumbers);
        deleteFront(clientNumbers);
    }
    printGraph(outFile, clientGraph);

    //finds distances from given input to destination and prints shortest paths to outFile.txt
    vertex1 = front(clientNumbers);
    deleteFront(clientNumbers);
    vertex2 = front(clientNumbers);
    deleteFront(clientNumbers);
    fprintf(outFile,"\n");
    while (vertex1 != 0 || vertex2 != 0) {
        List pathList = newList();
        BFS(clientGraph,vertex1);
        getPath(pathList,clientGraph, vertex2);
        if (length(pathList) == 0) {
            append(pathList,NIL);
        }
        if (front(pathList) == NIL) {
            fprintf(outFile,"The distance from %d to %d is infinity\n", vertex1, vertex2);
            fprintf(outFile,"No %d-%d path exists", vertex1, vertex2);
        } else {
            fprintf(outFile,"The distance from %d to %d is %d\n", vertex1, vertex2, length(pathList)-1);
            fprintf(outFile,"A shortest %d-%d path is:", vertex1, vertex2);
            moveFront(pathList);
            while (index(pathList) != -1) {
                fprintf(outFile, " %d", get(pathList));
                moveNext(pathList);
            }
        }
        fprintf(outFile, "\n\n");
        vertex1 = front(clientNumbers);
        deleteFront(clientNumbers);
        vertex2 = front(clientNumbers);
        deleteFront(clientNumbers);
        freeList(&pathList);
    }
    fclose(inFile);
    fclose(outFile);
    freeList(&clientNumbers);
    freeGraph(&clientGraph);
}