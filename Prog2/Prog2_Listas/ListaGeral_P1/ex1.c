#include <stdio.h>

int buildString(int number, char *array){

	int index = 0;

	while(number >= 10){
		char holder = number % 10 +'0';

		array[index] = holder;

		number = number/10;
		index++;
	}

	array[index] = number +'0';
	return ++index;
}

int checkPalindrome(int number){
	int divisionHolder, iterationCounter = 0;



	//printf("-->%d\n", numberAsString[0]);
	//printf("%d", numberAsString[1]);
	//printf("%d", numberAsString[2]);

	if(1){
		return 1;
	}
	else{
		return 0;
	}
}

int main(void) {

	int entry = 14257812;
	char numberAsString[10];

	int stringSize = buildString(entry, numberAsString);

	for(int i = 0; i<stringSize; i++){
		printf("--->%c\n", numberAsString[i]);
	}
	

	/*do{
		scanf("%d", &entry);
		if(entry <= 0) break;

		if(checkPalindrome(entry)){
			printf("É um palindromo.\n");
		}
		else{
			printf("Não é um palindromo.\n");
		}

	}while(entry >= 0);*/
	
	
	return 0;
}