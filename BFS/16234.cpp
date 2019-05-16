#include <cstdio>
#include <vector>
#include <queue>
#include <cmath>

using namespace std;

int unionNum = 0;
int lands[50][50];
int visit[50][50];
int n, l, r, day = 0;
vector<pair<int, int> > unions[2500];
int unionPop[2500];
int dir[4][2] = {
    {0,1},{1,0},{-1,0},{0,-1}
};

void bfs(int x, int y, int flag);
bool checkIdx(int x, int y);

int main(){
    scanf("%d %d %d", &n, &l, &r);

    // 땅 정보 입력
    for(int i=0; i<n; i++ ){
        for(int j=0; j<n; j++ ){
            scanf("%d", &lands[i][j]);
        }
    }
    
    while(true){
        // 기존 visit 초기화
        for(int i=0; i<n; i++ ){
            for(int j=0; j<n; j++ ){
                visit[i][j] = 0;
            }
        }
        for(int i=0; i<unionNum+1; i++){
            unions[i].clear();
            unionPop[i] = 0;
        } 
        unionNum = 0;


        // 연합별로 마킹.
        for(int i=0; i<n; i++ ){
            for(int j=0; j<n; j++ ){
                if(visit[i][j] == 0){
                    visit[i][j] = 1;
                    bfs(i, j, unionNum);
                    if(unions[unionNum].size() > 1){
                        unionNum++;
                    } 
                }
            }
        }

        if(unionNum == 0) break;

        // 인구조정
        for(int i=0; i<unionNum; i++){
            int unionSize = unions[i].size();
            int pop = unionPop[i];
            
            
            for(int j=0; j<unionSize; j++){
                lands[unions[i][j].first][unions[i][j].second] = pop/unionSize;
            }
        }
        
        day++;
    }

    printf("%d\n", day);

}

void bfs(int x, int y, int flag){
    // 해당 flag의 국가가 0개이면 일단 해당 국가 push

    int size = -1;
    pair<int, int> temp;
    queue<pair<int, int> > q;

    // 해당 국가 Push
    q.push(make_pair(x, y));

    while(size != 0){
        size = q.size();
        for(int i=0; i<size; i++){
            temp = q.front();
            q.pop();
            visit[temp.first][temp.second] = 1;

            // 총 인구수 증가.
            unionPop[flag] += lands[temp.first][temp.second];
            unions[flag].push_back(make_pair(temp.first, temp.second));

            // 다음 좌표 확인.
            for(int j=0; j<4; j++){
                int nx = temp.first + dir[j][0];
                int ny = temp.second + dir[j][1];
                if(checkIdx(nx, ny)){
                    int diff = abs(lands[nx][ny]-lands[temp.first][temp.second]);
                    if(diff >= l && diff <= r && visit[nx][ny] == 0){
                        visit[nx][ny] = 1;
                        q.push(make_pair(nx, ny));
                    }
                } 
            }   
        }
    }

    // 하나도 주변국가 열리지 않으면 삭제.
    if(unions[flag].size() == 1){
        unionPop[flag] = 0;
        unions[flag].pop_back();
    } 
}

bool checkIdx(int x, int y){
    if(x >= 0 && x < n && y >= 0 && y < n) return true;
    else return false;
}