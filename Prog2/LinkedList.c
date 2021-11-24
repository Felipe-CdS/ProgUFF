#include <stdio.h>
#include <stdlib.h>

struct LinkedListStruct {
	int data;
	struct LinkedListStruct *nextIndex;
};
typedef struct LinkedListStruct LinkedList; 

/*Searches for an element and returns true or false if found. previousNode argument saves the node right before the elem index*/
int searchElement(LinkedList *L, int elem, LinkedList **previousNode){
	LinkedList *aux, *preL;
	aux = L;
	preL = NULL;

	while((aux != NULL) && (aux->data != elem)){
		preL = aux;
		aux = aux->nextIndex;	
	}

	(*previousNode) = preL;

	if((aux != NULL) && (aux->data == elem)){
		return 1;
	}
	else{
		return 0;
	}	
}

/*Returns the pointer of the last index in the list*/
LinkedList *searchLastElement(LinkedList *L){
	LinkedList *aux, *LastElement;
	aux = L;
	LastElement = NULL;

	while((aux != NULL)){
		LastElement = aux;
		aux = aux->nextIndex;
	}

	return LastElement;
}

/*Adds a new number to the end of the List and returns the First Index pointer*/
LinkedList *addNewElement(LinkedList *L, int elem){
	LinkedList *newIndex, *previousNode;

	newIndex = (LinkedList *) malloc(sizeof(LinkedList));
	newIndex->data = elem;
	newIndex->nextIndex = NULL;

	if(L == NULL){
		L = newIndex;
	}
	else{
		previousNode = searchLastElement(L);
		previousNode->nextIndex = newIndex;
	}
	
	return L;
}

/*Removes the element*/
LinkedList *removeElement(LinkedList *L, int elem){
	LinkedList *prevNode, *aux;

	if(searchElement(L, elem, &prevNode)){
		if(prevNode == NULL){
			aux = L;
			L = L->nextIndex;			
		}
		else{
			aux = prevNode->nextIndex;
			prevNode->nextIndex = aux->nextIndex;
		}	
		free(aux);
	}

	return L;
}

/*PrintEverything*/
void printListElements(LinkedList *L){
	LinkedList *aux, *lastElement;
	aux = L;
	lastElement = NULL;

	while((aux != NULL)){
		lastElement = aux;
		aux = aux->nextIndex;
		printf("[Data: %d | nextPointer: %x]\n", lastElement->data, lastElement->nextIndex);
	}
}

int main(void){
	LinkedList *firstIndex, *aux;
	firstIndex = NULL;

	for(int i = 1; i <=10; i++){
		firstIndex = addNewElement(firstIndex, i);
	}
	
	printListElements(firstIndex);	
	printf("\n");

	for(int i = 1; i <=10; i++){
		if(i % 2 != 0){
			firstIndex = removeElement(firstIndex, i);
		}	
	}

	printListElements(firstIndex);	
	printf("\n");
	return 0;
}