#include <cstdio>
#include <vector>

using namespace std;

typedef struct{
    int x, y;
    int type;
}cam;

typedef struct{
    int office[8][8];
    int unWatched;
}stat;

int office[8][8];       // 7이면 감시받는 지점.
vector<int> camDir[6];
int dir[4][2] = {
    {0,1}, {-1,0}, {0,-1}, {1,0}
};
int n, m, unWatched = 0;
vector<cam> cams;

void dfs(stat now, int curCamIdx);
bool checkIdx(int x, int y);
int main(){

    cam temp;
    stat tempStat;

    // 카메라별 방향 넣어놓기.
    camDir[1].push_back(0);
    camDir[2].push_back(0);
    camDir[2].push_back(2);
    camDir[3].push_back(0);
    camDir[3].push_back(1);
    for(int i=0; i<3; i++) camDir[4].push_back(i);
    for(int i=0; i<4; i++) camDir[5].push_back(i);

    scanf("%d %d", &n, &m);

    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            scanf("%d", &office[i][j]);
            if(office[i][j] > 0 && office[i][j] < 6){
                temp.x = i; temp.y = j; temp.type = office[i][j];
                cams.push_back(temp);
            }else if(office[i][j] == 0){
                unWatched++;
            }
        }
    }
    
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            tempStat.office[i][j] = office[i][j];
        }
    }
    tempStat.unWatched = unWatched;

    dfs(tempStat, 0);
    printf("%d\n", unWatched);

}

void dfs(stat now, int curCamIdx){
    // 모든 카메라 탐색한 경우 return
    if(curCamIdx >= cams.size()){
        if(unWatched > now.unWatched){
            unWatched = now.unWatched;
        } 
        return;
    }

    // 다음 카메라 방향 돌려서 dfs
    // if(cams[curCamIdx].type != 5){
    if(true){
        cam currentCam = cams[curCamIdx];
        // 모든 시계방향으로 돌려서 확인.
        for(int i=0; i<4; i++){
            stat next = now;
            int nowWatched = 0;
            // 현재 카메라의 모든 방향 탐색
            for(int j=0; j<camDir[currentCam.type].size(); j++){
                int nx = currentCam.x + dir[(camDir[currentCam.type][j]+i)%4][0]; int ny = currentCam.y + dir[(camDir[currentCam.type][j]+i)%4][1];
                // 해당 지점 통과가능시 그 방향으로 계속 탐색 및 제거. 
                while(checkIdx(nx, ny) && (next.office[nx][ny] != 6)){
                    // 해당 지점 감시 가능
                    if(next.office[nx][ny] == 0){
                        nowWatched++;
                        next.office[nx][ny] = 7;
                    }
                    // 다음지점으로 좌표이동.
                    nx += dir[(camDir[currentCam.type][j]+i)%4][0];
                    ny += dir[(camDir[currentCam.type][j]+i)%4][1];
                }
            }   
            next.unWatched -= nowWatched;
            // 이 방향일 때 dfs 실행.
            dfs(next, curCamIdx+1);
        }
        // 카메라가 5일때.
    }else{

    }
}

bool checkIdx(int x, int y){
    if(x >= 0 && x < n && y >= 0 && y < m) return true;
    else return false;
}

