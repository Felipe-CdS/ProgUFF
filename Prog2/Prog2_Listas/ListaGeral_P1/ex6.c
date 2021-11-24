#include <stdio.h>


void countLetters(int *counter, char *keyword){
	if(keyword[*counter] != '\0'){
		(*counter)++;

		countLetters(&(*counter), keyword);
	}
}

int main(void){

	int counter = 0;
	char keyword[1024];

	scanf(" %[^\n]s", keyword);

	countLetters(&counter, keyword);
	printf("%d\n", counter);


	return 0;
}