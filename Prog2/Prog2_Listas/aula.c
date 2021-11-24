#include <stdio.h>

#define ROW 4
#define COLUMN 4

void fillMatrix(int a[][COLUMN]){
	int counter = 1;

	for(int i = 0; i < ROW; i++){
		for(int j = 0; j < COLUMN; j++){
			a[i][j] = counter;
			counter++;
		}
	}
}

void printFullMatrix(int (*a)[COLUMN]){
	for(int i = 0; i < ROW; i++){
		for(int j = 0; j < COLUMN; j++){
			printf("%3d ", a[i][j]);					
		}
		printf("\n");
	}
}

void printDiagonal(int a[ROW][COLUMN]){
	int holderSum = 0;

	for(int i = 0; i < ROW; i++){
		holderSum+= a[i][i];
	}
	
	printf("Main diagonal sum: %d\n", holderSum);
}

int main(void){
	int matrix[ROW][COLUMN];

	fillMatrix(matrix);
	printFullMatrix(matrix);
	printDiagonal(matrix);

	return 0;
}