#include <iostream>
#include <string>
using namespace std; 

struct mahasiswa {
    string nama;
    int umur;

};

int main(){
    int jumlah;

    cout << "masukkan jumlah mahasigma : ";
    cin >> jumlah;

    mahasiswa mhs[jumlah];

    for (int i = 0; i < jumlah; i++) {
        cout << "\nMahasiswa ke-" << i + 1 << endl;
        cout << "Nama : ";
        cin >> mhs[i].nama;
        cout << "Umur: ";
        cin >> mhs[i].umur;
    }

    cout << "\n === Data Mahasiswa ===\n";
    for (int i = 0; i < jumlah; i++) {
        cout << "Mahasiswa ke- " << i + 1
            << " | Nama: " << mhs [i].nama
            << " | Umur: " << mhs [i].umur << endl;
    }

    return 0;
}