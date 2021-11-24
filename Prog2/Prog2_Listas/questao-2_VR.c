#include <stdlib.h>
#include <stdio.h>

struct LinkedList {
	int data;
	struct LinkedList *nextIndex;
};
typedef struct LinkedList List;

int menuRoutine(){
	int returnValue = 0;

	printf("\n===========================\n");
	printf("1)Interseção;\n");
	printf("2)União;\n");
	printf("3)Subconjunto;\n");
	printf("4)Pertinencia;\n");
	printf("5)Sair;\n");
	printf("Escolha uma opção do menu: ");
	scanf("%d", &returnValue);

	printf("\n\nVocê escolheu a opção %d.\n", returnValue);

	return returnValue;
}

void imprimeLista(List *L){
	List *aux;
	aux = L;

	while(aux != NULL){
		printf("[%d] ", aux->data);
		aux = aux->nextIndex;
	}
	printf("\n");
}

int searchElement(List *L, int elem){
	List *aux;
	aux = L;

	while((aux != NULL) && (aux->data != elem)){
		aux = aux->nextIndex;	
	}

	if((aux != NULL) && (aux->data == elem)){
		return 1;
	}
	else{
		return 0;
	}	
}

List *insereElem(List *L, int elem){

	List *aux, *prevNode, *newNode;

	newNode = (List *) malloc(sizeof(List));
	newNode->data = elem;
	newNode->nextIndex = NULL;	

	if(L == NULL){
		L = newNode;
	}

	else{
		if(!searchElement(L, elem)){
			aux = L->nextIndex;
			prevNode = L;

			while(aux != NULL){
				prevNode = aux;
				aux = aux->nextIndex;
			}
			prevNode->nextIndex = newNode;
		}		
	}
	
	return L;
}

void intersecao(List *L1, List *L2){

	List *answerList, *aux;

	answerList = NULL;

	aux = L1;

	while(aux != NULL){
		if(searchElement(L2, aux->data)){
			answerList = insereElem(answerList, aux->data);	
		}
		aux = aux->nextIndex;
	}

	imprimeLista(answerList);
}

int subconjunto(List *L1, List *L2){

	List *answerList, *aux;

	int answer = 1;

	aux = L1;

	while(aux != NULL){
		if(!searchElement(L2, aux->data)){
			answer = 0;
		}
		aux = aux->nextIndex;
	}

	return answer;
}

void uniao(List *L1, List *L2){

	List *answerList, *aux;

	answerList = NULL;

	aux = L1;


	while(aux != NULL){
		answerList = insereElem(answerList, aux->data);
		aux = aux->nextIndex;
	}

	aux = L2;

	while(aux != NULL){
		answerList = insereElem(answerList, aux->data);
		aux = aux->nextIndex;
	}	

	imprimeLista(answerList);
}

int main(void){

	int listSizes = 0, menuOption = 0;
	List *L1, *L2;
	L1 = NULL;
	L2 = NULL;

	printf("Insira 5 valores para L1:\n");
	for(int i = 0; i < 5; i++){
		int holder = 0;
		printf("Proximo: ");
		scanf("%d", &holder);
		L1 = insereElem(L1, holder);
	}	

	printf("Insira 5 valores para L2:\n");
	for(int i = 0; i < 5; i++){
		int holder = 0;
		printf("Proximo: ");
		scanf("%d", &holder);
		L2 = insereElem(L2, holder);
	}

	imprimeLista(L1);
	imprimeLista(L2);

	menuOption = menuRoutine();	

	while(menuOption != 5){	
		switch(menuOption){
			case 1:
				printf("Intersecao das listas: ");		
				intersecao(L1, L2);	
				break;
			case 2:		
				printf("União das listas: ");		
				uniao(L1, L2);		
				break;
			case 3:
				if(subconjunto(L1, L2)) printf("L1 é um subconjunto de L2\n");
				else printf("L1 não é um subconjunto de L2\n");
				break;
			case 4:
				printf("Não implementado...\n");
				break;
			default:
				break;
		}

		menuOption = menuRoutine();		
	}	

	return 0;
}