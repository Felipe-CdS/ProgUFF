#include <stdio.h>


int main(void){
	int startHour, startMinute, finalHour, finalMinute; 
	int totalHours = 0, totalMinutes = 0, totalPrice = 0;

	scanf("%d", &startHour);
	scanf("%d", &startMinute);
	scanf("%d", &finalHour);
	scanf("%d", &finalMinute);

	totalHours = finalHour - startHour;
	totalMinutes = finalMinute - startMinute;

	if(totalMinutes < 0){
		totalMinutes = 60 + totalMinutes;
	}

	printf("Tempo total: %d:%d.\n", totalHours, totalMinutes);
	if(finalMinute >= startMinute){
		totalHours++;
	}

	if(totalHours <= 2){
		totalPrice += 4;
	}
	else{
		totalPrice += 4;
		totalPrice += (totalHours - 3);
	}

	printf("Total pago: %d\n", totalPrice);

	return 0;
}