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