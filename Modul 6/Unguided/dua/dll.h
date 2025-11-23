#ifndef DLL_H
#define DLL_H
#include <iostream>

using namespace std;
#define Nil NULL

typedef int boolean;
#define TRUE 1
#define FALSE 0

using namespace std;

typedef struct {
    string nopol;  
    string warna;  
    int thnBuat;   
} infotype;
typedef struct elmlist *address;
typedef struct elmlist {
    infotype info;
    address next;
    address prev;
} elmlist;
typedef struct {
    address first;
    address last;
} List;
bool IsEmpty(List L);
void CreateList(List &L);
address alokasi(infotype x);
void dealokasi(address &P);
void printInfo(List L);
void insertLast(List &L, address P);
address findElm(List L, string nopol); 
void insertFirst(List &L, address P);

void deleteFirst(List &L, address &P);
void deleteLast(List &L, address &P);
void deleteAfter(address Prec, address &P);

#endif