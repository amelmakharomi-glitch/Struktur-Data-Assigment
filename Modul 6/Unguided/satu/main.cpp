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