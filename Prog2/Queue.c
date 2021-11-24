#include <stdio.h>

#define MAX 15

struct QUEUE{
	int data[MAX];
	int firstIndex, nextAvaiableIndex, total;
};
typedef struct QUEUE queue;

void printQueue(queue *Q){
	int index = Q->firstIndex;
	for(int i = 0; i < Q->total; i++){
		printf("%d ", Q->data[index]);
		index++;
		index = index % MAX;
	}
	printf("\n");
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

	for(int i = 0; i < 15; i++){
		insert(&x, i);
	}

	printQueue(&x);

	for(int i = 1; i < 10; i++){
		removeItem(&x);
	}

	printQueue(&x);

	return 0;
}