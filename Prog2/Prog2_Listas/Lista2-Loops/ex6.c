#include <stdio.h>

int main(void){

	int entry;

	do{
		printf("Digite um valor de entrada entre 0 e 9.\n");
		scanf("%d", &entry);
	}while(entry < 0 || entry > 9);

	printf("Tabuada do %d.\n", entry);
	for(int i = 0; i <=10; i++){
		printf("%d x %d = %d\n", entry, i, (entry * i));
	}

	return 0;
}