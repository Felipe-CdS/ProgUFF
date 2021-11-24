#include <stdio.h>

int recursiveSum(int number){
	if(number > 1){
		return (number + recursiveSum(number-1));
	}
	else{
		return 1;
	}
}

int main(void){
	int entry = 0;

	scanf("%d", &entry);
	printf("%d\n", recursiveSum(entry));

	return 0;
}