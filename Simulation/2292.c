#include <stdio.h>
#include <stdlib.h>

int main(){
    int num, idx, ans;
    
    scanf("%d\n", &num);
    idx = 6;
    ans = 1;
    
    if(num == 1){
        printf("%d\n", ans);
        return 0;
    }
    while(num>1){
        num -= idx;
        ans++;
        idx += 6;
    }
    
    printf("%d\n", ans);
    
    return 0;
}