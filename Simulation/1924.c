#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){

	int year[13];
	int x, y, count;

	count = 0;

	scanf("%d %d", &x, &y);

	for (int i = 1; i < x; ++i)
	{
		switch(i){
			case 1: case 3: case 5: case 7: case 8: case 10: case 12:
				count += 31;
				break;
			case 2:
				count += 28;
				break;
			default:
				count += 30;
		}
	}

	count += y;

	switch(count%7){
		case 1:
			printf("MON\n");
			break;
		case 2:
			printf("TUE\n");
			break;
		case 3:
			printf("WED\n");
			break;
		case 4:
			printf("THU\n");
			break;
		case 5:
			printf("FRI\n");
			break;
		case 6:
			printf("SAT\n");
			break;
		default:
			printf("SUN\n");
			break;
	}


	return 0;
}


