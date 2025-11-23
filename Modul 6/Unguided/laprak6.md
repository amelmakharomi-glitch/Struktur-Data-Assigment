
  # <h1 align="center">Laporan Praktikum Modul Doubly Linked List</h1>
<p align="center">Amelia Sofiana Makharomi</p>

## Dasar Teori

Doubly Linked List (DLL) merupakan tipe linked list yang unik karena setiap elemennya tidak hanya memiliki pointer ke elemen sesudahnya (next), tetapi juga memiliki pointer yang menunjuk ke elemen sebelumnya (prev). Struktur ini dikelola oleh dua pointer utama, yaitu first untuk menunjuk elemen pertama dan last untuk elemen terakhir. Keunggulan utama DLL terletak pada kemampuannya untuk melakukan iterasi maju dan mundur, sehingga proses akses dan manipulasi elemen menjadi lebih mudah dan fleksibel dibandingkan Singly Linked List. Operasi primitif seperti penyisipan elemen (Insert First, Insert Last) dan penghapusan elemen (Delete First, Delete Last) melibatkan penyesuaian pointer next dan prev pada elemen yang terlibat untuk menjaga integritas urutan list. Secara teknis, setiap elemen list didefinisikan dengan tiga komponen: info (data), next (alamat elemen depan), dan prev (alamat elemen belakang).

## Guided

