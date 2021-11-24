#include <stdio.h>

#define MAX 100

struct LIST{
	int data[MAX];
	int total;
};
typedef struct LIST list;

void printList(list *L){

	printf("List: ");
	for(int i = 0; i < L->total; i++){
		printf("%d ", L->data[i]);
	}
	printf("\n\n");
}

int searchItem(list *L, int n, int *pos){

	for(int i = 0; i <= L->total; i++){
		(*pos) = i;	

		if(n <= L->data[i]){
			return 1;
		}
	}
	return 0;
}

/*void insert(list *L, int n){

	int pos = 0;
	
	if(L->total < MAX){

		if(searchItem(L, n, &pos)){
			for(int j = (MAX-2); j >= (pos); j--){
				L->data[j+1] = L->data[j];
			}
			L->data[pos] = n;
		}
		else{
			L->data[pos] = n;
		}
		L->total++;
			
	}
}*/

void insert(list *L, int n){

	int pos = 0;
	
	if(L->total < MAX){

		if(searchItem(L, n, &pos)){
			for(int j = L->total; j > pos; j--){
				L->data[j] = L->data[j-1];
			}
			L->data[pos] = n;
		}
		else{
			L->data[pos] = n;
		}
		L->total++;
			
	}
}

void removeItem(list *L, int n){

	int pos;

	if(L->total > 0){
		if(searchItem(L, n, &pos)){
			for(int j = pos; j < L->total-1; j++){
				L->data[j] = L->data[j+1];
			}
		L->total--;
		}
	}
}


int main(void){

	list x;
	x.total = 0;

	for(int i = 0; i < 10; i++){
		insert(&x, i);
	}
	printList(&x);

	insert(&x, 5);
	printList(&x);

	removeItem(&x, 6);
	printList(&x);
	return 0;
}