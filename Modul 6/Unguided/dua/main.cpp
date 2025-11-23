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