#include <cstdio>
#include <queue>
#define INF 99999999

using namespace std;

int map[100][100];
int dist[100][100];
int n, minDist = INF;

int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};

bool checkIdx(int x, int y){
    if(x < 0 || x >= n) return false;
    if(y < 0 || y >= n) return false;
    return true;
}

// 국가별 flag 표기
void dfs(int x, int y, int flag){
    map[x][y] = flag;
    for(int i=0; i<4; i++){
        int nx = x + dx[i];
        int ny = y + dy[i];
        if(checkIdx(nx, ny) && map[nx][ny] == 1 ){
            dfs(nx, ny, flag);
        }
    }
}

void bfs(){
    int cost = 0;
    queue<pair<int, int> > q;

    // 기존 땅들 queue에 다 넣음
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            if(map[i][j] > 1) q.push(make_pair(i, j));
        }
    }
    while(!q.empty()){
        cost++;
        int len = q.size();
        // queue에서 하나하나 뺌
        for(int i=0; i<len; i++){
            pair<int, int> temp;
            temp = q.front();
            q.pop();
            // 해당 땅 주변에 확장 가능한 땅(0) 있는지 체크
            for(int j=0; j<4; j++){
                // 있으면, 확장 --> map 확장, dist초기화
                // 확장한 땅의 좌표 queue에 넣음
                if(checkIdx(temp.first+dx[j], temp.second+dy[j]) && map[temp.first+dx[j]][temp.second+dy[j]] == 0 && dist[temp.first+dx[j]][temp.second+dy[j]] == 0){
                    map[temp.first+dx[j]][temp.second+dy[j]] = map[temp.first][temp.second];
                    dist[temp.first+dx[j]][temp.second+dy[j]] = cost;
                    q.push(make_pair(temp.first+dx[j], temp.second+dy[j]));
                }
            }
        }

    }

}

int main(){

    int flag = 1;

    scanf("%d", &n);
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            scanf("%d", &map[i][j]);
            dist[i][j] = 0;
        }
    }

    // 국가별로 다른 숫자로 태깅
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            if(map[i][j] == 1){
                dfs(i, j, ++flag);
            }
        }
    }
    bfs();

    // dist를 완전탐색하면서 0이 아닌 요소가 붙어있으면서 작은 값 탐색
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            if(dist[i][j] == 0) continue;
            for(int k=0; k<4; k++){
                int nx = i+dx[k];
                int ny = j+dy[k];
                if(checkIdx(nx, ny) && map[i][j] != map[nx][ny]){
                    if(minDist > (dist[i][j] + dist[nx][ny])) minDist = dist[i][j] + dist[nx][ny];
                }
            }
        }
    }
    

    printf("%d\n", minDist);
}