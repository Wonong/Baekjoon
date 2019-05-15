#include <cstdio>
#include <queue>

using namespace std;

int box[1000][1000];
int cnt = 0;    // 익은 토마토 갯수
int goal;  //목표 토마토 갯수
int maxCnt; //최대실행횟수
int n, m;
vector<pair<int, int> > rippeds;

int dir[2][4] = {
    {0, 1, 0, -1},
    {1, 0, -1, 0}
};

int bfs();

int main(){

    scanf("%d %d", &m, &n);

    goal = n*m;
    maxCnt = n*m;

    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            scanf("%d", &box[i][j]);
            if(box[i][j] == 1){
                rippeds.push_back(make_pair(i, j));
            }
            else if(box[i][j] == -1) goal--;
        }
    }
    printf("%d\n", bfs());


}

int bfs(){

    int size, time = 0;
    queue<pair<int, int> > q;
    pair<int, int> temp;

    for(int i=0; i<rippeds.size(); i++){
        q.push(rippeds[i]);
    }

    while(maxCnt--){
        size = q.size();
        for(int i=0; i<size; i++){
            temp = q.front();
            q.pop();
            cnt++;
            if(cnt == goal) return time;
            for(int j=0; j<4; j++){
                if(temp.first+dir[0][j] >= 0 && temp.first+dir[0][j] < n && temp.second+dir[1][j] >= 0 && temp.second+dir[1][j] < m && box[temp.first+dir[0][j]][temp.second+dir[1][j]] == 0){
                    q.push(make_pair(temp.first+dir[0][j], temp.second+dir[1][j]));
                    box[temp.first+dir[0][j]][temp.second+dir[1][j]] = 1;
                }
            }
        }
        
        time++;
    }
    return -1;
}