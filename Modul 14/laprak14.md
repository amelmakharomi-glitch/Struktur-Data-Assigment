# <h1 align="center">  GRAPH  </h1>
<p align="center">Amelia Sofiana Makharomi</p>

## Dasar Teori
Graph adalah struktur data yang terdiri dari node (vertex) dan edge yang merepresentasikan hubungan antar node. Graph dibedakan menjadi graph berarah dan tidak berarah. Representasi graph dapat menggunakan matriks ketetanggaan atau multilist, dimana multilist digunakan karena bersifat dinamis. Penelusuran graph dilakukan dengan metode Breadth First Search (BFS) dan Depth First Search (DFS), sedangkan graph berarah dapat digunakan untuk topological sort untuk menentukan urutan linear berdasarkan keterurutan parsial.

## Guided 

### 1. [GRAPH]
*graph.h*
```C++
#ifndef GRAPH_H
#define GRAPH_H

#include <iostream>

using namespace std;

typedef char infoGraph;
typedef struct ElmNode *adrNode;
typedef struct ElmEdge *adrEdge;

struct ElmNode {
    infoGraph info;      //menyimpan data node (misal: char/int)
    int visited;        //Penanda untuk traversal (0/1) (penanda apakah node sudah dikunjungi)
    adrEdge firstEdge; //Pointer ke edge pertama yang terhubung
    adrNode Next;     //Pointer ke node berikutnya dalam graph
};

struct ElmEdge {
    adrNode Node;  //Pointer yang menunjuk ke lokasi node tujuan
    adrEdge Next;  //Pointer ke edge berikutnya (jika satu node memiliki banyak cabang)
};

struct Graph {
    adrNode First;  //Pointer ke node pertama dalam list graph
};

void CreateGraph(Graph &G);  //prosedur untuk mengeset fitur dari graph sebagai NULL
adrNode AlokasiNode(infoGraph data);  //alokasi node baru
adrEdge AlokasiEdge(adrNode nodeTujuan);  //alokasi Edge baru

void InsertNode(Graph &G, infoGraph data);  //menambahkan node ke dalam graph
adrNode FindNode(Graph G, infoGraph data);  //function untuk mencari alamat node berdasarkan nilai info yang diberikan
void ConnectNode(Graph &G, infoGraph info1, infoGraph info2); //prosedur untuk menghubungkan dua node (membuat edge dari info1 ke info2)
void DisconnectNode(adrNode node1, adrNode node2);  //prosedur untuk memutuskan hubungan dua node (menghapus edge dari node1 ke node2)
void DeleteNode(Graph &G, infoGraph X);  //prosedur untuk menghapus node X beserta semua Edge yang terhubung

void PrintInfoGraph(Graph G);  //Menampilkan isi graph(Adjency list)
void ResetVisited(Graph &G);  //Reset status visited sebelum traversal
void PrintBFS(Graph G, infoGraph StartInfo);  //traversal Breadth Search / BFS (Menggunakan queue untuk menelusuri node berdasarkan tingkat)
void PrintDFS(Graph G, infoGraph StartInfo);  //traversal Depth First Search / DFS (menggunakan stack untuk menelusuri node secara mendalam)

#endif
```

