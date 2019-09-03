#include <cstdio>

#define SIZE 1000001

using namespace std;

int checkArr[SIZE];

int main(){
    long long min, max;
    int ans = 0;

    scanf("%lld %lld", &min, &max);

    for(int i=0; i<SIZE; i++) checkArr[i] = 1;

    for(long long i=2; i*i <= max; i++){
        long long start = i*i - min%(i*i);
        if(start == i*i) start = 0;
        for(long long j=start; j<=max-min; j += i*i){
            checkArr[j] = 0;
        }
    }

    for(int i=0; i<=max-min; i++){
        if(checkArr[i] == 1){
            ans++;
        }
    }

    printf("%d\n", ans);

}