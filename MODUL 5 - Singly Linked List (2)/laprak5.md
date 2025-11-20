  # <h1 align="center">Laporan Praktikum Modul Singly Linked List (Bagian Kedua)</h1>
<p align="center">Amelia Sofiana Makharomi</p>

## Dasar Teori

Singly Linked List adalah struktur data dinamis yang terdiri dari kumpulan node, di mana setiap node menyimpan data (info) dan alamat node berikutnya (next). Struktur ini memungkinkan penambahan dan penghapusan elemen tanpa perlu menggeser data lain seperti pada array. Operasi dasarnya meliputi pembuatan list, pengecekan kosong, penambahan, penghapusan, pencarian data, serta pencetakan isi list. Proses pencarian dilakukan dengan menelusuri tiap node hingga data ditemukan. Semua fungsi tersebut biasanya disusun dalam bentuk Abstract Data Type (ADT) menggunakan bahasa C/C++. Dengan pointer, linked list dapat menyesuaikan ukuran secara fleksibel dan efisien untuk pengelolaan data dinamis.

## Guided 

### 1. [Singly Linked List (Bagian Kedua)]
*listBuah.h*
```C++
//Header guard digunakan untuk mencegah file header yg sama

#ifndef LISTBUAH_H
#define LISTBUAH_H
#define Nil NULL 

#include <iostream>
using namespace std;

// deklarasi isi data struct mahasiswa
struct buah{
    string nama;
    int jumlah;
    float harga;
};

typedef buah dataBuah; //memberikan nama alias dataMahasiswa untuk struct mahasiswa

typedef struct node *address; //mendefinisikan alias address sebagai pointer ke struct node

struct node{ //node untuk isi linked listnya, isi setiap node adalah data & pointer next
    dataBuah isidata;
    address next;
};

struct linkedlist{//ini linked listnya 
    address first;
};

//semua function &prosedur yg akan dipakai 
//materi modul 4
bool isEmpty(linkedlist List);
void createList(linkedlist &List);
address alokasi(string nama, int jumlah, float harga);
void dealokasi(address &node);
void printList(linkedlist List);
void insertFirst(linkedlist &List, address nodebaru);
void insertAfter(linkedlist &List, address nodebaru, address prev);
void insertLast(linkedlist &List, address nodebaru);
void delFirst(linkedlist &List);
void delLast(linkedlist &List);
void delAfter(linkedlist &list, address nodeHapus, address nodePrev);
int nbList(linkedlist List);
void deleteList(linkedlist &List);

//materi modul 5(part 1 - update)
void updateFirst(linkedlist List);
void updateLast(linkedlist List);
void updateAfter(linkedlist List, address prev);

//materi modul 5(part 2 - searching)
void FindNodeByData(linkedlist list, string data);
void FindNodeByAddress(linkedlist list, address node);
void FindNodeByRange(linkedlist list, float hargaAwal, float hargaAkhir);

#endif
```
*listBuah.cpp*
```C++
#include "listBuah.h"
#include <iostream>
using namespace std;

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
    List.first = Nil;
}

//pembuatan node baru dengan menerapkan manajemen memori
address alokasi(string nama, int jumlah, float harga) { 
    address nodeBaru = new node; 
    nodeBaru->isidata.nama = nama;
    nodeBaru->isidata.jumlah = jumlah; 
    nodeBaru->isidata.harga = harga;
    nodeBaru->next = Nil;
    return nodeBaru;
}

//penghapusan node dengan menerapkan manajemen memori
void dealokasi(address &node) {
    node->next = Nil;
    delete node;
}

//prosedur-prosedur untuk insert / menambahkan node baru kedalam list
void insertFirst(linkedlist &List, address nodeBaru) {
    nodeBaru->next = List.first; 
    List.first = nodeBaru;
}

void insertAfter(linkedlist &List, address nodeBaru, address Prev) {
    if (Prev != Nil) {
        nodeBaru->next = Prev->next;
        Prev->next = nodeBaru;
    } else {
        cout << "Node sebelumnya tidak valid!" << endl;
    }
}

void insertLast(linkedlist &List, address nodeBaru) {
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
    address nodeHapus;
    if (isEmpty(List) == false) {
        nodeHapus = List.first;
        List.first = List.first->next;
        nodeHapus->next = Nil;
        dealokasi(nodeHapus);
        cout << "Node pertama berhasil terhapus!" << endl;
    } else {
        cout << "List kosong!" << endl;
    }
}

void delLast(linkedlist &List){
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
        cout << "Node terakhir berhasil terhapus!" << endl;
    } else {
        cout << "list kosong" << endl;
    }
}

void delAfter(linkedlist &List, address nodeHapus, address nodePrev){
    if(isEmpty(List) == true){
        cout << "List kosong!" << endl;
    } else { //jika list tidak kosong
        if (nodePrev != Nil && nodePrev->next != Nil) { 
            nodeHapus = nodePrev->next;       
            nodePrev->next = nodeHapus->next;  
            nodeHapus->next = Nil;         
            dealokasi(nodeHapus);
            cout << "Node setelah node " << nodePrev->isidata.nama << " berhasil terhapus!" << endl;
        } else {
            cout << "Node sebelumnya (prev) tidak valid!" << endl;
        }
    }
}

//prosedur untuk menampilkan isi list
void printList(linkedlist List) {
    if (isEmpty(List)) {
        cout << "List kosong." << endl;
    } else {
        address nodeBantu = List.first;
        while (nodeBantu != Nil) { 
            cout << "Nama Buah : " << nodeBantu->isidata.nama << ", Jumlah : " << nodeBantu->isidata.jumlah << ", Harga : " << nodeBantu->isidata.harga << endl;
            nodeBantu = nodeBantu->next;
        }
    }
}

//function untuk menampilkan jumlah node didalam list
int nbList(linkedlist List) {
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
    address nodeBantu, nodeHapus;
    nodeBantu = List.first;
    while(nodeBantu != Nil){
        nodeHapus = nodeBantu;
        nodeBantu = nodeBantu->next;
        dealokasi(nodeHapus); 
    }
    List.first = Nil; 
    cout << "List berhasil terhapus!" << endl;
}

/*----- MATERI PERTEMUAN 5 - SINGLY LINKED LIST (BAGIAN KEDUA) - PART 1 (UPDATE) -----*/
//prosedur-prosedur untuk melakukan update data node
void updateFirst(linkedlist List){ 
    if(isEmpty(List) == true){
        cout << "List kosong!" << endl;
    } else {
        cout << "Masukkan update data node pertama : " << endl;
        cout << "Nama buah : ";
        cin >> List.first->isidata.nama;
        cout << "Jumlah : ";
        cin >> List.first->isidata.jumlah;
        cout << "Harga : ";
        cin >> List.first->isidata.harga;
        cout << "Data Berhasil Diupdate!" << endl;
        cout << endl;
    }
}

void updateLast(linkedlist List){
    if (isEmpty(List) == true) {
        cout << "List Kosong!" << endl;
    } else {
        address nodeBantu = List.first; 
        while (nodeBantu->next != Nil) { //akan iterasi terus
            nodeBantu = nodeBantu->next; // bisa diganti nodeBantu=nodeAkhir
        }
        cout << "masukkan update data node terakhir : " << endl;
        cout << "Nama buah : ";
        cin >> nodeBantu->isidata.nama;
        cout << "Jumlah : ";
        cin >> nodeBantu->isidata.jumlah;
        cout << "Harga : ";
        cin >> nodeBantu->isidata.harga;
        cout << "Data Berhasil Diupdate!" << endl;
        cout << endl;
    }
}

void updateAfter(linkedlist List, address nodePrev){ //node diantara (bukan akhir atau awal) pointer mengarah ke nil
    if(isEmpty(List) == true){
        cout << "List kosong!" << endl;
    } else {
        if (nodePrev != Nil && nodePrev->next != Nil){ //next tidak mengarah ke nil
            address nodeBantu = nodePrev->next; //mengubah prosesnya
            cout << "masukkan update data node setelah node " << nodePrev->isidata.nama << " : " << endl;
            cout << "Nama buah : ";
            cin >> nodeBantu->isidata.nama;
            cout << "Jumlah : ";
            cin >> nodeBantu->isidata.jumlah;
            cout << "Harga : ";
            cin >> nodeBantu->isidata.harga;
            cout << "Data Berhasil Diupdate!" << endl;
            cout << endl;
        } else {
            cout << "Node sebelumnya (prev) tidak valid!" << endl;
        }
    }
}

/*----- MATERI PERTEMUAN 5 - SINGLY LINKED LIST (BAGIAN KEDUA) - PART 2 (SEARCHING) -----*/
//prosedur-prosedur untuk searching data
//prosedur untuk mencari node berdasarkan data
void FindNodeByData(linkedlist list, string data){
    if(isEmpty(list) == true){
        cout << "List kosong!" << endl;
    } else {
        address nodeBantu = list.first;
        int posisi = 0;
        bool found = false;
        while(nodeBantu != Nil){
            posisi++;
            if(nodeBantu->isidata.nama == data){
                cout << "Data " << data << " ditemukan pada posisi ke-" << posisi << "!" << endl;
                cout << "Nama Buah : " << nodeBantu->isidata.nama << ", Jumlah : " << nodeBantu->isidata.jumlah << ", Harga : " << nodeBantu->isidata.harga << endl;
                found = true;
                break;
            }
            nodeBantu = nodeBantu->next;
        }
        if(found == false){
            cout << "Node dengan data " << data << " tidak ditemukan!" << endl;
        }
    }
    cout << endl;
}

//prosedur untuk mencari node berdasarkan alamat node
void FindNodeByAddress(linkedlist list, address node) {
    if(isEmpty(list) == true) {
        cout << "List kosong!" << endl;
    } else {
        address nodeBantu = list.first;
        int posisi = 0;
        bool found = false;
        while (nodeBantu != Nil) {
            posisi++;
            if(nodeBantu == node) {
                cout << "Node ditemukan pada posisi ke-" << posisi << "!" << endl;
                cout << "Alamat node : " << nodeBantu << endl;
                cout << "Nama Buah : " << nodeBantu->isidata.nama << ", Jumlah : " << nodeBantu->isidata.jumlah << ", Harga : " << nodeBantu->isidata.harga << endl;
                found = true;
                break;
            }
            nodeBantu = nodeBantu->next;
        }
        if(found == false) {
            cout << "Node dengan alamat " << node << " tidak ditemukan dalam list!" << endl;
        }
    }
    cout << endl;
}

//prosedur untuk mencari node berdasarkan range data (range harga)
void FindNodeByRange(linkedlist list, float hargaAwal, float hargaAkhir) {
    if(isEmpty(list) == true) {
        cout << "List kosong!" << endl;
    } else {
        address nodeBantu = list.first;
        int posisi = 0;
        bool found = false;
        cout << "--- Buah dalam range harga " << hargaAwal << " - " << hargaAkhir << " ---" << endl;
        cout << "-------------------------------------------" << endl;
        while (nodeBantu != Nil) {
            posisi++;
            float harga = nodeBantu->isidata.harga;
            if(harga >= hargaAwal && harga <= hargaAkhir) {
                cout << "Data ditemukan pada posisi ke-" << posisi << " :" << endl;
                cout << "Nama Buah : " << nodeBantu->isidata.nama << ", Jumlah : " << nodeBantu->isidata.jumlah << ", Harga : " << nodeBantu->isidata.harga << endl;
                cout << "-------------------------------------------" << endl;
                found = true;
            }
            nodeBantu = nodeBantu->next;
        }
        if(found == false) {
            cout << "Tidak ada data buah dalam range harga tersebut!" << endl;
            cout << "-------------------------------------------" << endl;
        }
    }
    cout << endl;
}

```
*main.cpp*
```C++
#include "listBuah.h"

#include<iostream>
using namespace std;

int main(){
    linkedlist List;
    address nodeA, nodeB, nodeC, nodeD, nodeE = Nil;
    createList(List);

    dataBuah dtBuah;

    nodeA = alokasi("Jeruk", 100, 3000);
    nodeB = alokasi("Apel", 75, 4000);
    nodeC = alokasi("Pir", 87, 5000);
    nodeD = alokasi("Semangka", 43, 11500);
    nodeE = alokasi("Durian", 15, 31450);

    insertFirst(List, nodeA);
    insertLast(List, nodeB);
    insertAfter(List, nodeC, nodeA);
    insertAfter(List, nodeD, nodeC);
    insertLast(List, nodeE);

    cout << "--- ISI LIST SETELAH DILAKUKAN INSERT ---" << endl;
    printList(List);
    cout << "Jumlah node : " << nbList(List) << endl;
    cout << endl;

   updateFirst(List);
   updateLast(List);
   updateAfter(List, nodeD);

    cout << "--- ISI LIST SETELAH DILAKUKAN UPDATE ---" << endl;
    printList(List);
    cout << "Jumlah node : " << nbList(List) << endl;
    cout << endl;

    FindNodeByData(List, "Kelapa");
    FindNodeByAddress(List, nodeC);
    FindNodeByRange(List, 5000, 10000);

    delFirst(List);
    delLast(List);
    delAfter(List, nodeD, nodeC);

    cout << "--- ISI LIST SETELAH DILAKUKAN DELETE ---" << endl;
    printList(List);
    cout << "jumlah node : " << nbList(List) << endl;
    cout << endl;

    deleteList(List);
    cout << "--- ISI LIST SETELAH DILAKUKAN HAPUS LIST ---" << endl;
    printList(List);
    cout << "jumlah node : " << nbList(List) << endl;
    cout << endl;

    return 0;
}
```

