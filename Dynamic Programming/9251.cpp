#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

int dp[1001][1001];

int main(){
    char str[2][1001];
    int len[2], ans = 0;

    scanf("%s", &str[0][1]);
    scanf("%s", &str[1][1]);

    len[0] = strlen(&str[0][1]);
    len[1] = strlen(&str[1][1]);

    if(str[0][1] == str[1][1]){
        dp[1][1] = 1;
        ans = 1;
    }

    for(int i = 1; i<=len[0]; i++){
        for(int j = 1; j<=len[1]; j++){
            if(str[0][i] == str[1][j]) dp[i][j] = dp[i-1][j-1] + 1;
            else dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
            
            if(dp[i][j] > ans) ans = dp[i][j];
        }
    }
    
    printf("%d\n", ans);

}