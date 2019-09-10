#include <cstdio>

using namespace std;

int arr[1000001];

int maker(int num){
    int ret = num;
    while(num != 0){
        ret += num%10;
        num /= 10;
    }
    return ret;
}

int main(){
    int n, digits = 1;
    int low, high;

    scanf("%d", &n);

    for(int i=10; i < 1000000; i*=10){
        if(n / i >= 1) digits += 1;
        else break;
    }

    low = n - digits * 10;
    high = n + digits * 10;

    for(int i=low; i <= high; i++){
        if(maker(i) == n){
            printf("%d\n", i);
            return 0;
        }
    }
    printf("%d\n", 0);
}