#include <cstdio>

using namespace std;

int m, n;
int map[500][500];
int dp[500][500];

int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};

int getDp(int x, int y){
    if(dp[x][y] == -1){
        dp[x][y] = 0;
        for(int i=0; i<4; i++){
            if(x+dx[i] < 0 || x+dx[i] >= m || y+dy[i] < 0 || y+dy[i] >= n) continue;
            if(map[x+dx[i]][y+dy[i]] <= map[x][y]) continue;
            dp[x][y] += getDp(x+dx[i], y+dy[i]);
        }
    }
    return dp[x][y];
}

int main(){
    scanf("%d %d", &m, &n);

    for(int i=0; i<m; i++){
        for(int j=0; j<n; j++){
            scanf("%d", &map[i][j]);
            dp[i][j] = -1;
        }
    }
    dp[0][0] = 1;

    printf("%d\n", getDp(m-1, n-1));
}