#include <iostream>
using namespace std;

int main() {
    float a, b; 

    cout << "Bilangan pertama: ";
    cin >> a;
    cout << "Bilangan kedua: ";
    cin >> b;

    cout << "\nHasil Operasi Aritmatika:" << endl;
    cout << "Penjumlahan  : " << a + b << endl;
    cout << "Pengurangan  : " << a - b << endl;
    cout << "Perkalian    : " << a * b << endl;
    cout << "Pembagian    : " << a / b << endl;

    return 0;
}
