#include <iostream>
#include <string>
#include <stack>
#include <queue>
#include <algorithm>
#include <math.h>

using namespace std;

long long calDp(long long *dp, int num);

int main(){
    
    int t, n;
    long long *dp, *ans;
    
    cin >> t;

    ans = (long long*)malloc(sizeof(long long)*t);
    dp = (long long*)calloc(101, sizeof(long long));

    dp[1] = 1;
    dp[2] = 1;
    dp[3] = 1;
    dp[4] = 2;
    dp[5] = 2;

    for(int i=0; i<t; i++){
        cin >> n;
        ans[i] = calDp(dp, n);
    }

    for(int i=0; i<t; i++){
        cout << ans[i] << endl;    
    }

    free(dp);
    return 0;
}

long long calDp(long long *dp, int num){
    if(dp[num] != 0){
        return dp[num];
    }
    dp[num] = calDp(dp, num-1) + calDp(dp, num-5);
    return dp[num];
}


