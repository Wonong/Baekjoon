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

    dp = (int*)calloc((n+1), sizeof(int));

    dp[1] = 0;
    if(n>=2) dp[2] = 1;
    if(n>=3) dp[3] = 1;

    cout << getAns(dp, n) << "\n";

    free(dp);
    return 0;
}

int getAns(int *dp, int num){

    int minVal;


    if(num == 1) return 0;
    if(dp[num] > 0){
        return dp[num];
    }else{

        if(num%2 == 0){
            if(num%3 == 0){
                minVal = std::min(getAns(dp, num/2), getAns(dp, num/3));
            }else{
                minVal = getAns(dp, num/2);
            }
            minVal = std::min(minVal, getAns(dp, num-1));
        }else if(num %3 == 0){
            minVal = std::min(getAns(dp, num/3), getAns(dp, num-1));
        }else{
            minVal = getAns(dp, num-1);    
        }

        dp[num] = 1 + minVal;

        return dp[num];
    }
    
}

