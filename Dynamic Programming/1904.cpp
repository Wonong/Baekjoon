#include <cstdio>

using namespace std;

long long dp[1000001];

int main(){
    int n;

    scanf("%d", &n);
    
    dp[1] = 1;
    dp[2] = 2;

    for(int i=3; i <= n; i++){
        dp[i] = (dp[i-2] + dp[i-1])%15746;
        
    }
    printf("%lld\n", dp[n]);

}