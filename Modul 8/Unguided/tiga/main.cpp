#include "queue.h" 
#include <iostream>
#include <iomanip>

using namespace std;

int main() {
    cout << "UJI ALTERNATIF 3 (Head/Tail Berputar - Circular Queue)" << endl;

    Antrean Q;
    buatAntreanKosong(Q);

    cout << "-----------------------------------" << endl;
    cout << " H - T : Queue Info" << endl;
    cout << "-----------------------------------" << endl;

    masukkan(Q, 10); 
    masukkan(Q, 20); 
    masukkan(Q, 30); 
    masukkan(Q, 40); 
    masukkan(Q, 50); tampilkanData(Q); 

    cout << "DEQUEUE 3x (H bergerak) >>" << endl;
    keluarkan(Q); tampilkanData(Q);
    keluarkan(Q); tampilkanData(Q); 
    keluarkan(Q); tampilkanData(Q); 
    
    cout << "ENQUEUE 60 (Tail berputar ke 0) >>" << endl;
    masukkan(Q, 60); tampilkanData(Q);
    cout << "ENQUEUE 70 (Tail maju ke 1) >>" << endl;
    masukkan(Q, 70); tampilkanData(Q); 
    cout << "ENQUEUE 80 (Tail maju ke 2 -> PENUH) >>" << endl;
    masukkan(Q, 80); tampilkanData(Q); 
    cout << "ENQUEUE 90 (Gagal, Penuh) >>" << endl;
    masukkan(Q, 90); tampilkanData(Q); 
    cout << "DEQUEUE 4x (H berputar ke 0) >>" << endl;
    keluarkan(Q); tampilkanData(Q); 
    keluarkan(Q); tampilkanData(Q); 
    keluarkan(Q); tampilkanData(Q); 
    keluarkan(Q); tampilkanData(Q); 
    
    cout << "DEQUEUE terakhir (Kosong) >>" << endl;
    keluarkan(Q); tampilkanData(Q); 

    return 0;
}