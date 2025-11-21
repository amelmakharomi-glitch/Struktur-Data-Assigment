
  # <h1 align="center">Laporan Praktikum Modul Stack</h1>
<p align="center">Amelia Sofiana Makharomi</p>

## Dasar Teori

Modul ini membahas dasar-dasar struktur data Stack menggunakan array dalam bahasa C++. Stack merupakan struktur data yang mengikuti prinsip Last In, First Out (LIFO), di mana elemen yang terakhir dimasukkan akan menjadi elemen pertama yang dikeluarkan. Dalam implementasi berbasis array, stack terdiri dari sebuah array penampung data dan variabel top yang menunjuk ke posisi elemen teratas. Modul menjelaskan cara menginisialisasi stack, menambah data menggunakan operasi push, menghapus data menggunakan pop, serta menampilkan isi stack melalui printInfo. Selain operasi dasar, modul juga memperkenalkan pengembangan stack seperti membalik urutan elemen dengan balikStack, memasukkan elemen secara terurut menggunakan pushAscending, dan membaca input karakter berturut-turut dengan getInputStream. Dengan mempelajari materi ini, mahasiswa dapat memahami bagaimana stack bekerja, bagaimana operasi dilakukan pada struktur LIFO, serta bagaimana array dimanfaatkan untuk mengelola data secara terstruktur dan efisien.
## Guided 

### 1. [Stack]
*stack.h*
```C++
#ifndef STACK_TABLE
#define STACK_TABLE

#include <iostream>
using namespace std;

//ubah kapasitas sesuai kebutuhan
const int MAX = 10;

struct stackTable{
    int data[MAX];
    int top; // -1 = kosong

};

bool isEmpty(stackTable s);
bool isFull(stackTable s);
void createStack(stackTable &s);

void push(stackTable &s, int angka);
void pop(stackTable &s);
void update(stackTable &s, int posisi);
void view(stackTable s);
void searchData(stackTable s, int data);

#endif
```
*stack.cpp*
```C++
#include "stack.h"
#include <iostream>

using namespace std;

bool isEmpty(stackTable s) {
    return s.top == -1;
}

bool isFull(stackTable s){
    return s.top == MAX -1;
}

void createStack(stackTable &s) {
    s.top = -1;
}

void push(stackTable &s, int angka){
    if(isFull(s)){
        cout << "Stack Penuh!" << endl;
    } else {
        s.top++;
        s.data[s.top] = angka;
        cout << "Data " << angka << " berhasil ditambahkan kedalam stack!" << endl;
    }
}

void pop(stackTable &s){
    if(isEmpty(s)){
        cout << "Stack kosong!" << endl;
    } else {
        int val = s.data[s.top];
        s.top--;
        cout << "Data " << val << " Berhasil dihapus dari stack!" << endl;
    }
}

void update(stackTable &s, int posisi){
    if(isEmpty(s)){
        cout << "Stack kosong!" << endl;
        return;
    }
    if(posisi <= 0){
        cout << "Posisi tidak valid!" << endl;
        return;
    }

    //index = top - (posisi -1)
    int idx = s.top - (posisi -1);
    if(idx < 0 || idx > s.top){
        cout << "Posisi " << posisi << " Tidak valid!" << endl;
        return;
    }

    cout << "Update data posisi ke-" << posisi << endl;
    cout << "Masukkan angka: ";
    cin >> s.data[idx];
    cout << "Data berhasil diupdate!" << endl;
    cout << endl;
}

void view(stackTable s){
    if(isEmpty(s)){
        cout << "Stack Kosong!" << endl;
    } else {
        for(int i = s.top; i >= 0; --i){
            cout << s.data[i] << " ";
        }
    }
    cout << endl;
}

void searchData(stackTable s, int data){
    if(isEmpty(s)){
        cout << "Stack Kosong!" << endl;
        return;
    }
    cout << "Mencari data" << data << "..." << endl;
    int posisi = 1;
    bool found = false;

    for(int i = s.top; i >= 0; --i){
        if(s.data[i] == data){
            cout << "Data " << data << " ditemukan pada posisi ke-" << posisi << endl;
            cout << endl;
            found = true;
            break;
        }
        posisi++;
    }

    if(!found){
        cout << "Data " << data << " tidak ditemukan didalam stack!" << endl;
        cout << endl;
    }
}
```
*main.cpp*
```C++
#include "stack.h"
#include <iostream>

using namespace std;

int main(){
    stackTable s;
    createStack(s);

    push(s, 1);
    push(s, 2);
    push(s, 3);
    push(s, 4);
    push(s, 5);
    cout << endl;

    cout << "--- Stack setelah push ---" << endl;
    view(s);
    cout << endl;

    pop(s);
    pop(s);
    cout << endl;

    cout << "--- Stack setelah pop 2 kali ---" << endl;
    view(s);
    cout << endl;

    //Posisi dihitung dari TOP(1-based)
    update(s, 2);
    update(s, 1);
    update(s, 4);
    cout << endl;

    cout << "--- Stack setelah update ---" << endl;
    view(s);
    cout << endl;

    searchData(s, 4);
    searchData(s, 9);

    return 0;
}
```

