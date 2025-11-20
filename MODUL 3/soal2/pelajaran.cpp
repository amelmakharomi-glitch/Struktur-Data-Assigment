#include <iostream>
#include "pelajaran.h"
using namespace std;

Pelajaran buatPelajaran(string nama, string kode) {
    Pelajaran pel;
    pel.namaMatkul = nama;
    pel.kodeMatkul = kode;
    return pel;
}
void tampilPelajaran(Pelajaran data) {
    cout << "Nama Mata Kuliah : " << data.namaMatkul << endl;
    cout << "Kode Mata Kuliah : " << data.kodeMatkul << endl;
}
