#ifndef CIRCULARLIST_H
#define CIRCULARLIST_H

#include <iostream>
using namespace std;

#define NIL NULL

struct mahasiswa {
    string nama;
    string nim;
    char jk;
    float ipk;
};
typedef mahasiswa infotype;
typedef struct Node *address;

struct Node {
    infotype data;
    address next;
};
struct List {
    address first;
};
void createList(List &L);
address createNode(infotype data);
void deleteNode(address &P);

void addFirst(List &L, address P);
void addAfter(List &L, address prec, address P);
void addLast(List &L, address P);

void removeFirst(List &L, address &P);
void removeAfter(List &L, address prec, address &P);
void removeLast(List &L, address &P);

address searchByNim(List L, infotype x);
void showData(List L);

#endif
