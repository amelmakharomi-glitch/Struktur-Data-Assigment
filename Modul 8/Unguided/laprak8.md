

  # <h1 align="center">Laporan Praktikum Modul Queue</h1>
<p align="center">Amelia Sofiana Makharomi</p>

## Dasar Teori

Queue merupakan struktur data yang dapat diumpamakan seperti sebuah antrean, yang prinsip dasarnya adalah FIFO (First In, First Out), di mana proses yang pertama masuk akan diakses terlebih dahulu. Dalam implementasi Queue, dapat menggunakan tipe data array (tabel) atau linked list (pointer). Jika menggunakan linked list, operasi penyisipan (Enqueue) selalu dilakukan pada bagian Tail (belakang list) dan proses pengambilan (Delete/Dequeue) selalu dilakukan pada bagian Head (depan list). Sementara itu, representasi tabel berbeda dari pointer karena memiliki jumlah antrean yang terbatas dan tidak memerlukan manajemen memori. Representasi tabel memiliki tiga alternatif utama, mulai dari Alternatif 1 (Head diam) dan Alternatif

## Guided

### 1. [Queue]
*queue.h*
```C++
#ifndef QUEUE_H
#define QUEUE_H

#include <iostream>
#include <string>
using namespace std;

struct Node {
    string nama;
    Node* next;
};

struct queue {
    Node* head;
    Node* tail;
};

void CreateQueue(queue &Q);
bool isEmpty(queue Q);
bool isFull(queue Q);
void enQueue(queue &Q, const string &nama);
void deQueue(queue &Q);
void viewQueue(queue Q);
void clearQueue(queue &Q);

#n

void deQueue(queue &Q) {
    if (isEmpty(Q)) {
        cout << "Queue kosong!" << endl;
        return;
    }
    Node* hapus = Q.head;
    cout << "Menghapus data " << hapus->nama << "..." << endl;
    Q.head = Q.head->next;
    if (Q.head == nullptr) {
        Q.tail = nullptr;
    }
    delete hapus;
}

void viewQueue(queue Q) {
    if (isEmpty(Q)) {
        cout << "Queue kosong!" << endl;
        return;
    }
    int i = 1;
    for (Node* p = Q.hemad; p != nullptr; p = p->next) {
        cout << i++ << ". " << p->nama << endl;
    }
}

void clearQueue(queue &Q) {
    while (!isEmpty(Q)) {
        deQueue(Q);
    }
}


```
*queue.cpp*
```C++
#include "queue.h"
using namespace std;

void CreateQueue(queue &Q) {
    Q.head = nullptr;
    Q.tail = nullptr;
}

bool isEmpty(queue Q) {
    return Q.head == nullptr;
}

bool isFull(queue) {
    return false;
}

void enQueue(queue &Q, const string &nama) {
    Node* baru = new Node{nama, nullptr};
    if (isEmpty(Q)) {
        Q.head = Q.tail = baru;
    } else {
        Q.tail->next = baru;
        Q.tail = baru;
    }
    cout << "nama " << nama << " berhasil ditambahkan kedalam queue!" << endl;
}

void deQueue(queue &Q) {
    if (isEmpty(Q)) {
        cout << "Queue kosong!" << endl;
        return;
    }
    Node* hapus = Q.head;
    cout << "Menghapus data " << hapus->nama << "..." << endl;
    Q.head = Q.head->next;
    if (Q.head == nullptr) { 
        Q.tail = nullptr;
    }
    delete hapus;
}

void viewQueue(queue Q) { //buat looping (katanya)
    if (isEmpty(Q)) {
        cout << "Queue kosong!" << endl;
        return;
    }
    int i = 1;
    for (Node* p = Q.head; p != nullptr; p = p->next) {
        cout << i++ << ". " << p->nama << endl;
    }
}

void clearQueue(queue &Q) {
    while (!isEmpty(Q)) { 
        deQueue(Q); //selama q ga kosong
    }
}
```
*main.cpp*
```C++
#include "queue.h"
#include <iostream>
using namespace std;

int main() {
    queue Q;
    CreateQueue(Q);

    enQueue(Q, "dhimas");
    enQueue(Q, "Arvin");
    enQueue(Q, "Rizal");
    enQueue(Q, "Hafizh");
    enQueue(Q, "Fathur");
    enQueue(Q, "Atha");
    cout << endl;

    cout << "--- Isi Queue Setelah enQueue ---" << endl;
    viewQueue(Q);

    deQueue(Q);
    deQueue(Q);
    deQueue(Q);
    deQueue(Q);
    cout << endl;

    cout << "--- Isi Queue Setelah deQueue ---" << endl;
    viewQueue(Q);

    clearQueue(Q);
    return 0;
}
```

