#include "SLL.h"

int main(void){
	SLL *list = StartList(), *previousIndex;

	/*for(int i = 0; i < 3; i++){
		list = AddNewElementStart(list, i);
		PrintList(list);
	}*/

	for(int i = 1; i < 10; i++){
		list = AddNewElementEnd(list, i);
		
	}

	RecursivePrintList(list);
	printf("\n");
	list = RemoveElement(list, 1);
	RecursivePrintList(list);
	printf("\n");

	return 0;
}