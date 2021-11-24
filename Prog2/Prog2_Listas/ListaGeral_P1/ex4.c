#include <stdio.h>


int mdc(int *x, int *y){

	if(y <= x && (*x % *y) == 0){
		return *y;
	}
	else if(x < y){
		mdc(&(*y), &(*x));
	}
	else{
		int organizeHolder = *x % *y; 
		mdc(&(*y), &organizeHolder);
	}

}

int main(void){
	int entry1, entry2;

	scanf(" %d", &entry1);
	scanf(" %d", &entry2);

	printf("O mdc é: %d\n", mdc(&entry1, &entry2));
	return 0;
}