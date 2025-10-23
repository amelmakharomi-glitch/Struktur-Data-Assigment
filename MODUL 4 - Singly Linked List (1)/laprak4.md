# <h1 align="center">SINGLY LINKED LIST (BAGIAN 1)</h1>
<p align="center">Amelia Sofiana Makharomi</p>

## Dasar Teori
Linked list adalah struktur data yang terdiri dari elemen-elemen yang saling terhubung dan bersifat fleksibel karena dapat bertambah atau berkurang sesuai kebutuhan. Data di dalamnya bisa berupa data tunggal (misalnya nama bertipe *string*) atau data majemuk (misalnya data mahasiswa yang berisi nama, NIM, dan alamat dengan tipe data berbeda).


## Guided 

### 1. [Nama Topik]
**list.h**
```C++
//
//
#ifndef LIST_H
#define LIST_H
#define Nil NULL

#include <iostream>
using namespace std;

//deklarasi isi data struct mahasiswa
struct mahasiswa{
    string nama;
    string nim;
    int umur;
};

typedef mahasiswa dataMahasiswa; //Membiarkan nama alias dataMahasiswa untuk struct mahasiswa

typedef struct node *address; //Mendefinisikan alias address sbg pointer ke struct node

struct node{
    dataMahasiswa isidata;
    address next;
};

struct linkedlist{ //ini linked list nya
    address first;
};

//semua function & prosedur yang akan dipakai
bool isEmpty(linkedlist List);
void createList(linkedlist &List);
address alokasi(string nama, string nim, int umur);
void dealokasi(address &node);
void printList(linkedlist List);
void insertFirst(linkedlist &List, address nodeBaru);
void insertAfter(linkedlist &List, address nodeBaru, address Prev);
void insertLast(linkedlist &List, address nodeBaru);

#endif
}
```
**list.cpp**
```C++
#include "list.h"
#include <iostream>
using namespace std;

//I.S = Initial State / kondisi awal
//F.S = Final State / kondisi akhir

//fungsi untuk cek apakah list kosong atau tidak
bool isEmpty(linkedlist List) {
    if(List.first == Nil){
        return true; 
    } else {
        return false;
    }
}

//pembuatan linked list kosong
void createList(linkedlist &List) {
    /* I.S. sembarang
       F.S. terbentuk list kosong */
    List.first = Nil;
}

//pembuatan node baru dengan menerapkan manajemen memori
address alokasi(string nama, string nim, int umur) { 
    /* I.S. sembarang
       F.S. mengembalikan alamat node baru dengan isidata = sesuai parameter dan next = Nil */
    address nodeBaru = new node; 
    nodeBaru->isidata.nama = nama;
    nodeBaru->isidata.nim = nim; 
    nodeBaru->isidata.umur = umur;
    nodeBaru->next = Nil;
    return nodeBaru;
}

//penghapusan node dengan menerapkan manajemen memori
void dealokasi(address &node) {
    /* I.S. P terdefinisi
       F.S. memori yang digunakan node dikembalikan ke sistem */
    node->next = Nil;
    delete node;
}

//prosedur-prosedur untuk insert / menambahkan node baru kedalam list
void insertFirst(linkedlist &List, address nodeBaru) {
    /* I.S. sembarang, P sudah dialokasikan
       F.S. menempatkan elemen list (node) pada awal list */
    nodeBaru->next = List.first; 
    List.first = nodeBaru;
}

void insertAfter(linkedlist &List, address nodeBaru, address Prev) {
    /* I.S. sembarang, nodeBaru dan Prev alamat salah satu elemen list (node)
       F.S. menempatkan elemen (node) sesudah elemen node Prev */
    if (Prev != Nil) {
        nodeBaru->next = Prev->next;
        Prev->next = nodeBaru;
    } else {
        cout << "Node sebelumnya tidak valid!" << endl;
    }
}

void insertLast(linkedlist &List, address nodeBaru) {
    /* I.S. sembarang, nodeBaru sudah dialokasikan
       F.S. menempatkan elemen nodeBaru pada akhir list */
    if (isEmpty(List)) {
        List.first = nodeBaru;
    } else {
        address nodeBantu = List.first;
        while (nodeBantu->next != Nil) {
            nodeBantu = nodeBantu->next;
        }
        nodeBantu->next = nodeBaru;
    }
}

//prosedur-prosedur untuk delete / menghapus node yang ada didalam list
void delFirst(linkedlist &List){
    /* I.S. list tidak kosong
    F.S. node pertama di list terhapus*/
    address nodeHapus;
    if (isEmpty(List) == false) {
        nodeHapus = List.first;
        List.first = List.first->next;
        nodeHapus->next = Nil;
        dealokasi(nodeHapus);
    } else {
        cout << "List kosong!" << endl;
    }
}

void delLast(linkedlist &List){
    /* I.S. list tidak kosong
    F.S. node terakhir di list terhapus */
    address nodeHapus, nodePrev;
    if(isEmpty(List) == false){
        nodeHapus = List.first;
        if(nodeHapus->next == Nil){
            List.first->next = Nil;
            dealokasi(nodeHapus);
        } else { 
            while(nodeHapus->next != Nil){
                nodePrev = nodeHapus; 
                nodeHapus = nodeHapus->next;
            }
            nodePrev->next = Nil; 
            dealokasi(nodeHapus);
        }
    } else {
        cout << "list kosong" << endl;
    }
}

void delAfter(linkedlist &List, address nodeHapus, address nodePrev){
    /* I.S. list tidak kosng, Prev alamat salah satu elemen list
    F.S. nodeBantu adalah alamat dari Prev→next, menghapus Prev→next dari list */
    if(isEmpty(List) == true){
        cout << "List kosong!" << endl;
    } else { //jika list tidak kosong
        if (nodePrev != Nil && nodePrev->next != Nil) { 
            nodeHapus = nodePrev->next;       
            nodePrev->next = nodeHapus->next;  
            nodeHapus->next = Nil;         
            dealokasi(nodeHapus);
        } else {
            cout << "Node sebelumnya (prev) tidak valid!" << endl;
        }
    }
}

//prosedur untuk menampilkan isi list
void printList(linkedlist List) {
    /* I.S. list mungkin kosong
       F.S. jika list tidak kosong menampilkan semua info yang ada pada list */
    if (isEmpty(List)) {
        cout << "List kosong." << endl;
    } else {
        address nodeBantu = List.first;
        while (nodeBantu != Nil) { 
            cout << "Nama : " << nodeBantu->isidata.nama << ", NIM : " << nodeBantu->isidata.nim << ", Usia : " << nodeBantu->isidata.umur << endl;
            nodeBantu = nodeBantu->next;
        }
    }
}

//function untuk menampilkan jumlah node didalam list
int nbList(linkedlist List) {
    /* I.S. list sudah ada
       F.S. menampilkan jumlah node didalam list*/
    int count = 0;
    address nodeBantu = List.first;
    while (nodeBantu != Nil) {
        count++;
        nodeBantu = nodeBantu->next; 
    }
    return count;
}

//prosedur untuk menghapus list (menghapus semua node didalam list)
void deleteList(linkedlist &List){
    /* I.S. list sudah ada
       F.S. menghapus semua node didalam list*/
    address nodeBantu, nodeHapus;
    nodeBantu = List.first;
    while(nodeBantu != Nil){
        nodeHapus = nodeBantu;
        nodeBantu = nodeBantu->next;
        dealokasi(nodeHapus); 
    }
    List.first = Nil; 
    cout << "List sudah terhapus!" << endl;
}
```
**main.cpp**
```C++
#include "list.h"

#include<iostream>
using namespace std;

int main(){
    linkedlist List;
    address nodeA, nodeB, nodeC, nodeD, nodeE = Nil;
    createList(List);

    dataMahasiswa mhs;

    nodeA = alokasi("Dhimas", "2311102151", 20);
    nodeB = alokasi("Arvin", "2211110014", 21);
    nodeC = alokasi("Rizal", "2311110029", 20);
    nodeD = alokasi("Satrio", "2211102173", 21);
    nodeE = alokasi("Joshua", "2311102133", 21);

    insertFirst(List, nodeA);
    insertLast(List, nodeB);
    insertAfter(List, nodeC, nodeA);
    insertAfter(List, nodeD, nodeC);
    insertLast(List, nodeE);

    cout << "--- ISI LIST SETELAH DILAKUKAN INSERT ---" << endl;
    printList(List);

    return 0;
}
```

