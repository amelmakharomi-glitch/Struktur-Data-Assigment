#include <iostream>
#include "pelajaran.h"
using namespace std;

int main() {
    string nama = "Struktur Data";
    string kode = "STD";

    Pelajaran matkul = buatPelajaran(nama, kode);
    tampilPelajaran(matkul);

    return 0;
}
