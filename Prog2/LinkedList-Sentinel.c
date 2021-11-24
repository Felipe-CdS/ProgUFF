#include <stdio.h>
#include <stdlib.h>


struct LinkedListSentinelStruct {
	int data;
	struct LinkedListSentinelStruct *nextIndex;
};
typedef struct LinkedListSentinelStruct Node;

int searchElement(Node *firstIndex, Node **previousIndex, int elem){
	Node *aux, *preN;
	aux = firstIndex->nextIndex;
	preN = firstIndex;

	while(aux != NULL && aux->data != elem){
		preN = aux;
		aux = aux->nextIndex;
	}

	(*previousIndex) = preN;

	if(aux != NULL && aux->data == elem){
		return 1;
	}
	else{
		return 0;
	}
}


Node *addNewElement(Node *firstIndex, int elem){
	Node *newIndex, *preN;

	newIndex = (Node *) malloc(sizeof(Node));
	newIndex->data = elem;
	newIndex->nextIndex = NULL;

	if(searchElement(firstIndex, &preN, elem)){
		printf("No duplicates...\n");
	} 			
	else {
		printf("Adding %d...\n", elem);
		preN->nextIndex = newIndex;
	}

	return firstIndex;
}

Node *removeElement(Node *firstIndex, int elem){
	Node *thrash, *preN;

	if(searchElement(firstIndex, &preN, elem)){
		printf("Removing %d...\n", elem);
		thrash = preN->nextIndex;
		preN->nextIndex = thrash->nextIndex;
		free(thrash);
	} 

	return firstIndex;
}


void printFullList(Node *firstIndex){
	Node *aux;
	aux = firstIndex;
}
int main(void){

	Node *L, *previousNode;
	L = (Node *) malloc(sizeof(Node));
	L->nextIndex = NULL;

	for(int i = 0; i < 10; i++){
		addNewElement(L, i);
	}

	for(int i = 0; i < 5; i++){
		removeElement(L, i);
	}


	return 0;
}