### 1. [DLL]
*dll_insert.cpp*
```C++
#include <iostream>
#define Nil NULL
using namespace std;

typedef int infotype; // Definisikan tipe data infotype sebagai integer untuk menyimpan informasi elemen
typedef struct elmlist *address; // Definisikan tipe address sebagai pointer ke struct elmlist

struct elmlist {
    infotype info; // Deklarasikan field info untuk menyimpan data elemen
    address next;
    address prev;
};

struct List { 
    address first; 
    address last; 
}; 

void insertFirst(List &L, address P) { 
    P->next = L.first; // Set pointer next dari P ke elemen pertama saat ini
    P->prev = Nil; // Set pointer prev dari P ke Nil karena menjadi elemen pertama
    if (L.first != Nil) L.first->prev = P; // Jika list tidak kosong, set prev elemen pertama lama ke P
    else L.last = P; // Jika list kosong, set last juga ke P
    L.first = P; // Update first list menjadi P
} 

void insertLast(List &L, address P) { 
    P->prev = L.last; // Set pointer prev dari P ke elemen terakhir saat ini
    P->next = Nil; // Set pointer next dari P ke Nil karena menjadi elemen terakhir
    if (L.last != Nil) L.last->next = P; // Jika list tidak kosong, set next elemen terakhir lama ke P
    else L.first = P; // Jika list kosong, set first juga ke P
    L.last = P; // Update last list menjadi P
} 

void insertAfter(List &L, address P, address R) { // Definisikan fungsi insertAfter untuk menyisipkan elemen setelah R
    P->next = R->next; // Set pointer next dari P ke elemen setelah R
    P->prev = R; // Set pointer prev dari P ke R
    if (R->next != Nil) R->next->prev = P; // Jika ada elemen setelah R, set prev elemen tersebut ke P
    else L.last = P; // Jika R adalah terakhir, update last menjadi P
    R->next = P; // Set next dari R ke P
}

address alokasi(infotype x) { // Definisikan fungsi alokasi untuk membuat elemen baru
    address P = new elmlist; // Alokasikan memori baru untuk elemen
    P->info = x; // Set info elemen dengan nilai x
    P->next = Nil; // Set next elemen ke Nil
    P->prev = Nil; // Set prev elemen ke Nil
    return P; 
} 

void printInfo(List L) { // Definisikan fungsi printInfo untuk mencetak isi list
    address P = L.first; // Set P ke elemen pertama list
    while (P != Nil) { // Loop selama P tidak Nil
        cout << P->info << " "; // Cetak info dari P 
        P = P->next; // Pindah ke elemen berikutnya
    } 
    cout << endl; 
}

int main() { 
    List L; 
    L.first = Nil; 
    L.last = Nil;
    address P1 = alokasi(1); 
    insertFirst(L, P1); 
    address P2 = alokasi(2); 
    insertLast(L, P2); 
    address P3 = alokasi(3); 
    insertAfter(L, P3, P1); 
    printInfo(L); 
    return 0; 
}
```
*dll_hapus.cpp*
```C++
#include <iostream> 
using namespace std; 
#define Nil NULL 

typedef int infotype; // Definisikan tipe data infotype sebagai integer untuk menyimpan informasi elemen
typedef struct elmlist *address; // Definisikan tipe address sebagai pointer ke struct elmlist

struct elmlist { 
    infotype info; // Deklarasikan field info untuk menyimpan data elemen
    address next;   
    address prev; 
}; 

struct List { 
    address first; 
    address last;
}; 

address alokasi(infotype x) { // Definisikan fungsi alokasi untuk membuat elemen baru
    address P = new elmlist; // Alokasikan memori baru untuk elemen
    P->info = x; P->next = Nil; P->prev = Nil; return P; // Set nilai info, next, prev, dan kembalikan pointer
} 
void dealokasi(address &P) { delete P; P = Nil; } // Definisikan fungsi dealokasi untuk mengosongkan memori elemen
void insertFirst(List &L, address P) { 
    P->next = L.first; P->prev = Nil; // Set pointer next P ke first saat ini dan prev ke Nil
    if (L.first != Nil) L.first->prev = P; else L.last = P; // Jika list tidak kosong, update prev first; jika kosong, set last ke P
    L.first = P; // Update first list menjadi P
}

void printInfo(List L) { 
    address P = L.first; while (P != Nil) { cout << P->info << " "; P = P->next; } cout << endl; // Loop melalui list dan cetak info setiap elemen
} 
void deleteFirst(List &L, address &P) { 
    P = L.first; L.first = L.first->next; // Set P ke first dan update first ke next-nya
    if (L.first != Nil) L.first->prev = Nil; else L.last = Nil; // Jika list tidak kosong, set prev first baru ke Nil; jika kosong, set last ke Nil
    P->next = Nil; P->prev = Nil; // Kosongkan pointer next dan prev P
}

void deleteLast(List &L, address &P) { 
    P = L.last; L.last = L.last->prev; // Set P ke last dan update last ke prev-nya
    if (L.last != Nil) L.last->next = Nil; else L.first = Nil; // Jika list tidak kosong, set next last baru ke Nil; jika kosong, set first ke Nil
    P->prev = Nil; P->next = Nil; // Kosongkan pointer prev dan next P
} 
    
void deleteAfter(List &L, address &P, address R) { 
    P = R->next; R->next = P->next; // Set P ke next R dan update next R ke next P
    if (P->next != Nil) P->next->prev = R; else L.last = R; // Jika ada next P, update prev-nya ke R; jika tidak, set last ke R
    P->prev = Nil; P->next = Nil; // Kosongkan pointer prev dan next P
} 

int main() { 
    List L; L.first = Nil; L.last = Nil; 
    insertFirst(L, alokasi(1)); insertFirst(L, alokasi(2)); insertFirst(L, alokasi(3)); // Sisipkan elemen 1, 2, 3 di awal list
    printInfo(L);
    address P; deleteFirst(L, P); dealokasi(P); // Deklarasikan P, hapus first, dealokasi P
    deleteAfter(L, P, L.first); dealokasi(P); // Hapus setelah first, dealokasi P
    printInfo(L); 
    return 0; 
}
```

## Unguided 

