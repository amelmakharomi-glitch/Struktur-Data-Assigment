# <h1 align="center">  TREE(BAGIANPERTAMA)  </h1>
<p align="center">Amelia Sofiana Makharomi</p>

## Dasar Teori
Tree merupakan struktur data non-linear yang menyimpan data secara hierarkis dengan satu root. Binary Search Tree (BST) adalah binary tree yang mengatur data sehingga nilai di kiri lebih kecil dan di kanan lebih besar dari parent. Operasi pada BST umumnya dilakukan secara rekursif, dan traversal in-order menghasilkan data terurut menaik.

## Guided 

### 1. [TREE]
bst.h
```C++
#ifndef BST_H
#define BST_H
#define Nil nullptr

using namespace std;

typedef struct BST *Node; //alis pointer = node

struct BST{ // nama structnya BST 
    int angka;
    node left;
    node right;
};

typedef node BinTree; //alias tree = BinTree (merujuk ke node root dari BST)

bool isEmpty(BinTree tree);
void createTree(Bintree &tree);
node alokasi(int angka);
void dealokasi(node nodeHapus);

void insertNode(BimTree &tree, node nodeBaru);
void searchByData(BinTree tree, int angka);
void preOrder(BInTree tree);
void inOrder(BinTree tree);
void postOrder(BinTree tree);

bool deleteNode(BinTree &tree, int angka);
node mostRight(BinTree tree);
node mostLeft(BinTree tree);
void deleteTree(BinTree &tree);
int size(BinTree tree);
int hegight(BinTree tree);

#endif
}
```
bst.cpp
```
#include <iostream>
#include "bst.h"

using namespace std;

int main() {
    BinTree tree;
    createTree(tree);

    int pilih, angka;

    do {
        cout << "========= MENU BST =========" << endl;
        cout << "1. Insert Node" << endl;
        cout << "2. Delete Node" << endl;
        cout << "3. Search Data" << endl;
        cout << "4. Tampilkan PreOrder" << endl;
        cout << "5. Tampilkan InOrder" << endl;
        cout << "6. Tampilkan PostOrder" << endl;
        cout << "7. Size Tree (jumlah node)" << endl;
        cout << "8. Height Tree (tinggi level)" << endl;
        cout << "9. Tampilkan mostright" << endl;
        cout << "10. Tampilkan mostleft" << endl;
        cout << "11. Delete Seluruh Tree" << endl;
        cout << "0. Keluar" << endl;
        cout << "pilihan anda : ";
        cin >> pilih;
        cout << endl;

        switch (pilih){
        case 1:
            cout << "Masukkan angka: ";
            cin >> angka;
            insertNode(tree, alokasi(angka));
            cout << endl;
            break;

        case 2:
            if(isEmpty(tree) == true){
                cout << "Tree kosong!" << endl;
            } else {
                cout << "Masukkan angka yang ingin dihapus: ";
                cin >> angka;
                if(deleteNode(tree, angka)){
                    cout << "Data " << angka << " berhasil dihapus!" << endl;
                } else {
                    cout << "Data " << angka << " tidak ditemukan!" << endl;
                }
            }
            cout << endl;
            break;

        case 3:
            if(isEmpty(tree) == true){
                cout << "Tree kosong!" << endl;
            } else {
                cout << "Masukkan angka yang ingin dicari: ";
                cin >> angka;
                searchByData(tree, angka);
            }
            cout << endl;
            break;

        case 4:
            if(isEmpty(tree) == true){
                cout << "Tree kosong!" << endl;
            } else {
                cout << "PreOrder : ";
                preOrder(tree);
                cout << endl;
            }
            cout << endl;
            break;

        case 5:
            if(isEmpty(tree) == true){
                cout << "Tree kosong!" << endl;
            } else {
                cout << "InOrder : ";
                inOrder(tree);
                cout << endl;
            }
            cout << endl;
            break;

        case 6:
            if(isEmpty(tree) == true){
                cout << "Tree kosong!" << endl;
            } else {
                cout << "PostOrder : ";
                postOrder(tree);
                cout << endl;
            }
            cout << endl;
            break;

        case 7:
            cout << "Size Tree = " << size(tree) << endl;
            cout << endl;
            break;

        case 8:
            cout << "Height Tree = " << height(tree) << endl;
            cout << endl;
            break;

        case 9: 
            if(isEmpty(tree) == true){
                cout << "Tree kosong!" << endl;
                cout << endl;
            } else {
                cout << "Mostright : " << mostRight(tree)->angka << endl;
                cout << endl;
            }
            break;
        
        case 10:
            if(isEmpty(tree) == true){
                cout << "Tree kosong!" << endl;
                cout << endl;
            } else {
                cout << "Mostleft : " << mostLeft(tree)->angka << endl;
                cout << endl;
            }
            break;

        case 11:
            if(isEmpty(tree) == true){
                cout << "Tree kosong!" << endl;
            } else {
                deleteTree(tree);
                cout << "Seluruh tree berhasil dihapus!" << endl;
            }
            cout << endl;
            break;

        case 0:
            cout << "Keluar dari program..." << endl;
            break;

        default:
            cout << "Pilihan tidak valid!" << endl;
            break;
        }

    } while (pilih != 0);

    return 0;
}
```
main.cpp