## Unguided 

### 1. [Soal]
*singlylist.h*
```C++
#ifndef SINGLYLIST_H
#define SINGLYLIST_H
#include <iostream>
using namespace std;

struct Node {       
    int info;       
    Node* next;     
};
struct List {       
    Node* first;    
};
void createList(List &L);
Node* alokasi(int x);
void insertFirst(List &L, Node* P);
void printInfo(List L);

#endif
```

*singlylist.cpp*
```C++
#include "Singlylist.h"

void createList(List &L) {          
    L.first = NULL;
}
Node* alokasi(int x) {              
    return new Node{x, NULL};
}
void insertFirst(List &L, Node* P) { 
    P->next = L.first;
    L.first = P;
}
void printInfo(List L) {             
    Node* P = L.first;
    while (P != NULL) {
        cout << P->info << " ";
        P = P->next;
    }
    cout << endl;
}
```

*main.cpp*
```C++
#include "Singlylist.h"

int main() {
    List L; createList(L);           

    insertFirst(L, alokasi(2));
    insertFirst(L, alokasi(0));
    insertFirst(L, alokasi(8));
    insertFirst(L, alokasi(12));
    insertFirst(L, alokasi(9));

    printInfo(L);                    
    return 0;
}
```
#### Output:
<img width="822" height="72" alt="{90998F02-F49C-4D68-8003-106F0BA53003}" src="https://github.com/user-attachments/assets/0bfafcc1-d3bb-4e8e-ab1a-1b047109a41f" />

