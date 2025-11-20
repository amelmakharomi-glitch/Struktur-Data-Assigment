# <h1 align="center">Laporan Praktikum Modul Pengenalan Bahasa C++ (1)</h1>
<p align="center">Amelia Sofiana Makharomi</p>

## Dasar Teori

Bahasa C++ merupakan turunan dari C yang mendukung pemrograman prosedural dan berorientasi objek. Praktikum ini menggunakan Code::Blocks IDE sebagai alat untuk menulis, mengompilasi, dan menjalankan program. Struktur dasar C++ meliputi header (#include <iostream>), fungsi utama (int main()), serta penggunaan cout dan cin untuk input-output. Bahasa ini juga memiliki tipe data, operator, dan struktur kontrol seperti if, for, dan while untuk mengatur logika program.

## Guided 

### 1. Modul Codeblocks IDE & Pengenalan Bahas C++ (1)


```C++
#include <iostream>

using namespace std;

int main () {
    // array 1 dimensi
    int arrID[5] = {10,20,30,40,50};
    cout << "Array 1 Dimensi" << endl;
    for (int i=0; i<5; i++) {
        cout << "arrID" << i << " = " << arrID[i] << endl; 
        
    }
    cout << endl;

    // array 2 dimensi baris & kolom
    int arr2D[2][3] = {
        {1,2,3},
        {4,5,6}
    };
    cout << "Array 2 Dimensi" << endl;
    for (int i=0; i<2; i++) {
        for (int j=0; j<3; j++) {
            cout << "arr2D[" << i << "}[" << j << "] = " << arr2D[i][j]
            << " ";
        }
        cout << endl;
    }
    cout << endl;
    
    //array multi dimensi (3D)
    int arr3D[2][2][3] = {
    { { 1, 2, 3 }, {4, 5, 6} },
    { { 7, 8, 9} , {10, 11, 12} }   
    };
    cout << "array 3 dimensi" << endl;
    for (int i=0; i<2; i++) {
        for (int j=0; j<2; j++) {
            for (int k=0; k<3; k++) {
                cout << "arr3D[" << i << "][" << j << "]["
                << k << "] = " << arr3D[i][j][k] << endl;
            }
        }
    }

    return 0;
}
```

## Unguided 

### 1. [Soal]

```C++
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
```
#### Output:
<img width="1106" height="203" alt="{F816EAB5-B151-45F5-A13B-00627255978B}" src="https://github.com/user-attachments/assets/5bc2dc54-38e7-437e-a002-a3647883a28d" />

Program ini meminta dua input bertipe float dari pengguna, lalu menampilkan hasil penjumlahan, pengurangan, perkalian, dan pembagian menggunakan operator aritmatika dasar.

### 2. [Soal]

```C++
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
```
#### Output:
<img width="1108" height="151" alt="{FD92FDF0-ECB1-4FFA-A456-8D6093B6F340}" src="https://github.com/user-attachments/assets/d7cbcbd8-2978-4efa-a9e1-ea8a5163b9d1" />

Program di atas digunakan untuk mengubah angka yang dimasukkan pengguna menjadi tulisan. Hasil konversinya, ditampilkan dengan perintah cout.

### 3. [Soal]

```C++
#include <iostream>
using namespace std;

int main() {
    int n;
    cout << "input: ";
    cin >> n;

    cout << "output:" << endl;
    for (int i = n; i >= 1; i--) {

        for (int s = n; s > i; s--)
            cout << "  ";

        for (int j = i; j >= 1; j--)
            cout << j << " ";

        cout << "* ";

        for (int j = 1; j <= i; j++)
            cout << j << " ";

        cout << endl;
    }
    for (int s = 0; s < n; s++)
        cout << "  ";
    cout << "*" << endl;

    return 0;
}
```
#### Output:
<img width="1119" height="173" alt="{FEEC10BE-9718-4E8F-8139-9482F55CA9AA}" src="https://github.com/user-attachments/assets/9711b5ac-a0de-4f8a-8aa2-827f586a20cb" />

Program ini menampilkan pola cermin angka dengan menggunakan perulangan bersarang. Spasi di awal baris berfungsi untuk merapikan tampilan agar simetris. Angka bagian kiri dicetak menurun, diikuti tanda *, lalu angka bagian kanan dicetak menaik. Baris terakhir hanya menampilkan tanda * di tengah sebagai akhir pola.


## Kesimpulan
C++ memiliki struktur program yang teratur dan mudah dipahami untuk membuat program sederhana. Mempraktikkan penggunaan input-output (cin, cout), variabel, tipe data, serta percabangan dan perulangan. 

## Referensi
1. Modul 1_Codeblocks IDE & Pengenalan Bahasa C++ (Bagian Pertama)
2. Cplusplus.com. (2024). Basic Input/Output in C++.
