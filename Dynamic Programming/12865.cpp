#include <cstdio>
#include <algorithm>

using namespace std;

int dp[100001][100];
int things[100][2];

int getDp(int weight, int tIdx){
    if(dp[weight][tIdx] == -1){
        if(weight >= things[tIdx][0]){
            dp[weight][tIdx] = max(getDp(weight, tIdx-1), getDp(weight-things[tIdx][0], tIdx-1) + things[tIdx][1]);
        }else dp[weight][tIdx] = getDp(weight, tIdx-1);
    }
    return dp[weight][tIdx];
}

int main(){
    int n, k;

    scanf("%d %d", &n, &k);
    for(int i=0; i<n; i++){
        scanf("%d %d", &things[i][0], &things[i][1]);
        for(int j=0; j<=k; j++){
            dp[j][i] = -1;
        }
        dp[0][i] = 0;
    }

    // 0번쨰 아이템 관련 초기화
    for(int i=0; i<things[0][0]; i++) dp[i][0] = 0;
    for(int i=things[0][0]; i<=k; i++) dp[i][0] = things[0][1];

    printf("%d\n", getDp(k, n-1));
}