Program ini menerapkan ADT Singly Linked List, yaitu struktur data dinamis yang terdiri dari node berisi data (info) dan pointer ke node berikutnya (next). Fungsi createList() membuat list kosong, alokasi() membuat node baru, insertFirst() menambah node di awal list, dan printInfo() menampilkan seluruh isi list.

#### Full code Screenshot:
<img width="1920" height="1080" alt="{3241EBED-8219-471E-8248-6DF13FD399C4}" src="https://github.com/user-attachments/assets/97f84ca4-8d8d-45f8-af3a-037b85ba5156" />
<img width="1920" height="1080" alt="{FE869002-4AC8-4837-89EF-90F85FCCCB57}" src="https://github.com/user-attachments/assets/115b2138-c9fc-4cd4-a3f7-bdaed2aaa7f2" />
<img width="1920" height="1080" alt="{302B9B76-925F-4A76-A411-4F8095775919}" src="https://github.com/user-attachments/assets/ba6aa7ae-a32d-4da1-9785-db6bbcfdf19b" />

### 2. [Soal]
*singlylist.h*
```C++
#ifndef SINGLYLIST_H
#define SINGLYLIST_H
#include <iostream>
using namespace std;

struct Node {
    int info;
    Node* next;
};
struct List {
    Node* first;
};
void createList(List &L);
Node* alokasi(int x);
void insertFirst(List &L, Node* P);
void printInfo(List L);
Node* findElm(List L, int x);   

#endif
```