### 1. [Soal]
*dll.h*
```C++
#ifndef DLL_H
#define DLL_H
#include <iostream>

using namespace std;
#define Nil NULL

typedef int boolean;
#define TRUE 1
#define FALSE 0

typedef struct {
    string nopol;  
    string warna;  
    int thnBuat;        
} infotype;
typedef struct elmlist *address;
typedef struct elmlist {
    infotype info; 
    address next;  
    address prev;  
} elmlist;
typedef struct {
    address first; 
    address last;  
} List;
bool IsEmpty(List L);
void CreateList(List &L);
address alokasi(infotype x);
void dealokasi(address &P);
void printInfo(List L);
void insertLast(List &L, address P);
address findElm(List L, std::string nopol);

void insertFirst(List &L, address P);

#endif

```
*dll.cpp*
```C++
#include "dll.h"
#include <iostream>

using namespace std;
bool IsEmpty(List L) {
    return (L.first == Nil);
}
void CreateList(List &L) {
    L.first = Nil;
    L.last = Nil;
}
address alokasi(infotype x) {
    address P = new elmlist;
    if (P != Nil) {
        P->info = x;
        P->next = Nil;
        P->prev = Nil;
        return P;
    } else {
        return Nil;
    }
}
void dealokasi(address &P) {
    if (P != Nil) {
        delete P;
        P = Nil;
    }
}
void printInfo(List L) {
    if (IsEmpty(L)) {
        cout << "List kosong." << endl;
    } else {
        address P = L.first;
        while (P != Nil) {
            cout << "no polisi : " << P->info.nopol << endl;
            cout << "warna     : " << P->info.warna << endl;
            cout << "tahun     : " << P->info.thnBuat << endl;
            P = P->next;
        }
    }
}
void insertLast(List &L, address P) {
    if (IsEmpty(L)) {
        L.first = P;
        L.last = P;
    } else {
        P->prev = L.last; 
        L.last->next = P; 
        L.last = P; 
    }
}
address findElm(List L, std::string nopol) {
    address P = L.first;
    while (P != Nil) {
        if (P->info.nopol == nopol) {
            return P; 
        }
        P = P->next;
    }
    return Nil; 
}
void insertFirst(List &L, address P) {
    if (IsEmpty(L)) {
        L.first = P;
        L.last = P;
    } else {
        P->next = L.first; 
        L.first->prev = P; 
        L.first = P;
    }
}
```
*main.cpp*
```C++
#include "dll.h"
#include <iostream>
using namespace std;
void simulateInput(const string& nopol, const string& warna, int thn) {
    cout << "masukkan nomor polisi: " << nopol << endl;
    cout << "masukkan warna kendaraan: " << warna << endl;
    cout << "masukkan tahun kendaraan: " << thn << endl;
}
int main() {
    List L;
    CreateList(L);
    infotype data;
    address P = Nil;

    cout << "===== UJI COBA DOUBLY LINKED LIST ADT =====" << endl;

    data.nopol = "D001"; data.warna = "hitam"; data.thnBuat = 90;
    simulateInput(data.nopol, data.warna, data.thnBuat); 
    P = alokasi(data);
    if (P != Nil) {
        insertFirst(L, P); 
    }
    data.nopol = "D003"; data.warna = "putih"; data.thnBuat = 70;
    cout << "\n";
    simulateInput(data.nopol, data.warna, data.thnBuat); 
    P = alokasi(data);
    if (P != Nil) {
        insertFirst(L, P); 
    }
    data.nopol = "D001"; data.warna = "merah"; data.thnBuat = 80;
    cout << "\n";
    simulateInput(data.nopol, data.warna, data.thnBuat);
    
    address duplicate = findElm(L, data.nopol);
    
    if (duplicate != Nil) {
        cout << "nomor polisi sudah terdaftar" << endl;
    } else {
        P = alokasi(data);
        if (P != Nil) {
            insertFirst(L, P);
        }
    }
    data.nopol = "D004"; data.warna = "kuning"; data.thnBuat = 90;
    cout << "\n";
    simulateInput(data.nopol, data.warna, data.thnBuat);
    P = alokasi(data);
    if (P != Nil) {
        insertFirst(L, P); 
    }
    cout << "\nDATA LIST 1" << endl;
    printInfo(L);
    cout << "========================================" << endl;

    return 0;
}
```
#### Output:
<img width="1012" height="656" alt="{354DC1C8-028D-4CC9-BCB2-8CDF8B1A2FF8}" src="https://github.com/user-attachments/assets/926e5e7d-a2e8-4502-b02a-d76bdbb45ac6" />

