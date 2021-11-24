#include <stdio.h>

int main(void){

	float totalWeight = 0;

	for(int i = 0; i < 25; i++){
		float holder;

		printf("Digite o peso da caixa nº %d: ", (i+1));
		scanf("%f", &holder);

		totalWeight += holder;
	}

	printf("O total do caminhão é: %.2f\n", totalWeight);

	return 0;
}