#include "graph.h"
#include <queue>

void initGraph(Graph &G) {
    G.first = NULL;
}
adrNode newNode(infotype x) {
    adrNode p = new Node;
    p->data = x;
    p->visited = 0;
    p->edge = NULL;
    p->next = NULL;
    return p;
}
adrEdge newEdge(adrNode n) {
    adrEdge e = new Edge;
    e->tujuan = n;
    e->next = NULL;
    return e;
}
void addNode(Graph &G, infotype x) {
    adrNode p = newNode(x);

    if (G.first == NULL) {
        G.first = p;
    } else {
        adrNode q = G.first;
        while (q->next != NULL)
            q = q->next;
        q->next = p;
    }
}
adrNode searchNode(Graph G, infotype x) {
    adrNode p = G.first;
    while (p != NULL) {
        if (p->data == x)
            return p;
        p = p->next;
    }
    return NULL;
}
void addEdge(adrNode a, adrNode b) {
    // a ke b
    adrEdge e1 = newEdge(b);
    e1->next = a->edge;
    a->edge = e1;

    adrEdge e2 = newEdge(a);
    e2->next = b->edge;
    b->edge = e2;
}
void showGraph(Graph G) {
    adrNode p = G.first;
    while (p != NULL) {
        cout << p->data << " -> ";
        adrEdge e = p->edge;
        while (e != NULL) {
            cout << e->tujuan->data << " ";
            e = e->next;
        }
        cout << endl;
        p = p->next;
    }
}
void resetVisited(Graph &G) {
    adrNode p = G.first;
    while (p != NULL) {
        p->visited = 0;
        p = p->next;
    }
}
void PrintDFS(Graph G, adrNode N) {
    if (N != NULL && N->visited == 0) {
        cout << N->data << " ";
        N->visited = 1;

        adrEdge e = N->edge;
        while (e != NULL) {
            if (e->tujuan->visited == 0) {
                PrintDFS(G, e->tujuan);
            }
            e = e->next;
        }
    }
}
void PrintBFS(Graph G, adrNode N) {
    if (N == NULL) return;

    queue<adrNode> Q;
    N->visited = 1;
    Q.push(N);

    while (!Q.empty()) {
        adrNode P = Q.front();
        Q.pop();

        cout << P->data << " ";

        adrEdge e = P->edge;
        while (e != NULL) {
            if (e->tujuan->visited == 0) {
                e->tujuan->visited = 1;
                Q.push(e->tujuan);
            }
            e = e->next;
        }
    }
}