#include <iostream>
#include <string>
#include <stack>
#include <queue>
#include <algorithm>

using namespace std;

int getAns(int *dp, int num);

int main(){

    int n, *dp;

    cin >> n;

    dp = (int*)calloc(n+1, sizeof(int));

    dp[1] = 1;
    if(n >=2) dp[2] = 3;   

    cout << getAns(dp, n) << endl;

    return 0;
}

int getAns(int *dp, int num){

    if(dp[num] > 0) return dp[num];

    dp[num] = (getAns(dp, num-1) + getAns(dp, num-2)*2)%10007;

    return dp[num];
    
}

