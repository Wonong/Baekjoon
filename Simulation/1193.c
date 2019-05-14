#include <stdio.h>

int main(){
    
    int num, idx;
    scanf("%d", &num);
    idx = 0;
    
    do{
        num -= idx;
    }while(num > ++idx);
    
    if(idx%2 == 0) printf("%d/%d\n", num, idx - num + 1);
    else printf("%d/%d\n", idx - num + 1, num);
    
    
    return 0;
}