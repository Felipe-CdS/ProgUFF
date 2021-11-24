#include <stdio.h>

#define SIZE 3

/* ################ */
/* Questão 2 */
void createMatrix(int matrix[SIZE][SIZE]){
	for(int i = 0; i < SIZE; i++){
		for(int j = 0; j < SIZE; j++){
			int holder;
			printf("enter next number: ");
			scanf("%d", &holder);
			matrix[i][j] = holder; 
		}
	}
}

/* ################ */
/* Questão 2-A) */
int sumSecondaryDiagonal(int matrix[SIZE][SIZE]){
	int totalSum = 0, indexCounter = SIZE-1;

	for(int i = 0; i < SIZE; i++){
		for(int j = 0; j < SIZE; j++){
			
			if(j == indexCounter){
				totalSum += matrix[i][j];
			}
		}
		--indexCounter;
	}
	return totalSum;
}

/* ################ */
/* Questão 2-B) */
int checkSymmetricMatrix(int matrix[SIZE][SIZE]){
	int totalSum = 0, booleanCheck = 1;

	for(int i = 0; i < SIZE; i++){
		for(int j = 0; j < SIZE; j++){
			if(matrix[i][j] != matrix[j][i]){
				booleanCheck = 0;
			}		
		}
	}
	return booleanCheck;
}

/* ################ */
/* Questão 2-C) */
int checkPerfectNumber(int number){
	int booleanCheck = 1, vectorIndex = 0, divisorsSum = 0;
	int holderVector[number];


	for(int i = 0; i < number; i++){
		holderVector[i] = 0;
	}

	for(int i = 1; i < number; i++){
		if((number % i) == 0){
			holderVector[vectorIndex] = i;
			++vectorIndex;
		}
	}

	for(int i = 0; i < number; i++){
		divisorsSum += holderVector[i];
	}

	if(divisorsSum == number){
		return 1;
	}
	else{
		return 0;
	}
}

/* ################ */
/* Questão 2-D) */
void recursiveOddSequence(int *counter, int number){

	printf("%d ", number);
	
	if(*counter > 1){
		number += 2;
		*counter -= 1;
		recursiveOddSequence(&(*counter), number);
	}	
}

/* ################ */
/* Print Debugs */
void printMatrix(int matrix[SIZE][SIZE]){
	for(int i = 0; i < SIZE; i++){
		for(int j = 0; j < SIZE; j++){
			int holder;
			printf("%2d ", matrix[i][j]);
		}
		printf("\n");
	}
}

int main(void){
	int matrix[SIZE][SIZE];
	int perfectNumberCounter = 0, greatestDiagonalNumber;

	createMatrix(matrix);

	printf("\n\n\n2)\n");
	printMatrix(matrix);


	/* ################ */
	/* Questão 2-A) */
	printf("2-A) Secondary Diagonal Sum: %d;\n", sumSecondaryDiagonal(matrix));


	/* ################ */
	/* Questão 2-B) */
	if(checkSymmetricMatrix(matrix)){
		printf("2-B) Symmetric;\n");
	}
	else{
		printf("2-B) Not symmetric;\n");
	}

	/* ################ */
	/* Questão 2-C) */
	for(int i = 0; i < SIZE; i++){
		for(int j = 0; j < SIZE; j++){
			if(checkPerfectNumber(matrix[i][j])){
				++perfectNumberCounter;
			}
		}
	}
	printf("2-C) perfect Number quant: %d;\n", perfectNumberCounter);

	/* ################ */
	/* Questão 2-D) */
	for(int i = 0; i < SIZE; i++){
		for(int j = 0; j < SIZE; j++){
			if(i == j){
				if(matrix[i][j] > greatestDiagonalNumber){
					greatestDiagonalNumber = matrix[i][j];
				}
			}
		}
	}

	printf("2-D) First %d odd numbers: ", greatestDiagonalNumber);
	recursiveOddSequence(&greatestDiagonalNumber, 1);
	printf("\n");
	return 0;
}