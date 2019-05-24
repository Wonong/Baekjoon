#include <cstdio>

using namespace std;

long long getFib(int num);

long long fibArr[91];

int main(){

    int num;

    scanf("%d", &num);

    fibArr[0] = 0;
    fibArr[1] = 1;

    printf("%lld\n", getFib(num));

}

long long getFib(int num){
    if(fibArr[num] != 0 || num == 0) return fibArr[num];
    else{
        fibArr[num] = getFib(num-1) + getFib(num-2);
    }
    return fibArr[num];
}