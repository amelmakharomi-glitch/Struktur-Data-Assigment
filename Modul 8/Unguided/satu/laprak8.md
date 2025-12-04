

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
*stack.h*
```C++
#ifndef STACK_H
#define STACK_H
#define MAX 20           
typedef int infotype;    

struct Stack {
    infotype info[MAX];
    int top;
}; 
void CreateStack(Stack &S);
int IsEmpty(Stack S);
int IsFull(Stack S);
void push(Stack &S, infotype X);

infotype pop(Stack &S); 
void printInfo(Stack S);

void insertAtBottom(Stack &S, infotype X); 
void balikStack(Stack &S);
void pushAscending(Stack &S, infotype X);  

#endif 
```
*stack.cpp*
```C++
#include "stack.h"
#include <iostream>
using namespace std;

int IsEmpty(Stack S) {
    return (S.top == -1);
}
int IsFull(Stack S) {
    return (S.top == MAX - 1);
}
void CreateStack(Stack &S) {
    S.top = -1; 
}
void push(Stack &S, infotype X) {
    if (IsFull(S)) {
        cout << "Stack Penuh, Push Gagal!" << endl;
    } else {
        S.top++;
        S.info[S.top] = X;
    }
}
infotype pop(Stack &S) {
    if (IsEmpty(S)) {
        cout << "Stack Kosong, Pop Gagal!" << endl;
        return 0; 
    } else {
        infotype X = S.info[S.top];
        S.top--; 
        return X;
    }
}
void printInfo(Stack S) {
    cout << "[TOP] ";
    if (IsEmpty(S)) {
        cout << "Stack Kosong" << endl;
        return;
    }
    for (int i = S.top; i >= 0; i--) {
        cout << S.info[i] << " ";
    }
    cout << endl;
}
void insertAtBottom(Stack &S, infotype X) {
    if (IsEmpty(S)) {
        push(S, X); 
        return;
    }
    infotype temp = pop(S); 
    insertAtBottom(S, X); 
    push(S, temp); 
}
void balikStack(Stack &S) {
    if (IsEmpty(S)) {
        return;
    }
    infotype X = pop(S); 
    balikStack(S);     
    insertAtBottom(S, X); 
}
void pushAscending(Stack &S, infotype X) {
    if (IsEmpty(S) || S.info[S.top] <= X) {
        push(S, X); 
        return;
    }
    infotype temp = pop(S); 
    pushAscending(S, X);    
    push(S, temp);          
}
```
*main.cpp*
```C++
#include "stack.h"
#include <iostream>
using namespace std;

int main()
{
    cout << "Hello world!" << endl;
    
    Stack S;
    CreateStack(S);

    pushAscending(S, 3);
    pushAscending(S, 4);
    pushAscending(S, 8);
    pushAscending(S, 2);
    pushAscending(S, 3);
    pushAscending(S, 9);
    
    cout << "Setelah pushAscending:" << endl;
    printInfo(S); 
    cout << "balik stack" << endl;
    balikStack(S);
    printInfo(S); 
    
    return 0;
}
```
#### Output:
<img width="1014" height="153" alt="{30A044AA-A453-46BB-90CA-5901DD43DF7E}" src="https://github.com/user-attachments/assets/020bfc76-6176-4ea7-aac4-0c70542f2c91" />

Program menjalankan siklus inisialisasi, lalu menggunakan prosedur pushAscending (penyisipan terurut) untuk memasukkan enam elemen; prosedur rekursif ini menjamin urutan terurut menaik (terkecil di dasar, terbesar di TOP), menghasilkan 9 8 4 3 3 2. Setelah itu, prosedur balikStack dipanggil untuk membalikkan seluruh tumpukan, menghasilkan output akhir 2 3 3 4 8 9.

#### Full code Screenshot:
<img width="1920" height="1080" alt="{261E7B77-DA8F-4243-83DC-A77D9B6543FF}" src="https://github.com/user-attachments/assets/e9d17381-36bd-4131-af0a-6caad2d0dee7" />
<img width="1920" height="1080" alt="{B3C53CDD-5F5B-465D-9162-3130D7E8DDC5}" src="https://github.com/user-attachments/assets/6a2984a6-9dff-49ef-ac10-14672b65096b" />
<img width="1920" height="1080" alt="{D106D5A0-7C52-4D83-B6EB-B3B0EA24441F}" src="https://github.com/user-attachments/assets/ef54c394-b9c5-49d4-90a5-4f375ed6cdf8" />
<img width="1920" height="1080" alt="{B9F18226-A7DD-4FE3-A805-B6ACED77842B}" src="https://github.com/user-attachments/assets/fe9a29ff-9429-4d93-bbbc-1c2189ace4c4" />


