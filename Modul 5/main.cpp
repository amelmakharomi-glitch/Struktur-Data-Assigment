#include "singlylist.h"

int main() {
    List L;
    createList(L);

    insertFirst(L, alokasi(2));
    insertFirst(L, alokasi(0));
    insertFirst(L, alokasi(8));
    insertFirst(L, alokasi(12));
    insertFirst(L, alokasi(9));

    int total = totalInfo(L); 
    cout << "Total info dari kelima elemen adalah " << total << endl;

    return 0;
}
