/***
* Jooho Lee
* jlee897
* 2024 Winter CSE101 PA3
* Graph.c
* Graph ADT
***/ 
#include "Graph.h"
#include <stdlib.h>
#include <stdio.h>

#define WHITE_COLOR 'w'
#define GREY_COLOR 'g'
#define BLACK_COLOR 'b'

typedef struct GraphOBJ {
    int order;//veritces
    int size;//edges
    List *neighbors;
    char *color;
    int *parent;
    int *discover;
    int *finish;
} GraphOBJ;

/*** Constructors-Destructors ***/

//mallocs new Graph and returns new mallocd Graph
Graph newGraph(int n) {
    Graph tempGraph = (Graph)malloc(sizeof(GraphOBJ));
    tempGraph->order = n;
    tempGraph->size = 0;
    tempGraph->neighbors = (List*)malloc(sizeof(List) * (n + 1));
    if (tempGraph->neighbors == NULL) {
        printf("ERROR: neighbors malloc in newGraph returned NULL! // Graph.c\n");
        exit(EXIT_FAILURE);
    }
    tempGraph->color = (char*)malloc(sizeof(char) * (n + 1));
    if (tempGraph->color == NULL) {
        printf("ERROR: color malloc in newGraph returned NULL! // Graph.c\n");
        exit(EXIT_FAILURE);
    }
    tempGraph->parent = (int*)malloc(sizeof(int) * (n + 1));
    if (tempGraph->parent == NULL) {
        printf("ERROR: parent malloc in newGraph returned NULL! // Graph.c\n");
        exit(EXIT_FAILURE);
    }
    tempGraph->discover = (int*)malloc(sizeof(int) * (n + 1));
    if (tempGraph->discover == NULL) {
        printf("ERROR: discover malloc in newGraph returned NULL! // Graph.c\n");
        exit(EXIT_FAILURE);
    }
    tempGraph->finish = (int*)malloc(sizeof(int) * (n + 1));
    if (tempGraph->finish == NULL) {
        printf("ERROR: finish malloc in newGraph returned NULL! // Graph.c\n");
        exit(EXIT_FAILURE);
    }
    for (int newGraphCount = 1; newGraphCount <= n ; newGraphCount++) {
        tempGraph->neighbors[newGraphCount] = newList();
        tempGraph->color[newGraphCount] = WHITE_COLOR;
        tempGraph->parent[newGraphCount] = NIL;
        tempGraph->discover[newGraphCount] = UNDEF;
        tempGraph->finish[newGraphCount] = UNDEF;
    }
    return tempGraph;
}

//frees graph
void freeGraph(Graph *pG) {
    if (*pG == NULL || pG == NULL) {
        printf("ERROR: *pG or pG is NULL in freeGraph //Graph.c\n");
        exit(EXIT_FAILURE);
    }
    for (int freeCount = 1; freeCount <= (*pG)->order; freeCount++) {
        freeList(&(*pG)->neighbors[freeCount]);
    }
    free((*pG)->neighbors);
    free((*pG)->color);
    free((*pG)->parent);
    free((*pG)->discover);
    free((*pG)->finish);
    free(*pG);
    *pG = NULL;
}

/*** Access functions ***/

//returns order of given graph G
int getOrder(Graph G) {
    if (G == NULL) {
        printf("ERROR: G in getOrder is NULL //Graph.c\n");
        exit(EXIT_FAILURE);
    }
    return G->order;
}

//returns size of given graph G
int getSize(Graph G) {
    if (G == NULL) {
        printf("ERROR: G in getSize is NULL //Graph.c\n");
        exit(EXIT_FAILURE);
    }
    return G->size;
}

//return the parent of vertex u in the DFS tree
//created by DFS(), or NIL if DFS() has not yet been called
//precondition 1 ≤ 𝑢 ≤ getOrder(𝐺)
//gets parent for vertex u in graph G
int getParent(Graph G, int u) {
    if (G == NULL) {
        printf("ERROR: G in getOrder is NULL //Graph.c\n");
        exit(EXIT_FAILURE);
    }
    if (u < 1 || u > getOrder(G)) {
        printf("ERROR: u is less than 1 or greater than order of given graph G //Graph.c\n");
        exit(EXIT_FAILURE);
    }
    return G->parent[u];
}

