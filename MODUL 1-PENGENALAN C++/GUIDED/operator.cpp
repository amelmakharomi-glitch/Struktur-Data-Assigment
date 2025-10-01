#include <iostream> 
using namespace std;

int main() {
    int a;
    int b;

    cout << "angka : ";
    cin >> a;
    cout << "angka 2 : ";
    cin >> b;
 
    cout << "a+b = " << (a+b) << endl;
    cout << "a-b = " << (a-b) << endl;
    cout << "a*b = " << (a*b) << endl;
    cout << "a/b = " << (a/b) << endl;
    cout << "a%b = " << (a%b) << endl;

    cout << "a>b = " << (a>b) << endl;
    cout << "a<b = " << (a<b) << endl;
    cout << "a>=b = " << (a>=b) << endl;
    cout << "a<=b = " << (a<=b)<< endl;
    cout << "a==b = " << (a==b) << endl;
    cout << "a!=b = " << (a!=b) << endl;

    return 0;
}
