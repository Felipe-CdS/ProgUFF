#include <stdio.h>

int main(void) {
	
	int size = 0;

	while(size >= 0){
		printf("Enter size: ");
		scanf(" %d", &size);

		int matrix[size][size];


		for(int i = 0; i < size; i++){
			for(int j = 0; j < size; j++){
				matrix[i][j] = (i + 1) * (j + 1);
				printf(" %3d", matrix[i][j]);
			}
			printf("\n");
		}

		printf("\n");
	}
	

	return 0;
}