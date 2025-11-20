#include <iostream>
using namespace std;

void tampil(int arr[3][3]) {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) cout << arr[i][j] << "\t";
        cout << endl;
    }
}
void tukarArray(int a[3][3], int b[3][3], int i, int j) {
    int tmp = a[i][j];
    a[i][j] = b[i][j];
    b[i][j] = tmp;
}
void tukarPointer(int *p1, int *p2) {
    int tmp = *p1;
    *p1 = *p2;
    *p2 = tmp;
}
int main() {
    int A[3][3] = {{1,2,3},{4,5,6},{7,8,9}};
    int B[3][3] = {{10,11,12},{13,14,15},{16,17,18}};
    int x = 20, y = 40;

    cout << "Array A awal:\n"; tampil(A);
    cout << "\nArray B awal:\n"; tampil(B);

    tukarArray(A, B, 1, 1);

    cout << "\nArray A sesudah tukar:\n"; tampil(A);
    cout << "\nArray B sesudah tukar:\n"; tampil(B);

    cout << "\nSebelum tukar pointer: x=" << x << ", y=" << y << endl;
    tukarPointer(&x, &y);
    cout << "Sesudah tukar pointer: x=" << x << ", y=" << y << endl;

    return 0;
}