Program ini mengimplementasikan struktur data Stack menggunakan array dengan kapasitas tetap. Stack disimpan dalam struct stackTable yang memiliki array data dan variabel top sebagai penanda elemen teratas. Fungsi dasar seperti push dan pop digunakan untuk menambah dan menghapus elemen sesuai prinsip LIFO, sedangkan isEmpty dan isFull memeriksa kondisi stack. Fungsi update memungkinkan perubahan nilai pada posisi tertentu yang dihitung dari bagian atas stack, view menampilkan seluruh isi stack dari atas ke bawah, dan searchData melakukan pencarian elemen mulai dari top. Dalam fungsi main, beberapa data dimasukkan, dihapus, diperbarui, dan dicari sehingga menunjukkan bagaimana operasi-operasi stack bekerja secara keseluruhan.

## Unguided 

### 1. [Soal]
*stack.h*
```C++
#ifndef STACK_H
#define STACK_H

typedef int infotype;

typedef struct {
    infotype info[20];
    int top;
} Stack;

void createStack(Stack &S);
void push(Stack &S, infotype x);
infotype pop(Stack &S);
void printInfo(Stack S);
void balikStack(Stack &S);

#endif
```
*stack.cpp*
```C++
#include <iostream>
#include "stack.h"
using namespace std;

void createStack(Stack &S) {
    S.top = -1;
}

void push(Stack &S, infotype x) {
    if (S.top < 19) {
        S.top++;
        S.info[S.top] = x;
    } else {
        cout << "Stack penuh!" << endl;
    }
}

infotype pop(Stack &S) {
    if (S.top >= 0) {
        int x = S.info[S.top];
        S.top--;
        return x;
    } else {
        cout << "Stack kosong!" << endl;
        return -1;
    }
}

void printInfo(Stack S) {
    cout << "[TOP] ";
    for (int i = S.top; i >= 0; i--) {
        cout << S.info[i] << " ";
    }
    cout << endl;
}

void balikStack(Stack &S) {
    Stack temp;
    createStack(temp);

    while (S.top != -1) {
        push(temp, pop(S));
    }

    S = temp;
}
```
*main.cpp*
```C++
#include <iostream>
#include "stack.h"
using namespace std;

int main() {
    cout << "Hello world!" << endl;

    Stack S;
    createStack(S);

    push(S, 3);
    push(S, 4);
    push(S, 8);
    pop(S);
    push(S, 2);
    push(S, 3);
    pop(S);
    push(S, 9);

    printInfo(S);

    cout << "balik stack" << endl;
    balikStack(S);

    printInfo(S);

    return 0;
}
```
#### Output:
<img width="785" height="183" alt="image" src="https://github.com/user-attachments/assets/21905806-3133-4832-9a88-82bc969d40e4" />

Program ini mengimplementasikan ADT Stack menggunakan array. Stack menyimpan data dalam array info dan menggunakan variabel top untuk menandai posisi elemen paling atas. Fungsi createStack menginisialisasi stack, push menambah elemen ke atas stack, dan pop menghapus elemen teratas. Fungsi printInfo menampilkan isi stack dari atas ke bawah, sedangkan balikStack membalik urutan stack menggunakan stack sementara. Di fungsi main, beberapa operasi push dan pop dilakukan, kemudian isi stack ditampilkan sebelum dan sesudah dibalik.

