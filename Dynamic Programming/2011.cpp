#include <iostream>
#include <stdio.h>
#include <stdlib.h>

using namespace std;

long calDp(long *dp, string str, int idx);

int main(){

    string num;
    long *dp;
    int len;

    getline(cin, num);

    len = num.length();
    dp = (long*)calloc(len, sizeof(long));
    for(int i=0; i<len; i++) dp[i] = -1;

    // 마지막 원소 초기화
    if(len > 0){
        if(num.at(len-1)-'0' != 0) dp[len-1] = 1;
        else dp[len-1] = 0;
    }
    
    // 뒤에서 두번째 원소 초가화
    if(len > 1){
        dp[len-2] = 0;
        if(num.at(len-2)-'0' != 0){
            dp[len-2] += dp[len-1];
            if(atoi(num.substr(len-2, 2).c_str()) < 27) dp[len-2] += 1;
        }
        
    }

    cout << calDp(dp, num, 0) << endl;

    free(dp);

    return 0;
}

long calDp(long *dp, string str, int idx){

    if(dp[idx] != -1){
        return dp[idx];
    }

    if(str.at(idx) - '0' == 0) dp[idx] = 0;
    else{
        dp[idx] = calDp(dp, str, idx+1);
        if(atoi(str.substr(idx, 2).c_str()) < 27){
            dp[idx] += calDp(dp, str, idx+2);
        }
    }

    dp[idx] %= 1000000;

    return dp[idx];
}