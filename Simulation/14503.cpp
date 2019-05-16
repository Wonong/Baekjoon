#include <cstdio>

using namespace std;

int n, m;
int room[50][50];       // 2는 청소된 상태, 1은 벽, 0은 청소 안 된 방.
int vx, vy, vd;         // 청소기 좌표 및 현재방향.
int nd;
int cleaned = 0;
bool isClean = true;;       // 현재 시도에 청소했는지 여부 저장

int dir[4][2] = {
    {-1, 0}, {0, 1}, {1, 0}, {0, -1}
};

bool checkIdx(int x, int y);

int main(){
    scanf("%d %d", &n, &m);
    scanf("%d %d %d", &vx, &vy, &vd);
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            scanf("%d", &room[i][j]);
        }
    }

    while(true){
        // 청소기 현재 위치 청소(1)
        // 지난 번에 2-1 번 과정에서 청소한 경우에만 현재 위치 청소.
        if(isClean && room[vx][vy] == 0){
            room[vx][vy] = 2;
            cleaned++;
        }

        isClean = false;

        // 2-1,2
        // 각 방향 탐색
        nd = (vd+3)%4;
        for(int i=0; i<4; i++){
            // 현재 방향이 청소 안된 상태.
            if(room[vx+dir[nd][0]][vy+dir[nd][1]] == 0){
                // 방향 전환 및 해당 방향으로 이동.
                vd = nd;
                vx += dir[nd][0];
                vy += dir[nd][1];
                isClean = true;
                break;
            }
            // 다음 방향으로 전환
            nd = (nd+3)%4;
        }


        //네 방향 전부 청소되어있거나 벽인경우.
        if(!isClean){
            // 뒤에가 벽이 아닌 경우.(2-3), 후진
            if(checkIdx(vx-dir[vd][0], vy-dir[vd][1]) && room[vx-dir[vd][0]][vy-dir[vd][1]] != 1){
                vx -= dir[vd][0];
                vy -= dir[vd][1];
            }else{
                // 뒤에가 벽인 경우(2-4)
                break;
            }
        }
    }
    printf("%d\n", cleaned);
}

bool checkIdx(int x, int y){
    if(x >= 0 && x < n && y >= 0 && y < m) return true;
    else return false;
}

