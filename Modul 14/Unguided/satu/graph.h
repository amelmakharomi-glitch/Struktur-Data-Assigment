#ifndef GRAPH_H
#define GRAPH_H

#include <iostream>
using namespace std;

typedef char infotype;

struct Edge;
struct Node;

typedef Node* adrNode;
typedef Edge* adrEdge;

struct Edge {
    adrNode tujuan;
    adrEdge next;
};
struct Node {
    infotype data;
    int visited;
    adrEdge edge;
    adrNode next;
};
struct Graph {
    adrNode first;
};
void initGraph(Graph &G);
adrNode newNode(infotype x);
adrEdge newEdge(adrNode n);
void addNode(Graph &G, infotype x);
void addEdge(adrNode a, adrNode b);
adrNode searchNode(Graph G, infotype x);
void showGraph(Graph G);

#endif
