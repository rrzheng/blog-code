#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "stack.h"
#include "graph.h"

/* recursive DFS function to traverse the graph,
 * the graph is represented by adjacency list
*/
void dfs(int u, Graph *g, int *visit, Stack *s) {
    visit[u] = 1;
    AdjListNode *pCrawl = g->array[u].head;
    while(pCrawl) {
        if(!visit[pCrawl->dest])
            dfs(pCrawl->dest, g, visit, s);
        pCrawl = pCrawl->next;
    }
    push(u, s);
}

// the topological sort function
void topologicalSort(Graph *g) {
    int *visit = (int *) malloc(g->V * sizeof(int));
    memset(visit, 0, g->V * sizeof(int));
    Stack *s = initStack();
    int i;
    for(i = 0; i < g->V; i++) {
        if(!visit[i]) dfs(i, g, visit, s);
    }

    // the order of stack element is the sorted order
    while(!isEmpty(s)) {
        printf("vertex %d\n", pop(s));
    }
}

//int *getInDegree(Graph *g) {
//    int *inDegreeArray = (int *) malloc(g->V * sizeof(int));
//    memset(inDegreeArray, 0, g->V * sizeof(int));
//    int i;
//    AdjListNode *pCrawl;
//    for(i = 0; i < g->V; i++) {
//        pCrawl = g->array[i].head;
//        while(pCrawl) {
//            inDegreeArray[pCrawl->dest]++;
//            pCrawl = pCrawl->next;
//        }
//    }
//    return inDegreeArray;
//}

//void topologicalSort(Graph *g) {
//    int *inDegreeArray = getInDegree(g);
//    Stack *zeroInDegree = initStack();
//    int i;
//    for(i = 0; i < g->V; i++) {
//        if(inDegreeArray[i] == 0)
//            push(i, zeroInDegree);
//    }
//
//    printf("topological sorted order\n");
//    AdjListNode *pCrawl;
//    while(!isEmpty(zeroInDegree)) {
//        i = pop(zeroInDegree);
//        printf("vertex %d\n", i);
//
//        pCrawl = g->array[i].head;
//        while(pCrawl) {
//            inDegreeArray[pCrawl->dest]--;
//            if(inDegreeArray[pCrawl->dest] == 0)
//                push(pCrawl->dest, zeroInDegree);
//            pCrawl = pCrawl->next;
//        }
//    }
//}


void main () {
    int V = 6, E = 6;
    Graph* graph = createGraph(V, E);
    addEdge(graph, 0, 3);
    addEdge(graph, 3, 1);
    addEdge(graph, 4, 1);
    addEdge(graph, 4, 2);
    addEdge(graph, 5, 2);
    addEdge(graph, 5, 0);

    topologicalSort(graph);
}