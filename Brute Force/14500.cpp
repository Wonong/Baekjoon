#include <cstdio>
#include <vector>

using namespace std;

int n, m;
int paper[500][500];
int maxVal = 0;
int dir[4][2] = {
    {1,0}, {0,1}, {-1,0}, {0,-1}
};

bool checkIdx(int x, int y);
void dfs(int x0, int y0, int x, int y, int cnt, int sum, vector<pair<int, int> > visited);

int main(){

    vector<pair<int, int> > temp;

    scanf("%d %d", &n, &m);
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            scanf("%d", &paper[i][j]);
        }
    }

    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            temp.push_back(make_pair(i, j));
            dfs(-1, -1, i, j, 1, paper[i][j], temp);
            temp.erase(temp.begin());
        }
    }

    printf("%d\n", maxVal);
}

// x0와 y0는 직전 방문 좌표
void dfs(int x0, int y0, int x, int y, int cnt, int sum, vector<pair<int, int> > visited){
    
    if(cnt == 4){
        if(sum > maxVal){
            maxVal = sum;
        }
        return;
    }else{
        // x = visited[k].first;
        // y = visited[k].second;
        for(int i=0; i<4; i++){
            if(checkIdx(x+dir[i][0], y+dir[i][1]) && !( (x+dir[i][0]) == x0 && (y+dir[i][1]) == y0)){
                int isVisited = false;
                /*
                for(int j=0; j<visited.size(); j++){
                    if(visited[j].first == x+dir[i][0] && visited[j].second == y+dir[i][1]) {
                        isVisited = true;
                        break;
                    }
                }
                */
                if(!isVisited){
                    visited.push_back(make_pair(x+dir[i][0], y+dir[i][1]));
                    dfs(x, y, x+dir[i][0], y+dir[i][1], cnt+1, sum+paper[x+dir[i][0]][y+dir[i][1]], visited);
                    visited.erase(visited.begin()+(visited.size()-1));
                }
            }
        }
        // ㅗ자형 예외처리.
        if(cnt == 1){
            int nowX = visited[0].first;
            int nowY = visited[0].second;
            for(int i=0; i<4; i++){
                sum = paper[nowX][nowY];
                bool flag = true;

                for(int j=0; j<3; j++){
                    int sx = nowX + dir[((i+j)%4)][0];
                    int sy = nowY + dir[((i+j)%4)][1];
                    if(checkIdx(sx, sy)){
                        sum += paper[sx][sy];
                    }else{
                        flag = false;
                        break;
                    }
                }
                if(flag){
                    if(maxVal < sum) maxVal = sum;
                }
            }
        }
    }
}

bool checkIdx(int x, int y){
    if(x >= 0 && x < n && y >= 0 && y < m) return true;
    else return false;
}