```
#include "bst.h"
#include <iostream>

using namespace std;

//NOTE : parameter tree disini maksudnya merujuk ke node; baik itu node root atau node lain dari tree

bool isEmpty(BinTree tree){
    if(tree == Nil){
        return true;
    } else {
        return false;
    }
}

void createTree(BinTree &tree){
    tree = Nil;
}

node alokasi(int angkaInput){
    node nodeBaru = new BST;
    nodeBaru->angka = angkaInput;
    nodeBaru->left = Nil;
    nodeBaru->right = Nil;
    return nodeBaru;
}

void dealokasi(node nodeHapus){
    delete nodeHapus;
}

void insertNode(BinTree &tree, node nodeBaru){
    if(tree == Nil){
        tree = nodeBaru;
        cout << "Node " << nodeBaru->angka << " berhasil ditambahkan ke dalam tree!" << endl;
        return;
    } else if(nodeBaru->angka < tree->angka){
        insertNode(tree->left, nodeBaru);
    } else if(nodeBaru->angka > tree->angka){
        insertNode(tree->right, nodeBaru);
    }
}

void searchByData(BinTree tree, int angkaCari){
    if(isEmpty(tree) == true){
        cout << "Tree kosong!" << endl;
    } else {
        node nodeBantu = tree;
        node parent = Nil;
        bool ketemu = false;
        while(nodeBantu != Nil){
            if(angkaCari < nodeBantu->angka){
                parent = nodeBantu;
                nodeBantu = nodeBantu->left;
            } else if(angkaCari > nodeBantu->angka){
                parent = nodeBantu;
                nodeBantu = nodeBantu->right;
            } else if(angkaCari == nodeBantu->angka){
                ketemu = true;
                break;
            }
        }
        if(ketemu == false){
            cout << "Data tidak ditemukan" << endl;
        } else if(ketemu == true){
            cout << "Data ditemukan didalam tree!" << endl;
            cout << "Data Angka : " << nodeBantu->angka << endl;

            //menampilkan parentnya & pengecekan sibling
            node sibling = Nil;
            if(parent != Nil){
                cout << "Parent : " << parent->angka << endl;
                if(parent->left == nodeBantu){
                    sibling = parent->right;
                } else if(parent->right == nodeBantu){
                    sibling = parent->left;
                }
            } else {
                cout << "Parent : - (node root)"<< endl;
            }

            //menampilkan siblingnya
            if(sibling != Nil){
                cout << "Sibling : " << sibling->angka << endl;
            } else {
                cout << "Sibling : - " << endl;
            }

            //menampilkan childnya
            if(nodeBantu->left != Nil){
                cout << "Child kiri : " << nodeBantu->left->angka << endl;
            } else if(nodeBantu->left == Nil){
                cout << "Child kiri : -" << endl;
            }
            if(nodeBantu->right != Nil){
                cout << "Child kanan : " << nodeBantu->right->angka << endl;
            } else if(nodeBantu->right == Nil){
                cout << "Child kanan : -" << endl;
            }
        }
    }
}

void preOrder(BinTree tree){
    if(tree == Nil){
        return;
    }
    cout << tree->angka << " - ";
    preOrder(tree->left);
    preOrder(tree->right);
}

void inOrder(BinTree tree){
    if(tree == Nil){
        return;
    }
    inOrder(tree->left);
    cout << tree->angka << " - ";
    inOrder(tree->right);
}

void postOrder(BinTree tree){
    if(tree == Nil){
        return;
    }
    postOrder(tree->left);
    postOrder(tree->right);
    cout << tree->angka << " - ";
}



bool deleteNode(BinTree &tree, int angka) {
    if (tree == Nil) {
        return false; //data tidak ditemukan di subtree ini
    } else {
        if (angka < tree->angka) {
            return deleteNode(tree->left, angka);
        } else if (angka > tree->angka) {
            return deleteNode(tree->right, angka);
        } else {
            //jika node yang mau dihapus ditemukan
            //Case 1 : node yang mau dihapus adalah leaf
            if (tree->left == Nil && tree->right == Nil) {
                node tmp = tree;
                tree = Nil;
                dealokasi(tmp);
            }
            //Case 2 : node yang mau dihapus hanya punya right child
            else if (tree->left == Nil) {
                node tmp = tree;
                tree = tree->right;
                dealokasi(tmp);
            }
            //Case 3 : node yang mau dihapus hanya punya left child
            else if (tree->right == Nil) {
                node tmp = tree;
                tree = tree->left;
                dealokasi(tmp);
            }
            // Case 4 : jika node yang mau dihapus punya dua child, maka ambil mostleft dari subtree kanan untuk menggantikan node yang mau dihapus
            else {
                //mostleft dari subtree kanan = node successor (node penerus)
                node successor = mostLeft(tree->right);
                //salin data successor ke node saat ini
                tree->angka = successor->angka;
                //hapus successor pada subtree kanan
                return deleteNode(tree->right, successor->angka);
            }
            return true; //berhasil dihapus
        }
    }
}

node mostRight(BinTree tree){
    while (tree->right != Nil){
        tree = tree->right;
    }
    return tree;    
}

node mostLeft(BinTree tree){
    while (tree->left != Nil){
        tree = tree->left;
    }
    return tree;
}

void deleteTree(BinTree &tree){
    if(tree == Nil){
        return;
    } else {
        deleteTree(tree->left);
        deleteTree(tree->right);
        dealokasi(tree);
        tree = Nil;
    }
}

int size(BinTree tree){ //mengembalikan jumlah semua node
    if(isEmpty(tree) == true){
        return 0;
    } else {
        return 1 + size(tree->left) + size(tree->right);
    }
    cout << endl;
}

int height(BinTree tree){ //mengembalikan jumlah level tree
    if(isEmpty(tree) == true){
        return -1; //tree kosong jika height = -1
    } else {
        int hl = height(tree->left);
        int hr = height(tree->right);
        int maxHeight;
        if (hl > hr){
            maxHeight = hl;
        } else {
            maxHeight = hr;
        }
        return 1 + maxHeight;
    }
    cout << endl;
}
```