Tujuan program ini adalah membangun dan menguji fungsionalitas inti dari Doubly Linked List, khususnya prosedur insertFirst dan alokasi, serta memastikan integritas data List. List dibuat, dan data kendaraan dimasukkan secara berurutan. Tujuan kritisnya adalah menerapkan validasi menggunakan fungsi pencarian untuk mencegah data duplikat berdasarkan Nomor Polisi (nopol) agar tidak dimasukkan ke dalam List.

#### Full code Screenshot:
<img width="1920" height="1080" alt="{C65E986F-ADBB-41A3-9577-63DA06BA16A4}" src="https://github.com/user-attachments/assets/70d48f4d-4850-43a2-9be1-9cc8ad8566ec" />
<img width="1920" height="1080" alt="{708CFFFB-EDBF-4FD5-817D-20393AD232E1}" src="https://github.com/user-attachments/assets/18ce3c19-d2b9-4de2-9431-ddb15ad06b57" />
<img width="1920" height="1080" alt="{7940043A-818B-42B9-B6D4-6D9CFFBFDADC}" src="https://github.com/user-attachments/assets/4ec782d2-b135-4322-afa7-e48343931a2d" />


### 2. [Soal]
*dll.h*
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
*dll.cpp*
```C++
#include "dll.h"
#include <iostream>

using namespace std;

bool IsEmpty(List L) {
    return (L.first == Nil);
}
void CreateList(List &L) {
    L.first = Nil;
    L.last = Nil;
}
address alokasi(infotype x) {
    address P = new elmlist;
    if (P != Nil) {
        P->info = x;
        P->next = Nil;
        P->prev = Nil;
        return P;
    } else {
        return Nil;
    }
}
void dealokasi(address &P) {
    if (P != Nil) {
        delete P;
        P = Nil;
    }
}
void printInfo(List L) {
    if (IsEmpty(L)) {
        cout << "List kosong." << endl;
    } else {
        address P = L.first;
        while (P != Nil) {
            cout << "no polisi : " << P->info.nopol << endl;
            cout << "warna     : " << P->info.warna << endl;
            cout << "tahun     : " << P->info.thnBuat << endl;
            P = P->next;
        }
    }
}
void insertLast(List &L, address P) {
    if (IsEmpty(L)) {
        L.first = P;
        L.last = P;
    } else {
        P->prev = L.last; 
        L.last->next = P; 
        L.last = P; 
    }
}
address findElm(List L, string nopol) { 
    address P = L.first;
    while (P != Nil) {
        if (P->info.nopol == nopol) {
            return P;
        }
        P = P->next;
    }
    return Nil;
}
void insertFirst(List &L, address P) {
    if (IsEmpty(L)) {
        L.first = P;
        L.last = P;
    } else {
        P->next = L.first; 
        L.first->prev = P; 
        L.first = P;
    }
}
void deleteFirst(List &L, address &P) {
    if (IsEmpty(L)) {
        P = Nil;
        return;
    }
    P = L.first; 
    if (L.first == L.last) { 
        L.first = Nil;
        L.last = Nil;
    } else {
        L.first = P->next; 
        if (L.first != Nil) {
            L.first->prev = Nil; 
        }
        P->next = Nil; 
    }
    P->prev = Nil;
}
void deleteLast(List &L, address &P) {
    if (IsEmpty(L)) {
        P = Nil;
        return;
    }
    P = L.last; 
    if (L.first == L.last) {
        L.first = Nil;
        L.last = Nil;
    } else {
        L.last = L.last->prev; 
        if (L.last != Nil) {
            L.last->next = Nil; 
        }
        P->prev = Nil; 
    }
    P->next = Nil;
}
void deleteAfter(address Prec, address &P) {
    if (Prec == Nil || Prec->next == Nil) {
        P = Nil;
        return;
    }
    P = Prec->next;
    if (P->next == Nil) {
        Prec->next = Nil;
    } else {
        Prec->next = P->next;
        P->next->prev = Prec; 
    }
    P->next = Nil;
    P->prev = Nil; 
}
```
*main.cpp*
```C++
#include "dll.h"
#include <iostream>

using namespace std; 

void simulateInput(const string& nopol, const string& warna, int thn) {
    cout << "masukkan nomor polisi: " << nopol << endl;
    cout << "masukkan warna kendaraan: " << warna << endl;
    cout << "masukkan tahun kendaraan: " << thn << endl;
}
int main() {
    List L;
    CreateList(L);
    infotype data;
    address P = Nil;

    cout << "===== LATIHAN 1: DOUBLY LINKED LIST ADT (INSERT & VALIDASI) =====" << endl;

    data.nopol = "D001"; data.warna = "hitam"; data.thnBuat = 90;
    simulateInput(data.nopol, data.warna, data.thnBuat);
    P = alokasi(data);
    if (P != Nil) {
        insertFirst(L, P); 
    }
    data.nopol = "D003"; data.warna = "putih"; data.thnBuat = 70;
    cout << "\n";
    simulateInput(data.nopol, data.warna, data.thnBuat);
    P = alokasi(data);
    if (P != Nil) {
        insertFirst(L, P); 
    }
    data.nopol = "D001"; data.warna = "merah"; data.thnBuat = 80;
    cout << "\n";
    simulateInput(data.nopol, data.warna, data.thnBuat);
    
    address duplicate = findElm(L, data.nopol);
    
    if (duplicate != Nil) {
        cout << "nomor polisi sudah terdaftar" << endl;
    } else {
        P = alokasi(data);
        if (P != Nil) {
            insertFirst(L, P);
        }
    }
    data.nopol = "D004"; data.warna = "kuning"; data.thnBuat = 90;
    cout << "\n";
    simulateInput(data.nopol, data.warna, data.thnBuat);
    P = alokasi(data);
    if (P != Nil) {
        insertFirst(L, P); 
    }

    cout << "\nDATA LIST 1 (Setelah Insert Latihan 1)" << endl;
    printInfo(L); 
    cout << "===================================================" << endl;

    string nopolCari = "D001";
    cout << "===== LATIHAN 2: PENCARIAN ELEMEN =====" << endl;
    cout << "Masukkan Nomor Polisi yang dicari : " << nopolCari << endl;

    address foundElm = findElm(L, nopolCari);
    
    if (foundElm != Nil) {
        cout << "Nomor Polisi : " << foundElm->info.nopol << endl;
        cout << "Warna        : " << foundElm->info.warna << endl;
        cout << "Tahun        : " << foundElm->info.thnBuat << endl;
    } else {
        cout << "Data tidak ditemukan." << endl;
    }

    cout << "\n===================================================" << endl;

    string nopolHapus = "D003";
    cout << "===== LATIHAN 3: PENGHAPUSAN ELEMEN =====" << endl;
    cout << "Masukkan Nomor Polisi yang akan dihapus: " << nopolHapus << endl;

    address Prec_D003 = findElm(L, "D004"); 
    address P_delete = Nil;
    
    if (Prec_D003 != Nil && Prec_D003->next != Nil && Prec_D003->next->info.nopol == nopolHapus) {
        deleteAfter(Prec_D003, P_delete);
        
        if (P_delete != Nil && P_delete == L.last) {
            L.last = Prec_D003; 
        }

        cout << "Data dengan nomor polisi " << nopolHapus << " berhasil dihapus." << endl;

    } else {
        cout << "Data dengan nomor polisi " << nopolHapus << " tidak ditemukan untuk dihapus." << endl;
    }
    if (P_delete != Nil) {
        dealokasi(P_delete);
    }
    
    cout << "\nDATA LIST 1 (Setelah Penghapusan D003)" << endl;
    printInfo(L);
    cout << "===================================================" << endl;

    while (!IsEmpty(L)) {
        deleteFirst(L, P);
        dealokasi(P);
    }
    return 0;
}
```
#### Output:
<img width="1024" height="900" alt="{15838580-343F-4D5B-81B5-7DF7CEF2CB04}" src="https://github.com/user-attachments/assets/458bc034-1308-48c1-b65e-385ff19d1680" />

