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