## Unguided 

### 1. [Soal]
*bstree.h*
```C++
#ifndef BSTREE_H
#define BSTREE_H

#include <iostream>
using namespace std;

#define Nil NULL

typedef int infotype;
typedef struct Node* address;

struct Node {
    infotype info;
    address left;
    address right;
};
address buatNode(infotype x);
void tambahNode(address &root, infotype x);
address cariNode(infotype x, address root);
void cetakInOrder(address root);

#endif
```

*bstree.cpp*
```c++
#include "bstree.h"

address buatNode(infotype x) {
    address baru = new Node;
    if (baru != Nil) {
        baru->info = x;
        baru->left = Nil;
        baru->right = Nil;
    }
    return baru;
}
void tambahNode(address &root, infotype x) {
    if (root == Nil) {
        root = buatNode(x);
    }
    else if (x < root->info) {
        tambahNode(root->left, x);
    }
    else if (x > root->info) {
        tambahNode(root->right, x);
    }
}
address cariNode(infotype x, address root) {
    if (root == Nil) {
        return Nil;
    }
    if (x == root->info) {
        return root;
    }
    else if (x < root->info) {
        return cariNode(x, root->left);
    }
    else {
        return cariNode(x, root->right);
    }
}
void cetakInOrder(address root) {
    if (root != Nil) {
        cetakInOrder(root->left);
        cout << root->info << " - ";
        cetakInOrder(root->right);
    }
}
```

