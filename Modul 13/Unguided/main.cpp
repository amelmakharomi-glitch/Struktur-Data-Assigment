#include "circularlist.h"

address buatData(string nama, string nim, char jk, float ipk){
    infotype mhs;
    mhs.nama = nama;
    mhs.nim = nim;
    mhs.jk = jk;
    mhs.ipk = ipk;
    return createNode(mhs);
}
int main(){
    List L;
    address pCari, pBaru;
    infotype key;

    createList(L);

    cout << "Percobaan insert data mahasiswa" << endl;

    addFirst(L, buatData("Danu", "04", 'L', 4.0));
    addLast(L, buatData("Fahmi", "06", 'L', 3.45));
    addFirst(L, buatData("Bobi", "02", 'L', 3.71));
    addFirst(L, buatData("Ali", "01", 'L', 3.3));
    addLast(L, buatData("Gita", "07", 'P', 3.75));

    key.nim = "07";
    pCari = searchByNim(L, key);
    pBaru = buatData("Cindi", "03", 'P', 3.5);
    addAfter(L, pCari, pBaru);

    key.nim = "02";
    pCari = searchByNim(L, key);
    pBaru = buatData("Hilmi", "08", 'P', 3.3);
    addAfter(L, pCari, pBaru);

    key.nim = "04";
    pCari = searchByNim(L, key);
    pBaru = buatData("Eli", "05", 'P', 3.4);
    addAfter(L, pCari, pBaru);

    showData(L);
    return 0;
}
