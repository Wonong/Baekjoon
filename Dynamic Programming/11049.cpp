#include <cstdio>
#include <algorithm>

#define INF 2147483645

using namespace std;

struct mat{
    int r,c;
};

int n;
int dp[500][500], mat[500][2];

int getDp(int i, int j){

    int ret = INF;

    if(j-i == 1){
        dp[i][j] = mat[i][0] * mat[i][1] * mat[j][1];
        return dp[i][j];
    }

    if(dp[i][j] == -1){
        for(int k = i; k<j; k++){
            ret = min(ret, getDp(i, k) + getDp(k+1, j) + mat[i][0]*mat[k][1]*mat[j][1]);
        }
        dp[i][j] = ret;
    }

    return dp[i][j];
}

int main(){
    
    scanf("%d", &n);

    for(int i=0; i<n; i++){
        scanf("%d %d", &mat[i][0], &mat[i][1]);
        for(int j=0; j<n; j++){
            dp[i][j] = -1;
        }
        dp[i][i] = 0;
    }

    printf("%d\n", getDp(0, n-1));

}