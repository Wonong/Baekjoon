#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){

	char *str;
	int temp;
	int result, len;
	int i, j;

	result = 0;
	str = (char*)malloc(sizeof(char)*16);

	gets(str);
	len = strlen(str);

	result += len;

	for (i = 0; i < len; ++i){
		temp = str[i] - 'A';
		switch(temp){
			case 0: case 1: case 2:
				result += 2;
				break;
			case 3: case 4: case 5:
				result += 3;
				break;
			case 6: case 7: case 8:
				result += 4;
				break;
			case 9: case 10: case 11:
				result += 5;
				break;
			case 12: case 13: case 14:
				result += 6;
				break;	
			case 15: case 16: case 17: case 18:
				result += 7;
				break;
			case 19: case 20: case 21:
				result += 8;
				break;
			default:
				result += 9;
				break;
		}
	}
		
	printf("%d\n", result);

	return 0;
}	



