#include <iostream>
#include <string>
#include <stack>
#include <queue>
#include <algorithm>
#include <math.h>

using namespace std;
long long calDp(long long **dp, int num, int k);
int main(){
    
    int n, k;
    long long *dp[201];

    cin >> n >> k;
    
    for(int i=0; i<201; i++) dp[i] = (long long*)calloc(n+1, sizeof(long long));
    for(int i=0; i<=n; i++) dp[1][i] = 1;

    cout << calDp(dp, n, k) << endl;

    for(int i=0; i<201; i++) free(dp[i]);

    return 0;
}

long long calDp(long long **dp, int num, int k){
    
    if(dp[k][num] != 0) return dp[k][num];
    
    for(int i=0; i<=num; i++){
        dp[k][num] += calDp(dp, num-i, k-1);
    }
    // cout << "num : " << num << ", k : " << k << endl;
    dp[k][num] %= 1000000000;
    return dp[k][num];
}