/* Pre: 1<=u<=n=getOrder(G) */
int getDiscover(Graph G, int u) {
    if (G == NULL) {
        printf("ERROR: G in getDiscover() is NULL //Graph.c\n");
        exit(EXIT_FAILURE);
    }
    if (u < 1 || u > getOrder(G)) {
        printf("ERROR: u is less than 1 or greater than order of given graph G in getDiscover() //Graph.c\n");
        exit(EXIT_FAILURE);
    }
    return G->discover[u];
}

/* Pre: 1<=u<=n=getOrder(G) */
int getFinish(Graph G, int u) {
    if (G == NULL) {
        printf("ERROR: G in getFinish() is NULL //Graph.c\n");
        exit(EXIT_FAILURE);
    }
    if (u < 1 || u > getOrder(G)) {
        printf("ERROR: u is less than 1 or greater than order of given graph G in getFinish() //Graph.c\n");
        exit(EXIT_FAILURE);
    }
    return G->finish[u];
}

/*** Manipulation procedures ***/

//inserts a new edge joining u to v, i.e. u is added to the adjacency 
//List of v, and v to the adjacency List of u
//precondition 1 < u < getOrder(G)
//precondition 1 < v < getOrder(G)
void addEdge(Graph G, int u, int v) {
    if (G == NULL) {
        printf("ERROR: G is NULL in addEdge() //Graph.c\n");
        exit(EXIT_FAILURE);
    }
    if (u < 1 || u > getOrder(G)) {
        printf("ERROR: precondition precondition 1 < u < getOrder(G) failed in addEdge() //Graph.c\n");
        exit(EXIT_FAILURE);
    }
    if (v < 1 || v > getOrder(G)) {
        printf("ERROR: precondition precondition 1 < v < getOrder(G) failed in addEdge() //Graph.c\n");
        exit(EXIT_FAILURE);
    }
    addArc(G, u, v);
    addArc(G, v, u);
    G->size--;
}

//inserts a new directed edge from u to v, i.e. v is added to the adjacency 
//List of u (but not u to the adjacency List of v)
//precondition 1 < u < getOrder(G)
//precondition 1 < v < getOrder(G)
void addArc(Graph G, int u, int v) {
    if (G == NULL) {
        printf("ERROR: G is NULL in addArc() //Graph.c\n");
        exit(EXIT_FAILURE);
    }
    if (u < 1 || u > getOrder(G)) {
        printf("ERROR: precondition precondition 1 < u < getOrder(G) failed in addArc() //Graph.c\n");
        exit(EXIT_FAILURE);
    }
    if (v < 1 || v > getOrder(G)) {
        printf("ERROR: precondition precondition 1 < v < getOrder(G) failed in addArc() //Graph.c\n");
        exit(EXIT_FAILURE);
    }
    List tempNeighbors = G->neighbors[u];
    if (length(tempNeighbors) == 0) {
        append(tempNeighbors,v);
        G->size++;
        return;
    }
    moveFront(tempNeighbors);
    while (index(tempNeighbors) >= 0) {
        int myNum = get(tempNeighbors);
        if (myNum > v) {
            insertBefore(tempNeighbors, v);
            G->size++;
            return;
        } else if (myNum == v) {
            return;
        }
        moveNext(tempNeighbors);
    }
    append(tempNeighbors, v);
    G->size++;
    tempNeighbors = NULL;
}

