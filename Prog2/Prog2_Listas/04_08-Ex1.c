#include <stdio.h>

#define MAX 100

struct QUEUE {
	int data[MAX];
	int firstIndex, nextAvaiableIndex, total;
};
typedef struct QUEUE queue;

void printQueue(queue *Q){
	printf("Process queue: ");
	for(int i = Q->firstIndex; i < Q->nextAvaiableIndex; i++){
		printf("%d ", Q->data[i]);
	}
	printf("\n\n");
}


void insert(queue *Q, int n){
	if(Q->total < MAX){
		Q->data[Q->nextAvaiableIndex] = n;
		Q->nextAvaiableIndex++;
		Q->nextAvaiableIndex = Q->nextAvaiableIndex % MAX;
		Q->total++;
	}
}

int removeItem(queue *Q){
	int n;
	if(Q->total > 0){
		n = Q->data[Q->firstIndex];
		Q->firstIndex++;
		Q->firstIndex = Q->firstIndex % MAX;
		Q->total--;
	}
	return n;
}

int main(void){

	queue x;
	x.firstIndex = 0;
	x.nextAvaiableIndex = 0;
	x.total = 0;

	int quantEntry;
	printf("Enter processes quantity: ");
	scanf("%d", &quantEntry);

	for(int i = 0; i < quantEntry; i++){
		int holderEntry;
		printf("Enter next process number: ");
		scanf("%d", &holderEntry);
		insert(&x, holderEntry);
	}

	printQueue(&x);

	printf("How many do you want to remove? ");
	scanf("%d", &quantEntry);

	for(int i = 0; i < quantEntry; i++){
		printf("Removing %d...\n", removeItem(&x));
	}

	printQueue(&x);
	return 0;
}