### 3. [Soal]
*stack.h*
```C++
#ifndef STACK_H
#define STACK_H
#define MAX 20           

typedef int infotype;    
struct Stack {
    infotype info[MAX];
    int top;
};
void CreateStack(Stack &S);
int IsEmpty(Stack S);
int IsFull(Stack S);
void push(Stack &S, infotype X);
infotype pop(Stack &S); 
void printInfo(Stack S);
void insertAtBottom(Stack &S, infotype X); 
void balikStack(Stack &S);
void pushAscending(Stack &S, infotype X); 
void getInputStream(Stack &S); 

#endif 
```
*stack.cpp*
```C++
#include "stack.h"
#include <iostream>

using namespace std; 
void CreateStack(Stack &S) { S.top = -1; }
int IsEmpty(Stack S) { return (S.top == -1); }
int IsFull(Stack S) { return (S.top == MAX - 1); }
void push(Stack &S, infotype X) {
    if (IsFull(S)) { cout << "Error: Stack Penuh, Push Gagal!" << endl; } 
    else { S.top++; S.info[S.top] = X; }
}
infotype pop(Stack &S) {
    if (IsEmpty(S)) { cout << "Error: Stack Kosong, Pop Gagal!" << endl; return 0; } 
    else { infotype X = S.info[S.top]; S.top--; return X; }
}
void printInfo(Stack S) {
    cout << "[TOP] ";
    if (IsEmpty(S)) { cout << "Stack Kosong" << endl; return; }
    for (int i = S.top; i >= 0; i--) { cout << S.info[i] << " "; }
    cout << endl;
}
void insertAtBottom(Stack &S, infotype X) {
    if (IsEmpty(S)) { push(S, X); return; }
    infotype temp = pop(S); insertAtBottom(S, X); push(S, temp); 
}
void balikStack(Stack &S) {
    if (IsEmpty(S)) { return; }
    infotype X = pop(S); balikStack(S); insertAtBottom(S, X); 
}
void pushAscending(Stack &S, infotype X) {
    if (IsEmpty(S) || S.info[S.top] <= X) { push(S, X); return; }
    infotype temp = pop(S); pushAscending(S, X); push(S, temp);          
}
void getInputStream(Stack &S) {
    char ch;
    
    cout << "Input : ";
    while (cin.get(ch) && ch != '\n') {
        
        if (ch >= '0' && ch <= '9') {
            infotype X = ch - '0';
            push(S, X); 
        } 
    }
}
```
*main.cpp*
```C++
#include "stack.h"
#include <iostream>

using namespace std;

int main()
{
    cout << "Hello world!" << endl;
    Stack S;
    CreateStack(S);
    getInputStream(S); 
    printInfo(S); 
    
    cout << "balik stack" << endl;
    balikStack(S);
    printInfo(S); 
    
    return 0;
}
```
#### Output:
<img width="1024" height="160" alt="{2AA0788D-A214-496B-B485-E3E699394F4D}" src="https://github.com/user-attachments/assets/170b084f-ad7c-4f3d-b107-353f6b1c877c" />

Program ini berfokus pada pemrosesan input data stream. Prosedur getInputStream membaca input pengguna karakter demi karakter, memfilter hanya digit, dan menyisipkannya ke Stack (LIFO). Untuk mengembalikan urutan ke kondisi asli input, Stack kemudian dibalik oleh balikStack. Hasil akhirnya adalah tampilan urutan digit yang sama persis seperti yang dimasukkan pengguna.

#### Full code Screenshot:
<img width="1920" height="1080" alt="{C0E695AD-01B6-477C-9346-D2FD2F8CC441}" src="https://github.com/user-attachments/assets/a245c7da-a111-40d5-99d6-0b8a7e3f0237" />
<img width="1920" height="1080" alt="{6576DADD-0430-4318-9EFD-2DD50791B8E7}" src="https://github.com/user-attachments/assets/c5764cbd-692e-4d4e-bfd8-205be7b0fc74" />
<img width="1920" height="1080" alt="{5B4164CB-0D71-4AEF-9675-A0D9D1849F78}" src="https://github.com/user-attachments/assets/d930c073-1c21-4dd6-ab99-49c8e2952c13" />
<img width="1920" height="1080" alt="{E467B6D8-041A-4DD6-80D4-532EF5E3C460}" src="https://github.com/user-attachments/assets/8de03d08-bbd2-4946-9813-8ce93ff3b607" />


## Kesimpulan
Program ini berhasil mengimplementasikan Abstract Data Type (ADT) Stack berbasis array dengan fungsionalitas lanjutan. Implementasi ini mendemonstrasikan bahwa manipulasi urutan kompleks seperti pembalikan (balikStack) dan penyisipan terurut (pushAscending) dapat dicapai secara efektif melalui rekursi, dengan tetap mematuhi batasan operasi Stack (hanya push dan pop). Selain itu, program berhasil mengintegrasikan pemrosesan input dari pengguna (getInputStream) untuk mengubah karakter mentah menjadi elemen Stack, membuktikan penguasaan prinsip LIFO dan integrasi I/O.

## Referensi
1. Modul 7 Stack
2. Konsep dan Implementasi Stack dengan Array di C++.
3. GeeksforGeeks. (2025). C++ Program For char to int Conversion.
