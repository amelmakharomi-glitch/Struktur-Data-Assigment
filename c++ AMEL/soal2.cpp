#include <iostream>
#include <string>
using namespace std;

string satuan[] = {"", "Satu", "Dua", "Tiga", "Empat", "Lima", 
                   "Enam", "Tujuh", "Delapan", "Sembilan"};
string belasan[] = {"Sepuluh", "Sebelas", "Dua Belas", "Tiga Belas", "Empat Belas",
                    "Lima Belas", "Enam Belas", "Tujuh Belas", "Delapan Belas", "Sembilan Belas"};
string puluhan[] = {"", "", "Dua Puluh", "Tiga Puluh", "Empat Puluh", 
                    "Lima Puluh", "Enam Puluh", "Tujuh Puluh", "Delapan Puluh", "Sembilan Puluh"};

string konversi(int n) {
    if (n == 0) return "Nol";
    else if (n < 10) return satuan[n];
    else if (n < 20) return belasan[n - 10];
    else if (n < 100) {
        int p = n / 10;
        int s = n % 10;
        if (s == 0) return puluhan[p];
        else return puluhan[p] + " " + satuan[s];
    }
    else if (n == 100) return "Seratus";
    return "Diluar jangkauan";
}

int main() {
    int angka;
    cout << "Masukkan angka (0-100): ";
    cin >> angka;

    cout << angka << " : " << konversi(angka) << endl;

    return 0;
}