Program ini membangun sistem linked list mahasiswa yang dapat menyimpan, menambah, menghapus, dan menampilkan data secara dinamis.

## Unguided 

### 1. [Soal]
**Singlylist.h**
```C++
#ifndef SINGLYLIST_H
#define SINGLYLIST_H

#include <iostream>
using namespace std;

typedef int infotype;

struct ElmList {
    infotype info;
    ElmList* next;
};

typedef ElmList* address;

struct List {
    address First;
};

void createList(List &L);
address alokasi(infotype x);
void dealokasi(address P);
void insertFirst(List &L, address P);
void printInfo(List L);

#endif
```

**Singlylist.cpp**
```C++
#include "Singlylist.h"

void createList(List &L) {
    L.First = nullptr;
}

address alokasi(infotype x) {
    address P = new ElmList;
    if (P != nullptr) {
        P->info = x;
        P->next = nullptr;
    }
    return P;
}

void dealokasi(address P) {
    delete P;
}

void insertFirst(List &L, address P) {
    if (P != nullptr) {
        P->next = L.First;
        L.First = P;
    }
}

void printInfo(List L) {
    address P = L.First;
    while (P != nullptr) {
        cout << P->info << " ";
        P = P->next;
    }
    cout << endl;
}
```

**main.cpp**
```C++
#include "Singlylist.h"

int main() {
    List L;
    address P1, P2, P3, P4, P5;

    createList(L);

    P1 = alokasi(2);
    insertFirst(L, P1);

    P2 = alokasi(0);
    insertFirst(L, P2);

    P3 = alokasi(8);
    insertFirst(L, P3);

    P4 = alokasi(12);
    insertFirst(L, P4);

    P5 = alokasi(9);
    insertFirst(L, P5);

    printInfo(L);

    return 0;
}
```

