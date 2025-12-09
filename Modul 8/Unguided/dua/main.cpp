#include "queue.h" 
#include <iostream>

using namespace std;

int main() {
    cout << "UJI ALTERNATIF 2 (Head/Tail Bergerak)" << endl;

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

    cout << "DEQUEUE 3x (H berubah) >>" << endl;
    keluarkan(Q); tampilkanData(Q); 
    keluarkan(Q); tampilkanData(Q); 
    keluarkan(Q); tampilkanData(Q); 
    
    cout << "ENQUEUE 60 (Harusnya geser data) >>" << endl;
    masukkan(Q, 60); tampilkanData(Q); 
    
    masukkan(Q, 70); tampilkanData(Q); 
    masukkan(Q, 80); tampilkanData(Q); 

    cout << "ENQUEUE 90 (Penuh Sesungguhnya) >>" << endl;
    masukkan(Q, 90); 
    tampilkanData(Q); 

    return 0;
}