## Unguided 

### 1. [Soal]
*queue.h*
```C++
#ifndef ANTREAM_H
#define ANTREAM_H

#include <iostream>

typedef int TipeData;

#define MAX_ELEMEN 5 

struct Antrean {
    TipeData data[MAX_ELEMEN]; 
    int depan;                
    int belakang;              
};
void buatAntreanKosong(Antrean &Q);
bool apaKosong(Antrean Q);
bool apaPenuh(Antrean Q);
void masukkan(Antrean &Q, TipeData nilaiBaru);
TipeData keluarkan(Antrean &Q);
void tampilkanData(Antrean Q);

#endif
```
*queue.cpp*
```C++
#include "queue.h"
#include <iostream>
#include <iomanip>

using namespace std;

void buatAntreanKosong(Antrean &Q) {
    Q.depan = -1;
    Q.belakang = -1;
}
bool apaKosong(Antrean Q) {
    return (Q.depan == -1 && Q.belakang == -1);
}
bool apaPenuh(Antrean Q) {
    return (Q.belakang == MAX_ELEMEN - 1);
}
void masukkan(Antrean &Q, TipeData nilaiBaru) {
    if (apaPenuh(Q)) {
        cout << "Antrean Penuh! Data " << nilaiBaru << " gagal dimasukkan." << endl;
        return;
    }

    if (apaKosong(Q)) {
        Q.depan = 0;
        Q.belakang = 0;
    } else {
        Q.belakang++;
    }
    Q.data[Q.belakang] = nilaiBaru;
}
TipeData keluarkan(Antrean &Q) {
    TipeData nilaiDihapus = -999; 

    if (apaKosong(Q)) {
        cout << "Antrean Kosong!" << endl;
        return nilaiDihapus;
    }
    nilaiDihapus = Q.data[Q.depan];

    for (int i = Q.depan; i < Q.belakang; i++) {
        Q.data[i] = Q.data[i + 1];
    }
    Q.belakang--;

    if (Q.belakang == -1) { 
        buatAntreanKosong(Q); 
    }

    return nilaiDihapus;
}
void tampilkanData(Antrean Q) {
    cout << setw(2) << Q.depan << " - " << setw(2) << Q.belakang << " : ";

    if (apaKosong(Q)) {
        cout << "empty queue" << endl;
    } else {
        for (int i = Q.depan; i <= Q.belakang; i++) {
            cout << Q.data[i];
            if (i < Q.belakang) {
                cout << " "; 
            }
        }
        cout << endl;
    }
}
```
*main.cpp*
```C++
#include "queue.h" 
#include <iostream>

using namespace std;

int main() {
    cout << "Hello World!" << endl;

    Antrean Q;
    buatAntreanKosong(Q);

    cout << "-------------" << endl;
    cout << " H - T : Queue Info" << endl;
    cout << "-------------" << endl;

    tampilkanData(Q); 
    masukkan(Q, 5); tampilkanData(Q); 
    masukkan(Q, 2); tampilkanData(Q); 
    masukkan(Q, 7); tampilkanData(Q); 
    keluarkan(Q); tampilkanData(Q); 
    masukkan(Q, 4); tampilkanData(Q);
    keluarkan(Q); tampilkanData(Q); 
    keluarkan(Q); tampilkanData(Q); 
    keluarkan(Q); tampilkanData(Q); 

    return 0;
}
```
#### Output:
<img width="1018" height="328" alt="{DF3549AD-931A-43A5-885E-1AFB06061E78}" src="https://github.com/user-attachments/assets/e7d8e1fd-c112-4da4-8d54-41d2e693b8b3" />

Program ini mensimulasikan Queue yang diimplementasikan menggunakan array berukuran tetap, sesuai prinsip FIFO. Ia secara spesifik menggunakan mekanisme Alternatif 1 di mana Head (depan) selalu berada di indeks 0. Konsekuensi pentingnya adalah, setiap kali elemen keluar (Dequeue), program harus menggeser seluruh data yang tersisa satu langkah ke depan. Hal ini membuat operasi Dequeue menjadi tidak efisien karena memerlukan pemindahan data secara massal.

