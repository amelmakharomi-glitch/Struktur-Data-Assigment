#include "Singlylist.h"
#include <iostream>
using namespace std;

void createList(List &L) {
    L.first = Nil;
}
address alokasi(infotype x) {
    address P = new ElmList;
    if (P != Nil) {
        P->info = x;
        P->next = Nil;
    }
    return P;
}
void dealokasi(address &P) {
    delete P;
    P = Nil;
}
void insertFirst(List &L, address P) {
    if (P != Nil) {
        P->next = L.first;
        L.first = P;
    }
}
void printInfo(List L) {
    address P = L.first;
    while (P != Nil) {
        cout << P->info << " ";
        P = P->next;
    }
    cout << endl;
}

void deleteFirst(List &L, address &P) {
    if (L.first != Nil) {
        P = L.first;
        L.first = L.first->next;
        P->next = Nil;
    } else {
        P = Nil;
    }
}
void deleteLast(List &L, address &P) {
    if (L.first != Nil) {
        address Q = L.first;
        if (Q->next == Nil) { 
            P = Q;
            L.first = Nil;
        } else {
            while (Q->next->next != Nil) {
                Q = Q->next;
            }
            P = Q->next;
            Q->next = Nil;
        }
    } else {
        P = Nil;
    }
}
void deleteAfter(address Prec, address &P) {
    if (Prec != Nil && Prec->next != Nil) {
        P = Prec->next;
        Prec->next = P->next;
        P->next = Nil;
    } else {
        P = Nil;
    }
}
int nbList(List L) {
    int count = 0;
    address P = L.first;
    while (P != Nil) {
        count++;
        P = P->next;
    }
    return count;
}
void deleteList(List &L) {
    address P;
    while (L.first != Nil) {
        deleteFirst(L, P);
        dealokasi(P);
    }
}
