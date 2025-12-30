#include "circularlist.h"

void createList(List &L){
    L.first = NIL;
}
address createNode(infotype data){
    address newNode = new Node;
    newNode->data = data;
    newNode->next = NIL;
    return newNode;
}
void deleteNode(address &P){
    delete P;
    P = NIL;
}
void addFirst(List &L, address P){
    if(L.first == NIL){
        L.first = P;
        P->next = P;
    } else {
        address last = L.first;
        while(last->next != L.first){
            last = last->next;
        }
        P->next = L.first;
        last->next = P;
        L.first = P;
    }
}
void addAfter(List &L, address prec, address P){
    P->next = prec->next;
    prec->next = P;
}
void addLast(List &L, address P){
    if(L.first == NIL){
        addFirst(L, P);
    } else {
        address last = L.first;
        while(last->next != L.first){
            last = last->next;
        }
        last->next = P;
        P->next = L.first;
    }
}
void removeFirst(List &L, address &P){
    if(L.first != NIL){
        address last = L.first;
        while(last->next != L.first){
            last = last->next;
        }
        P = L.first;
        if(P->next == P){
            L.first = NIL;
        } else {
            L.first = P->next;
            last->next = L.first;
        }
        P->next = NIL;
    }
}
void removeAfter(List &L, address prec, address &P){
    P = prec->next;
    prec->next = P->next;
    P->next = NIL;
}
void removeLast(List &L, address &P){
    if(L.first != NIL){
        address curr = L.first;
        address prev = NIL;

        while(curr->next != L.first){
            prev = curr;
            curr = curr->next;
        }
        P = curr;
        if(prev == NIL){
            L.first = NIL;
        } else {
            prev->next = L.first;
        }
        P->next = NIL;
    }
}
address searchByNim(List L, infotype x){
    if(L.first == NIL) return NIL;

    address temp = L.first;
    do {
        if(temp->data.nim == x.nim){
            return temp;
        }
        temp = temp->next;
    } while(temp != L.first);

    return NIL;
}
void showData(List L){
    if(L.first != NIL){
        address temp = L.first;
        do {
            cout << "Nama : " << temp->data.nama << endl;
            cout << "NIM  : " << temp->data.nim << endl;
            cout << "JK   : " << temp->data.jk << endl;
            cout << "IPK  : " << temp->data.ipk << endl << endl;
            temp = temp->next;
        } while(temp != L.first);
    }
}
