/***
* Jooho Lee
* jlee897
* 2024 Winter CSE101 PA3
* Graph.h
* header file for Graph.h
***/ 
#ifndef GRAPH_H_INCLUDE_
#define GRAPH_H_INCLUDE_
#define UNDEF -1
#define NIL 0
#include "List.h"
#include <stdlib.h>
#include <stdio.h>

typedef struct GraphOBJ* Graph;

// Constructors-Destructors
Graph newGraph(int n);
void freeGraph(Graph* pG);
// Access functions
int getOrder(Graph G);
int getSize(Graph G);
int getParent(Graph G, int u); /* Pre: 1<=u<=n=getOrder(G) */
int getDiscover(Graph G, int u); /* Pre: 1<=u<=n=getOrder(G) */
int getFinish(Graph G, int u); /* Pre: 1<=u<=n=getOrder(G) */
// Manipulation procedures
void addArc(Graph G, int u, int v); /* Pre: 1<=u<=n, 1<=v<=n */
void addEdge(Graph G, int u, int v); /* Pre: 1<=u<=n, 1<=v<=n */
void DFS(Graph G, List S); /* Pre: length(S)==getOrder(G) */
// Other Functions
Graph transpose(Graph G);
Graph copyGraph(Graph G);
void printGraph(FILE* out , Graph G);

#endif