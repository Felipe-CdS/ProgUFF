#include <stdio.h>
#include <string.h>

#define N 3 

struct typeStudent{
	char mat[11];
	char name[40];
	float CR;
	int trancado;
};
typedef struct typeStudent tStudent;


tStudent studentConstructor(char *mat, char *name, float CR, int trancado){
	tStudent studentHolder;

	strcpy(studentHolder.mat, mat);
	strcpy(studentHolder.name , name);
	studentHolder.CR = CR;
	studentHolder.trancado = trancado;

	return studentHolder;
}

void printStudent(tStudent *x){
	printf("%s | %s | %.2f | %d\n", (*x).mat, (*x).name, (*x).CR, (*x).trancado);
}

/*int jubila(tStudent *studentsVector){
	int quant = 0, thisSemester = 1, thisYear = 2021;
	int studentSemesterHolder, studentYearHolder;
	for(int i = 0; i < N; i++){
		char holder[11];
		strcpy(holder, &studentsVector[i].mat);
		printf("%s\n", holder);
	}

	return quant;
}*/


int main(void){
	tStudent studentsVector[N];

	for(int i = 0; i < N; i++){
		
		char matHolder[11], nameHolder[40];
		float CRHolder;
		int trancadoHolder;

		printf("Mat: ");
		scanf(" %s", matHolder);
		printf("Name: ");
		scanf(" %[^\n]s", nameHolder);
		printf("CR: ");
		scanf("%f", &CRHolder);
		printf("Trancado: ");
		scanf("%d", &trancadoHolder);

		studentsVector[i] = studentConstructor(matHolder, nameHolder, CRHolder, trancadoHolder);
	}
	
	printStudent(&studentsVector[0]);

	//jubila(studentsVector);

	
	return 0;
}