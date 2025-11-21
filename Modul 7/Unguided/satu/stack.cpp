#include "stack.h"
#include <iostream>

using namespace std;

int IsEmpty(Stack S) {
    return (S.top == -1);
}
int IsFull(Stack S) {
    return (S.top == MAX - 1);
}
void CreateStack(Stack &S) {
    S.top = -1; 
}
void push(Stack &S, infotype X) {
    if (IsFull(S)) {
        cout << "Stack Penuh, Push Gagal!" << endl;
    } else {
        S.top++;
        S.info[S.top] = X;
    }
}
infotype pop(Stack &S) {
    if (IsEmpty(S)) {
        cout << "Stack Kosong, Pop Gagal!" << endl;
        return 0; 
    } else {
        infotype X = S.info[S.top];
        S.top--; 
        return X; 
    }
}
void printInfo(Stack S) {
    cout << "[TOP] ";
    if (IsEmpty(S)) {
        cout << "Stack Kosong" << endl;
        return;
    }
    for (int i = S.top; i >= 0; i--) {
        cout << S.info[i] << " ";
    }
    cout << endl;
}
void insertAtBottom(Stack &S, infotype X) {
    if (IsEmpty(S)) {
        push(S, X); 
        return;
    }
    infotype temp = pop(S); 
    insertAtBottom(S, X); 
    push(S, temp); 
}
void balikStack(Stack &S) {
    if (IsEmpty(S)) {
        return;
    }
    infotype X = pop(S); 
    balikStack(S);     
    insertAtBottom(S, X); 
}