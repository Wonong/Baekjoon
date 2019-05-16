#include <cstdio>
#include <vector>
#include <queue>

using namespace std;

int n;
int ocean[20][20];
int visit[20][20];
int sx, sy;     // 상어 위치
int sSize = 2;  // 상어 크기
int fx, fy; // 현재 가장 가까운 물고기 위치
int feeded = 0, cnt = 0;
int lastFeedTime = 0;
bool isFish = false;

int dir[4][2] = {
    {1,0}, {0,1}, {-1, 0}, {0, -1}
};

bool checkIdx(int x, int y);
bool checkNear(int x1, int y1, int x2, int y2);
void bfs();

int main(){
    scanf("%d", &n);
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            scanf("%d", &ocean[i][j]);
            if(ocean[i][j] == 9){
                sx = i;
                sy = j;
            }
        }
    }
    bfs();
    printf("%d\n", cnt);

}

void bfs(){
    queue<pair<int, int> > q;
    int size;
    pair<int, int> temp;
    q.push(make_pair(sx, sy));

    while(true){
        size = q.size();
        isFish = false;
        for(int i=0; i<size; i++){
            temp = q.front();
            q.pop();
            // 현재 칸에 물고기 존재.
            if(ocean[temp.first][temp.second] != 0 && ocean[temp.first][temp.second] != 9 && ocean[temp.first][temp.second] < sSize){
                // 기존에 물고기 위치 파악 안됐거나, 현재 물고기가 더 가까운 경우.
                if(!isFish || checkNear(temp.first, temp.second, fx, fy)){
                    isFish = true;
                    fx = temp.first;
                    fy = temp.second;
                }
            }
            // 옆의 칸들 확인(자기보다 큰 물고기 존재X, 자기 자신의 칸X) 후 q에 입력
            for(int j = 0; j<4; j++){
                if(checkIdx(temp.first+dir[j][0], temp.second+dir[j][1])){
                    if(ocean[temp.first+dir[j][0]][temp.second+dir[j][1]] != 9 && ocean[temp.first+dir[j][0]][temp.second+dir[j][1]] <= sSize){
                        if(visit[temp.first+dir[j][0]][temp.second+dir[j][1]] == 0){
                            q.push(make_pair(temp.first+dir[j][0], temp.second+dir[j][1]));
                            visit[temp.first+dir[j][0]][temp.second+dir[j][1]] = 1;
                        }
                        
                    }
                }
            }
        }
        if(isFish){
            // printf("time: %d / pos: %d, %d\n", cnt, fx, fy);
            isFish = false;
            // visit 배열 초기화.
            for(int i=0; i<n; i++){
                for(int j=0; j<n; j++){
                    visit[i][j] = 0;
                }
            }
            // 나이만큼 먹으면 크기 증가 및 먹은양 초기화.
            feeded++;
            if(feeded == sSize){
                sSize++;
                feeded = 0;
            }
            // 기존 bfs 초기화.
            while(!q.empty()) q.pop();
            lastFeedTime = cnt--;
            // q에 물고기 잡으러 갈 위치 push.
            ocean[sx][sy] = 0;
            sx = fx;
            sy = fy;
            q.push(make_pair(sx, sy));
            ocean[sx][sy] = 9;
            visit[sx][sy] = 1;
        }else if(size == 0){
            cnt = lastFeedTime;
            return;
        }
        cnt++;
        
    }

}

// 첫번째 좌표가 두번째보다 가까우면 true 반환
bool checkNear(int x1, int y1, int x2, int y2){
    if(x1 < x2) return true;
    else if(x1 == x2){
        if(y1 < y2) return true;
        else return false;
    }else return false;
}

bool checkIdx(int x, int y){
    if(x >= 0 && x<n && y>= 0 && y<n) return true;
    else return false;
}