#include <cstdio>
#include <algorithm>

#define INF 9999999999

using namespace std;

long long dp[500][500];
int novel[500], novelSum[500];

long long getDp(int i, int j){
    long long ret = INF;

    if(dp[i][j] != -1) return dp[i][j];
    else{
        for(int k = i; k < j; k++){
            long long temp = getDp(i, k) + getDp(k+1, j) + (novelSum[j] - novelSum[i-1]);
            ret = min(ret, temp);
        }
        dp[i][j] = ret;
    }
    
    return dp[i][j];
}

int main(){
    int t, k;

    scanf("%d", &t);
    while(t--){
        scanf("%d", &k);
        
        for(int i=0; i<k; i++){
            scanf("%d", &novel[i]);
            // dp 배열 초기화
            for(int j=0; j<k; j++) dp[i][j] = -1;
            dp[i][i] = 0;
        }
        // 부분합 배열 초기화
        novelSum[0] = novel[0];
        for(int i=1; i<k; i++) novelSum[i] = novelSum[i-1] + novel[i];
        
        printf("%lld\n", getDp(0, k-1));
    }
}