#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){

	int apt[15][15];
	int num, k, n;
	int *ans;


	apt[0][1] = 1;
	for (int i = 1; i < 15; ++i){
		apt[0][i] = i;
		apt[i][1] = 1;	
	} 


	for (int i = 1; i < 15; ++i){
		for (int j = 2; j < 15; ++j){
			apt[i][j] = apt[i][j-1] + apt[i-1][j];
		}
	}

	scanf("%d", &num);
	ans = (int*)malloc(sizeof(int)*num);
	for (int i = 0; i < num; ++i){
		scanf("%d", &k);
		scanf("%d", &n);
		ans[i] = apt[k][n];
	}

	for (int i = 0; i < num; ++i){
		printf("%d\n", ans[i]);
	}

	free(ans);

	return 0;
}