#### Full code Screenshot:
<img width="404" height="439" alt="image" src="https://github.com/user-attachments/assets/49b94a02-1d5c-4ffa-a559-b9de0f33df7c" />
<img width="469" height="973" alt="image" src="https://github.com/user-attachments/assets/aa46b6dd-997c-4418-93a5-55a8e09a223a" />
<img width="438" height="638" alt="image" src="https://github.com/user-attachments/assets/3ea58a78-cee0-4f73-870c-0ef48920f927" />

### 2. [Soal]
*stack.h*
```C++
#ifndef STACK_H
#define STACK_H

typedef int infotype;

typedef struct {
    infotype info[20];
    int top;
} Stack;

void createStack(Stack &S);
void push(Stack &S, infotype x);
infotype pop(Stack &S);
void printInfo(Stack S);
void balikStack(Stack &S);
void pushAscending(Stack &S, infotype x);

#endif
```
*stack.cpp*
```C++
#include <iostream>
#include "stack.h"
using namespace std;

void createStack(Stack &S) {
    S.top = -1;
}

void push(Stack &S, infotype x) {
    if (S.top < 19) {
        S.top++;
        S.info[S.top] = x;
    } else {
        cout << "Stack penuh!" << endl;
    }
}

infotype pop(Stack &S) {
    if (S.top >= 0) {
        int x = S.info[S.top];
        S.top--;
        return x;
    } else {
        cout << "Stack kosong!" << endl;
        return -1;
    }
}

void printInfo(Stack S) {
    cout << "[TOP] ";
    for (int i = S.top; i >= 0; i--) {
        cout << S.info[i] << " ";
    }
    cout << endl;
}

void balikStack(Stack &S) {
    Stack temp;
    createStack(temp);

    while (S.top != -1) {
        push(temp, pop(S));
    }

    S = temp;
}

void pushAscending(Stack &S, infotype x) {
    Stack temp;
    createStack(temp);

    while (S.top != -1 && S.info[S.top] > x) {
        push(temp, pop(S));
    }

    push(S, x);

    while (temp.top != -1) {
        push(S, pop(temp));
    }
}

```
*main.cpp*
```C++
#include <iostream>
#include "stack.h"
using namespace std;

int main() {
    cout << "Hello world!" << endl;

    Stack S;
    createStack(S);

    pushAscending(S, 3);
    pushAscending(S, 4);
    pushAscending(S, 8);
    pushAscending(S, 2);
    pushAscending(S, 3);
    pushAscending(S, 9);

    printInfo(S);

    cout << "balik stack" << endl;
    balikStack(S);
    printInfo(S);

    return 0;
}
```
#### Output:
<img width="787" height="183" alt="image" src="https://github.com/user-attachments/assets/7340f79e-c980-47ef-8d51-683a56ba4121" />

Fungsi pushAscending memasukkan data ke stack sambil menjaga agar elemen-elemen di dalamnya tetap terurut naik. Cara kerjanya adalah memindahkan sementara elemen yang lebih besar, memasukkan nilai baru, lalu mengembalikan elemen yang dipindahkan. Di main, beberapa nilai dimasukkan dengan pushAscending, sehingga stack langsung tersusun ascending. Setelah ditampilkan, stack dibalik dengan balikStack dan hasilnya ditampilkan kembali.

#### Full code Screenshot:
<img width="429" height="450" alt="image" src="https://github.com/user-attachments/assets/d0e58b3e-2a1e-4495-b214-a1c400759466" />
<img width="368" height="890" alt="image" src="https://github.com/user-attachments/assets/5d090075-39fe-44f9-b741-15e5888487ce" />
<img width="436" height="576" alt="image" src="https://github.com/user-attachments/assets/eacb0216-15b2-4b42-99dd-cb59b21e637d" />

