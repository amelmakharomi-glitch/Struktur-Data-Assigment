#include <iostream>
using namespace std;

void tukarPointer(int *a, int *b, int *c) {
    int temp = *a;
    *a = *b;
    *b = *c;
    *c = temp;
}
void tukarReference(int &x, int &y, int &z) {
    int temp = x;
    x = y;
    y = z;
    z = temp;
}
int main() {
    int a, b, c;
    cout << "Tiga nilai: ";
    cin >> a >> b >> c;

    cout << "\nNilai awal: a=" << a << " b=" << b << " c=" << c << endl;

    tukarPointer(&a, &b, &c);
    cout << "Setelah tukar (pointer): a=" << a << " b=" << b << " c=" << c << endl;

    tukarReference(a, b, c);
    cout << "Setelah tukar (reference): a=" << a << " b=" << b << " c=" << c << endl;

    return 0;
}
