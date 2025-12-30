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