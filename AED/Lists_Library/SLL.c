#include "SLL.h"

/*
====================================

	Simple Linked List Library

====================================
*/

//Methods implementation

SLL* StartList(void){

	return NULL;
}

SLL* AddNewElementStart(SLL *l, int elem){
	SLL *newIndex;

	newIndex = (SLL*) malloc(sizeof(SLL));
	newIndex->data = elem;
	newIndex->nextIndex = l;
	return newIndex;
}

SLL* AddNewElementEnd(SLL *l, int elem){
	SLL *newIndex, *previousIndex;

	newIndex = (SLL*) malloc(sizeof(SLL));
	newIndex->data = elem;
	newIndex->nextIndex = NULL;

	previousIndex = l;

	if(previousIndex == NULL){
		l = newIndex;
	}
	else{
		while(previousIndex->nextIndex != NULL){
			previousIndex = previousIndex->nextIndex;
		}

		previousIndex->nextIndex = newIndex;
	}

	return l;
}

SLL* RemoveElement(SLL *l, int elem){

	SLL *aux, *previousIndex;

	aux = l;
	previousIndex = NULL;

	while((aux != NULL) && (aux->data != elem)){

		previousIndex = aux;
		aux = aux->nextIndex;
	}

	if(aux == NULL) 
		return l;

	if(previousIndex != NULL)
		previousIndex->nextIndex = aux->nextIndex;
	else
		l = l->nextIndex;	

	free(aux);

	return l;
}

SLL* SearchElement(SLL *l, int elem){
	SLL *aux;

	aux = l;

	while((aux != NULL) && (aux->data != elem))
		aux = aux->nextIndex;			

	return l;
}


SLL* SearchByIndex(SLL *l, int searchedIndex){

	int currentIndex;
	SLL *aux;

	currentIndex = 0;
	aux = l;

	while(currentIndex != searchedIndex){
		aux = aux->nextIndex;
		++currentIndex;

		if(aux == NULL)
			break;
	}

	return aux;
}

int GetSize(SLL *l){

	int size = 0;

	while(l){
		l = l->nextIndex;
		++size;
	}

	return size;
}

void RecursivePrintList(SLL *l){
	if(l){
		printf("%d\t", l->data);
		RecursivePrintList(l->nextIndex);
	}	
}