*main.cpp*
```c++
#include <iostream>
#include "bstree.h"

using namespace std;

int main() {
    cout << "Hello World!" << endl;

    address root = Nil;

    tambahNode(root, 1);
    tambahNode(root, 2);
    tambahNode(root, 6);
    tambahNode(root, 4);
    tambahNode(root, 5);
    tambahNode(root, 3);
    tambahNode(root, 6); 
    tambahNode(root, 7);

    cetakInOrder(root);

    return 0;
}
```
#### Output:
<img width="1044" height="129" alt="{5EEFF5AF-ADE0-474D-A2A6-66084140F685}" src="https://github.com/user-attachments/assets/c3ae55b7-d677-455e-bcd9-ce5309534c5f" />

Program ini menjalankan implementasi Binary Search Tree (BST) menggunakan linked list. Program menyisipkan beberapa data integer ke dalam BST sesuai aturan kiri lebih kecil, kanan lebih besar, lalu menampilkan seluruh isi tree menggunakan traversal InOrder sehingga data keluar dalam urutan menaik.

#### Full code Screenshot:
<img width="1920" height="1080" alt="{9D5CC659-11E9-4BF0-8915-0F6954DCBACA}" src="https://github.com/user-attachments/assets/982d5595-4b0a-443e-8a96-aca65d2ae0d0" />
<img width="1920" height="1080" alt="{C2037BE7-CD31-4046-9958-9C641E282B1A}" src="https://github.com/user-attachments/assets/183ec387-cb30-4660-996d-28edb4e27c6a" />
<img width="1920" height="1080" alt="{E3C68283-D215-4BEC-93A2-E19D10137A0B}" src="https://github.com/user-attachments/assets/1c3ec803-b527-4692-9e56-bd85599d7283" />

### 2. [Soal]
*bstree.h*
```C++
#ifndef BSTREE_H
#define BSTREE_H

#include <iostream>
using namespace std;

#define Nil NULL

typedef int infotype;
typedef struct Node* address;

struct Node {
    infotype info;
    address left;
    address right;
};
address buatNode(infotype x);
void tambahNode(address &root, infotype x);
address cariNode(infotype x, address root);
void cetakInOrder(address root);

int hitungNode(address root);
int hitungTotal(address root);
int hitungKedalaman(address root, int level);

#endif    
```

*bstree.cpp*
```c++
#include "bstree.h"

address buatNode(infotype x) {
    address baru = new Node;
    if (baru != Nil) {
        baru->info = x;
        baru->left = Nil;
        baru->right = Nil;
    }
    return baru;
}
void tambahNode(address &root, infotype x) {
    if (root == Nil) {
        root = buatNode(x);
    }
    else if (x < root->info) {
        tambahNode(root->left, x);
    }
    else if (x > root->info) {
        tambahNode(root->right, x);
    }
}
address cariNode(infotype x, address root) {
    if (root == Nil) {
        return Nil;
    }
    if (x == root->info) {
        return root;
    }
    else if (x < root->info) {
        return cariNode(x, root->left);
    }
    else {
        return cariNode(x, root->right);
    }
}
void cetakInOrder(address root) {
    if (root != Nil) {
        cetakInOrder(root->left);
        cout << root->info << " - ";
        cetakInOrder(root->right);
    }
}
int hitungNode(address root) {
    if (root == Nil) {
        return 0;
    }
    return 1 + hitungNode(root->left) + hitungNode(root->right);
}
int hitungTotal(address root) {
    if (root == Nil) {
        return 0;
    }
    return root->info
         + hitungTotal(root->left)
         + hitungTotal(root->right);
}
int hitungKedalaman(address root, int level) {
    if (root == Nil) {
        return level;
    }
    int kiri  = hitungKedalaman(root->left, level + 1);
    int kanan = hitungKedalaman(root->right, level + 1);

    return (kiri > kanan) ? kiri : kanan;
}
```

