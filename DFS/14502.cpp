#include <cstdio>
#include <vector>

using namespace std;

int lab[8][8];
int tempLab[8][8];
int dir[2][4] = {
    {1, 0, -1 ,0},
    {0, 1, 0, -1}
};
int safed = 0;
int n, m;

vector<pair<int, int> > virus;
vector<pair<int, int> > wallAvailable;

void dfs(vector<int> walls, int curIdx);
void dfsVirus(int x, int y);

int main(){
    
    vector<int> walls;

    scanf("%d %d", &n, &m);
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            scanf("%d", &lab[i][j]);
            if(lab[i][j] == 2) virus.push_back(make_pair(i, j));
            if(lab[i][j] == 0) wallAvailable.push_back(make_pair(i, j));
        }
    }
    dfs(walls, 0);
    printf("%d\n", safed);
}

void dfs(vector<int> walls, int curIdx){
    
    
    if(walls.size() == 3){
        int safedSize = 0;

        // 임시 연구실에 기존 연구실 정보 복사.
        for(int i=0; i<8; i++){
            for(int j=0; j<8; j++){
                tempLab[i][j] = lab[i][j];
            }
        }
        // 임시 연구실에 벽 설치
        for(int i=0; i<3; i++){
            tempLab[wallAvailable[walls[i]].first][wallAvailable[walls[i]].second] = 1;
        }
        // 기존 연구실에서 바이러스 퍼진 곳들을 임시 연구실에서 전부 2로 표시.
        for(int j=0; j<virus.size(); j++){
            for(int i=0; i<4; i++){
                if(virus[j].first+dir[0][i] >= 0 && virus[j].first+dir[0][i] < n && virus[j].second+dir[1][i] >= 0 && virus[j].second+dir[1][i] < m){
                    if(tempLab[virus[j].first+dir[0][i]][virus[j].second+dir[1][i]] == 0){
                        dfsVirus(virus[j].first+dir[0][i], virus[j].second+dir[1][i]);
                    }
                }
            }
        }

        // 안전영역 크기 도출.
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(tempLab[i][j] == 0) safedSize++;
            }
        }
        if(safed < safedSize) safed = safedSize;
        return;
    }else if(curIdx >= wallAvailable.size()){
        return;
    }


    dfs(walls, curIdx+1);
    if(curIdx < wallAvailable.size()){
        walls.push_back(curIdx);
        dfs(walls, curIdx+1);
    }
}

// 가능한 바이러스 퍼질 수 있는 곳 전부 퍼트림.
void dfsVirus(int x, int y){
    tempLab[x][y] = 2;
    for(int i=0; i<4; i++){
        if(x+dir[0][i] >= 0 && x+dir[0][i] < n && y+dir[1][i] >= 0 && y+dir[1][i] < m){
            if(tempLab[x+dir[0][i]][y+dir[1][i]] == 0){
                dfsVirus(x+dir[0][i], y+dir[1][i]);
            }
        }
    }
}