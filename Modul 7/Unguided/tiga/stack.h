#ifndef STACK_H
#define STACK_H
#define MAX 20           

typedef int infotype;    
struct Stack {
    infotype info[MAX];
    int top;
};
void CreateStack(Stack &S);
int IsEmpty(Stack S);
int IsFull(Stack S);
void push(Stack &S, infotype X);
infotype pop(Stack &S); 
void printInfo(Stack S);
void insertAtBottom(Stack &S, infotype X); 
void balikStack(Stack &S);
void pushAscending(Stack &S, infotype X); 
void getInputStream(Stack &S); 

#endif 