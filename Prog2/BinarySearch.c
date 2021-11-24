#include <stdio.h>

#define MAX 1000000

int binarySearch(int *v, int *n, int *quant, int *start, int *end){
	int halfIndex = ((*end) + (*start))/ 2;
	int vectorSize = (*end) - (*start);

	//printf("%d %d %d\n", (*start), (*end), halfIndex);
	

	if(vectorSize != 1){
		(*quant)++;
		if((*n) <= v[halfIndex]){
			(*end) = halfIndex;
			binarySearch(v, &(*n), &(*quant), &(*start), &(*end));
		}
		else{
			(*start) = halfIndex;
			binarySearch(v, &(*n), &(*quant), &(*start), &(*end));
		}
	}
	else{	
		if(v[(*start)] == (*n)) return (*start);
		else if(v[(*end)] == (*n))  return (*end);
		else return -1;
	}
}


int main(void){

	int orderedVector[MAX], searchedElem = 8;
	int startIndex = 0, endIndex = (MAX-1), iterationsQuant = 0;

	for(int i = 0; i < MAX; i++){
		orderedVector[i] = i*2;
	}

	printf("\nIndex of [%d] = %d\n", searchedElem, binarySearch(orderedVector, &searchedElem, &iterationsQuant, &startIndex, &endIndex));
	printf("Operations needed = %d\n", iterationsQuant);
	
	return 0;
}