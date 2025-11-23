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
address findElm(List L, string nopol) {
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
void deleteFirst(List &L, address &P) {
    if (IsEmpty(L)) {
        P = Nil;
        return;
    }
    P = L.first; 

    if (L.first == L.last) { 
        L.first = Nil;
        L.last = Nil;
    } else {
        L.first = P->next; 
        if (L.first != Nil) {
            L.first->prev = Nil; 
        }
        P->next = Nil; 
    }
    P->prev = Nil;
}
void deleteLast(List &L, address &P) {
    if (IsEmpty(L)) {
        P = Nil;
        return;
    }
    P = L.last; 

    if (L.first == L.last) {
        L.first = Nil;
        L.last = Nil;
    } else {
        L.last = L.last->prev; 
        if (L.last != Nil) {
            L.last->next = Nil; 
        }
        P->prev = Nil; 
    }
    P->next = Nil;
}
void deleteAfter(address Prec, address &P) {
    if (Prec == Nil || Prec->next == Nil) {
        P = Nil;
        return;
    }
    
    P = Prec->next;
    
    if (P->next == Nil) {
        Prec->next = Nil;
    } else {
        Prec->next = P->next;
        P->next->prev = Prec; 
    }

    P->next = Nil;
    P->prev = Nil; 
}