*Singlylist.cpp*
```C++
#include "Singlylist.h"

void createList(List &L) { L.first = NULL; }

Node* alokasi(int x) { return new Node{x, NULL}; }

void insertFirst(List &L, Node* P) {
    P->next = L.first;
    L.first = P;
}
void printInfo(List L) {
    Node* P = L.first;
    while (P != NULL) {
        cout << P->info << " ";
        P = P->next;
    }
    cout << endl;
}
Node* findElm(List L, int x) {
    Node* P = L.first;
    while (P != NULL) {
        if (P->info == x) {
            return P; 
        }
        P = P->next;
    }
    return NULL; 
}
```

*main.cpp*
```C++
#include "Singlylist.h"

int main() {
    List L;
    createList(L);

    insertFirst(L, alokasi(2));
    insertFirst(L, alokasi(0));
    insertFirst(L, alokasi(8));
    insertFirst(L, alokasi(12));
    insertFirst(L, alokasi(9));

    printInfo(L);   

    int cari = 8;   
    Node* hasil = findElm(L, cari);

    if (hasil != NULL)
        cout << cari << " ditemukan dalam list" << endl;
    else
        cout << cari << " tidak ditemukan dalam list" << endl;

    return 0;
}
```
#### Output:
<img width="822" height="81" alt="{521E69A7-1347-4703-BB41-1D0B5A8482E3}" src="https://github.com/user-attachments/assets/7e5da831-936b-4c81-943d-977af342c655" />

