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
