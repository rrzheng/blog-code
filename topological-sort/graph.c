#include <stdio.h>
#include <stdlib.h>

typedef struct AdjListNode {
    int dest;
    struct AdjListNode *next;
}AdjListNode;

typedef struct AdjList {
    AdjListNode *head;
}AdjList;

typedef struct Graph {
    int V, E;
    AdjList *array;
}Graph;

AdjListNode * newAdListNode(int dest) {
    AdjListNode *node = (AdjListNode *) malloc(sizeof(AdjListNode));
    node->dest = dest;
    node->next = NULL;
}

void addEdge(Graph *g, int src, int dest) {
    AdjListNode *node = newAdListNode(dest);
    node->next = g->array[src].head;
    g->array[src].head = node;
}

Graph *createGraph(int V, int E) {
    Graph *g = (Graph *) malloc(sizeof(Graph));
    g->V = V;
    g->E = E;
    g->array = (AdjList *) malloc(V * sizeof(AdjList));

    int i;
    for(i = 0; i < V; i++) {
        g->array[i].head = NULL;
    }
    return g;
}

void printGraph(Graph *g) {
    int v;
    for (v = 0; v < g->V; ++v) {
        AdjListNode * pCrawl = g->array[v].head;
        printf("\n Adjacency list of vertex %d\n head ", v);
        while(pCrawl) {
            printf("-> %d", pCrawl->dest);
            pCrawl = pCrawl->next;
        }
        printf("\n");
    }
}