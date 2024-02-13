/***
* Jooho Lee
* jlee897
* 2024 Winter CSE101 PA3
* FindComponents.c
* Gets directed Graph from input and runs DFS and outputs edges and strongly connected components
***/ 
#include "Graph.h"
#include <stdlib.h>
#include <stdio.h>

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
        printf("ERROR: wrong number of arguements for FindComponents.c\n");
        exit(EXIT_FAILURE);
    }

    //opens files for reading and writing
    char* inFileString = argv[1];
    char* outFileString = argv[2];
    FILE *inFile = fopen(inFileString, "r");
    FILE *outFile = fopen(outFileString, "w");
    if (inFile == NULL) {
        printf("ERROR: inFile does not exit //FindComponents.c\n");
        exit(EXIT_FAILURE);
    }
    if (outFile == NULL) {
        printf("ERROR: outFile does not exit //FindComponents.c\n");
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
        addArc(clientGraph,vertex1,vertex2);
        vertex1 = front(clientNumbers);
        deleteFront(clientNumbers);
        vertex2 = front(clientNumbers);
        deleteFront(clientNumbers);
    }
    fprintf(outFile,"Adjacency list representation of G:\n");
    printGraph(outFile, clientGraph);

    //runs DFS and calculates Transpose to find s and output SCC
    Graph clientTranspose = transpose(clientGraph);
    List clientList = newList();
    int countDFS;
    for (countDFS = 1; countDFS <= getOrder(clientGraph); countDFS++) {
        append(clientList,countDFS);
    }
    DFS(clientGraph,clientList);
    DFS(clientTranspose,clientList);

    int comCount = 0;
    moveFront(clientList);
    while (index(clientList) != -1) {
        if (getParent(clientTranspose,get(clientList)) == NIL){
            comCount++;
        }
        moveNext(clientList);
    }
    
    fprintf(outFile,"\n");
    moveBack(clientList);
    fprintf(outFile,"G contains %d strongly connected components:\n", comCount);
    List tempList = newList();
    int printCount;
    for (printCount = 1; printCount <= comCount; printCount++) {
        fprintf(outFile,"Component %d:", printCount);
        while (getParent(clientTranspose,get(clientList)) != NIL) {
            prepend(tempList, get(clientList));
            movePrev(clientList);
        }
        prepend(tempList, get(clientList));
        movePrev(clientList);
        moveFront(tempList);
        while(index(tempList) != -1) {
            fprintf(outFile," %d", get(tempList));
            moveNext(tempList);
        }
        fprintf(outFile,"\n");
        clear(tempList);
    }

    freeGraph(&clientGraph);
    freeGraph(&clientTranspose);
    freeList(&clientList);
    freeList(&clientNumbers);
    freeList(&tempList);
    fclose(outFile);
    fclose(inFile);

    return EXIT_SUCCESS;
}