### 3. [Soal]
*stack.h*
```C++
#ifndef STACK_H
#define STACK_H

typedef int infotype;

typedef struct {
    infotype info[20];
    int top;
} Stack;

void createStack(Stack &S);
void push(Stack &S, infotype x);
infotype pop(Stack &S);
void printInfo(Stack S);
void balikStack(Stack &S);
void pushAscending(Stack &S, infotype x);
void getInputStream(Stack &S);

#endif
```
*stack.cpp*
```C++
#include <iostream>
#include "stack.h"
using namespace std;

void createStack(Stack &S) {
    S.top = -1;
}

void push(Stack &S, infotype x) {
    if (S.top < 19) {
        S.top++;
        S.info[S.top] = x;
    } else {
        cout << "Stack penuh!" << endl;
    }
}

infotype pop(Stack &S) {
    if (S.top >= 0) {
        int x = S.info[S.top];
        S.top--;
        return x;
    } else {
        cout << "Stack kosong!" << endl;
        return -1;
    }
}

void printInfo(Stack S) {
    cout << "[TOP] ";
    for (int i = S.top; i >= 0; i--) {
        cout << S.info[i] << " ";
    }
    cout << endl;
}

void balikStack(Stack &S) {
    Stack temp;
    createStack(temp);

    while (S.top != -1) {
        push(temp, pop(S));
    }

    S = temp;
}

void pushAscending(Stack &S, infotype x) {
    Stack temp;
    createStack(temp);

    while (S.top != -1 && S.info[S.top] > x) {
        push(temp, pop(S));
    }

    push(S, x);

    while (temp.top != -1) {
        push(S, pop(temp));
    }
}

void getInputStream(Stack &S) {
    char c;

    cin >> c;

    while (c != '\n')
    {
        push(S, c - '0');
        c = cin.get();
    }
}
```
*main.cpp*
```C++
#include <iostream>
#include "stack.h"
using namespace std;

int main() {
    cout << "Hello world!" << endl;

    Stack S;
    createStack(S);

    getInputStream(S);

    printInfo(S);

    cout << "balik stack" << endl;
    balikStack(S);
    printInfo(S);

    return 0;
}
```
#### Output:
<img width="781" height="199" alt="image" src="https://github.com/user-attachments/assets/c310e061-eee7-474d-bc68-353d6aaa0d28" />

getInputStream membaca input pengguna satu karakter setiap kali, kemudian memasukkan setiap karakter angka ke dalam stack. Pembacaan dilakukan terus-menerus menggunakan cin.get() sampai pengguna menekan tombol ENTER. Setiap karakter yang diterima dikonversi menjadi angka dan langsung dimasukkan ke stack dengan push. Di fungsi main, input dimasukkan sebagai rangkaian angka, lalu isi stack ditampilkan sebelum dan sesudah dibalik menggunakan balikStack.

#### Full code Screenshot:
<img width="419" height="485" alt="image" src="https://github.com/user-attachments/assets/3fdf8e30-5b0a-4e1e-ba72-ea67dcccd39a" />
<img width="309" height="883" alt="image" src="https://github.com/user-attachments/assets/b56f6a8e-6351-432e-9580-9997050d09c5" />
<img width="389" height="503" alt="image" src="https://github.com/user-attachments/assets/6aaccb67-9de1-49de-a9a0-b33b9685f103" />


## Kesimpulan
Kesimpulan dari ketiga program di atas adalah bahwa semuanya menerapkan konsep struktur data stack menggunakan array sebagai media penyimpanan. Program pertama menekankan pada operasi dasar seperti push, pop, menampilkan isi stack, serta membalik urutannya. Program kedua memperluas fungsi stack dengan menambahkan pushAscending yang memungkinkan penyisipan data secara terurut. Program ketiga menambahkan kemampuan membaca input karakter berurutan dari pengguna melalui getInputStream. Dari seluruh program tersebut dapat disimpulkan bahwa implementasi stack dengan array memungkinkan pengelolaan data secara terstruktur berdasarkan prinsip LIFO, sekaligus dapat dikembangkan dengan berbagai fitur tambahan. Pemahaman mengenai indeks array, operasi pada variabel top, serta alur masuk-keluarnya data menjadi hal penting agar stack dapat dikelola dengan benar dan efisien.


## Referensi
[1] GeeksforGeeks. (n.d.). Stack Data Structure. https://www.geeksforgeeks.org/stack-data-structure/
[2] Tutorialspoint. (n.d.). Data Structures — Stack. https://www.tutorialspoint.com/data_structures_algorithms/stack_algorithm.htm
[3] W3Schools. (n.d.). C++ Input and Streams. https://www.w3schools.com/cpp/cpp_files.asp
