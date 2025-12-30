#include "graph.h"

int main() {
    Graph G;
    initGraph(G);

    char node[] = {'A','B','C','D','E','F','G','H'};
    for (char n : node)
        addNode(G, n);

    adrNode A = searchNode(G,'A');
    adrNode B = searchNode(G,'B');
    adrNode C = searchNode(G,'C');
    adrNode D = searchNode(G,'D');
    adrNode E = searchNode(G,'E');
    adrNode F = searchNode(G,'F');
    adrNode G1 = searchNode(G,'G');
    adrNode H = searchNode(G,'H');

    addEdge(A,B);
    addEdge(A,C);
    addEdge(B,D);
    addEdge(B,E);
    addEdge(C,F);
    addEdge(C,G1);
    addEdge(D,H);
    addEdge(E,H);
    addEdge(F,H);
    addEdge(G1,H);

    cout << "Graph:" << endl;
    showGraph(G);

    resetVisited(G);
    cout << "\nHasil DFS: ";
    PrintDFS(G, A);

    return 0;
}
