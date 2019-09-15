#include <cstdio>

using namespace std;

bool checkNum(int num){
    int cnt = 3;

    while(num > 0){
        int temp = num % 10;
        num /= 10;
        if(temp == 6){
            cnt--;
            if(cnt == 0) return true;
        }else{
            cnt = 3;
        }
    }
    return false;
}

int main(){

    int n, i = 666, cnt = 1;
    
    scanf("%d", &n);

    while(cnt != n){
        while(true){
            i += 1;
            if(checkNum(i)) break;
        }
        cnt += 1;
    }

    printf("%d\n", i);
}