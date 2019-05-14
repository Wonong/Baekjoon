#include <cstdio>
#include <vector>
#include <queue>

using namespace std;

int miro[100][100];
int visited[100][100];
int n, m;
int dir[2][4] = {
    {0, 1, 0, -1},
    {1, 0, -1, 0}
};

int bfs(int x, int y);
int main(){
    
    scanf("%d %d", &n, &m);

    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++) scanf("%1d", &miro[i][j]);
    }


    printf("%d\n", bfs(0,0));


}

int bfs(int x, int y){
    
    queue<pair<int, int> > q;
    int cnt = 1;
    pair<int, int> temp;

    q.push(make_pair(x,y));

    while(true){
        int size = q.size();
        for(int i=0; i<size; i++){
            temp = q.front();
            q.pop();
            if(temp.first == n-1 && temp.second == m-1){
                return cnt;
            }
            for(int k=0; k<4; k++){
                if(temp.first + dir[0][k] >= 0 && temp.first + dir[0][k] < n && temp.second + dir[1][k] >= 0 && temp.second + dir[1][k] < m && visited[temp.first+dir[0][k]][temp.second + dir[1][k]] == 0 && miro[temp.first+dir[0][k]][temp.second + dir[1][k]] == 1){
                    q.push(make_pair(temp.first+dir[0][k], temp.second + dir[1][k]));
                    visited[temp.first+dir[0][k]][temp.second + dir[1][k]] = 1;
                }
            }
        }
        
        cnt++;
    }
    
}

