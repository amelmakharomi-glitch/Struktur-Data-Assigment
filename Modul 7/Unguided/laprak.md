
  # <h1 align="center">Laporan Praktikum Modul Stack</h1>
<p align="center">Amelia Sofiana Makharomi</p>

## Dasar Teori

Stack adalah struktur data linear yang bekerja dengan prinsip **LIFO (Last In, First Out)**, yaitu data yang terakhir dimasukkan akan menjadi data pertama yang dikeluarkan. Operasi utama pada stack meliputi **push** untuk menambah elemen ke bagian atas, **pop** untuk menghapus elemen teratas, dan **peek** untuk melihat elemen teratas tanpa menghapusnya. Stack dapat diimplementasikan menggunakan **array** yang bersifat statis atau **linked list** yang bersifat dinamis. Struktur data ini banyak digunakan dalam berbagai aplikasi seperti fitur **undo/redo**, navigasi **back/forward** pada browser, **call stack** dalam pemanggilan fungsi, evaluasi ekspresi matematika, serta pengecekan keseimbangan tanda kurung.

## Guided

### 1. [Stack]
*stack.h*
```C++
#ifndef STACK_TABLE
#define STACK_TABLE

#include <iostream>
using namespace std;

//ubah kapasitas sesuai kebutuhan
const int MAX = 10;

struct stackTable{
    int data[MAX];
    int top; // -1 = kosong

};

bool isEmpty(stackTable s);
bool isFull(stackTable s);
void createStack(stackTable &s);

void push(stackTable &s, int angka);
void pop(stackTable &s);
void update(stackTable &s, int posisi);
void view(stackTable s);
void searchData(stackTable s, int data);

#endif
```
*stack.cpp*
```C++
#include "stack.h"
#include <iostream>

using namespace std;

bool isEmpty(stackTable s) {
    return s.top == -1;
}

bool isFull(stackTable s){
    return s.top == MAX -1;
}

void createStack(stackTable &s) {
    s.top = -1;
}

void push(stackTable &s, int angka){
    if(isFull(s)){
        cout << "Stack Penuh!" << endl;
    } else {
        s.top++;
        s.data[s.top] = angka;
        cout << "Data " << angka << " berhasil ditambahkan kedalam stack!" << endl;
    }
}

void pop(stackTable &s){
    if(isEmpty(s)){
        cout << "Stack kosong!" << endl;
    } else {
        int val = s.data[s.top];
        s.top--;
        cout << "Data " << val << " Berhasil dihapus dari stack!" << endl;
    }
}

void update(stackTable &s, int posisi){
    if(isEmpty(s)){
        cout << "Stack kosong!" << endl;
        return;
    }
    if(posisi <= 0){
        cout << "Posisi tidak valid!" << endl;
        return;
    }

    //index = top - (posisi -1)
    int idx = s.top - (posisi -1);
    if(idx < 0 || idx > s.top){
        cout << "Posisi " << posisi << " Tidak valid!" << endl;
        return;
    }

    cout << "Update data posisi ke-" << posisi << endl;
    cout << "Masukkan angka: ";
    cin >> s.data[idx];
    cout << "Data berhasil diupdate!" << endl;
    cout << endl;
}

void view(stackTable s){
    if(isEmpty(s)){
        cout << "Stack Kosong!" << endl;
    } else {
        for(int i = s.top; i >= 0; --i){
            cout << s.data[i] << " ";
        }
    }
    cout << endl;
}

void searchData(stackTable s, int data){
    if(isEmpty(s)){
        cout << "Stack Kosong!" << endl;
        return;
    }
    cout << "Mencari data" << data << "..." << endl;
    int posisi = 1;
    bool found = false;

    for(int i = s.top; i >= 0; --i){
        if(s.data[i] == data){
            cout << "Data " << data << " ditemukan pada posisi ke-" << posisi << endl;
            cout << endl;
            found = true;
            break;
        }
        posisi++;
    }

    if(!found){
        cout << "Data " << data << " tidak ditemukan didalam stack!" << endl;
        cout << endl;
    }
}
```
*main.cpp*
```C++
#include "stack.h"
#include <iostream>

using namespace std;

int main(){
    stackTable s;
    createStack(s);

    push(s, 1);
    push(s, 2);
    push(s, 3);
    push(s, 4);
    push(s, 5);
    cout << endl;

    cout << "--- Stack setelah push ---" << endl;
    view(s);
    cout << endl;

    pop(s);
    pop(s);
    cout << endl;

    cout << "--- Stack setelah pop 2 kali ---" << endl;
    view(s);
    cout << endl;

    //Posisi dihitung dari TOP(1-based)
    update(s, 2);
    update(s, 1);
    update(s, 4);
    cout << endl;

    cout << "--- Stack setelah update ---" << endl;
    view(s);
    cout << endl;

    searchData(s, 4);
    searchData(s, 9);

    return 0;
}
```

## Unguided 

### 1. [Soal]
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
int IsFull(Stack S);
int IsEmpty(Stack S);

void CreateStack(Stack &S);
void push(Stack &S, infotype X);
infotype pop(Stack &S);

void printInfo(Stack S);
void balikStack(Stack &S);

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
```
*main.cpp*
```C++
#include "stack.h"
#include <iostream>

using namespace std;

int main() {
    cout << "Hello world!" << endl;

    Stack S;
    CreateStack(S); 

    push(S, 3); 
    push(S, 4); 
    push(S, 8); 
    
    pop(S);     
    
    push(S, 2); 
    push(S, 3); 
    
    pop(S);     
    
    push(S, 9); 
    printInfo(S); 

    cout << "balik stack" << endl; 
    
    balikStack(S); 
    printInfo(S);

    return 0;
}
```
#### Output:
<img width="1032" height="137" alt="{3EB134B0-3573-4023-B64E-E42F719375FC}" src="https://github.com/user-attachments/assets/27822935-bcbb-472e-b099-593427d362a6" />

Program ini bertujuan untuk mengimplementasikan Abstract Data Type (ADT) Stack (Tumpukan) menggunakan Representasi Tabel (Array) dalam bahasa pemrograman C++. Implementasi harus mendukung operasi dasar Stack berdasarkan prinsip LIFO (Last In First Out), serta prosedur tambahan untuk membalik urutan elemen dalam Stack (balikStack).

#### Full code Screenshot:
<img width="1920" height="1080" alt="{2C5EED14-09B0-4EDB-83A9-41034003F265}" src="https://github.com/user-attachments/assets/08142c6d-660d-4952-8dfd-a00f05f1be26" />
<img width="1920" height="1080" alt="{60179764-CFA0-4B90-8D6C-A625D806D8C1}" src="https://github.com/user-attachments/assets/123c8b88-e60a-4452-9eee-0ea236894020" />
<img width="1920" height="1080" alt="{626180D8-A5EA-41E0-B50F-2DEB7003F8FD}" src="https://github.com/user-attachments/assets/9e97c89f-b3f0-4fd8-ba19-4156415ab590" />
<img width="1920" height="1080" alt="{9D1DB8C5-CBCE-48EF-A5FC-F67D17D9D90C}" src="https://github.com/user-attachments/assets/0cc2c8f7-10bf-48ed-b688-cdd0978faff1" />


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