#### Output:
<img width="1230" height="207" alt="image" src="https://github.com/user-attachments/assets/f748c89e-95e8-4c39-a665-ccdbcad2811a" />



Program ini dipakai untuk membuat dan menampilkan daftar data sederhana menggunakan singly linked list. Setiap kali ada data baru, datanya dimasukkan di bagian depan, jadi urutannya jadi terbalik dari saat dimasukkan. Hasil akhirnya, program menampilkan angka 9 12 8 0 2 di layar.

#### Full code Screenshot:
<img width="1912" height="1121" alt="image" src="https://github.com/user-attachments/assets/57fb7fb5-b007-4b72-9bd9-a9b24cdb3227" />

### 2. [Soal]
**Singlylist.h**
```C++
#ifndef SINGLYLIST_H
#define SINGLYLIST_H

#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

struct List {
    Node* head;
};

void createList(List &L);
Node* createNode(int nilai);
void deleteNode(Node* P);
void insertFirst(List &L, Node* P);
void printList(List L);

void deleteFirst(List &L, Node* &P);
void deleteLast(List &L, Node* &P);
void deleteAfter(Node* prec, Node* &P);
int countList(List L);
void deleteAll(List &L);

#endif
```

**Singlylist.cpp**
```C++
#include "Singlylist.h"

void createList(List &L) {
    L.head = nullptr;
}

Node* createNode(int nilai) {
    Node* P = new Node;
    P->data = nilai;
    P->next = nullptr;
    return P;
}

void deleteNode(Node* P) {
    delete P;
}

void insertFirst(List &L, Node* P) {
    if (P != nullptr) {
        P->next = L.head;
        L.head = P;
    }
}

void printList(List L) {
    Node* P = L.head;
    while (P != nullptr) {
        cout << P->data << " ";
        P = P->next;
    }
    cout << endl;
}

void deleteFirst(List &L, Node* &P) {
    if (L.head != nullptr) {
        P = L.head;
        L.head = P->next;
        P->next = nullptr;
    } else {
        P = nullptr;
    }
}

void deleteLast(List &L, Node* &P) {
    if (L.head == nullptr) {
        P = nullptr;
    } else if (L.head->next == nullptr) {
        P = L.head;
        L.head = nullptr;
    } else {
        Node* Q = L.head;
        while (Q->next->next != nullptr) {
            Q = Q->next;
        }
        P = Q->next;
        Q->next = nullptr;
    }
}

void deleteAfter(Node* prec, Node* &P) {
    if (prec != nullptr && prec->next != nullptr) {
        P = prec->next;
        prec->next = P->next;
        P->next = nullptr;
    } else {
        P = nullptr;
    }
}

int countList(List L) {
    int jumlah = 0;
    Node* P = L.head;
    while (P != nullptr) {
        jumlah++;
        P = P->next;
    }
    return jumlah;
}

void deleteAll(List &L) {
    Node* P;
    while (L.head != nullptr) {
        deleteFirst(L, P);
        deleteNode(P);
    }
}
```

