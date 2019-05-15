#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){

	char *str;
	int temp;
	int result, len;
	int i, j;

	result = 0;
	str = (char*)malloc(sizeof(char)*101);

	gets(str);
	len = strlen(str);

		

	for (int i = 0; i < len; ++i){
		switch(str[i]){
			case 'c':
				if(str[i+1] == '=' || str[i+1] == '-') i++;
				break;
			case 'd':
				if(str[i+1] == 'z' && str[i+2] == '=') i+=2;
				else if(str[i+1] == '-') i++;
				break;
			case 'l': case 'n':
				if(str[i+1] == 'j') i++;
				break;
			case 's': case 'z':
				if(str[i+1] == '=') i++;
				break;
			default:
				break;
		}
		result++;
	}
	printf("%d\n", result);
	return 0;
}	