*main.cpp*
```c++
#include <iostream>
#include "bstree.h"

using namespace std;

int main() {
    cout << "Hello World!" << endl;

    address root = Nil;

    tambahNode(root,1);
    tambahNode(root,2);
    tambahNode(root,6);
    tambahNode(root,4);
    tambahNode(root,5);
    tambahNode(root,3);
    tambahNode(root,6); 
    tambahNode(root,7);

    cetakInOrder(root);
    cout << endl;

    cout << "kedalaman : " << hitungKedalaman(root,0) << endl;
    cout << "jumlah node : " << hitungNode(root) << endl;
    cout << "total : " << hitungTotal(root) << endl;

    return 0;
}
```

#### Output:
<img width="1045" height="161" alt="{D555A3C7-A1A4-43A2-915C-6C341596FAD9}" src="https://github.com/user-attachments/assets/b41fbcb8-b17f-48a9-8009-b7404c2dbee8" />

Program ini menyimpan data ke dalam Binary Search Tree (BST), lalu menampilkan isi tree secara in-order serta menghitung kedalaman tree, jumlah node, dan total nilai seluruh node menggunakan fungsi rekursif.

#### Full code Screenshot:
<img width="1920" height="1080" alt="{AD61AD9E-DEF3-42A3-B38D-3AABBB8264DB}" src="https://github.com/user-attachments/assets/219a4d3e-7879-493f-9dae-f6e01f819208" />
<img width="1920" height="1080" alt="{90F3C326-9C30-4556-B7DF-492871AC6357}" src="https://github.com/user-attachments/assets/40ca1d71-0ba3-4341-a3d2-30e6e2d163e8" />
<img width="1920" height="1080" alt="{95D69A6D-BBB0-457F-B49C-297AF1490F6B}" src="https://github.com/user-attachments/assets/2423cfde-bde9-4831-aca6-c03941b2615e" />

### 3. [Soal]
*bstree.h*
```C++
#ifndef BSTREE_H
#define BSTREE_H

#include <iostream>
using namespace std;

#define Nil NULL

typedef int infotype;
typedef struct Node* address;

struct Node {
    infotype info;
    address left;
    address right;
};
address buatNode(infotype x);
void tambahNode(address &root, infotype x);
address cariNode(infotype x, address root);
void cetakInOrder(address root);

int hitungNode(address root);
int hitungTotal(address root);
int hitungKedalaman(address root, int level);

void cetakPreOrder(address root);
void cetakPostOrder(address root);

#endif    
```

