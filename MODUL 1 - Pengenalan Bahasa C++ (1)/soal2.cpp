#include <iostream>
using namespace std;

int main() {
    int angka;
    string kata[] = {"nol","satu","dua","tiga","empat","lima","enam","tujuh","delapan","sembilan"};

    cout << "Masukkan angka (0-100): ";
    cin >> angka;

    if (angka < 0 || angka > 100)
        cout << "Angka tidak sesuai !" << endl;
    else if (angka == 100)
        cout << angka << " : seratus" << endl;
    else if (angka < 10)
        cout << angka << " : " << kata[angka] << endl;
    else if (angka < 20) {
        if (angka == 10) cout << angka << " : sepuluh" << endl;
        else if (angka == 11) cout << angka << " : sebelas" << endl;
        else cout << angka << " : " << kata[angka % 10] << " belas" << endl;
    } else {
        cout << angka << " : " << kata[angka / 10] << " puluh";
        if (angka % 10 != 0) cout << " " << kata[angka % 10];
        cout << endl;
    }
    return 0;
}
