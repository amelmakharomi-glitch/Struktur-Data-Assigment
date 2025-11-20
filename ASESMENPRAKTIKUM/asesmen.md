  # <h1 align="center">Asesmen Praktikum</h1>
<p align="center">Amelia Sofiana Makharomi</p>

### 1a. [Soal]
*SLLInventory.h*
```C++
#ifndef SLLINVENTORY_H_INCLUDE
#define SLLINVENTORY_H_INCLUDE

#include <iostream>

using namespace std;

#define Nil NULL
struct Product {
    string Nama;
    string SKU;
    int Jumlah;
    float HargaSatuan;
    float DiskonPersen;
};
typedef struct Node *address;
struct Node {
    Product info;
    address next;
};
struct List {
    address head;
};

float HitungHargaAkhir(Product P);
bool isEmpty(List L);
void createList(List &L);
address allocate(Product P);
void deallocate(address addr);

void insertFirst(List &L, Product P);
void insertLast(List &L, Product P);
void insertAfter(List &L, address Q, Product P);

void deleteFirst(List &L, Product &P);
void deleteLast(List &L, Product &P);
void deleteAfter(List &L, address Q, Product &P);

void updateAtPosition(List &L, int posisi, Product P);
void viewList(List L);
void searchByFinalPriceRange(List L, float minPrice, float maxPrice);

#endif
```
*SLLInventory.cpp*
```C++
#include "SLLInventory.h"
#include <iostream>
using namespace std;

float HitungHargaAkhir(Product P) {
    return P.HargaSatuan * (1.0 - (P.DiskonPersen/100.0));
}
bool isEmpty(List L) {
    return (L.head == Nil); 
}
void createList(List &L) {
    L.head = Nil; 
}
address allocate(Product P) {
    address addr = new Node;
    addr->info = P;
    addr->next = Nil;
    return addr;
}
void deallocate(address addr) {
    delete addr;
}
void insertFirst(List &L, Product P) {
    address addr = allocate(P);
    addr->next = L.head; 
    L.head = addr;
}
void insertLast(List &L, Product P) {
    address addr = allocate(P);

    if (isEmpty(L)) {
        L.head = addr;
    } else {
        address Q = L.head;
        while (Q->next != Nil) {
            Q = Q->next;
        }
        Q->next = addr;
    }
}
void insertAfter(List &L, address Q, Product P) {
    if (Q == Nil) return;

    address addr = allocate(P);
    addr->next = Q->next; 
    Q->next = addr;
}
void deleteFirst(List &L, Product &P) {
    if (isEmpty(L)) return;

    address D = L.head;
    P = D->info;

    L.head = D->next;
    deallocate(D);
}
void deleteLast(List &L, Product &P) {
    if (isEmpty(L)) return;

    address D = L.head;
    address Prev = Nil;

    if (D->next == Nil) { 
        P = D->info;
        L.head = Nil;
        deallocate(D);
        return;
    }
    while (D->next != Nil) {
        Prev = D;
        D = D->next;
    }
    P = D->info;
    Prev->next = Nil; 
    deallocate(D);
}
void deleteAfter(List &L, address Q, Product &P) {
    if (Q == Nil || Q->next == Nil) return;

    address D = Q->next;
    P = D->info;

    Q->next = D->next;
    deallocate(D);
}
void updateAtPosition(List &L, int posisi, Product P) {
    if (isEmpty(L) || posisi < 1) return;

    address current = L.head;
    int counter = 1;

    while (current != Nil && counter < posisi) {
        current = current->next;
        counter++;
    }
    if (current != Nil && counter == posisi) {
        current->info = P; 
        cout << "\n[INFO] Data produk di posisi ke-" << posisi << " BERHASIL di-update." << endl;
    } else {
        cout << "\n[ERROR] Posisi ke-" << posisi << " TIDAK DITEMUKAN. Update dibatalkan." << endl;
    }
}
void viewList(List L) {
    cout << "\n=== Daftar Inventaris Produk ===";
    if (isEmpty(L)) {
        cout << "\nList kosong.\n";
    } else {
        address current = L.head;
        int counter = 1;
        
        while (current != Nil) {
            float hargaAkhir = HitungHargaAkhir(current->info);
            cout << "\n" << counter << ". Nama: " << current->info.Nama 
                 << ", SKU: " << current->info.SKU 
                 << ", Jml: " << current->info.Jumlah 
                 << ", Harga Akhir: " << hargaAkhir 
                 << " (Diskon: " << current->info.DiskonPersen << "%)";
            
            current = current->next;
            counter++;
        }
        cout << "\n================================\n";
    }
}
void searchByFinalPriceRange(List L, float minPrice, float maxPrice) {
    cout << "\n--- Hasil Pencarian Harga Akhir (Rentang " << minPrice << " s/d " << maxPrice << ") ---";

    if (isEmpty(L)) {
        cout << "\nList kosong. Pencarian dibatalkan.\n";
        return;
    }
    address current = L.head;
    int counter = 1;
    bool found = false;

    while (current != Nil) {
        float hargaAkhir = HitungHargaAkhir(current->info);
        
        if (hargaAkhir >= minPrice && hargaAkhir <= maxPrice) {
            cout << "\n[Pos " << counter << "] " << current->info.Nama 
                 << " | Harga Akhir: " << hargaAkhir;
            found = true;
        }
        
        current = current->next;
        counter++;
    }
    if (!found) {
        cout << "\nProduk tidak ditemukan dalam rentang harga ini.\n";
    } else {
        cout << "\n--- Akhir Hasil Pencarian --- \n";
    }
}
```
*main.cpp*
```C++
#include "SLLInventory.h"
using namespace std;

Product buatProduk(string nama, string sku, int jml, float harga, float diskon) {
    Product p;
    p.Nama = nama;
    p.SKU = sku;
    p.Jumlah = jml;
    p.HargaSatuan = harga;
    p.DiskonPersen = diskon;
    
    return p;
}
int main() {
    List L;
    
    createList(L);
    cout << "1. List inventory kosong (createList)." << endl;
    
    Product p1 = buatProduk("Pulpen", "A001", 20, 2500.0, 0.0);
    Product p2 = buatProduk("Buku Tulis", "A002", 15, 5000.0, 10.0);
    Product p3 = buatProduk("Penghapus", "A003", 30, 1500.0, 0.0);
    
    cout << "\n2. Masukkan 3 produk pakai insertLast." << endl;
    insertLast(L, p1);
    insertLast(L, p2);
    insertLast(L, p3);

    cout << "\n3. Cek list sekarang:";
    viewList(L);
    
    Product deletedProduct;
    deleteFirst(L, deletedProduct); 
    cout << "\n4. Hapus elemen pertama (deleteFirst). Produk terhapus: " << deletedProduct.Nama << endl;
    
    cout << "\n5. List setelah penghapusan:";
    viewList(L); 
    
    Product pUpdate = {"Stabilo", "A010", 40, 9000.0, 5.0};
    cout << "\n6. Ganti data di posisi ke-2 (sebelumnya Penghapus) dengan Stabilo." << endl;
    updateAtPosition(L, 2, pUpdate); 
    
    cout << "\n7. List final setelah update:";
    viewList(L); 
    
    float minP = 2000.0;
    float maxP = 7000.0;
    cout << "\n8. Cari produk dengan Harga Akhir dalam rentang 2000 - 7000." << endl;
    searchByFinalPriceRange(L, minP, maxP);

    cout << "\nSemua operasi selesai.\n";
    return 0;
}
```
#### Output:
<img width="601" height="716" alt="{1740DC56-EFD2-4FCA-9A41-4B9696E8AE88}" src="https://github.com/user-attachments/assets/e183c803-0576-457c-8aff-3aa0a17c1cb1" />


