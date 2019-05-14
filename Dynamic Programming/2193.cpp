#include <iostream>
#include <string>
#include <stack>
#include <queue>
#include <algorithm>

using namespace std;

long long getPN(long long *dp, int num);

int main(){
    
    int n;
    long long *dp;

    cin >> n;

    dp = (long long*)calloc(n+1, sizeof(long long));

    dp[1] = 1;
    if(n>=2) dp[2] = 1;
    if(n>=3) dp[3] = 2;

    cout << getPN(dp, n) << endl;

    free(dp);

    return 0;
}

long long getPN(long long *dp, int num){

    if(dp[num] > 0) return dp[num];

    dp[num] = getPN(dp, num-1) + getPN(dp, num-2);
    return dp[num];
}



