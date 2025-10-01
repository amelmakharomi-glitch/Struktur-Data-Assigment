#include <iostream>
using namespace std;

int main() {
    float a, b;
    cout << "bilangan pertama: ";
    cin >> a;
    cout << "bilangan kedua: ";
    cin >> b;

    cout << "Hasil Penjumlahan: " << a + b << endl;
    cout << "Hasil Pengurangan: " << a - b << endl;
    cout << "Hasil Perkalian  : " << a * b << endl;
    if (b != 0)
        cout << "Hasil Pembagian  : " << a / b << endl;
    else
        cout << "Pembagian tidak dapat dilakukan (pembagi = 0)" << endl;

    return 0;
}
