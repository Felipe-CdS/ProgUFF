#include <stdio.h>
#include <stdlib.h>

struct LinkedQueueStruct {
	int data;
	struct LinkedQueueStruct *nextIndex;
};
typedef struct LinkedQueueStruct LinkedQueue;

void addElement(LinkedQueue **start, LinkedQueue **end, int elem){

	LinkedQueue *newElem;
	newElem = (LinkedQueue *) malloc(sizeof(LinkedQueue));
	newElem->data = elem;
	newElem->nextIndex = NULL;

	if((*start) == NULL){
		(*start) = newElem;
		(*end) = newElem;
	}
	else{
		(*end)->nextIndex = newElem;
		(*end) = newElem;
	}
}

void removeElement(LinkedQueue **start){
	if((*start) != NULL){
		LinkedQueue *thrash;
		thrash = (*start);
		(*start) = (*start)->nextIndex;
		free(thrash);
	}
}

void printAllElements(LinkedQueue *start){
	LinkedQueue *aux;
	aux = start;

	while(aux != NULL){
		printf("[%2d | %x] // Next index @ %x;\n", aux->data, aux, aux->nextIndex);
		aux = aux->nextIndex;
	}

	printf("End of Queue...\n");
}

int main(void){

	LinkedQueue *startIndex, *endIndex;
	startIndex = NULL;
	endIndex = NULL;

	for(int i = 1; i <= 20; i++){
		addElement(&startIndex, &endIndex, i);
	}

	printAllElements(startIndex);

	for(int i = 1; i <= 5; i++){
		removeElement(&startIndex);
	}

	printAllElements(startIndex);

	return 0;
}