Program ini menerapkan konsep ADT Singly Linked List, di mana setiap node menyimpan data dan alamat node berikutnya. Fungsi createList() membuat list kosong, alokasi() menyiapkan node baru, insertFirst() menambahkan elemen di awal list, dan printInfo() menampilkan seluruh isi list. Fungsi tambahan findElm() digunakan untuk mencari elemen tertentu dengan menelusuri setiap node.

#### Full code Screenshot:
<img width="1920" height="1080" alt="{D4970092-5B84-4B97-99C2-6879F0EDD219}" src="https://github.com/user-attachments/assets/bc1bc22a-7f5d-492e-9ed6-22a824ebe594" />
<img width="1920" height="1080" alt="{10661890-DA9C-4A19-87FB-4B231EEFFE9A}" src="https://github.com/user-attachments/assets/90dc6c7e-93a3-48e5-a9a9-881d82646178" />
<img width="1920" height="1080" alt="{70E3E655-676C-4F3D-95B8-70483F283DD2}" src="https://github.com/user-attachments/assets/4a773b5e-9806-4a9c-8ca6-6a66906b6062" />

### 3. [Soal]
*singlylist.h*
```C++
#ifndef SINGLYLIST_H
#define SINGLYLIST_H
#include <iostream>
using namespace std;

struct Node {
    int info;
    Node* next;
};
struct List {
    Node* first;
};
void createList(List &L);
Node* alokasi(int x);
void insertFirst(List &L, Node* P);
void printInfo(List L);
Node* findElm(List L, int x);
int totalInfo(List L);     

#endif

```
*singlylist.cpp*
```C++
#include "singlylist.h"

void createList(List &L) { 
    L.first = NULL; 
}
Node* alokasi(int x) { 
    return new Node{x, NULL}; 
}
void insertFirst(List &L, Node* P) {
    P->next = L.first;
    L.first = P;
}
void printInfo(List L) {
    Node* P = L.first;
    while (P != NULL) {
        cout << P->info << " ";
        P = P->next;
    }
    cout << endl;
}
Node* findElm(List L, int x) {
    Node* P = L.first;
    while (P != NULL) {
        if (P->info == x)
            return P;
        P = P->next;
    }
    return NULL;
}
int totalInfo(List L) {
    int total = 0;
    Node* P = L.first;
    while (P != NULL) {
        total += P->info;
        P = P->next;
    }
    return total;
}
```
*main.cpp*
```C++
#include "singlylist.h"

int main() {
    List L;
    createList(L);

    insertFirst(L, alokasi(2));
    insertFirst(L, alokasi(0));
    insertFirst(L, alokasi(8));
    insertFirst(L, alokasi(12));
    insertFirst(L, alokasi(9));

    int total = totalInfo(L); 
    cout << "Total info dari kelima elemen adalah " << total << endl;

    return 0;
}
```
#### Output:
<img width="818" height="58" alt="{6640C204-507A-4305-A3D7-0B71A54D705F}" src="https://github.com/user-attachments/assets/1c0b1923-f2ed-4855-a201-2f05f4e5a63e" />

