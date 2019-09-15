#include <cstdio>
#include <algorithm>
using namespace std;

int tree[500][500], dp[500][500];

int main(){
    int n, ans;

    scanf("%d", &n);

    for(int i=0; i<n; i++){
        for(int j=0; j<=i; j++){
            scanf("%d", &tree[i][j]);
        }
    }

    dp[0][0] = tree[0][0];

    for(int i=1; i<n; i++){
        dp[i][0] = dp[i-1][0] + tree[i][0];
        dp[i][i] = dp[i-1][i-1] + tree[i][i];

        for(int j=1; j<i; j++){
            dp[i][j] = max(dp[i-1][j-1], dp[i-1][j]) + tree[i][j];
        }
    }

    ans = dp[n-1][0];

    for(int i=1; i<n; i++){
        if(ans < dp[n-1][i]) ans = dp[n-1][i];
    }

    printf("%d\n", ans);

}