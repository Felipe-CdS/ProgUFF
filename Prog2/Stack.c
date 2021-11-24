#include <stdio.h>

#define MAX 100

struct STACK {
	int data[MAX];
	int topIndex;
}; 
typedef struct STACK stack;

void printStack(stack *S){
	for(int i = 0; i <= S->topIndex; i++){
		printf("%d ", S->data[i]);
	}
	printf("\n");
}

void push(stack *S, int n){
	if(S->topIndex < MAX-1){
		S->topIndex += 1;
		S->data[S->topIndex] = n;
	}
}

int pop(stack *S){
	int n;
	if(S->topIndex > -1){
		n = S->data[S->topIndex];
		S->topIndex -= 1;
	}
	return n;
}

int main(void){

	stack x;
	x.topIndex = -1;

	for(int i = 0; i <= 20; i += 2){
		push(&x, i);
	}

	printStack(&x);

	printf("Removing %d;\n", pop(&x));
	printf("Removing %d;\n", pop(&x));
	printf("Removing %d;\n", pop(&x));

	printStack(&x);
	return 0;
}