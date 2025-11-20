#ifndef PELAJARAN_H_INCLUDED
#define PELAJARAN_H_INCLUDED

#include <string>
using namespace std;

struct Pelajaran {
    string namaMatkul;
    string kodeMatkul;
};
Pelajaran buatPelajaran(string nama, string kode);
void tampilPelajaran(Pelajaran data);

#endif