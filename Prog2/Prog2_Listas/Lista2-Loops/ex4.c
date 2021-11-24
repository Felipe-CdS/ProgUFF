#include <stdio.h>

int main(void){
	int entryA, entryB, sum = 0;

	printf("Digite o primeiro número: ");
	scanf("%d", &entryA);
	printf("Digite o segundo número: ");
	scanf("%d", &entryB);

	if(entryA > entryB) {
		printf("Impossivel operar.\n");
	}
	else{
		entryA++;

		while(entryA < entryB){
			if(entryA % 4 == 0) sum += entryA;
			entryA++;
		}

		printf("A soma total é: %d.\n", sum);
	}

	return 0;
}