#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){

	char *str;
	char temp;
	int result, len;
	int i, j;

	result = 0;
	str = (char*)malloc(sizeof(char)*1000001);

	gets(str);
	len = strlen(str);

	for (i = 0; i < len; ++i){
		if(str[i] != ' ' && str[i] != '\0'){
			j = i;
			while(str[j] != ' ' && str[j] != '\0') j++;
			result++;
			i = j;
		}
	}
		

	printf("%d\n", result);

	return 0;
}	



