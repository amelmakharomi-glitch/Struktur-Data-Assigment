#ifndef ANTREAM_H
#define ANTREAM_H

#include <iostream>

typedef int TipeData;

#define MAX_ELEMEN 5 

struct Antrean {
    TipeData data[MAX_ELEMEN]; 
    int depan;                
    int belakang;              
};
void buatAntreanKosong(Antrean &Q);
bool apaKosong(Antrean Q);
bool apaPenuh(Antrean Q);
void masukkan(Antrean &Q, TipeData nilaiBaru);
TipeData keluarkan(Antrean &Q);
void tampilkanData(Antrean Q);

#endif