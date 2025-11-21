#ifndef STACK_H
#define STACK_H
#define MAX 20

typedef int infotype;
struct Stack {
    infotype info[MAX]; 
    int top;           
};
int IsFull(Stack S);
int IsEmpty(Stack S);

void CreateStack(Stack &S);
void push(Stack &S, infotype X);
infotype pop(Stack &S);

void printInfo(Stack S);
void balikStack(Stack &S);

#endif 