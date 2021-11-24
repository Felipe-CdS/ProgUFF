#include <stdio.h>

int main(void){
	float totalPrice = 0;

	for(int i = 0; i < 50; i++){
		printf("Digite o preço do produto nº %d: ", (i+1));
		float holder;
		scanf("%f", &holder);

		totalPrice += holder;
	}

	printf("O total da compra é %.2f.\n", totalPrice);

	return 0;
}