#include <iostream> 
using namespace std;

int main() {
    int a = 10;
    int b = 20;

    if (a>b){
        cout << "angka lebih besat" << endl;
    } else if (a<b) {
        cout << "angka lebih kecil" << endl;
    } else {
        cout << "angka sama" << endl;
    }

    return 0;
}