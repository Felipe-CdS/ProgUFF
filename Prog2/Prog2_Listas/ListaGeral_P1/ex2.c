#include <stdio.h>


float calcAverage(float *vector){
	float average;
	int smallestIndex = 0, highestIndex = 0;

	for(int i = 0; i < 6; i++){
		if(vector[i] <= vector[smallestIndex]){
			smallestIndex = i;
		}
		if(vector[i] >= vector[highestIndex]){
			highestIndex = i;
		}
	}

	printf("discarting %.2f and %.2f\n", vector[smallestIndex], vector[highestIndex]);

	vector[smallestIndex] = 0;
	vector[highestIndex] = 0;

	for(int i = 0; i < 6; i++){
		average += vector[i];
	}

	average = average / 4;

	return average;
}


int main(void){
	float scores[6] = {2,3,4,1,8,7.5};
	printf("result: %.2f\n", calcAverage(scores));
	return 0;
}