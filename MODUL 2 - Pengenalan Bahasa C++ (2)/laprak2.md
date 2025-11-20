# <h1 align="center">Laporan Praktikum Modul Pengenalan Bahasa C++ (2)</h1>
<p align="center">Amelia Sofiana Makharomi</p>

## Dasar Teori

Modul ini membahas konsep dasar C++ seperti penggunaan array, fungsi, pointer, matriks, dan struktur kontrol switch-case untuk memahami cara pengolahan data, pemanggilan fungsi, serta pembuatan logika program yang terstruktur.

## Guided 

### 1. MODUL PENGENALAN BAHASA C++ BAGIAN 2


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
    int A[3][3], B[3][3], C[3][3];

    cout << "Matriks A:\n";
    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++)
            cin >> A[i][j];

    cout << "Matriks B:\n";
    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++)
            cin >> B[i][j];

    cout << "\nHasil Penjumlahan (A + B):\n";
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            C[i][j] = A[i][j] + B[i][j];
            cout << C[i][j] << "\t";
        }
        cout << endl;
    }
    cout << "\nHasil Pengurangan (A - B):\n";
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            C[i][j] = A[i][j] - B[i][j];
            cout << C[i][j] << "\t";
        }
        cout << endl;
    }
    cout << "\nHasil Perkalian (A x B):\n";
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            C[i][j] = 0;
            for (int k = 0; k < 3; k++)
                C[i][j] += A[i][k] * B[k][j];
            cout << C[i][j] << "\t";
        }
        cout << endl;
    }
    return 0;
}
```
#### Output:
<img width="1102" height="479" alt="{5FC99FFF-72AA-46FF-8566-9CF46077A4F4}" src="https://github.com/user-attachments/assets/74a4c370-5091-4706-8141-7e19339bccd0" />

Program ini menampilkan hasil tiga operasi utama pada matriks 3x3: penjumlahan, pengurangan, dan perkalian, menggunakan konsep array dua dimensi dan perulangan bersarang dari materi dasar C++.

### 2. [Soal]

```C++
#include <iostream>
using namespace std;

void tukarPointer(int *a, int *b, int *c) {
    int temp = *a;
    *a = *b;
    *b = *c;
    *c = temp;
}
void tukarReference(int &x, int &y, int &z) {
    int temp = x;
    x = y;
    y = z;
    z = temp;
}
int main() {
    int a, b, c;
    cout << "Tiga nilai: ";
    cin >> a >> b >> c;

    cout << "\nNilai awal: a=" << a << " b=" << b << " c=" << c << endl;

    tukarPointer(&a, &b, &c);
    cout << "Setelah tukar (pointer): a=" << a << " b=" << b << " c=" << c << endl;

    tukarReference(a, b, c);
    cout << "Setelah tukar (reference): a=" << a << " b=" << b << " c=" << c << endl;

    return 0;
}
```
#### Output:
<img width="1112" height="150" alt="{9FC8FC68-38B0-4A9A-8270-4492532D5F7C}" src="https://github.com/user-attachments/assets/1f804264-10d7-4b06-ae6f-b7fd10a42d75" />

Program ini menukar nilai tiga variabel dengan dua cara: pointer yang mengakses alamat memori, dan reference. Keduanya memungkinkan perubahan nilai variabel tanpa mengembalikan hasil dari fungsi.

### 3. [Soal]

```C++
#include <iostream>
using namespace std;

int cariMinimum(int arr[], int n) {
    int min = arr[0];
    for (int i = 1; i < n; i++)
        if (arr[i] < min)
            min = arr[i];
    return min;
}
int cariMaksimum(int arr[], int n) {
    int max = arr[0];
    for (int i = 1; i < n; i++)
        if (arr[i] > max)
            max = arr[i];
    return max;
}
void hitungRataRata(int arr[], int n) {
    float total = 0;
    for (int i = 0; i < n; i++)
        total += arr[i];
    cout << "Nilai rata-rata = " << total / n << endl;
}
int main() {
    int arrA[] = {11, 8, 5, 7, 12, 26, 3, 54, 33, 55};
    int n = sizeof(arrA) / sizeof(arrA[0]);
    int pilih;

    do {
        cout << "\n--- Menu Program Array ---\n";
        cout << "1. Tampilkan isi array\n";
        cout << "2. Cari nilai maksimum\n";
        cout << "3. Cari nilai minimum\n";
        cout << "4. Hitung nilai rata-rata\n";
        cout << "5. Keluar\n";
        cout << "Pilih menu: ";
        cin >> pilih;

        switch (pilih) {
            case 1:
                cout << "Isi array: ";
                for (int i = 0; i < n; i++)
                    cout << arrA[i] << " ";
                cout << endl;
                break;
            case 2:
                cout << "Nilai maksimum = " << cariMaksimum(arrA, n) << endl;
                break;
            case 3:
                cout << "Nilai minimum = " << cariMinimum(arrA, n) << endl;
                break;
            case 4:
                hitungRataRata(arrA, n);
                break;
            case 5:
                cout << "Program selesai.\n";
                break;
            default:
                cout << "Pilihan tidak valid.\n";
        }
    } while (pilih != 5);
    return 0;
}
```
#### Output:
<img width="866" height="811" alt="{79ADFBDA-14F5-4673-970B-C62D0913572A}" src="https://github.com/user-attachments/assets/71338492-e392-4fbb-8f69-a406cab0b06e" />

Program ini menggunakan array satu dimensi untuk menyimpan data, lalu mengolahnya dengan tiga fungsi: mencari nilai maksimum, minimum, dan rata-rata. Struktur switch-case dipakai untuk menampilkan menu interaktif agar pengguna dapat memilih operasi yang diinginkan.

## Kesimpulan
Menjelaskan konsep dasar C++ meliputi array, fungsi, pointer, reference, serta penggunaan perulangan dan percabangan. Dari tiga latihan yang dikerjakan, diperoleh pemahaman tentang pengolahan data matriks, pertukaran nilai variabel melalui pointer dan reference, serta pembuatan program sederhana untuk menampilkan nilai maksimum, minimum, dan rata-rata. Secara keseluruhan, modul ini membantu memahami logika dan struktur dasar dalam pemrograman C++ sebagai landasan untuk tahap lanjutan.

## Referensi
1. Modul 2_Pengenalan Bahasa C++ (bagian 2)
2. Programiz. (2024). C++ Pointers and Arrays.



