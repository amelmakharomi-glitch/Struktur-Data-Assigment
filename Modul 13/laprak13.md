# <h1 align="center">  MULTI LINKED LIST  </h1>
<p align="center">Amelia Sofiana Makharomi</p>

## Dasar Teori
Multi Linked List adalah struktur data yang terdiri dari beberapa linked list yang saling terhubung, umumnya berbentuk list induk dan list anak. Setiap elemen induk memiliki satu list anak sehingga membentuk hubungan satu ke banyak.

Operasi utama pada struktur ini meliputi penambahan dan penghapusan elemen induk maupun anak. Penghapusan elemen induk akan menghapus seluruh elemen anak yang terhubung dengannya. Multi Linked List digunakan untuk merepresentasikan data bertingkat secara dinamis.

## Guided 

### 1. [MLL]
```C++
/* buat dahulu elemen yang akan disisipkan */ 
address_anak alokasiAnak(infotypeanak X){
    address_anak P = alokasi(X); 
    P→next = Nil; 
    P→prev = Nil; 
    return P; 
} 
/* mencari apakah ada elemen pegawai dengan info X */ 
address findElm(listinduk L, infotypeinduk X){ 
    address cariInduk = L.first; 
    do{ 
        if(cariInduk.info == X){ 
            return cariInduk; 
        }else{ 
            cariInduk = cariInduk→next; 
}  
    }while(cariInduk.info != X || cariInduk != L→last) 
} 
/* menyisipkan anak pada akhir list anak */ 
void insertLastAnak(listanak &Lanak, address_anak P){ 
    address_anak ! = head(&Lanak); 
    do{ 
        Q = Q→next; 
    }while(next(&Lanak)!=Nil) 
    Q→next = P; 
    P→prev = Q; 
    P→next = Nil; 
}
```