*graph.cpp*
```
#include "graph.h"
#include <iostream>
#include <queue> //library queue untuk BFS
#include <stack> //library stack untuk DFS

using namespace std;

//prosedur untuk mengeset first dari graph sebagai NULL
void CreateGraph(Graph &G) {
    G.First = NULL;
}

//alokasi Node baru
adrNode AlokasiNode(infoGraph data) {
    adrNode nodeBaru = new ElmNode;
    nodeBaru->info = data;
    nodeBaru->visited = 0; //isinya 0/1
    nodeBaru->firstEdge = NULL;
    nodeBaru->Next = NULL;
    return nodeBaru;
}

//alokasi Edge baru
adrEdge AlokasiEdge(adrNode nodeTujuan) {
    adrEdge edgeBaru = new ElmEdge;
    edgeBaru->Node = nodeTujuan;
    edgeBaru->Next = NULL;
    return edgeBaru;
}

//Menambahkan Node ke dalam Graph
void InsertNode(Graph &G, infoGraph data) {
    adrNode nodeBaru = AlokasiNode(data);
    if (G.First == NULL) {
        G.First = nodeBaru;
    } else {
        //konsepnya insert last
        adrNode nodeBantu = G.First;
        while (nodeBantu->Next != NULL) {
            nodeBantu = nodeBantu->Next;
        }
        nodeBantu->Next = nodeBaru;
    }
}

//function untuk mencari alamat Node berdasarkan infonya
adrNode FindNode(Graph G, infoGraph data) {
    adrNode nodeBantu = G.First;
    while (nodeBantu != NULL) {
        if (nodeBantu->info == data) {
            return nodeBantu;
        }
        nodeBantu = nodeBantu->Next;
    }
    return NULL;
}

//prosedur untuk menghubungkan dua Node (Undirected Graph)
void ConnectNode(Graph &G, infoGraph info1, infoGraph info2) {
    adrNode node1 = FindNode(G, info1);
    adrNode node2 = FindNode(G, info2);

    if (node1 != NULL && node2 != NULL) {
        //Hubungkan node1 ke node2
        adrEdge Edge1 = AlokasiEdge(node2);
        Edge1->Next = node1->firstEdge; // Insert First pada list edge
        node1->firstEdge = Edge1;

        //Hubungkan node2 ke node1 (Karena Undirected/Bolak-balik)
        adrEdge Edge2 = AlokasiEdge(node1);
        Edge2->Next = node2->firstEdge;
        node2->firstEdge = Edge2;
    } else {
        cout << "Node tidak ditemukan!" << endl;
    }
}

//prosedur untuk memutuskan hubungan dua node
void DisconnectNode(adrNode node1, adrNode node2) {
    if (node1 != NULL && node2 != NULL) {
        adrEdge edgeBantu = node1->firstEdge;
        adrEdge PrevE = NULL;

        //Cari edge yang mengarah ke node2 di dalam list milik node1
        while (edgeBantu != NULL && edgeBantu->Node != node2) {
            PrevE = edgeBantu;
            edgeBantu = edgeBantu->Next;
        }

        if (edgeBantu != NULL) { //jika Edge ditemukan
            if (PrevE == NULL) {
                //Hapus edge pertama
                node1->firstEdge = edgeBantu->Next;
            } else {
                //Hapus edge di tengah/akhir
                PrevE->Next = edgeBantu->Next;
            }
            delete edgeBantu;
        }
    }
}

//prosedur untuk menghapus Node X beserta semua edge yang berhubungan dengannya
void DeleteNode(Graph &G, infoGraph X) {
    //1. Cari Node yang akan dihapus (nodeHapus)
    adrNode nodeHapus = FindNode(G, X);
    if (nodeHapus == NULL) {
        cout << "Node tidak ditemukan." << endl;
        return;
    }

    //2. Hapus semua Edge yang MENGARAH ke nodeHapus (Incoming Edges)
    //cek setiap node di graph, apakah punya edge ke nodeHapus
    adrNode nodeLainnya = G.First;
    while (nodeLainnya != NULL) {
        DisconnectNode(nodeLainnya, nodeHapus); //putus hubungan nodeLainnya ke nodeHapus
        nodeLainnya = nodeLainnya->Next;
    }

    //3. Hapus semua Edge yang KELUAR dari nodeHapus (Outgoing Edges)
    //Deallokasi list edge milik nodeHapus
    adrEdge edgeBantu = nodeHapus->firstEdge;
    while (edgeBantu != NULL) {
        adrEdge tempE = edgeBantu;
        edgeBantu = edgeBantu->Next;
        delete tempE;
    }
    nodeHapus->firstEdge = NULL;

    //4. Hapus nodeHapus dari List Utama Graph
    if (G.First == nodeHapus) {
        //jika nodeHapus di awal
        G.First = nodeHapus->Next;
    } else {
        //jika nodeHapus di tengah/akhir
        adrNode nodeBantu = G.First;
        while (nodeBantu->Next != nodeHapus) {
            nodeBantu = nodeBantu->Next;
        }
        nodeBantu->Next = nodeHapus->Next;
    }

    //5. delete nodeHapus
    delete nodeHapus;
}

//Menampilkan isi Graph (Adjacency List) 
void PrintInfoGraph(Graph G) {
    adrNode nodeBantu = G.First;
    while (nodeBantu != NULL) {
        cout << "Node " << nodeBantu->info << " terhubung ke: ";
        adrEdge edgeBantu = nodeBantu->firstEdge;
        while (edgeBantu != NULL) {
            cout << edgeBantu->Node->info << " "; //Akses info dari node tujuan
            edgeBantu = edgeBantu->Next;
        }
        cout << endl;
        nodeBantu = nodeBantu->Next;
    }
}

//Reset status visited sebelum traversal
void ResetVisited(Graph &G) {
    adrNode nodeReset = G.First;
    while (nodeReset != NULL) {
        nodeReset->visited = 0;
        nodeReset = nodeReset->Next;
    }
}

//traversal Breadth First Search / BFS (Menggunakan Queue)
void PrintBFS(Graph G, infoGraph StartInfo) {
    ResetVisited(G);
    adrNode StartNode = FindNode(G, StartInfo);
    
    if (StartNode == NULL) return;

    queue<adrNode> Qyu;
    
    //Enqueue start
    Qyu.push(StartNode);
    StartNode->visited = 1;

    cout << "BFS Traversal: ";
    while (!Qyu.empty()) {
        adrNode nodeBantu = Qyu.front();
        Qyu.pop();
        cout << nodeBantu->info << " - ";

        //Cek semua tetangga atau edge nya
        adrEdge edgeBantu = nodeBantu->firstEdge;
        while (edgeBantu != NULL) {
            if (edgeBantu->Node->visited == 0) {
                edgeBantu->Node->visited = 1;
                Qyu.push(edgeBantu->Node);
            }
            edgeBantu = edgeBantu->Next;
        }
    }
    cout << endl;
}

//Traversal Depth First Search / DFS (Menggunakan Stack)
void PrintDFS(Graph G, infoGraph StartInfo) {
    ResetVisited(G);
    adrNode StartNode = FindNode(G, StartInfo);
    
    if (StartNode == NULL) return;

    stack<adrNode> Stak;
    
    Stak.push(StartNode);

    cout << "DFS Traversal: ";
    while (!Stak.empty()) {
        adrNode nodeBantu = Stak.top();
        Stak.pop();

        if (nodeBantu->visited == 0) {
            nodeBantu->visited = 1;
            cout << nodeBantu->info << " - ";

            //masukkan tetangga ke stack
            adrEdge edgeBantu = nodeBantu->firstEdge;
            while (edgeBantu != NULL) {
                if (edgeBantu->Node->visited == 0) {
                    Stak.push(edgeBantu->Node);
                }
                edgeBantu = edgeBantu->Next;
            }
        }
    }
    cout << endl;
}
```

