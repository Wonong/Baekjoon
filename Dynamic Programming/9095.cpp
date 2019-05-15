#include <iostream>
#include <string>
#include <stack>
#include <queue>
#include <algorithm>

using namespace std;

int getAns(int *dp, int num);
int main(){

    int n, *dp, *t;

    cin >> n;
    dp = (int*)calloc(11, sizeof(int));
    t = (int*)malloc(sizeof(int)*n);

    dp[1] = 1;
    dp[2] = 2;
    dp[3] = 4;

    for(int i=0; i<n; i++){
        cin >> t[i];
    }
    for(int i=0; i<n; i++){
        cout << getAns(dp, t[i]) << endl;
    }

    return 0;
}

int getAns(int *dp, int num){

    if(dp[num] > 0) return dp[num];

    dp[num] = getAns(dp, num-1) + getAns(dp, num-2) + getAns(dp, num-3);

    return dp[num];

}

