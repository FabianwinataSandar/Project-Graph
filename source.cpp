#include <iostream>
#include <stdlib.h>
#include "header.h"

using namespace std;

AdjListNode* newAdjListNode(int dest) {
    AdjListNode* newNode = (AdjListNode*)malloc(sizeof(AdjListNode));
    newNode->dest = dest;
    newNode->next = NULL;
    return newNode;
}

Graph* createGraph(int V) {
    Graph* graph = (Graph*)malloc(sizeof(Graph));
    graph->V = V;

    graph->array = (AdjList*)malloc(V * sizeof(AdjList));

    for (int i = 0; i < V; ++i) {
        graph->array[i].head = NULL;
    }

    return graph;
}

void addEdge(Graph* graph, int src, int dest) {
    AdjListNode* newNode = newAdjListNode(dest);
    newNode->next = graph->array[src].head;
    graph->array[src].head = newNode;
}

void printGraph(Graph* graph) {
    for (int v = 0; v < graph->V; ++v) {
        AdjListNode* pCrawl = graph->array[v].head;
        cout << endl;
        cout << "Daftar adjacency dari vertex " << v << " head";
        while (pCrawl) {
            cout << " -> " << pCrawl->dest;
            pCrawl = pCrawl->next;
        }
        cout << endl;
    }
}

bool CekEdge(Graph* graph, int src, int dest) {
    AdjListNode* pCrawl = graph->array[src].head;
    while (pCrawl) {
        if (pCrawl->dest == dest) {
            return true;
        }
        pCrawl = pCrawl->next;
    }
    return false;
}

int hasEdge(Graph* graph, int src, int dest) {
    AdjListNode* pCrawl = graph->array[src].head;
    while (pCrawl) {
        if (pCrawl->dest == dest) {
            return 1;
        }
        pCrawl = pCrawl->next;
    }
    return 0;
}
