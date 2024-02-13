/***
* Jooho Lee
* jlee897
* 2024 Winter CSE101 PA2
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
    int *distance;
    int source;
} GraphOBJ;

/*** Constructors-Destructors ***/

//mallocs new graph and returns Graph
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
    tempGraph->distance = (int*)malloc(sizeof(int) * (n + 1));
    if (tempGraph->distance == NULL) {
        printf("ERROR: distance malloc in newGraph returned NULL! // Graph.c\n");
        exit(EXIT_FAILURE);
    }
    for (int newGraphCount = 1; newGraphCount <= n ; newGraphCount++) {
        tempGraph->neighbors[newGraphCount] = newList();
        tempGraph->color[newGraphCount] = WHITE_COLOR;
        tempGraph->parent[newGraphCount] = NIL;
        tempGraph->distance[newGraphCount] = INF;
    }
    tempGraph->source = NIL;
    return tempGraph;
}

//frees graph
void freeGraph(Graph *pG) {
    if (*pG == NULL || pG == NULL) {
        printf("ERROR: *pG or pG is NuULL in freeGraph //Graph.c\n");
        exit(EXIT_FAILURE);
    }
    for (int freeCount = 1; freeCount <= (*pG)->order; freeCount++) {
        freeList(&(*pG)->neighbors[freeCount]);
    }
    free((*pG)->neighbors);
    free((*pG)->color);
    free((*pG)->parent);
    free((*pG)->distance);
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

//returns source of given graph G
int getSource(Graph G) {
    if (G == NULL) {
        printf("ERROR: G in getSource is NULL //Graph.c\n");
        exit(EXIT_FAILURE);
    }
    return G->source;
}

//return the parent of vertex u in the BFS tree
//created by BFS(), or NIL if BFS() has not yet been called
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

//returns the distance from the most recent BFS source 
//to vertex u, or INF if BFS() has not yet been called
//returns distance of given graph G from source u
//precondition 1 ≤ 𝑢 ≤ getOrder(𝐺)
int getDist(Graph G, int u) {
    if (G == NULL) {
        printf("ERROR: G in getDist is NULL //Graph.c\n");
        exit(EXIT_FAILURE);
    }
    if (u < 1 || u > getOrder(G)) {
        printf("ERROR: u is less than 1 or greater than order of given graph G  in getDist() //Graph.c\n");
        exit(EXIT_FAILURE);
    }
    return G->distance[u];
}

//appends to the List L the vertices of a shortest path in G from source to u, 
//or appends to L the value NIL if no such path exists
//precondition getSource(G)!=NIL
//precondition 1 ≤ 𝑢 ≤ getOrder(𝐺)
void getPath(List L, Graph G, int u) {
    if (G == NULL || L == NULL) {
        printf("ERROR: G or L in getPath is NULL //Graph.c\n");
        exit(EXIT_FAILURE);
    }
    if (u < 1 || u > getOrder(G)) {
        printf("ERROR: u is less than 1 or greater than order of given graph G in getPath() //Graph.c\n");
        exit(EXIT_FAILURE);
    }
    if (getSource(G) == NIL) {
        printf("ERROR: getSource(G) == NIL in getPath() //Graph.c\n");
        exit(EXIT_FAILURE);
    }
    if (getSource(G) == u) {
        append(L, u);
    } else if (getParent(G,u) == NIL) {
        prepend(L,NIL);
    } else {
        getPath(L, G, getParent(G,u));
        append(L,u);
    }
}

/*** Manipulation procedures ***/

//deletes all edges of G, restoring it to its original (no edge) state
void makeNull(Graph G) {
    if (G == NULL) {
        printf("ERROR: G is NULL in makeNull() //Graph.c\n");
        exit(EXIT_FAILURE);
    }
    for (int makeNullCount = 1; makeNullCount <= G->order; makeNullCount++) {
        clear(G->neighbors[makeNullCount]);
    }
    G->size = 0;
}

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
}

//runs the BFS algorithm on the Graph G with source s,
//setting the color, distance, parent, and source fields of G accordingly
void BFS(Graph G, int s) {
    if (G == NULL) {
        printf("ERROR: G is NULL in addArc() //Graph.c\n");
        exit(EXIT_FAILURE);
    }
    if (s < 1 || s > getOrder(G)) {
        printf("ERROR: precondition 1 < s < getOrder(G) failed in BFS() //Graph.c\n");
        exit(EXIT_FAILURE);
    }
    G->source = s;
    List tempList = newList();
    append(tempList,s);
    int bfsCount;
    for (bfsCount = 1; bfsCount <= getOrder(G); bfsCount++) {
        if (bfsCount == s) {
            G->color[bfsCount] = GREY_COLOR;
            G->distance[bfsCount] = 0;
            G->parent[bfsCount] = NIL;
        } else {
            G->color[bfsCount] = WHITE_COLOR;
            G->distance[bfsCount] = INF;
            G->parent[bfsCount] = NIL;
        }
    }
    while (length(tempList) != 0) {
        moveFront(tempList);
        int myNum = get(tempList);
        deleteFront(tempList);
        List tempNeighbors = G->neighbors[myNum];
        if (length(tempNeighbors) == 0) {
            ;
        } else {
            moveFront(tempNeighbors);
            while (index(tempNeighbors) >= 0) {
                int tempCount = get(tempNeighbors);
                if (G->color[tempCount] == WHITE_COLOR) {
                    G->color[tempCount] = GREY_COLOR;
                    G->distance[tempCount] = G->distance[myNum] + 1;
                    G->parent[tempCount] = myNum;
                    append(tempList, tempCount);
                }
                moveNext(tempNeighbors);
            }
        }
        G->color[myNum] = BLACK_COLOR;
    }
    freeList(&tempList);
}

/*** Other operations ***/

//prints the adjacency list representation of G to the file pointed to by out
void printGraph(FILE* out, Graph G) {
    if (out == NULL || G == NULL) {
        printf("ERROR: G i or out s NULL in printGraph() //Graph.c\n");
        exit(EXIT_FAILURE);
    }
    for (int printCount = 1; printCount <= getOrder(G); printCount++) {
        fprintf(out, "%d:", printCount);
        List tempNeighbors = G->neighbors[printCount];
        if (length(tempNeighbors) == 0) {
            ;
        } else {
            moveFront(tempNeighbors);
            while (index(tempNeighbors) >= 0) {
                int whileCount = get(tempNeighbors);
                fprintf(out, " %d", whileCount);
                moveNext(tempNeighbors);
            }
        }
        fprintf(out, "\n");
    }
}

