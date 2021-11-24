#include <stdio.h>

int main(void){
	int entryA, entryB, sum = 0;

	printf("Digite o primeiro número: ");
	scanf("%d", &entryA);
	printf("Digite o segundo núrmero: ");
	scanf("%d", &entryB);

	if(entryA > entryB){
		printf("Impossivel operar.\n");
	} else {
		entryA++;
		while(entryA < entryB){
			sum += entryA;
			entryA++;
		}
		printf("A soma é igual a: %d.\n", sum);
	}
	
	return 0;
}