#### Full code Screenshot:
<img width="1920" height="1080" alt="{87A6A14F-13AB-4C13-8981-633E5FE2E765}" src="https://github.com/user-attachments/assets/37970cd2-c16b-412c-b8a6-f44c62dc6294" />
<img width="1920" height="1080" alt="{166E4210-E519-473F-9ED5-27791BC1F81E}" src="https://github.com/user-attachments/assets/6e892220-cf8b-4e87-834d-2272b4db8e59" />
<img width="1920" height="1080" alt="{24A14BC0-8DDB-4E03-A615-D5494B078C67}" src="https://github.com/user-attachments/assets/52e1750d-74e5-4471-a469-cfe93ef52fc9" />


### 2. [Soal]
*queue.h*
```C++
#ifndef ANTREAM_H
#define ANTREAM_H

#include <iostream>

typedef int TipeData;

#define MAX_ELEMEN 5 

struct Antrean {
    TipeData data[MAX_ELEMEN]; 
    int depan;                
    int belakang;              
};
void buatAntreanKosong(Antrean &Q);
bool apaKosong(Antrean Q);
bool apaPenuh(Antrean Q);
void masukkan(Antrean &Q, TipeData nilaiBaru);
TipeData keluarkan(Antrean &Q);
void tampilkanData(Antrean Q);

#endif
```
*queue.cpp*
```C++
#include "queue.h"
#include <iostream>
#include <iomanip>

using namespace std;

void buatAntreanKosong(Antrean &Q) {
    Q.depan = -1;
    Q.belakang = -1;
}
bool apaKosong(Antrean Q) {
    return (Q.depan == -1 && Q.belakang == -1);
}
bool apaPenuh(Antrean Q) {
    return (Q.belakang == MAX_ELEMEN - 1);
}
void geserElemen(Antrean &Q) {
    int jumlahElemen = Q.belakang - Q.depan + 1;
    
    for (int i = 0; i < jumlahElemen; i++) {
        Q.data[i] = Q.data[Q.depan + i];
    }
    Q.depan = 0;
    Q.belakang = jumlahElemen - 1;
    cout << " (GESER DATA) "; 
}
void masukkan(Antrean &Q, TipeData nilaiBaru) {
 
    if (apaPenuh(Q)) {
        if (Q.depan > 0) {
            geserElemen(Q);
        } else {
            cout << "Antrian Penuh Sesungguhnya! Data " << nilaiBaru << " gagal dimasukkan." << endl;
            return;
        }
    }
    if (apaKosong(Q)) {
        Q.depan = 0;
        Q.belakang = 0;
    } else {
        Q.belakang++;
    }
    Q.data[Q.belakang] = nilaiBaru;
}
TipeData keluarkan(Antrean &Q) {
    TipeData nilaiDihapus = -999; 

    if (apaKosong(Q)) {
        cout << "Antrian Kosong!" << endl;
        return nilaiDihapus;
    }
    nilaiDihapus = Q.data[Q.depan];
    if (Q.depan == Q.belakang) {
        buatAntreanKosong(Q); 
    } else {
        Q.depan++;
    }

    return nilaiDihapus;
}
void tampilkanData(Antrean Q) {
    cout << setw(2) << Q.depan << " - " << setw(2) << Q.belakang << " : ";

    if (apaKosong(Q)) {
        cout << "empty queue" << endl;
    } else {
        for (int i = Q.depan; i <= Q.belakang; i++) {
            cout << Q.data[i];
            if (i < Q.belakang) {
                cout << " "; 
            }
        }
        cout << endl;
    }
}
```
*main.cpp*
```C++
#include "queue.h" 
#include <iostream>

using namespace std;

int main() {
    cout << "UJI ALTERNATIF 2 (Head/Tail Bergerak)" << endl;

    Antrean Q;
    buatAntreanKosong(Q);

    cout << "-----------------------------------" << endl;
    cout << " H - T : Queue Info" << endl;
    cout << "-----------------------------------" << endl;

    masukkan(Q, 10); 
    masukkan(Q, 20); 
    masukkan(Q, 30); 
    masukkan(Q, 40);
    masukkan(Q, 50); tampilkanData(Q); 

    cout << "DEQUEUE 3x (H berubah) >>" << endl;
    keluarkan(Q); tampilkanData(Q); 
    keluarkan(Q); tampilkanData(Q); 
    keluarkan(Q); tampilkanData(Q); 
    
    cout << "ENQUEUE 60 (Harusnya geser data) >>" << endl;
    masukkan(Q, 60); tampilkanData(Q); 
    
    masukkan(Q, 70); tampilkanData(Q); 
    masukkan(Q, 80); tampilkanData(Q); 

    cout << "ENQUEUE 90 (Penuh Sesungguhnya) >>" << endl;
    masukkan(Q, 90); 
    tampilkanData(Q); 

    return 0;
}
```
#### Output:
<img width="1014" height="404" alt="{9F2F2305-E1B9-42D4-ADA6-88FFC053434D}" src="https://github.com/user-attachments/assets/6d87a7a4-29b1-4ae1-863b-67969fdc91c0" />

