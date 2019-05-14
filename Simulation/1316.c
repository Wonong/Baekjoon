#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int checkNear(int a, int b);

int main(){

	int num, result;
	char str[100][101];
	int alphabet[100][26] = {0,};
	

	scanf("%d", &num);

	result = num;

	for(int i=0; i<num; i++){
		scanf("%s", str[i]);
		for(int j=0; j<strlen(str[i]); j++){
			if(alphabet[i][str[i][j]-'a'] == 0 || alphabet[i][str[i][j]-'a'] == j) alphabet[i][str[i][j]-'a'] = j+1;
			else{
				result--;
				break;
			}
		}
	}

	printf("%d", result);
	
	return 0;
}

