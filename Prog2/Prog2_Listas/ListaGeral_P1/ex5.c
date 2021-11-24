#include <stdio.h>


void calcAndPrint(int *i, int *j, int gap){

	*i += gap;

	if(*i < *j){
		printf("%d ", *i);
		calcAndPrint(&(*i), &(*j), gap);
	}
	else{
		printf("\n");
	}
}

int main(void){
	int entry1, entry2, gap;

	scanf(" %d", &entry1);
	scanf(" %d", &entry2);
	scanf(" %d", &gap);

	calcAndPrint(&entry1, &entry2, gap);
	return 0;
}