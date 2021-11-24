#include <stdio.h>
#include <string.h>


int main(void){
	char finalCode[4], holderEntry[4];
	float finalPrice = 0.3f, holderEntryPrice;

	scanf("%s", holderEntry);

	while(strcmp(holderEntry, "xxx") != 0){

		scanf("%f", &holderEntryPrice);

		if(holderEntryPrice >= finalPrice){
			strcpy(finalCode, holderEntry);
			finalPrice = holderEntryPrice;
		}

		scanf("%s", holderEntry);
	}

	printf("Final Code: %s\n", finalCode);
	printf("Final Price: %.3f\n", finalPrice);

	return 0;
}