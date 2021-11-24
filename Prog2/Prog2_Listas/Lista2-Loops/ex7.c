#include <stdio.h>

int main(void){

	int ageEntry, iterationsCounter = 0;
	char movieRating;


	float 	ageAverage = 0, 
			greatPercentage = 0, goodPercentage = 0, 
		  	regularPercentage = 0, terriblePercentage = 0;

	printf("Digite uma idade negativa para finalizar\n");

	while(1){
		printf("Digite a sua idade: ");
		scanf("%d", &ageEntry);

		if(ageEntry < 0) break;

		do{
			printf("Digite a sua nota do filme(O-B-R-P): ");
			scanf(" %c", &movieRating);
		}while(movieRating != 'O' && movieRating != 'B' && movieRating != 'R' && movieRating != 'P');


		iterationsCounter++;

		ageAverage += ageEntry;
		if(movieRating == 'O') greatPercentage++;
		if(movieRating == 'B') goodPercentage++;
		if(movieRating == 'R') regularPercentage++;
		if(movieRating == 'P') terriblePercentage++;
	}

	ageAverage = ageAverage / iterationsCounter;
	greatPercentage    = (greatPercentage    / iterationsCounter)*100;
	goodPercentage     = (goodPercentage     / iterationsCounter)*100;
	regularPercentage  = (regularPercentage  / iterationsCounter)*100;
	terriblePercentage = (terriblePercentage / iterationsCounter)*100;
	
	printf("\nMédia de idade: %.2f.\n", ageAverage);
	printf("Média de notas ótimas: %.1f%%.\n", greatPercentage);
	printf("Média de notas boas: %.1f%%.\n", goodPercentage);
	printf("Média de notas regulares: %.1f%%.\n", regularPercentage);
	printf("Média de notas terriveis: %.1f%%.\n", terriblePercentage);
	return 0;
}