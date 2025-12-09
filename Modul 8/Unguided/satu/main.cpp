#include "queue.h" 
#include <iostream>

using namespace std;

int main() {
    cout << "Hello World!" << endl;

    Antrean Q;
    buatAntreanKosong(Q);

    cout << "-------------" << endl;
    cout << " H - T : Queue Info" << endl;
    cout << "-------------" << endl;

    tampilkanData(Q); 
    masukkan(Q, 5); tampilkanData(Q); 
    masukkan(Q, 2); tampilkanData(Q); 
    masukkan(Q, 7); tampilkanData(Q); 
    keluarkan(Q); tampilkanData(Q); 
    masukkan(Q, 4); tampilkanData(Q);
    keluarkan(Q); tampilkanData(Q); 
    keluarkan(Q); tampilkanData(Q); 
    keluarkan(Q); tampilkanData(Q); 

    return 0;
}