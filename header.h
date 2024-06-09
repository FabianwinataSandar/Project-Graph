#include <iostream>
#include <stdlib.h>

using namespace std;

typedef struct AdjListNode {
    int dest;
    struct AdjListNode* next;
} AdjListNode;

typedef struct AdjList {
    struct AdjListNode *head;
} AdjList;

typedef struct Graph {
    int V;
    struct AdjList* array;
} Graph;

AdjListNode* newAdjListNode(int dest);
Graph* createGraph(int V);
void addEdge(Graph* graph, int src, int dest);
void printGraph(Graph* graph);
bool CekEdge(Graph* graph, int src, int dest);
int hasEdge(Graph* graph, int src, int dest);
