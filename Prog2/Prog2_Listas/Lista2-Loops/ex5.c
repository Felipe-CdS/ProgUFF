#include <stdio.h>

int main(void){

	int entry, totalArea = 0;

	printf("Digite um número negativo a qualquer momento para sair.\n");
	while(1){
		float holder;

		printf("Digite a largura do próximo cômodo: ");
		scanf("%d", &entry);
		if(entry < 0) break;

		holder = entry;

		printf("Digite a altura do próximo cômodo: ");
		scanf("%d", &entry);
		if(entry < 0) break;

		holder *= entry;
		totalArea += holder;
		printf("Altura parcial: %d.\n\n", totalArea);
	}

	printf("A area total é: %d\n", totalArea);



	return 0;	
}