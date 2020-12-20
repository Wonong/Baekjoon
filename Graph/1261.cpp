#include <cstdio>
#include <vector>
#include <queue>

#define BREAK_WALL 1000
#define INF 999999

using namespace std;
int map[100][100];
int d[100][100];
int dir[4][2] = {
    {-1, 0},
    {1, 0},
    {0, -1},
    {0, 1}
};
typedef struct{
    int x, y;
}pos;

struct cmp{
    bool operator()(pair<pos, int> a, pair<pos, int> b){
        if(a.second > b.second) return true;
        else return false;
    }
};


int main(){
    int n, m;

    scanf("%d %d", &n, &m);

    for(int i=0; i<m; i++){
        for(int j=0; j<n; j++){
            scanf("%1d", &map[i][j]);
            d[i][j] = INF;
            if(map[i][j] == 1) map[i][j] = BREAK_WALL;
        }
    }
    d[0][0] = 0;
    // goal: (m-1, n-1)
    priority_queue<pair<pos, int>, vector< pair<pos, int > >, cmp > pq;
    pos first_pos;

    first_pos.x = 0;
    first_pos.y = 0;
    pq.push(make_pair(first_pos, 0));
    while(!pq.empty()){
        pos current = pq.top().first;
        int distance = -pq.top().second;
        pq.pop();
        
        if(d[current.x][current.y] < distance) continue;
        for(int i=0; i<4; i++){
            pos newPos;
            newPos.x = current.x + dir[i][0];
            newPos.y = current.y + dir[i][1];
            if (newPos.x < 0 || newPos.x >= m || newPos.y < 0 || newPos.y >= n) continue;
            int nextDistance = map[newPos.x][newPos.y] + distance;
            if(nextDistance < d[newPos.x][newPos.y]){
                d[newPos.x][newPos.y] = nextDistance;
                pq.push(make_pair(newPos, -nextDistance));
            }
        }
    }

    printf("%d\n", d[m-1][n-1]/BREAK_WALL);
}