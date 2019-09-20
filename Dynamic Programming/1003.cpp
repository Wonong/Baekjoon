#include <cstdio>

using namespace std;

int dp[41][2];

int main(){
    int t, n;

    dp[0][0] = 1;
    dp[0][1] = 0;
    dp[1][0] = 0;
    dp[1][1] = 1;

    scanf("%d", &t);

    for(int i=2; i<=40; i++){
        dp[i][0] = dp[i-1][0] + dp[i-2][0];
        dp[i][1] = dp[i-1][1] + dp[i-2][1];
    }

    while(t--){
        scanf("%d", &n);
        printf("%d %d\n", dp[n][0], dp[n][1]);
    }
}