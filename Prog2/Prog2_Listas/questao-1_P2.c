#include <stdlib.h>
#include <stdio.h>


struct LinkedList {
	int data;
	struct LinkedList *nextIndex;
};
typedef struct LinkedList List;


List *addNewElement(List *L, int elem){
	List *aux, *prevNode, *newNode;
	newNode = (List *) malloc(sizeof(List));
	newNode->data = elem;
	newNode->nextIndex = NULL;

	aux = L->nextIndex;
	prevNode = L;

	while(aux != NULL){
		prevNode = aux;
		aux = aux->nextIndex;
	}

	prevNode->nextIndex = newNode;

	return L;
}

List *mixLists(List *X, List *Y){

	int alternateCounter = 0;

	List *aux, *holder, *prevNodeX, *prevNodeY;

	aux = X;
	holder = NULL;
	prevNodeX = X->nextIndex;
	prevNodeY = Y->nextIndex;

	while(aux != NULL){
		if(alternateCounter % 2 == 0){
			holder = aux->nextIndex;
			aux->nextIndex = prevNodeY;
			aux = aux->nextIndex;
		}
		else{
			aux->nextIndex = holder;
			holder = 
			prevNodeX = aux;			
		}
	}

	return X;
}


void printList(List *L){
	List *aux;
	aux = L->nextIndex;

	while(aux != NULL){
		printf("[%d] ", aux->data);
		aux = aux->nextIndex;
	}
	printf("\n");
}


int main(void){

	int listSizes = 0;
	List *listX, *listY;

	listX = (List *) malloc(sizeof(List));
	listX->nextIndex = NULL;

	listY = (List *) malloc(sizeof(List));
	listY->nextIndex = NULL;

	printf("Enter list size: ");
	scanf("%d", &listSizes);

	printf("Enter %d listX elements:\n", listSizes);
	for(int i = 0; i < listSizes; i++){
		int holder = 0;
		printf("Enter next element: ");
		scanf("%d", &holder);
		listX = addNewElement(listX, holder);
	}	

	printf("Enter listY elements:\n");
	for(int i = 0; i < listSizes; i++){
		int holder = 0;
		printf("Enter next element: ");
		scanf("%d", &holder);
		listY = addNewElement(listY, holder);
	}
	
	printList(listX);
	printList(listY);

	listX = mixLists(listX, listY);
	printList(listX);
	return 0;
}