*bstree.cpp*
```c++
#include "bstree.h"

address buatNode(infotype x) {
    address baru = new Node;
    if (baru != Nil) {
        baru->info = x;
        baru->left = Nil;
        baru->right = Nil;
    }
    return baru;
}
void tambahNode(address &root, infotype x) {
    if (root == Nil) {
        root = buatNode(x);
    }
    else if (x < root->info) {
        tambahNode(root->left, x);
    }
    else if (x > root->info) {
        tambahNode(root->right, x);
    }
}
address cariNode(infotype x, address root) {
    if (root == Nil) {
        return Nil;
    }
    if (x == root->info) {
        return root;
    }
    else if (x < root->info) {
        return cariNode(x, root->left);
    }
    else {
        return cariNode(x, root->right);
    }
}
void cetakInOrder(address root) {
    if (root != Nil) {
        cetakInOrder(root->left);
        cout << root->info << " - ";
        cetakInOrder(root->right);
    }
}
int hitungNode(address root) {
    if (root == Nil) {
        return 0;
    }
    return 1 + hitungNode(root->left) + hitungNode(root->right);
}
int hitungTotal(address root) {
    if (root == Nil) {
        return 0;
    }
    return root->info
         + hitungTotal(root->left)
         + hitungTotal(root->right);
}
int hitungKedalaman(address root, int level) {
    if (root == Nil) {
        return level;
    }
    int kiri  = hitungKedalaman(root->left, level + 1);
    int kanan = hitungKedalaman(root->right, level + 1);

    return (kiri > kanan) ? kiri : kanan;
}
void cetakPreOrder(address root) {
    if (root != Nil) {
        cout << root->info << " - ";
        cetakPreOrder(root->left);
        cetakPreOrder(root->right);
    }
}
void cetakPostOrder(address root) {
    if (root != Nil) {
        cetakPostOrder(root->left);
        cetakPostOrder(root->right);
        cout << root->info << " - ";
    }
}
```

*main.cpp*
```c++
#include <iostream>
#include "bstree.h"

using namespace std;

int main() {
    cout << "Hello World!" << endl;

    address root = Nil;

    tambahNode(root,1);
    tambahNode(root,2);
    tambahNode(root,6);
    tambahNode(root,4);
    tambahNode(root,5);
    tambahNode(root,3);
    tambahNode(root,6);
    tambahNode(root,7);

    cout << "InOrder   : ";
    cetakInOrder(root);
    cout << endl;

    cout << "PreOrder  : ";
    cetakPreOrder(root);
    cout << endl;

    cout << "PostOrder : ";
    cetakPostOrder(root);
    cout << endl;

    return 0;
}
```

#### Output:
<img width="1053" height="141" alt="{9B363DC2-C36C-4AA5-9151-674EDD35740B}" src="https://github.com/user-attachments/assets/92852ef7-4e01-4698-91f6-48a8210e437c" />

Program menampilkan isi Binary Search Tree menggunakan metode traversal pre-order dan post-order untuk melihat urutan kunjungan node berdasarkan akar dan subtree.

#### Full code Screenshot:
<img width="1920" height="1080" alt="{E7E8153A-520C-43C5-BC74-46D2A79FB0CD}" src="https://github.com/user-attachments/assets/ef97f21b-a248-4294-af82-eec7c33ba7b9" />
<img width="1920" height="1080" alt="{7E40DCDD-C274-4BC8-BE3A-55C67FD7820E}" src="https://github.com/user-attachments/assets/980c4b67-a508-40ec-858a-b8550b10e424" />
<img width="1920" height="1080" alt="{9457EA1C-1631-4F8A-9870-39360E36BB09}" src="https://github.com/user-attachments/assets/a8757521-c0d7-4279-b866-e408835ea340" />


## Kesimpulan
Struktur data Binary Search Tree (BST) mampu menyimpan data secara terstruktur dan memudahkan proses pencarian serta pengolahan data. Implementasi BST menggunakan linked list dapat dilakukan dengan memanfaatkan konsep rekursif pada operasi penambahan data, penelusuran, dan traversal. Melalui praktikum ini, diperoleh pemahaman bahwa metode traversal in-order, pre-order, dan post-order menghasilkan urutan kunjungan node yang berbeda sesuai kebutuhan. Selain itu, fungsi rekursif dapat digunakan untuk menghitung jumlah node, total nilai node, dan kedalaman tree secara efektif. Praktikum ini membantu memahami penerapan tree dalam pemrograman serta meningkatkan pemahaman konsep struktur data non-linear.

## Referensi
1. Modul 10 Tree (bagian pertama)
2. Cormen, T. H., Leiserson, C. E., Rivest, R. L., & Stein, C. (2009).