Implementasi program ini mewujudkan konsep Antrean (Queue) dengan menggunakan array dan mengadopsi skema Alternatif 2, yang memungkinkan penanda Head (depan) dan Tail (belakang) untuk bergerak secara independen. Pendekatan ini secara mendasar bertujuan meningkatkan efisiensi: saat elemen terdepan dikeluarkan (Dequeue), penanda Head hanya melompat maju, sehingga menghilangkan kebutuhan untuk menggeser seluruh sisa data (seperti yang terjadi pada Alternatif 1).

#### Full code Screenshot:
<img width="1920" height="1080" alt="{C6BD88EC-64B8-426A-873E-5FF3710E3679}" src="https://github.com/user-attachments/assets/cb65c2b1-b385-43bf-9d74-168fa526255a" />
<img width="1920" height="1080" alt="{1937D8F9-F5C1-457C-8DE3-570409701BEE}" src="https://github.com/user-attachments/assets/1101b4ad-a23e-4aca-bb8d-aa1b3b669bbf" />
<img width="1920" height="1080" alt="{432FB38D-5939-4595-8111-EE11E4376886}" src="https://github.com/user-attachments/assets/76c5d400-10d7-4b9d-953a-f859e124dab4" />


### 3. [Soal]
*queue.h*
```C++
#ifndef ANTREAM_H
#define ANTREAM_H

#include <iostream>

typedef int TipeData;

#define MAX_ELEMEN 5 

struct Antrean {
    TipeData data[MAX_ELEMEN]; 
    int depan;                
    int belakang;              
};
void buatAntreanKosong(Antrean &Q);
bool apaKosong(Antrean Q);
bool apaPenuh(Antrean Q);
void masukkan(Antrean &Q, TipeData nilaiBaru);
TipeData keluarkan(Antrean &Q);
void tampilkanData(Antrean Q);

#endif
```
*queue.cpp*
```C++
#include "queue.h"
#include <iostream>
#include <iomanip>

using namespace std;

void buatAntreanKosong(Antrean &Q) {
    Q.depan = -1;
    Q.belakang = -1;
}
bool apaKosong(Antrean Q) {
    return (Q.depan == -1); 
}
bool apaPenuh(Antrean Q) {
    if (Q.depan == 0 && Q.belakang == MAX_ELEMEN - 1) {
        return true;
    }
    if (Q.depan == Q.belakang + 1) {
        return true;
    }
    return false;
}
void masukkan(Antrean &Q, TipeData nilaiBaru) {
    if (apaPenuh(Q)) {
        cout << "Antrian Penuh (Circular Queue)! Data " << nilaiBaru << " gagal dimasukkan." << endl;
        return;
    }
    if (apaKosong(Q)) {
        Q.depan = 0;
        Q.belakang = 0;
    } else {
        Q.belakang = (Q.belakang + 1) % MAX_ELEMEN;
    }
    Q.data[Q.belakang] = nilaiBaru;
}
TipeData keluarkan(Antrean &Q) {
    TipeData nilaiDihapus = -999; 
    if (apaKosong(Q)) {
        cout << "Antrian Kosong!" << endl;
        return nilaiDihapus;
    }
    nilaiDihapus = Q.data[Q.depan];

    if (Q.depan == Q.belakang) {
        buatAntreanKosong(Q); 
    } else {
        Q.depan = (Q.depan + 1) % MAX_ELEMEN;
    }
    return nilaiDihapus;
}
void tampilkanData(Antrean Q) {
    cout << setw(2) << Q.depan << " - " << setw(2) << Q.belakang << " : ";

    if (apaKosong(Q)) {
        cout << "empty queue" << endl;
    } else {
        int i = Q.depan;
        while (true) {
            cout << Q.data[i];
            if (i == Q.belakang) break; 

            i = (i + 1) % MAX_ELEMEN;
            cout << " ";
        }
        cout << endl;
    }
}
```
*main.cpp*
```C++
#include "queue.h" 
#include <iostream>
#include <iomanip>

using namespace std;

int main() {
    cout << "UJI ALTERNATIF 3 (Head/Tail Berputar - Circular Queue)" << endl;

    Antrean Q;
    buatAntreanKosong(Q);

    cout << "-----------------------------------" << endl;
    cout << " H - T : Queue Info" << endl;
    cout << "-----------------------------------" << endl;

    masukkan(Q, 10); 
    masukkan(Q, 20); 
    masukkan(Q, 30); 
    masukkan(Q, 40); 
    masukkan(Q, 50); tampilkanData(Q); 

    cout << "DEQUEUE 3x (H bergerak) >>" << endl;
    keluarkan(Q); tampilkanData(Q);
    keluarkan(Q); tampilkanData(Q); 
    keluarkan(Q); tampilkanData(Q); 
    
    cout << "ENQUEUE 60 (Tail berputar ke 0) >>" << endl;
    masukkan(Q, 60); tampilkanData(Q);
    cout << "ENQUEUE 70 (Tail maju ke 1) >>" << endl;
    masukkan(Q, 70); tampilkanData(Q); 
    cout << "ENQUEUE 80 (Tail maju ke 2 -> PENUH) >>" << endl;
    masukkan(Q, 80); tampilkanData(Q); 
    cout << "ENQUEUE 90 (Gagal, Penuh) >>" << endl;
    masukkan(Q, 90); tampilkanData(Q); 
    cout << "DEQUEUE 4x (H berputar ke 0) >>" << endl;
    keluarkan(Q); tampilkanData(Q); 
    keluarkan(Q); tampilkanData(Q); 
    keluarkan(Q); tampilkanData(Q); 
    keluarkan(Q); tampilkanData(Q); 
    
    cout << "DEQUEUE terakhir (Kosong) >>" << endl;
    keluarkan(Q); tampilkanData(Q); 

    return 0;
}
```
#### Output:
<img width="819" height="576" alt="{D091D834-0055-4D68-AA59-E03FA39E1621}" src="https://github.com/user-attachments/assets/d1e6add8-31e7-44fe-ae3b-475c1c6df9f8" />

