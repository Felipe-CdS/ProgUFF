#include <stdlib.h>
#include <stdio.h>

struct LinkedList {
	int data;
	struct LinkedList *nextIndex;
};
typedef struct LinkedList List;

void imprimeLista(List *L){
	List *aux;
	aux = L->nextIndex;

	while(aux != L){
		printf("[%d] ", aux->data);
		aux = aux->nextIndex;
	}
	printf("\n");
}

List *insereElem(List *L, int elem){

	List *aux, *prevNode, *newNode;

	newNode = (List *) malloc(sizeof(List));
	newNode->data = elem;
	newNode->nextIndex = L;

	aux = L->nextIndex;
	prevNode = L;

	while(aux != L){
		prevNode = aux;
		aux = aux->nextIndex;
	}

	if(prevNode->data < newNode->data){
		prevNode->nextIndex = newNode;
	}
	else{
		printf("Not valid entry.\n");
	}	

	return L;
}

List *combinaLista(List *L1, List *L2){

	List *auxL1, *auxL2, *prevNode;

	auxL1 = L1->nextIndex;
	auxL2 = L2->nextIndex;
	prevNode = L1;

	while(auxL1 != L1){

		if(auxL1->data <= auxL2->data){
			prevNode->nextIndex = auxL1;
			prevNode = auxL1;
			auxL1 = auxL1->nextIndex;
		}
		else{
			prevNode->nextIndex = auxL2;
			prevNode = auxL2;
			auxL2 = auxL2->nextIndex;
		}

		if(auxL1 == L1){
			while(auxL2 != L2){
				prevNode->nextIndex = auxL2;
				prevNode = auxL2;
				auxL2 = auxL2->nextIndex;
			}
			prevNode->nextIndex = L1;			
		}

		if(auxL2 == L2){
			while(auxL1 != L1){
				prevNode->nextIndex = auxL1;
				prevNode = auxL1;
				auxL1 = auxL1->nextIndex;
			}
			prevNode->nextIndex = L1;	
		}
	}	

	free(L2);
	return L1;
}

int main(void){

	int listSizes = 0;
	List *L1, *L2;

	L1 = (List *) malloc(sizeof(List));
	L1->nextIndex = L1;

	L2 = (List *) malloc(sizeof(List));
	L2->nextIndex = L2;

	printf("Qual o tamanho das listas?");
	scanf("%d", &listSizes);

	printf("Insira valores para L1:\n");
	for(int i = 0; i < listSizes; i++){
		int holder = 0;
		printf("Proximo: ");
		scanf("%d", &holder);
		L1 = insereElem(L1, holder);
	}	

	printf("Insira valores para L2:\n");
	for(int i = 0; i < listSizes; i++){
		int holder = 0;
		printf("Proximo: ");
		scanf("%d", &holder);
		L2 = insereElem(L2, holder);
	}
	
	imprimeLista(L1);
	imprimeLista(L2);

	combinaLista(L1, L2);
	imprimeLista(L1);

	return 0;
}