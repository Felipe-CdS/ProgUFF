#include "../Lists_Library/SLL.h"
#include <stdio.h>

void recursive_binary_converter(int n, SLL **answer);
void print_number(SLL *number_array);

int	main(void){

	int entry;
	SLL *answer;

	while(1){
		answer = StartList();

		printf("Enter number to convert: ");
		scanf("%d", &entry);

		if(entry <= 0) break;

		recursive_binary_converter(entry, &answer);

		printf("Binary converted: ");
		print_number(answer);
		printf("\n");
	}	

	return 0;
}

void recursive_binary_converter(int n, SLL **answer){

	int quotient, remainder;

	quotient = n / 2;
	remainder = n % 2;

	if(quotient){
		recursive_binary_converter(quotient, answer);   
	}

	(*answer) = AddNewElementEnd((*answer), remainder);
}

void print_number(SLL *number_array){
	if(number_array){
		printf("%d", number_array->data);
		print_number(number_array->nextIndex);
	}
}