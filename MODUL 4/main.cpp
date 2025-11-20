#include "Singlylist.h"
#include <iostream>
#include <ctime>   
using namespace std;

int main() {
    clock_t start, end;    
    double exec_time;     

    start = clock();      

    List L;
    address P1, P2, P3, P4, P5;

    createList(L);

    P1 = alokasi(2);
    insertFirst(L, P1);

    P2 = alokasi(0);
    insertFirst(L, P2);

    P3 = alokasi(8);
    insertFirst(L, P3);

    P4 = alokasi(12);
    insertFirst(L, P4);

    P5 = alokasi(9);
    insertFirst(L, P5);

    cout << "Isi list: ";
    printInfo(L);

    end = clock(); 
    exec_time = double(end - start) / CLOCKS_PER_SEC;

    cout << "Execution time : " << exec_time << " s" << endl;
    cout << "Process returned 0 (0x0)" << endl;

    return 0;
}
