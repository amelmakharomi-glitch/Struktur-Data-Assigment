# <h1 align="center">ABSTRACT DATA TYPE (ADT)</h1>
<p align="center">Amelia Sofiana Makharomi</p>

## Dasar Teori

Abstract Data Type (ADT) adalah tipe data buatan sendiri yang memiliki struktur data (type) dan operasi dasar (primitif) untuk mengelola data tersebut.
ADT bersifat abstrak, artinya pengguna cukup tahu apa yang dilakukan, bukan bagaimana cara kerjanya di dalam.

## Guided 

### 1. ABSTRACT DATA TYPE (ADT) 

```C++
#include <iostream>
using namespace std;

struct mahasiswa{ 
char nim[10]; 
int nilai1,nilai2;
};
void inputMhs(mahasiswa &m); 
float rata2(mahasiswa m);

int main() 
{ 
mahasiswa mhs; 
inputMhs(mhs); 
cout << “rata-rata = “ << rata2(mhs); 
return 0; 
}


void inputMhs(mahasiswa &m){ 
cout << “input nama = “; 
cin >> m.nim; 
cout << “input nilai = “; 
cin >> m.nilai1; 
cout << “input nilai2 = “;
cin >> m.nilai2; 
} 
float rata2(mahasiswa m){ 
return float(m.nilai1+m.nilai2)/2; 
}

mahasiswa.h
#ifndef MAHASISWA_H_INCLUDED 
#define MAHASISWA_H_INCLUDED 
struct mahasiswa{ 
char nim[10]; 
int nilai1, nilai2; 
};
void inputMhs(mahasiswa &m); 
float rata2(mahasiswa m); 
#endif // MAHASISWA_H_INCLUDED

mahasiswa.cpp
#include “mahasiswa.h” 
void inputMhs(mahasiswa &m){ 
cout << “input nama = “; 
cin >> (m).nim; 
cout << “input nilai = “; 
cin >> (m).nilai1; 
cout << “input nilai2 = “; 
cin >> (m).nilai2;
} 
 
float rata2(mahasiswa m){ 
  return float(m.nilai1+m.nilai2)/2; 
}
}
```

## Unguided 

### 1. [Soal]
```C++
#include <iostream>
#include <string>
using namespace std;

struct Mahasiswa {
    string nama, nim;
    float uts, uas, tugas, nilaiAkhir;
};
float hitungNilaiAkhir(float uts, float uas, float tugas) {
    return 0.3 * uts + 0.4 * uas + 0.3 * tugas;
}
int main() {
    Mahasiswa mhs[10];
    int n;

    cout << "Jumlah mahasiswa (max 10): ";
    cin >> n; cin.ignore();

    for (int i = 0; i < n; i++) {
        cout << "\nData ke-" << i + 1 << endl;
        cout << "Nama  : "; getline(cin, mhs[i].nama);
        cout << "NIM   : "; getline(cin, mhs[i].nim);
        cout << "UTS   : "; cin >> mhs[i].uts;
        cout << "UAS   : "; cin >> mhs[i].uas;
        cout << "Tugas : "; cin >> mhs[i].tugas;
        cin.ignore();

        mhs[i].nilaiAkhir = hitungNilaiAkhir(mhs[i].uts, mhs[i].uas, mhs[i].tugas);
    }

    cout << "\n=== DATA MAHASISWA ===\n";
    for (int i = 0; i < n; i++) {
        cout << mhs[i].nama << " (" << mhs[i].nim << ") - Nilai Akhir: " 
             << mhs[i].nilaiAkhir << endl;
    }
    return 0;
}
```
#### Output:
<img width="1097" height="529" alt="{047334C9-DDFF-4D67-8926-99341881F0BA}" src="https://github.com/user-attachments/assets/46068a34-7ae9-490d-a1a5-7de581e884c9" />

Program tersebut berfungsi untuk mengelola data mahasiswa hingga maksimal 10 orang.
Di dalamnya digunakan struktur Mahasiswa yang berisi informasi nama, NIM, nilai UTS, UAS, dan tugas, lalu program akan menghitung dan menampilkan nilai akhir tiap mahasiswa secara otomatis.

### 2. [Soal]

**pelajaran.h**
```C++
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
```

**pelajaran.cpp**
```C++
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
```

**main.cpp**
```C++
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
```
#### Output:
<img width="873" height="88" alt="{140DF472-04E1-404A-BB99-E44C8A11D96E}" src="https://github.com/user-attachments/assets/4b7058e0-69e5-4099-90c9-9905e106f081" />

Program di atas menerapkan konsep ADT (Abstract Data Type) dengan memisahkan bagian:

Header (.h) untuk definisi tipe dan deklarasi fungsi

Implementasi (.cpp) untuk isi fungsi/prosedur ADT

Main (.cpp) untuk menggunakan ADT tersebut

Program ini menampilkan nama dan kode mata pelajaran yang dibuat melalui fungsi create_pelajaran() dan ditampilkan oleh tampil_pelajaran().

### 3. [Soal]

```C++
#include <iostream>
using namespace std;

void tampil(int arr[3][3]) {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) cout << arr[i][j] << "\t";
        cout << endl;
    }
}
void tukarArray(int a[3][3], int b[3][3], int i, int j) {
    int tmp = a[i][j];
    a[i][j] = b[i][j];
    b[i][j] = tmp;
}
void tukarPointer(int *p1, int *p2) {
    int tmp = *p1;
    *p1 = *p2;
    *p2 = tmp;
}
int main() {
    int A[3][3] = {{1,2,3},{4,5,6},{7,8,9}};
    int B[3][3] = {{10,11,12},{13,14,15},{16,17,18}};
    int x = 20, y = 40;

    cout << "Array A awal:\n"; tampil(A);
    cout << "\nArray B awal:\n"; tampil(B);

    tukarArray(A, B, 1, 1);

    cout << "\nArray A sesudah tukar:\n"; tampil(A);
    cout << "\nArray B sesudah tukar:\n"; tampil(B);

    cout << "\nSebelum tukar pointer: x=" << x << ", y=" << y << endl;
    tukarPointer(&x, &y);
    cout << "Sesudah tukar pointer: x=" << x << ", y=" << y << endl;

    return 0;
}
```
#### Output:
<img width="1108" height="442" alt="{95850B69-17AE-4142-9C24-BB2731C3B81B}" src="https://github.com/user-attachments/assets/54e9d5cf-5eb5-44f5-a92a-fb3d414aed89" />

Program ini menampilkan isi 2 array 3×3, menukar elemen pada posisi tertentu antara keduanya, serta menukar nilai 2 variabel menggunakan pointer.

## Kesimpulan
Praktikum modul 3 ini menunjukkan bahwa bahasa C++ dapat digunakan untuk mengelola data secara terstruktur dan modular dengan memanfaatkan struct, array, fungsi, serta pointer. Melalui penerapan konsep Abstract Data Type (ADT) dan pemisahan kode ke dalam file header dan implementasi, program menjadi lebih terorganisir, mudah dipahami, serta efisien untuk digunakan maupun dikembangkan kembali.

## Referensi
1. Modul 3 Strukdat
2. Carrano, F. M., & Henry, T. Data Abstraction and Problem Solving with C++: Walls and Mirrors (7th Edition). Pearson, 2017.
"ADT membantu dalam pemodelan data dan operasi dengan pendekatan modular agar program lebih mudah dikelola dan dikembangkan."
