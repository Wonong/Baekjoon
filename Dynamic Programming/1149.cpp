#include <cstdio>
#include <algorithm>
#define R 0
#define G 1
#define B 2

using namespace std;

int dp[1000][3];

int main(){
    int n, temp[3];
    int ans;

    scanf("%d", &n);
    scanf("%d %d %d", &temp[0], &temp[1], &temp[2]);

    dp[0][R] = temp[0];
    dp[0][G] = temp[1];
    dp[0][B] = temp[2];

    for(int i=1; i<n; i++){
        scanf("%d %d %d", &temp[R], &temp[G], &temp[B]);
        dp[i][R] = min(dp[i-1][G], dp[i-1][B]) + temp[R];
        dp[i][G] = min(dp[i-1][R], dp[i-1][B]) + temp[G];
        dp[i][B] = min(dp[i-1][R], dp[i-1][G]) + temp[B];
    }

    ans = min(dp[n-1][R], dp[n-1][G]);
    ans = min(ans, dp[n-1][B]);

    printf("%d\n", ans);

}