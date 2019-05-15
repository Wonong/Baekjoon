#include <stdio.h>
#include <stdlib.h>

int main(){

	int num;
	int h, w, n;
	int *numW, *numH;

	scanf("%d", &num);

	numW = (int*) malloc(sizeof(int)*num);
	numH = (int*) malloc(sizeof(int)*num);


	for (int i = 0; i < num; ++i){
		
		scanf("%d %d %d", &h, &w, &n);

		numH[i] = n % h;
		if(numH[i] == 0) numH[i] = h;

		numW[i] = 0;
		while(n > 0){
			numW[i]++;
			n -= h;
		}

	}

	for (int i = 0; i < num; ++i){
		if(numW[i] >= 10) printf("%d%d\n", numH[i], numW[i]);
		else printf("%d0%d\n", numH[i], numW[i]);
	}

	free(numH);
	free(numW);

	return 0;
}