*mll.h*
```
/* contoh ADT list berkait dengan representasi fisik pointer*/ 
/* representasi address dengan pointer*/ 
 
/* info tipe adalah integer */ 
#ifndef MULTILIST_H_INCLUDED 
#define MULTILIST_H_INCLUDED 
#define Nil NULL 
 
typedef int infotypeanak; 
typedef int infotypeinduk; 
typedef struct elemen_list_induk *address; 
typedef struct elemen_list_anak *address_anak; 
/* define list : */ 
 
/* list kosong jika L.first=Nil 
setiap elemen address P dapat diacu P→info atau P→next 
elemen terakhir list jika addressnya last, maka L.last = Nil */ 
struct elemen_list_anak{ 
/* struct ini untuk menyimpan elemen anak dan pointer penunjuk 
   elemen tetangganya */ 
     infotypeanak info; 
     address_anak next; 
     address_anak prev; 
}; 
 
struct listanak { 
/* struct ini digunakan untuk menyimpan list anak itu sendiri */ 
   address_anak first; 
   address_anak last; 
}; 
 
struct elemen_list_induk{ 
/* struct ini untuk menyimpan elemen induk dan pointer penunjuk 
   elemen tetangganya */
      infotypeanak info; 
      listanak lanak;
      address next; 
      address prev; 
}; 
struct listinduk { 
/* struct ini digunakan untuk menyimpan list induk itu sendiri */ 
  address first;
  address last;
}; 
 
/********* pengecekan apakah list kosong ***********/ 
boolean ListEmpty(listinduk L); 
/*mengembalikan nilai true jika list induk kosong*/ 
boolean ListEmptyAnak(listanak L); 
/*mengembalikan nilai true jika list anak kosong*/ 
 
/********* pembuatan list kosong *********/ 
void CreateList(listinduk &L); 
/* I.S. sembarang 
   F.S. terbentuk list induk kosong*/ 
void CreateListAnak(listanak &L); 
/* I.S. sembarang 
   F.S. terbentuk list anak kosong*/ 
    
/********* manajemen memori *********/ 
address alokasi(infotypeinduk P); 
/* mengirimkan address dari alokasi sebuah elemen induk 
   jika alokasi berhasil, maka nilai address tidak Nil dan jika gagal 
   nilai address Nil */ 
    
address_anak alokasiAnak(infotypeanak P); 
/* mengirimkan address dari alokasi sebuah elemen anak 
   jika alokasi berhasil, maka nilai address tidak Nil dan jika gagal 
   nilai address_anak Nil */ 
    
void dealokasi(address P); 
/* I.S. P terdefinisi 
   F.S. memori yang digunakan P dikembalikan ke sistem */ 
 
void dealokasiAnak(address_anak P); 
/* I.S. P terdefinisi 
   F.S. memori yang digunakan P dikembalikan ke sistem */    
/********* pencarian sebuah elemen list *********/ 
address findElm(listinduk L, infotypeinduk X); 
/* mencari apakah ada elemen list dengan P→info = X 
   jika ada, mengembalikan address elemen tab tsb, dan Nil jika sebaliknya 
*/ 
address_anak findElm(listanak Lanak, infotypeanak X); 
/* mencari apakah ada elemen list dengan P→info = X 
   jika ada, mengembalikan address elemen tab tsb, dan Nil jika sebaliknya 
*/ 
boolean fFindElm(listinduk L, address P); 
/* mencari apakah ada elemen list dengan alamat P 
   mengembalikan true jika ada dan false jika tidak ada */ 
boolean fFindElmanak(listanak Lanak, address_anak P); 
/* mencari apakah ada elemen list dengan alamat P 
   mengembalikan true jika ada dan false jika tidak ada */ 
 
address findBefore(listinduk L, address P); 
/* mengembalikan address elemen sebelum P 
   jika P berada pada awal list, maka mengembalikan nilai Nil */ 
address_anak findBeforeAnak(listanak Lanak, infotypeinduk X, address_anak 
P); 
/* mengembalikan address elemen sebelum P dimana P→info = X 
   jika P berada pada awal list, maka mengembalikan nilai Nil */ 
    
/********* penambahan elemen **********/ 
void insertFirst(listinduk &L, address P); 
/* I.S. sembarang, P sudah dialokasikan 
   F.S. menempatkan elemen beralamat P pada awal list */ 
    
void insertAfter(listinduk &L, address P, address Prec); 
/* I.S. sembarang, P dan Prec alamt salah satu elemen list 
   F.S. menempatkan elemen beralamat P sesudah elemen beralamat Prec */
void insertLast(listinduk &L, address P); 
/* I.S. sembarang, P sudah dialokasikan 
   F.S. menempatkan elemen beralamat P pada akhir list */ 
    
void insertFirstAnak(listanak &L, address_anak P); 
/* I.S. sembarang, P sudah dialokasikan 
   F.S. menempatkan elemen beralamat P pada awal list */ 
    
void insertAfterAnak(listanak &L, address_anak P, address_anak Prec); 
/* I.S. sembarang, P dan Prec alamt salah satu elemen list 
   F.S. menempatkan elemen beralamat P sesudah elemen beralamat Prec */ 
 
void insertLastAnak(listanak &L, address_anak P); 
/* I.S. sembarang, P sudah dialokasikan 
   F.S. menempatkan elemen beralamat P pada akhir list */ 
    
/********* penghapusan sebuah elemen *********/ 
void delFirst(listinduk &L, address &P); 
/* I.S. list tidak kosong 
   F.S. adalah alamat dari alamat elemen pertama list 
   sebelum elemen pertama list dihapus 
   elemen pertama list hilang dan list mungkin menjadi kosong 
   first elemen yang baru adalah successor first elemen yang lama */ 
void delLast(listinduk &L, address &P); 
/* I.S. list tidak kosong 
   F.S. adalah alamat dari alamat elemen terakhir list 
   sebelum elemen terakhir list dihapus 
   elemen terakhir list hilang dan list mungkin menjadi kosong 
   last elemen yang baru adalah successor last elemen yang lama */ 
 
void delAfter(listinduk &L, address &P, address Prec); 
/* I.S. list tidak kosng, Prec alamat salah satu elemen list 
   F.S. P adalah alamatdari Prec→next, menghapus Prec→next dari list */ 
void delP (listinduk &L, infotypeinduk X); 
/* I.S. sembarang 
   F.S. jika ada elemen list dengan alamat P, dimana P→info = X,  
        maka P dihapus dan P di-dealokasi,  
        jika tidak ada maka list tetap list mungkin akan menjadi kosong  
        karena penghapusan */ 
   
void delFirstAnak(listanak &L, address_anak &P); 
/* I.S. list tidak kosong 
   F.S. adalah alamat dari alamat elemen pertama list 
   sebelum elemen pertama list dihapus 
   elemen pertama list hilang dan list mungkin menjadi kosong 
   first elemen yang baru adalah successor first elemen yang lama */ 
void delLastAnak(listanak &L, address_anak &P); 
/* I.S. list tidak kosong 
   F.S. adalah alamat dari alamat elemen terakhir list 
   sebelum elemen terakhir list dihapus 
   elemen terakhir list hilang dan list mungkin menjadi kosong 
   last elemen yang baru adalah successor last elemen yang lama */ 
 
void delAfterAnak(listanak &L, address_anak &P, address_anak Prec); 
/* I.S. list tidak kosng, Prec alamat salah satu elemen list 
   F.S. P adalah alamatdari Prec→next, menghapus Prec→next dari list */ 
void delPAnak (listanak &L, infotypeanak X); 
/* I.S. sembarang 
   F.S. jika ada elemen list dengan alamat P, dimana P→info = X,  
        maka P dihapus dan P di-dealokasi,  
        jika tidak ada maka list tetap list mungkin akan menjadi kosong  
        karena penghapusan */ 
/********** proses semau elemen list *********/ 
void printInfo(list L); 
/* I.S. list mungkin kosong 
   F.S. jika list tidak kosong menampilkan semua info yang ada pada list 
*/ 

int nbList(list L); 
/* mengembalikan jumlah elemen pada list */ 
 
void printInfoAnak(listanak Lanak); 
/* I.S. list mungkin kosong 
   F.S. jika list tidak kosong menampilkan semua info yang ada pada list 
*/ 
 
int nbListAnak(listanak Lanak); 
/* mengembalikan jumlah elemen pada list anak */ 
 
/********** proses terhadap list **********/ 
void delAll(listinduk &L); 
/* menghapus semua elemen list dan semua elemen di-dealokasi */ 
#endif
```