Tujuan program ini adalah mengimplementasikan fungsi pencarian findElm(L: List, nopol: string): address. Fungsi ini harus secara efisien menelusuri List dari elemen awal hingga akhir dan mengembalikan pointer (address) dari node yang memiliki Nomor Polisi yang cocok. Tujuannya adalah untuk membuktikan bahwa elemen tertentu (D001) dapat ditemukan dan informasinya dapat diakses dari struktur List.

#### Full code Screenshot:
<img width="1920" height="1080" alt="{75900A71-C5DC-437A-857C-80677FCD3463}" src="https://github.com/user-attachments/assets/89d50fbe-d912-45d6-a55f-1e44b70438b5" />
<img width="1920" height="1080" alt="{B66ADB8A-AAA7-4B65-AE10-81A8BA9957C7}" src="https://github.com/user-attachments/assets/27198fa8-5677-4f55-a29b-9e1c75752581" />
<img width="1920" height="1080" alt="{4F1EA1EC-C8FD-457A-B643-FC9BFC852F70}" src="https://github.com/user-attachments/assets/07ec26d6-e6a6-42d6-ad98-2c1e5dea3045" />


### 3. [Soal]
*dll.h*
```C++
#ifndef DLL_H
#define DLL_H
#include <iostream>

using namespace std; 
#define Nil NULL

typedef int boolean;
#define TRUE 1
#define FALSE 0

typedef struct {
    string nopol;
    string warna;
    int thnBuat;
} infotype;
typedef struct elmlist *address;
typedef struct elmlist {
    infotype info;
    address next;
    address prev;
} elmlist;
typedef struct {
    address first;
    address last;
} List;

bool IsEmpty(List L);
void CreateList(List &L);
address alokasi(infotype x);
void dealokasi(address &P);
void printInfo(List L);
void insertLast(List &L, address P);
address findElm(List L, string nopol);
void insertFirst(List &L, address P); 
void deleteFirst(List &L, address &P);
void deleteLast(List &L, address &P);
void deleteAfter(address Prec, address &P);

#endif
```
*dll.cpp*
```C++
#include "dll.h"
#include <iostream>

using namespace std;

bool IsEmpty(List L) {
    return (L.first == Nil);
}
void CreateList(List &L) {
    L.first = Nil;
    L.last = Nil;
}
address alokasi(infotype x) {
    address P = new elmlist;
    if (P != Nil) {
        P->info = x;
        P->next = Nil;
        P->prev = Nil;
        return P;
    } else {
        return Nil;
    }
}
void dealokasi(address &P) {
    if (P != Nil) {
        delete P;
        P = Nil;
    }
}
void printInfo(List L) {
    if (IsEmpty(L)) {
        cout << "List kosong." << endl;
    } else {
        address P = L.first;
        while (P != Nil) {
            cout << "no polisi : " << P->info.nopol << endl;
            cout << "warna     : " << P->info.warna << endl;
            cout << "tahun     : " << P->info.thnBuat << endl;
            P = P->next;
        }
    }
}
void insertLast(List &L, address P) {
    if (IsEmpty(L)) {
        L.first = P;
        L.last = P;
    } else {
        P->prev = L.last; 
        L.last->next = P; 
        L.last = P; 
    }
}
address findElm(List L, string nopol) {
    address P = L.first;
    while (P != Nil) {
        if (P->info.nopol == nopol) {
            return P;
        }
        P = P->next;
    }
    return Nil;
}
void insertFirst(List &L, address P) {
    if (IsEmpty(L)) {
        L.first = P;
        L.last = P;
    } else {
        P->next = L.first; 
        L.first->prev = P; 
        L.first = P;
    }
}
void deleteFirst(List &L, address &P) {
    if (IsEmpty(L)) {
        P = Nil;
        return;
    }
    P = L.first; 

    if (L.first == L.last) { 
        L.first = Nil;
        L.last = Nil;
    } else {
        L.first = P->next; 
        if (L.first != Nil) {
            L.first->prev = Nil; 
        }
        P->next = Nil; 
    }
    P->prev = Nil;
}
void deleteLast(List &L, address &P) {
    if (IsEmpty(L)) {
        P = Nil;
        return;
    }
    P = L.last; 

    if (L.first == L.last) {
        L.first = Nil;
        L.last = Nil;
    } else {
        L.last = L.last->prev; 
        if (L.last != Nil) {
            L.last->next = Nil; 
        }
        P->prev = Nil; 
    }
    P->next = Nil;
}
void deleteAfter(address Prec, address &P) {
    if (Prec == Nil || Prec->next == Nil) {
        P = Nil;
        return;
    }
    
    P = Prec->next;
    
    if (P->next == Nil) {
        Prec->next = Nil;
    } else {
        Prec->next = P->next;
        P->next->prev = Prec; 
    }

    P->next = Nil;
    P->prev = Nil; 
}
```
*main.cpp*
```C++
#include "dll.h"
#include <iostream>

using namespace std;

void simulateInput(const string& nopol, const string& warna, int thn) {
    cout << "masukkan nomor polisi: " << nopol << endl;
    cout << "masukkan warna kendaraan: " << warna << endl;
    cout << "masukkan tahun kendaraan: " << thn << endl;
}
int main() {
    List L;
    CreateList(L);
    infotype data;
    address P = Nil;

    data.nopol = "D001"; data.warna = "hitam"; data.thnBuat = 90;
    simulateInput(data.nopol, data.warna, data.thnBuat);
    P = alokasi(data);
    if (P != Nil) {
        insertFirst(L, P); 
    }
    data.nopol = "D003"; data.warna = "putih"; data.thnBuat = 70;
    cout << "\n";
    simulateInput(data.nopol, data.warna, data.thnBuat);
    P = alokasi(data);
    if (P != Nil) {
        insertFirst(L, P); 
    }
    data.nopol = "D001"; data.warna = "merah"; data.thnBuat = 80;
    cout << "\n";
    simulateInput(data.nopol, data.warna, data.thnBuat);
    
    address duplicate = findElm(L, data.nopol);
    
    if (duplicate != Nil) {
        cout << "nomor polisi sudah terdaftar" << endl;
    } else {
        P = alokasi(data);
        if (P != Nil) {
            insertFirst(L, P);
        }
    }
    data.nopol = "D004"; data.warna = "kuning"; data.thnBuat = 90;
    cout << "\n";
    simulateInput(data.nopol, data.warna, data.thnBuat);
    P = alokasi(data);
    if (P != Nil) {
        insertFirst(L, P); 
    }
    cout << "\nDATA LIST 1 (Setelah Insert Latihan 1)" << endl;
    printInfo(L); 
    cout << "===================================================" << endl;

    string nopolCari = "D001";
    cout << "===== LATIHAN 2: PENCARIAN ELEMEN =====" << endl;
    cout << "Masukkan Nomor Polisi yang dicari : " << nopolCari << endl;

    address foundElm = findElm(L, nopolCari);
    
    if (foundElm != Nil) {
        cout << "Nomor Polisi : " << foundElm->info.nopol << endl;
        cout << "Warna        : " << foundElm->info.warna << endl;
        cout << "Tahun        : " << foundElm->info.thnBuat << endl;
    } else {
        cout << "Data tidak ditemukan." << endl;
    }

    cout << "\n===================================================" << endl;

    string nopolHapus = "D003";
    cout << "===== LATIHAN 3: PENGHAPUSAN ELEMEN =====" << endl;
    cout << "Masukkan Nomor Polisi yang akan dihapus: " << nopolHapus << endl;

    address Prec_D003 = findElm(L, "D004"); 
    address P_delete = Nil;
    
    if (Prec_D003 != Nil && Prec_D003->next != Nil && Prec_D003->next->info.nopol == nopolHapus) {
        
        if (Prec_D003->next == L.last) {
            L.last = Prec_D003; 
        }
        deleteAfter(Prec_D003, P_delete);
        cout << "Data dengan nomor polisi " << nopolHapus << " berhasil dihapus." << endl;
    } else {
        cout << "Data dengan nomor polisi " << nopolHapus << " tidak ditemukan untuk dihapus." << endl;
    }

    if (P_delete != Nil) {
        dealokasi(P_delete);
    }
    cout << "\nDATA LIST 1 (Setelah Penghapusan D003)" << endl;
    printInfo(L);
    cout << "===================================================" << endl;

    while (!IsEmpty(L)) {
        deleteFirst(L, P);
        dealokasi(P);
    }
    
    return 0;
}
```
#### Output:
<img width="793" height="404" alt="{EBA95265-C1B8-49E9-845C-86E2085B4372}" src="https://github.com/user-attachments/assets/5d12bec5-d7ef-4148-a4b9-f7b4c395d015" />

