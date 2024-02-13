/***
* Jooho Lee
* jlee897
* 2024 Winter CSE101 PA3
* GraphTest.c
* Test cases for Graph.c
***/ 
#include "Graph.h"
#include <stdlib.h>
#include <stdio.h>

int main() {

    FILE *outFile = fopen("outTest.txt", "w");
    Graph firstGraph = newGraph(8);
    Graph trans1;
    Graph copyFirst;

    List firstList = newList();
    int firstCount;
    for (firstCount = 1; firstCount <= 8; firstCount++) {
        append(firstList,firstCount);
    }

    addArc(firstGraph,1,2);
    addArc(firstGraph,2,3);
    addArc(firstGraph,2,5);
    addArc(firstGraph,2,6);
    addArc(firstGraph,3,4);
    addArc(firstGraph,3,7);
    addArc(firstGraph,4,3);
    addArc(firstGraph,4,8);
    addArc(firstGraph,5,1);
    addArc(firstGraph,5,6);
    addArc(firstGraph,6,7);
    addArc(firstGraph,7,6);
    addArc(firstGraph,7,8);
    addArc(firstGraph,8,8);

    DFS(firstGraph, firstList);
    fprintf(outFile,"order: %d\n", getOrder(firstGraph));
    fprintf(outFile,"Size: %d\n", getSize(firstGraph));
    fprintf(outFile,"\nAdjacency:\n");
    printGraph(outFile, firstGraph);
    fprintf(outFile,"\nTranspose:\n");
    trans1 = transpose(firstGraph);
    printGraph(outFile, trans1);
    fprintf(outFile,"\ncopy:\n");
    copyFirst = copyGraph(firstGraph);
    printGraph(outFile,copyFirst);
    fprintf(outFile,"\n");
    for (firstCount = 1; firstCount <= 8; firstCount++) {
        fprintf(outFile,"discover of %d: %d\n", firstCount, getDiscover(firstGraph,firstCount));
        fprintf(outFile,"finish of %d: %d\n", firstCount, getFinish(firstGraph,firstCount));
    }
    fprintf(outFile,"\n");
    for (firstCount = 1; firstCount <= 8; firstCount++) {
        fprintf(outFile,"copy discover of %d: %d\n", firstCount, getDiscover(copyFirst,firstCount));
        fprintf(outFile,"copy finish of %d: %d\n", firstCount, getFinish(copyFirst,firstCount));
    }

    fprintf(outFile,"\nList before G transpose:\n");
    moveFront(firstList);
    while (index(firstList) != -1) {
        fprintf(outFile,"%d, ", get(firstList));
        moveNext(firstList);
    }
    fprintf(outFile,"\nparents before transpose:\n");
    moveFront(firstList);
    while (index(firstList) != -1) {
        fprintf(outFile,"%d, ", getParent(firstGraph,get(firstList)));
        moveNext(firstList);
    }
    fprintf(outFile,"\n");


    DFS(trans1,firstList);
    fprintf(outFile,"\nList after G transpose:\n");
    moveFront(firstList);
    while (index(firstList) != -1) {
        fprintf(outFile,"%d, ", get(firstList));
        moveNext(firstList);
    }
    fprintf(outFile,"\nparents after transpose:\n");
    moveFront(firstList);
    while (index(firstList) != -1) {
        fprintf(outFile,"%d, ", getParent(trans1,get(firstList)));
        moveNext(firstList);
    }
    fprintf(outFile,"\n");

    int comCount = 0;
    moveFront(firstList);
    while (index(firstList) != -1) {
        if (getParent(trans1,get(firstList)) == NIL){
            comCount++;
        }
        moveNext(firstList);
    }
    
    fprintf(outFile,"\n");
    moveBack(firstList);
    fprintf(outFile,"G contains %d strongly connected components:\n", comCount);
    List tempList = newList();
    int printCount;
    for (printCount = 1; printCount <= comCount; printCount++) {
        fprintf(outFile,"Component %d:", printCount);
        while (getParent(trans1,get(firstList)) != NIL) {
            prepend(tempList, get(firstList));
            movePrev(firstList);
        }
        prepend(tempList, get(firstList));
        movePrev(firstList);
        moveFront(tempList);
        while(index(tempList) != -1) {
            fprintf(outFile," %d", get(tempList));
            moveNext(tempList);
        }
        fprintf(outFile,"\n");
        clear(tempList);
    }

    freeGraph(&copyFirst);
    freeGraph(&firstGraph);
    freeGraph(&trans1);
    freeList(&firstList);
    freeList(&tempList);
    fclose(outFile);

    return 0;
}