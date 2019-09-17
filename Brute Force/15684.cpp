#include <cstdio>
#include <algorithm>

#define INF 9999

using namespace std;

int width, m, height, ans = INF;
bool sadari[31][11];

bool checkSadari(){
    int y;
    // 전부 검사
    for(int i=1; i<=width; i++){
        y = i;
        for(int j=1; j<=height; j++){
            if(sadari[j][y]) y += 1;
            else if(sadari[j][y-1]) y -= 1;
        }
        if(y != i) return false;
    }
    return true;
}

void dfs(int row, int cnt){
    if(checkSadari()){
        ans = min(ans, cnt);
        return;
    }

    if(cnt != 3){
        for(int i = row; i<=height; i++){
            for(int j = 1; j<width; j++){
                // 해당 칸, 옆칸이 비어있으면 추가 후 dfs
                if(sadari[i][j]) continue;
                if(sadari[i][j-1]) continue;
                if(sadari[i][j+1]) continue;

                sadari[i][j] = true;
                dfs(i, cnt+1);
                sadari[i][j] = false;
            }
        }
    }
}

int main(){
    int temp[2];

    scanf("%d %d %d", &width, &m, &height);

    for(int i=0; i<m; i++){
        scanf("%d %d", &temp[0], &temp[1]);
        sadari[temp[0]][temp[1]] = true;
    }

    dfs(1, 0);
    if(ans == INF) ans = -1;
    printf("%d\n", ans);
}