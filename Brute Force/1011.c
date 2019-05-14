#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){

	int num;
	int x, y, dist;
	int temp, result;
	int *ans;

	scanf("%d", &num);
	ans = (int*)malloc(sizeof(int)*num);

	for (int i = 0; i < num; ++i){
		
		scanf("%d %d", &x, &y);

		dist = y-x;
		temp = 1;
		ans[i] = 0;

		while(dist >= temp*2){
			dist -= temp*2;
			temp++;
			ans[i] += 2;
		}
		while(dist >=  temp){
			dist -= temp;
			if(temp > 1) temp--;
			ans[i]++;
		}
		if(dist != 0) ans[i]++;
	}

	for (int i = 0; i < num; ++i)
	{
		printf("%d\n", ans[i]);
	}

	free(ans);

	return 0;
}


