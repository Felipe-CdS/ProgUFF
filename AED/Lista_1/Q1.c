#include "../Lists_Library/SLL.h"

int main(void){

	int entry, listSize;
	SLL *list;

	list = StartList();

	printf("Enter max number: ");
	scanf("%d", &entry);

	for(int i = 2; i <= entry; i++){
		list = AddNewElementEnd(list, i);
	}

	for(int i = 0; i <= GetSize(list); i++){

		SLL *elementAtI, *elementAtJ;

		//j = i+1 so it doesn't check and remove itself like 2%2=0 or 3%3=0
		for(int j = i+1; j <= GetSize(list); j++){

			elementAtI = SearchByIndex(list, i);
			elementAtJ = SearchByIndex(list, j);

			if(elementAtJ != 0 && elementAtI != 0){
				if(!(elementAtJ->data % elementAtI->data)){	
					list = RemoveElement(list, (elementAtJ->data));					
				}	
			}
		}	
	}

	printf("All prime numbers until %d: \n", entry);
	RecursivePrintList(list);
	printf("\n");	

	return 0;
}