## Unguided 

### [Soal]
*circularlist.h*
```C++
#ifndef CIRCULARLIST_H
#define CIRCULARLIST_H

#include <iostream>
using namespace std;

#define NIL NULL

struct mahasiswa {
    string nama;
    string nim;
    char jk;
    float ipk;
};
typedef mahasiswa infotype;
typedef struct Node *address;

struct Node {
    infotype data;
    address next;
};
struct List {
    address first;
};
void createList(List &L);
address createNode(infotype data);
void deleteNode(address &P);

void addFirst(List &L, address P);
void addAfter(List &L, address prec, address P);
void addLast(List &L, address P);

void removeFirst(List &L, address &P);
void removeAfter(List &L, address prec, address &P);
void removeLast(List &L, address &P);

address searchByNim(List L, infotype x);
void showData(List L);

#endif
```

*circularlist.cpp*
```c++
#include "circularlist.h"

void createList(List &L){
    L.first = NIL;
}
address createNode(infotype data){
    address newNode = new Node;
    newNode->data = data;
    newNode->next = NIL;
    return newNode;
}
void deleteNode(address &P){
    delete P;
    P = NIL;
}
void addFirst(List &L, address P){
    if(L.first == NIL){
        L.first = P;
        P->next = P;
    } else {
        address last = L.first;
        while(last->next != L.first){
            last = last->next;
        }
        P->next = L.first;
        last->next = P;
        L.first = P;
    }
}
void addAfter(List &L, address prec, address P){
    P->next = prec->next;
    prec->next = P;
}
void addLast(List &L, address P){
    if(L.first == NIL){
        addFirst(L, P);
    } else {
        address last = L.first;
        while(last->next != L.first){
            last = last->next;
        }
        last->next = P;
        P->next = L.first;
    }
}
void removeFirst(List &L, address &P){
    if(L.first != NIL){
        address last = L.first;
        while(last->next != L.first){
            last = last->next;
        }
        P = L.first;
        if(P->next == P){
            L.first = NIL;
        } else {
            L.first = P->next;
            last->next = L.first;
        }
        P->next = NIL;
    }
}
void removeAfter(List &L, address prec, address &P){
    P = prec->next;
    prec->next = P->next;
    P->next = NIL;
}
void removeLast(List &L, address &P){
    if(L.first != NIL){
        address curr = L.first;
        address prev = NIL;

        while(curr->next != L.first){
            prev = curr;
            curr = curr->next;
        }
        P = curr;
        if(prev == NIL){
            L.first = NIL;
        } else {
            prev->next = L.first;
        }
        P->next = NIL;
    }
}
address searchByNim(List L, infotype x){
    if(L.first == NIL) return NIL;

    address temp = L.first;
    do {
        if(temp->data.nim == x.nim){
            return temp;
        }
        temp = temp->next;
    } while(temp != L.first);

    return NIL;
}
void showData(List L){
    if(L.first != NIL){
        address temp = L.first;
        do {
            cout << "Nama : " << temp->data.nama << endl;
            cout << "NIM  : " << temp->data.nim << endl;
            cout << "JK   : " << temp->data.jk << endl;
            cout << "IPK  : " << temp->data.ipk << endl << endl;
            temp = temp->next;
        } while(temp != L.first);
    }
}
```

