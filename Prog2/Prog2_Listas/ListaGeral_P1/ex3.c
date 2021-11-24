#include <stdio.h>

int checkWord(char *keyword, char *phrase){
	int containsCheck = 0;

	int keywordIndex = 0;

	for(int i = 0; i < 256; i++){
		if(keyword[keywordIndex] == '\0'){
			containsCheck = 1;
			break;
		}
		if(keyword[keywordIndex] == phrase[i]){
			++keywordIndex;
		}	
	}

	return containsCheck;
}

int main(void){
	char keyword[256];
	char phrase[256];

	printf("Enter the keyword: ");
	scanf(" %s", keyword);
	printf("Enter the phrase: ");
	scanf(" %[^\n]s", phrase);

	printf("keyword: %s\n", keyword);
	printf("phrase: %s\n\n", phrase);

	if(checkWord(keyword, phrase)){
		printf("The phrase contains the keyword.\n");
	}
	else{
		printf("The phrase doesn't contain the keyword.\n");
	}
	return 0;
}