Tujuan program ini adalah mendemonstrasikan kemampuan modifikasi struktur List melalui operasi penghapusan, khususnya deleteAfter. Dengan List yang memiliki tiga elemen (D004 $\leftrightarrow$ D003 $\leftrightarrow$ D001), tujuannya adalah menghapus elemen D003 (elemen tengah) dengan menggunakan deleteAfter dan node sebelumnya sebagai acuan. Penghapusan harus berhasil menyambungkan kembali tautan ganda antara D004 dan D001, kemudian membebaskan memori D003, meninggalkan List dalam keadaan terstruktur dan konsisten.

#### Full code Screenshot:
<img width="1920" height="1080" alt="{C0E65934-B82A-4343-A45D-586F355AEA6C}" src="https://github.com/user-attachments/assets/f2bee35f-2380-46d8-be9b-6a020f473678" />
<img width="1920" height="1080" alt="{325375FD-46D0-4BD8-8964-E0EA02537051}" src="https://github.com/user-attachments/assets/eaff0ab1-2743-47d3-b572-00f51da5c3a5" />
<img width="1920" height="1080" alt="{F4B35F2C-ED47-4A24-BDB3-F60E25F814F1}" src="https://github.com/user-attachments/assets/4a7d1a44-c944-4c46-88a2-30205a5b7964" />


## Kesimpulan
Praktikum ini mengimplementasikan struktur data Doubly Linked List yang dilengkapi dengan pointer dua arah (next dan prev). List dibangun melalui prosedur insertFirst, dengan penekanan pada kontrol integritas data yang efektif, di mana node duplikat (berdasarkan nopol) ditolak melalui pemeriksaan menggunakan findElm. Fungsi pencarian ini membuktikan kemampuan untuk menelusuri dan menemukan elemen List secara akurat. Pencapaian utama tugas adalah modifikasi struktural List, yaitu penghapusan elemen tengah (D003). Penghapusan ini dilakukan menggunakan prosedur deleteAfter, yang secara cermat memperbaiki koneksi tautan ganda antar node yang tersisa, memastikan List tetap konsisten (D004 $\leftrightarrow$ D001).  Proses ini menegaskan bahwa List Berantai Ganda dapat dimanipulasi secara dinamis, sekaligus mengkonfirmasi penguasaan atas implementasi ADT dan manajemen memori.

## Referensi
1. Modul 6_Doubly Linked List (Bagian Pertama)
2. Programiz Doubly Linked List in C++ (with code example).
3. Cplusplus.com
