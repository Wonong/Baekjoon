#include <cstdio>

using namespace std;

int dp[10001];
int coins[100];

int main(){
    int n, k;

    scanf("%d %d", &n, &k);

    for(int i=0; i<n; i++){
        scanf("%d", &coins[i]);
    }

    dp[0] = 1;

    for(int i=0; i<n; i++){
        for(int j = coins[i]; j <= k; j++){
            dp[j] += dp[j-coins[i]];
        }
    }

    printf("%d\n", dp[k]);
}

