#include <stdio.h>
#include <stdlib.h>

struct LinkedStackStruct {
	int data;
	struct LinkedStackStruct *previousIndex;
};
typedef struct LinkedStackStruct LinkedStack;

LinkedStack *push(LinkedStack *L, int elem){

	LinkedStack *newElem;

	newElem = (LinkedStack *) malloc(sizeof(LinkedStack));
	newElem->data = elem;
	newElem->previousIndex = L;

	return newElem;
}

LinkedStack *pop(LinkedStack *L){

	if(L != NULL){
		LinkedStack *thrash;
		thrash = L;
		L = L->previousIndex;
		free(thrash);
	}

	return L;
}

void printAllElements(LinkedStack *L){

	LinkedStack *aux;

	aux = L;

	while(aux != NULL){
		printf("[%2d | %x]... Next index @ %x;\n", aux->data, aux, aux->previousIndex);
		aux = aux->previousIndex;
	}

	printf("[End of stack...\n");
}

int main(void){

	LinkedStack *L;
	L = NULL;

	printAllElements(L);

	for(int i = 1; i <=20; i++) L = push(L, i);

	printAllElements(L);

	for(int i = 1; i <=15; i++) L = pop(L);
	
	
	printAllElements(L);

	return 0;
}