### 1b. [Soal]

#### Output:
<img width="595" height="815" alt="{5F44C590-830D-484D-BF19-62C26549AD52}" src="https://github.com/user-attachments/assets/03cb4dc0-d819-49ac-a8c3-a98b2710a084" />

### 2. [Soal]
*DLLPlaylist.h*
```C++
#ifndef DOUBLYLIST_H_INCLUDE
#define DOUBLYLIST_H_INCLUDE

#include <iostream> 
using namespace std;

#define Nil NULL
struct Kendaraan {
    string nopol;
    string warna;
    int thnBuat;
};
typedef struct Elmlist *address;

struct Elmlist {
    Kendaraan info;
    address next; 
    address prev; 
};
struct List {
    address first;
    address last;
};
void CreateList(List &L);
bool isEmpty(List L);
address alokasi(Kendaraan X);
void dealokasi(address P);

void insertFirst(List &L, address P);
void insertLast(List &L, address P);

void deleteFirst(List &L, address &P);
void deleteLast(List &L, address &P);
void deleteAfter(address Prec, address &P);

address findElm(List L, string nopolX);
void printInfo(List L);

#endif
```
*DLLPlaylist.cpp*
```C++
#include "DLLPlaylist.h"
#include <iostream>
using namespace std;

void CreateList(List &L) {
    L.first = Nil;
    L.last = Nil;
}
bool isEmpty(List L) {
    return (L.first == Nil);
}
address alokasi(Kendaraan X) {
    address P = new Elmlist;
    P->info = X;
    P->next = Nil;
    P->prev = Nil;
    return P;
}
void dealokasi(address P) {
    delete P;
}
void insertFirst(List &L, address P) {
    if (isEmpty(L)) {
        L.first = P;
        L.last = P;
    } else {
        P->next = L.first;
        L.first->prev = P;
        L.first = P;
    }
}
void insertLast(List &L, address P) {
    if (isEmpty(L)) {
        L.first = P;
        L.last = P;
    } else {
        P->prev = L.last;
        L.last->next = P;
        L.last = P;
    }
}
void deleteFirst(List &L, address &P) {
    if (isEmpty(L)) return;

    P = L.first;

    if (L.first == L.last) { 
        L.first = Nil;
        L.last = Nil;
    } else {
        L.first = P->next;
        L.first->prev = Nil;
    }
    P->next = Nil;
    P->prev = Nil;
}
void deleteLast(List &L, address &P) {
    if (isEmpty(L)) return;

    P = L.last;

    if (L.first == L.last) { 
        L.first = Nil;
        L.last = Nil;
    } else {
        L.last = P->prev;
        L.last->next = Nil;
    }
    P->next = Nil;
    P->prev = Nil;
}
void deleteAfter(address Prec, address &P) {
    if (Prec == Nil || Prec->next == Nil) return;

    P = Prec->next;
    Prec->next = P->next;
    if (P->next != Nil) { 
        P->next->prev = Prec;
    }
    P->next = Nil;
    P->prev = Nil;
}
address findElm(List L, string nopolX) {
    address P = L.first;
    while (P != Nil) {
        if (P->info.nopol == nopolX) {
            return P;
        }
        P = P->next;
    }
    return Nil;
}
void printInfo(List L) {
    cout << "\n--- DATA LIST KENDARAAN ---";
    if (isEmpty(L)) {
        cout << "\nList kosong.\n";
        return;
    }
    address P = L.first;
    int counter = 1;
    while (P != Nil) {
        cout << "\n--------------------------";
        cout << "\nData ke-" << counter;
        cout << "\nNo Polisi: " << P->info.nopol;
        cout << "\nWarna    : " << P->info.warna;
        cout << "\nTahun    : " << P->info.thnBuat;
        P = P->next;
        counter++;
    }
    cout << "\n--------------------------\n";
}
```
*main.cpp*
```C++
#include "DLLPlaylist.h"
#include <iostream>
using namespace std;

Kendaraan buatKendaraan(string nopol, string warna, int thn) {
    Kendaraan K;
    K.nopol = nopol;
    K.warna = warna;
    K.thnBuat = thn;
    return K;
}
int main() {
    List L;
    CreateList(L);
    address P;
    Kendaraan K;
    string nopolSearch;
    string nopolDelete;

    cout << "\n===== DATA KENDARAAN =====";
    
    K = buatKendaraan("D001", "hitam", 90);
    P = alokasi(K);
    insertLast(L, P);

    K = buatKendaraan("D003", "putih", 70);
    P = alokasi(K);
    insertLast(L, P);

    cout << "\n--- Input D001 (Duplikat) ---";
    K = buatKendaraan("D001", "merah", 80);
    if (findElm(L, K.nopol) != Nil) {
        cout << "\nNomor Polisi " << K.nopol << " sudah terdaftar! Input dibatalkan.";
    } else {
        P = alokasi(K);
        insertLast(L, P);
    }
    K = buatKendaraan("D004", "kuning", 90);
    P = alokasi(K);
    insertLast(L, P);

    printInfo(L);
    
    cout << "\n===== CARI ELEMEN =====";
    nopolSearch = "D001";
    cout << "Nomor Polisi yang dicari: " << nopolSearch << endl;
    
    address found = findElm(L, nopolSearch);
    if (found != Nil) {
        cout << "Nomor Polisi: " << found->info.nopol;
        cout << "\nWarna       : " << found->info.warna;
        cout << "\nTahun       : " << found->info.thnBuat << endl;
    } else {
        cout << "Nomor Polisi " << nopolSearch << " tidak ditemukan.\n";
    }
    cout << "\n===== HAPUS ELEMEN =====";
    nopolDelete = "D003";
    cout << "Nomor Polisi yang akan dihapus: " << nopolDelete << endl;

    address toDelete = findElm(L, nopolDelete);
    if (toDelete != Nil) {
        address Pdel;
        
        if (toDelete == L.first) {
            deleteFirst(L, Pdel);
        } else if (toDelete == L.last) {
            deleteLast(L, Pdel);
        } else {
            deleteAfter(toDelete->prev, Pdel);
        }
        dealokasi(Pdel);
        cout << "Data dengan nomor polisi " << nopolDelete << " berhasil dihapus." << endl;
    } else {
        cout << "Data dengan nomor polisi " << nopolDelete << " tidak ditemukan untuk dihapus." << endl;
    }
    printInfo(L);

    return 0;
}
```
#### Output:
<img width="577" height="811" alt="{A9CAF882-3EC6-4859-BE7E-EB249B8942E8}" src="https://github.com/user-attachments/assets/c091120b-e5e9-4c8a-ba9b-634e4b29531d" />