main.cpp
```
#include "graph.h"
#include <iostream>
#include <queue>
#include <stack>
using namespace std;
int main(){
    Graph G;
    CreateGraph(G);

    InsertNode(G, 'A');
    InsertNode(G, 'B');
    InsertNode(G, 'C');
    InsertNode(G, 'D');
    InsertNode(G, 'E');
    InsertNode(G, 'F');
    
    //hubungkan antar node
    ConnectNode(G, 'A', 'B');
    ConnectNode(G, 'A', 'D');
    ConnectNode(G, 'B', 'C');
    ConnectNode(G, 'D', 'C');
    ConnectNode(G, 'B', 'E');
    ConnectNode(G, 'C', 'E');
    ConnectNode(G, 'C', 'F');
    ConnectNode(G, 'E', 'F');

    cout << "=== REPRESENTASI ADJACENCY LIST ===" << endl;
    PrintInfoGraph(G);
    cout << endl;

    cout << "=== HASIL TRAVERSAL ===" << endl;
    //mulai traversal dari node A
    PrintBFS(G, 'A');  //BFS
    PrintDFS(G, 'A');  //DFS
    cout << endl;

    cout << "=== HAPUS NODE E ===" << endl;
    DeleteNode(G, 'E');
    if(FindNode(G, 'E') == NULL) {
        cout << "node E berhasil dihapus" << endl;
    } else {
        cout << "Node E tidak berhasil dihapus" << endl;
    }
    cout << endl;

    cout << "=== REPRESENTASI ADJACENCY LIST ===" << endl;
    PrintInfoGraph(G);
    cout << endl;

    cout << "=== HASIL TRAVERSAL ===" << endl;
    //mulai traversal dari node A
    PrintBFS(G, 'A');  //BFS
    PrintDFS(G, 'A');  //DFS

    return 0;
}
```

## Unguided 

### 1. [Soal]
*graph.h*
```C++
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
```

*graph.cpp*
```c++
#include "graph.h"

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
```

*main.cpp*
```c++
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

    showGraph(G);
    return 0;
}
```
#### Output:
<img width="1034" height="227" alt="{673E2F35-5688-4507-9C5C-CA35104F4524}" src="https://github.com/user-attachments/assets/fdd9afe5-755e-43f4-913b-52de40a59386" />