*main.cpp*
```c++
#include "circularlist.h"

address buatData(string nama, string nim, char jk, float ipk){
    infotype mhs;
    mhs.nama = nama;
    mhs.nim = nim;
    mhs.jk = jk;
    mhs.ipk = ipk;
    return createNode(mhs);
}
int main(){
    List L;
    address pCari, pBaru;
    infotype key;

    createList(L);

    cout << "Percobaan insert data mahasiswa" << endl;

    addFirst(L, buatData("Danu", "04", 'L', 4.0));
    addLast(L, buatData("Fahmi", "06", 'L', 3.45));
    addFirst(L, buatData("Bobi", "02", 'L', 3.71));
    addFirst(L, buatData("Ali", "01", 'L', 3.3));
    addLast(L, buatData("Gita", "07", 'P', 3.75));

    key.nim = "07";
    pCari = searchByNim(L, key);
    pBaru = buatData("Cindi", "03", 'P', 3.5);
    addAfter(L, pCari, pBaru);

    key.nim = "02";
    pCari = searchByNim(L, key);
    pBaru = buatData("Hilmi", "08", 'P', 3.3);
    addAfter(L, pCari, pBaru);

    key.nim = "04";
    pCari = searchByNim(L, key);
    pBaru = buatData("Eli", "05", 'P', 3.4);
    addAfter(L, pCari, pBaru);

    showData(L);
    return 0;
}
```

#### Output:
<img width="783" height="914" alt="{C28924B0-1C91-4DB6-8085-885A7314648C}" src="https://github.com/user-attachments/assets/1c6679a9-b620-4fb0-b6d2-5efd2cb6bae9" />

Program ini digunakan untuk mengelola data mahasiswa menggunakan circular linked list. Data disimpan dalam bentuk melingkar sehingga elemen terakhir terhubung kembali ke elemen pertama. Program mendukung penambahan, pencarian berdasarkan NIM, dan penampilan data mahasiswa.

#### Full code Screenshot:
<img width="1920" height="1080" alt="{611BE1ED-FBC8-4DDA-9CE7-A5DB56D551B8}" src="https://github.com/user-attachments/assets/b51a4cf3-117d-41ed-81a8-4834705fe3b0" />
<img width="1920" height="1080" alt="{DE72D7A9-6260-41C3-BBBA-4BA8194DC032}" src="https://github.com/user-attachments/assets/4befacff-73c8-4675-9509-bed1b0c3cbcb" />
<img width="1920" height="1080" alt="{3BF2BA6E-41A9-4684-9544-2B5C8C2E8AEC}" src="https://github.com/user-attachments/assets/8c447430-bd86-499d-b2f8-e83534034040" />


## Kesimpulan
Multi Linked List dan Circular Linked List dapat digunakan untuk mengelola data yang saling berhubungan secara dinamis. Implementasi struktur data tersebut dengan bahasa C++ berhasil menjalankan operasi dasar seperti penambahan, pencarian, dan penampilan data, sehingga membantu memahami konsep linked list dengan lebih baik.

## Referensi
1. Modul 12 MULTI LINKED LIST
2. Sukamto, R. A., & Shalahuddin, M. (2018).
3. GeeksforGeeks “Circular Linked List meaning in DSA”




