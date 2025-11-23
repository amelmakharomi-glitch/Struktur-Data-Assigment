#include "dll.h"
#include <iostream>

using namespace std;
bool IsEmpty(List L) {
    return (L.first == Nil);
}
void CreateList(List &L) {
    L.first = Nil;
    L.last = Nil;
}
address alokasi(infotype x) {
    address P = new elmlist;
    if (P != Nil) {
        P->info = x;
        P->next = Nil;
        P->prev = Nil;
        return P;
    } else {
        return Nil;
    }
}
void dealokasi(address &P) {
    if (P != Nil) {
        delete P;
        P = Nil;
    }
}
void printInfo(List L) {
    if (IsEmpty(L)) {
        cout << "List kosong." << endl;
    } else {
        address P = L.first;
        while (P != Nil) {
            cout << "no polisi : " << P->info.nopol << endl;
            cout << "warna     : " << P->info.warna << endl;
            cout << "tahun     : " << P->info.thnBuat << endl;
            P = P->next;
        }
    }
}
void insertLast(List &L, address P) {
    if (IsEmpty(L)) {
        L.first = P;
        L.last = P;
    } else {
        P->prev = L.last; 
        L.last->next = P; 
        L.last = P; 
    }
}
address findElm(List L, std::string nopol) {
    address P = L.first;
    while (P != Nil) {
        if (P->info.nopol == nopol) {
            return P; 
        }
        P = P->next;
    }
    return Nil; 
}
void insertFirst(List &L, address P) {
    if (IsEmpty(L)) {
        L.first = P;
        L.last = P;
    } else {
        P->next = L.first; 
        L.first->prev = P; 
        L.first = P;
    }
}