Fungsi totalInfo() digunakan untuk menjumlahkan seluruh nilai data (info) dari setiap node dalam linked list. Proses dilakukan dengan menelusuri list dari node pertama hingga terakhir sambil menambahkan setiap nilai ke variabel total. Pada data 9, 12, 8, 0, dan 2, hasil penjumlahannya adalah 31, sehingga ditampilkan pesan “Total info dari kelima elemen adalah 31”

#### Full code Screenshot:
<img width="1920" height="1080" alt="{494372E2-B2D0-4D0F-83AF-2D656D4DDEA3}" src="https://github.com/user-attachments/assets/3efa6bd9-897a-46d2-8fda-6cb4d25885da" />
<img width="1920" height="1080" alt="{D3F906EB-48A4-4010-B54C-1E4BAFDC2A41}" src="https://github.com/user-attachments/assets/36a06e34-2298-45a6-9cec-8b04a102fd93" />
<img width="1920" height="1080" alt="{C79C14A0-9550-49DE-9A37-4862DB10EA27}" src="https://github.com/user-attachments/assets/d983a93f-8ea6-41a0-9c6f-6ea9c8045400" />


## Kesimpulan
Singly Linked List adalah struktur data dinamis yang tersusun dari node berisi data dan pointer ke elemen berikutnya. Pada soal pertama, dilakukan pembuatan dan penambahan elemen menggunakan createList(), alokasi(), dan insertFirst(), menghasilkan urutan data 9, 12, 8, 0, 2. Soal kedua menerapkan fungsi findElm() untuk mencari nilai tertentu, dan data 8 berhasil ditemukan. Sedangkan soal ketiga menggunakan totalInfo() untuk menghitung jumlah seluruh elemen, dengan hasil 31.
Ketiga soal ini menunjukkan penerapan dasar operasi linked list, mulai dari pembentukan, pencarian, hingga pengolahan data

## Referensi
1. Modul 5 Struktur Data SE Ganjil-2526
2. GeeksforGeeks — Program to Implement Singly Linked List in C++ Using Class
3. TutorialsPoint — C++ Program to Implement Singly Linked List


