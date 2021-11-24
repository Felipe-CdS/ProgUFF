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

	RecursivePrintList(list);
	printf("\n");

	listSize = GetSize(list);

	for(int i = 0; i <= listSize; i++){

		SLL *elementAtI, *elementAtJ;

		

		for(int j = 0; j <= listSize; j++){

			elementAtI = SearchByIndex(list, i);
			elementAtJ = SearchByIndex(list, j);			

			if(elementAtJ != 0 && elementAtI != 0){
				printf("I: %d | J: %d\n", elementAtI->data, elementAtJ->data);
				//if((elementAtJ->data % elementAtI->data) == 0){
					//RemoveElement(list, elementAtJ->data);
				//}		
			}
		}

		//RecursivePrintList(list);
		//printf("\n");
	}

	

	return 0;
}