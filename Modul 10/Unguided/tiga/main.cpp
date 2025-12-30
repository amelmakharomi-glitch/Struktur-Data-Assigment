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
