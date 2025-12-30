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