//Helper function for DFS()
static void Visit(Graph G, List tempList, int *time, int x) {
    G->discover[x] = (++*time);
    G->color[x] = GREY_COLOR;
    List currList = G->neighbors[x];
    if (length(currList) != 0) {
        moveFront(currList);
        while (index(currList) != -1) {
            if (G->color[get(currList)] == WHITE_COLOR) {
                G->parent[get(currList)] = x;
                Visit(G,tempList, time,get(currList));
            }
            moveNext(currList);
        }
    }
    currList = NULL;
    G->color[x] = BLACK_COLOR;
    prepend(tempList,x);
    G->finish[x] = (++*time);
}

/* Pre: length(S)==getOrder(G) */
void DFS(Graph G, List S) {
    if (G == NULL) {
        printf("ERROR: G in DFS() is null //Graph.c");
        exit(EXIT_FAILURE);
    }
    if (S == NULL) {
        printf("ERROR: S is null in DFS() //Graph.c");
        exit(EXIT_FAILURE);
    }
    if (length(S) != getOrder(G)) {
        printf("ERROR: length(S) != getOrder(G) in DFS() //Graph.c");
        exit(EXIT_FAILURE);
    }
    int DFScount;
    for (DFScount = 1; DFScount <= getOrder(G) ; DFScount++) {
        G->color[DFScount] = WHITE_COLOR;
        G->parent[DFScount] = NIL;
    }
    int time = 0;
    moveFront(S);
    List tempList = newList();
    while (index(S) != -1) {
        if (G->color[get(S)] == WHITE_COLOR) {
            Visit(G, tempList, &time, get(S));
        }
        moveNext(S);
    }
    clear(S);
    moveFront(tempList);
    while (index(tempList) != -1) {
        append(S,get(tempList));
        moveNext(tempList);
    }
    freeList(&tempList);
}

// Other Functions
Graph transpose(Graph G) {
    if (G == NULL) {
        printf("ERROR: G in transpose() is null //Graph.c");
        exit(EXIT_FAILURE);
    }
    Graph tempGraph = newGraph(getOrder(G));
    int transCount;
    for (transCount = 1; transCount <= getOrder(G); transCount++) {
        List currList = G->neighbors[transCount];
        if (length(currList) != 0) {
            moveFront(currList);
            while (index(currList) != -1) {
                addArc(tempGraph,get(currList),transCount);
                moveNext(currList);
            }
        }
        currList = NULL;
    }
    tempGraph->size = getSize(G);
    return tempGraph;
}//end of transpose

Graph copyGraph(Graph G) {
    if (G == NULL) {
        printf("ERROR: G in copyGraph() is null //Graph.c");
        exit(EXIT_FAILURE);
    }
    Graph tempGraph = newGraph(getOrder(G));
    int copyCount;
    for (copyCount = 1; copyCount <= getOrder(G); copyCount++) {
        List currList = G->neighbors[copyCount];
        if (length(currList) != 0) {
            moveFront(currList);
            while (index(currList) != -1) {
                addArc(tempGraph,copyCount,get(currList));
                moveNext(currList);
            }
        }
        currList = NULL;
    }
    for (copyCount = 1; copyCount <= getOrder(G); copyCount++) {
        tempGraph->discover[copyCount] = getDiscover(G,copyCount);
        tempGraph->finish[copyCount] = getFinish(G,copyCount);
        tempGraph->parent[copyCount] = getParent(G,copyCount);
    }
    tempGraph->size = getSize(G);
    return tempGraph;
}//end of copyGraph()

void printGraph(FILE* out , Graph G) {
    if (G == NULL) {
        printf("ERROR: G in printGraph() is null //Graph.c");
        exit(EXIT_FAILURE);
    }
    if (out == NULL) {
        printf("ERROR: out in printGraph() is null //Graph.c");
        exit(EXIT_FAILURE);
    }
    int printCount;
    for (printCount = 1; printCount <= getOrder(G); printCount++) {
        fprintf(out,"%d: ", printCount);
        List currList = G->neighbors[printCount];
        if (length(currList) != 0) {
            moveFront(currList);
            while (index(currList) != -1) {
                fprintf(out,"%d ", get(currList));
                moveNext(currList);
            }
        }
        fprintf(out,"\n");
        currList = NULL;
    }
}
