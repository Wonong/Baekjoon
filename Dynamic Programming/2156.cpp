#include <iostream>
#include <string>
#include <stack>
#include <queue>
#include <algorithm>

using namespace std;

int main(){
    
    int n;
    int *drinks;
    int *dp[2];

    cin >> n;

    drinks = (int*)malloc(sizeof(int)*n);
    for(int i=0; i<2; i++) dp[i] = (int*)malloc(sizeof(int)*n);

    for(int i=0; i<n; i++){
        cin >> drinks[i];
    }

    dp[0][0] = 0;
    dp[1][0] = drinks[0];
    dp[0][1] = dp[1][0];
    dp[1][1] = dp[1][0] + drinks[1];

    for(int i=2; i<n; i++){
        dp[0][i] = max(dp[1][i-1],dp[0][i-1]);
        dp[1][i] = max(dp[0][i-2] + drinks[i-1], dp[0][i-1]) + drinks[i];
    }

    cout << max(dp[0][n-1], dp[1][n-1]) << endl;

    free(dp[0]);
    free(dp[1]);

    return 0;
}