**main.cpp**
```C++
#include "Singlylist.h"

int main() {
    List L;
    Node *P, *hapus;

    createList(L);

    insertFirst(L, createNode(2));
    insertFirst(L, createNode(0));
    insertFirst(L, createNode(8));
    insertFirst(L, createNode(12));
    insertFirst(L, createNode(9));

    deleteFirst(L, hapus);
    deleteNode(hapus);

    deleteLast(L, hapus);
    deleteNode(hapus);

    Node* prec = L.head;
    deleteAfter(prec, hapus);
    deleteNode(hapus);

    printList(L);
    cout << "Jumlah node : " << countList(L) << endl;

    deleteAll(L);
    cout << "\n- List Berhasil Terhapus -" << endl;
    cout << "Jumlah node : " << countList(L) << endl;

    return 0;
}
```

#### Output:
<img width="1235" height="311" alt="image" src="https://github.com/user-attachments/assets/36a32c4e-b103-40d6-8d5f-a2e55fe1e1d8" />



Kesimpulannya, program ini digunakan untuk menghapus data dari sebuah **linked list** satu per satu. Pertama, data paling depan (9) dihapus, lalu data paling belakang (2), dan setelah itu data di tengah (8). Hasil akhirnya, list hanya tersisa **12 dan 0**, kemudian semua data dihapus sampai list benar-benar kosong.

#### Full code Screenshot:
<img width="1919" height="1126" alt="image" src="https://github.com/user-attachments/assets/3dee54d9-6833-4194-8bab-a354e4230c11" />




## Kesimpulan
Kesimpulannya, program ini dipakai untuk menambah dan menghapus data secara fleksibel dengan bantuan pointer. Data tersimpan dalam bentuk rantai (node-node) yang saling terhubung, dan bisa dihapus kapan saja. Setelah semua proses selesai, list jadi kosong, menandakan data berhasil dikelola tanpa perlu ukuran tetap seperti array.

## Referensi
Materi Modul 4, Wijoyo, A., Prasetiyo, A. R., Salsabila, A. A., Nife, K., Murni, & Nadapdap, P. B. (2024). Evaluasi Efisiensi Struktur Data Linked List pada Implementasi Sistem Antrian. Jurnal Riset Informatika dan Inovasi, 1(12), 1–9.
