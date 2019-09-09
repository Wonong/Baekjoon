#include <cstdio>

using namespace std;

long long dp[31];

int main(){
    int n;

    scanf("%d", &n);

    dp[0] = 1;
    dp[2] = 3;

    for(int i=4; i<=n; i += 2){
        dp[i] = 2;
        for(int j = 2; j < i; j += 2){
            if(j == 2) dp[i] += 3 * dp[i-j];
            else dp[i] += 2 * dp[i-j];
        }
    }

    printf("%lld\n", dp[n]);

}