Program ini mengimplementasikan Antrean (Queue) Melingkar menggunakan array, di mana penanda Head dan Tail bergerak bebas dan berputar kembali ke awal array (indeks 0) setelah mencapai batas akhir. Keunggulannya adalah efisiensi optimal ($O(1)$) karena menghilangkan semua pergeseran data (shifting) dan mengatasi masalah "penuh semu" dengan memanfaatkan seluruh ruang array. Kondisi penuh hanya dideteksi ketika Tail berada tepat satu langkah di belakang Head secara melingkar.

#### Full code Screenshot:
<img width="1920" height="1080" alt="{8EC95C06-1501-406C-80E7-8482E5B22CD4}" src="https://github.com/user-attachments/assets/fb27f557-648a-4a7e-ba3d-f1c1aa156d74" />
<img width="1920" height="1080" alt="{7FA6FD25-F6CB-4986-829D-2D3D81C546D6}" src="https://github.com/user-attachments/assets/817d2a2c-d6b9-4b95-919c-93e331bc0768" />
<img width="1920" height="1080" alt="{AE74040C-5199-4723-83A3-D240A5AB05DD}" src="https://github.com/user-attachments/assets/1a8513a5-d0aa-42c1-93aa-e1a43ab9df45" />


## Kesimpulan
Implementasi ADT Queue menggunakan array memiliki tiga skema utama yang memengaruhi efisiensi: Alternatif 1 (Head Diam) paling tidak efisien karena wajib menggeser seluruh data saat penghapusan (Dequeue). Alternatif 2 (Head Bergerak) lebih cepat karena Dequeue tidak memerlukan pergeseran, namun rentan terhadap masalah "penuh semu" yang memaksa dilakukannya pergeseran data korektif. Solusi terbaik dan paling optimal adalah Alternatif 3 (Circular Queue), yang secara total menghilangkan kebutuhan pergeseran data dan mengatasi masalah penuh semu dengan membuat penunjuk Head dan Tail berputar menggunakan aritmatika modular.

## Referensi
1. Modul 8 Queue
2. Goodrich, M. T., Tamassia, R., & Mount, D. M. (2011). Data Structures and Algorithms in C++ (2nd ed.). John Wiley & Sons.
3. GeeksforGeeks. (n.d.). Circular Queue | Set 1 (Introduction and Array Implementation)
