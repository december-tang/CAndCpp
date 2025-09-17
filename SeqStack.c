#include "SeqStack.h"

void initStack(Stack*stack){
	stack->top = -1;
}
void pushStack(Stack* stack,ElemType data){
	if(stack->top == maxSize-1){
		printf("栈已满，无法入栈\n");
	}else{
		stack->arr[++stack->top]=data;
	}
}

void popStack(Stack*stack,ElemType*data){
	if(stack->top == -1){
		printf("栈已空，无法出栈\n");
	}else{
		*data = stack->arr[stack->top--];
	}
}

//int main(){
//	Stack* stack = (Stack*)malloc(sizeof(Stack));
//	initStack(stack);
//	pushStack(stack,5);
//	pushStack(stack,7);
//	pushStack(stack,9);
//	pushStack(stack,1);
//	ElemType data;
//	popStack(stack,&data);
//	printf("pop:%d\n",data);
//	popStack(stack,&data);
//	printf("pop:%d\n",data);
//	popStack(stack,&data);
//	printf("pop:%d\n",data);
//	popStack(stack,&data);
//	printf("pop:%d\n",data);
//	popStack(stack,&data);
//	printf("pop:%d\n",data);
//	return 0;
//}
