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

AdjListNode * newAdListNode(int dest);

void addEdge(Graph *g, int src, int dest);

Graph *createGraph(int V, int E);

void printGraph(Graph *g);