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