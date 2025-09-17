#include <stdio.h>
#include <stdlib.h>

#define ElemType char
#define maxSize 10
typedef struct Stack{
	ElemType arr[maxSize];
	int top;
}Stack;

void initStack(Stack* stack);

void pushStack(Stack* stack,ElemType data);

void popStack(Stack* stack,ElemType*data);