Program ini dibuat untuk membangun graph tidak berarah menggunakan bahasa C++ dengan struktur multilist. Program dapat menambah node, menghubungkan node secara dua arah, dan menampilkan hubungan antar node dalam graph.

#### Full code Screenshot:
<img width="1920" height="1080" alt="{EBB49EA7-C8E0-4568-9351-690E70EECA6E}" src="https://github.com/user-attachments/assets/4cb4ef93-f17a-40ad-b5b0-69a75196430f" />
<img width="1920" height="1080" alt="{D40F8059-35EF-4E01-977D-BC282D4439B1}" src="https://github.com/user-attachments/assets/fdaa103b-0ca6-4e8d-a826-9c6e3c5ac016" />
<img width="1920" height="1080" alt="{6C4B4F37-D226-4C26-AAC8-56E8BA30CE18}" src="https://github.com/user-attachments/assets/93ffcd0d-b1f8-462e-86eb-5454401eeaf8" />


### 2. [Soal]
*graph.h*
```C++
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

void resetVisited(Graph &G);
void PrintDFS(Graph G, adrNode N);

#endif
```

*graph.cpp*
```c++
#include "graph.h"

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
```

*main.cpp*
```c++
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
```

#### Output:
<img width="1029" height="293" alt="{723CC071-A2A9-47E9-89A2-DD27ECFF100C}" src="https://github.com/user-attachments/assets/f054aaf1-34e4-49c5-ad59-a63588223f8d" />

Program ini mengimplementasikan graph tidak berarah menggunakan bahasa C++ dengan struktur multilist. Program dapat menambah node, menghubungkan node secara dua arah, serta menelusuri graph menggunakan metode Depth First Search (DFS) untuk menampilkan urutan kunjungan node.

#### Full code Screenshot:
<img width="1920" height="1080" alt="{798A184A-9849-4BB8-8924-3227C6BC8CEA}" src="https://github.com/user-attachments/assets/cf0dcff2-af83-4ae7-8f97-3422384c6152" />
<img width="1920" height="1080" alt="{8728B72E-67A2-4949-954F-D1AB86580BBA}" src="https://github.com/user-attachments/assets/1cb13156-c8ed-4e45-affe-2bb53bf92462" />
<img width="1920" height="1080" alt="{0F070B6B-7F3A-495E-905D-A5C16CD93373}" src="https://github.com/user-attachments/assets/46d22924-9d36-4053-8e36-dcbc9cbc41d5" />


### 3. [Soal]
*graph.h*
```C++
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

void resetVisited(Graph &G);
void PrintDFS(Graph G, adrNode N);
void PrintBFS(Graph G, adrNode N);

#endif
```

*graph.cpp*
```c++
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
```

*main.cpp*
```c++
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

    resetVisited(G);
    cout << "\nHasil BFS: ";
    PrintBFS(G, A);

    return 0;
}
```

#### Output:
<img width="1045" height="319" alt="{1751D055-0BC9-4D40-BCF0-FD28A5A2FAA9}" src="https://github.com/user-attachments/assets/78dc1ca3-67ce-4ab9-8dc1-c42c6553e897" />

Program ini menjalankan pembuatan graph tidak berarah menggunakan bahasa C++, kemudian menampilkan struktur graph, serta melakukan penelusuran DFS dan BFS dari satu node awal untuk menampilkan urutan kunjungan node.

#### Full code Screenshot:
<img width="1920" height="1080" alt="{B6B3AB65-0F2C-466E-83BD-94BE1800D157}" src="https://github.com/user-attachments/assets/f58dfdb5-1352-4584-a613-c1859d8d450e" />
<img width="1920" height="1080" alt="{ACA003CE-1DD8-4FB2-8D16-6A5253F89A56}" src="https://github.com/user-attachments/assets/1513bca9-baab-4af4-875d-a12956cb5ae7" />
<img width="1920" height="1080" alt="{39838FC6-BD0B-4B0A-959B-AA91D82246C4}" src="https://github.com/user-attachments/assets/7a94c631-a911-434b-a900-cdfe7175c1e7" />


## Kesimpulan
Praktikum ini berhasil menerapkan graph tidak berarah menggunakan bahasa C++ dengan struktur multilist. Program mampu membentuk graph serta melakukan penelusuran DFS dan BFS untuk menampilkan urutan kunjungan node. Praktikum ini meningkatkan pemahaman mengenai konsep graph dan metode penelusurannya.

## Referensi
1. Modul 14 GRAPH
2. Graph Data Structure – GeeksforGeeks
3. Breadth First Search (BFS) untuk Graph – GeeksforGeeks




