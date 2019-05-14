#include <iostream>
#include <string>
#include <stack>
#include <queue>
#include <algorithm>
#include <math.h>

using namespace std;

int calDp(int *dp, int num);

int main(){
    
    int n, count = 0;
    int *dp;

    cin >> n;
    
    dp = (int*)calloc(n+1, sizeof(int));

    dp[0] = 0;
    dp[1] = 1;
    dp[2] = 2;
    dp[3] = 3;
    dp[4] = 1;


    cout << calDp(dp, n) << endl;

    free(dp);

    return 0;
}

int calDp(int *dp, int num){

    int min = num;
    int limit = (int)sqrt(num);

    // if(limit * limit == num) return 1;
    if(num == 0) return 0;
    if(num != 0 && dp[num] != 0) return dp[num];
    
    for(int i=1; i<= limit; i++){
        if(min > calDp(dp, num - i*i)){
            min = dp[num - i*i];
            // cout << i << ", " << min << endl;
        }
    }
    dp[num] = min + 1;

    return dp[num];
}

