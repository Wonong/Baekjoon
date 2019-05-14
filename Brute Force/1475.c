#include <stdio.h>

int main(){
    
    int num, arr[9], max;
    scanf("%d", &num);

    for(int i=0; i<9; i++) arr[i] = 0;
    max = 0;
    
    while(num >= 10){
        if(num%10 == 9) arr[6]++;
        else arr[num%10]++;
        num /= 10;
    }
    if(num == 9) arr[6]++;
    else arr[num]++;
    
    if(arr[6] % 2 == 1) arr[6] = arr[6]/2 + 1;
    else arr[6] = arr[6]/2;

    for (int i = 0; i < 9; ++i){
        if(arr[i] > max) max = arr[i];
    }

    printf("%d\n", max);
    
    return 0;
}