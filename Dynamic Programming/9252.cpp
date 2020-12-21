#include <cstdio>
#include <cstring>
#include <string>
#include <algorithm>

using namespace std;

int dp[1001][1001];
string lcs[1001][1001];

int main(){
    char str[2][1001];
    int len_str[2];
    int ans = 0;
    string ret;

    scanf("%s", &str[0][1]);
    scanf("%s", &str[1][1]);

    for(int i=0; i<2; i++) len_str[i] = strlen(&str[i][1]);
    for(int i=0; i<len_str[0]; i++){
        lcs[i][0] = "";
        dp[i][0] = 0;
    }
    for(int i=0; i<len_str[1]; i++){
        lcs[0][i] = "";
        dp[0][i] = 0;
    } 

    for(int i=1; i<=len_str[0]; i++){
        for(int j=1; j<=len_str[1]; j++){
            if(str[0][i] == str[1][j]){
                dp[i][j] = dp[i-1][j-1] + 1;
                lcs[i][j] = lcs[i-1][j-1] + str[0][i];
            }else{
                dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
                if (dp[i-1][j] > dp[i][j-1]){
                    lcs[i][j] = lcs[i-1][j];
                }else{
                    lcs[i][j] = lcs[i][j-1];
                }
            }
        }
    }

    for(int i=0; i<=len_str[1]; i++){
        if(ans < dp[len_str[0]][i]){
            ans = dp[len_str[0]][i];
            ret = lcs[len_str[0]][i];
        }
    }
    
    printf("%d\n", ans);
    printf("%s\n", ret.c_str());
}