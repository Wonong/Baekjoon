#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
#include <stack>
#include <queue>

using namespace std;

void dfs(int v);
void bfs(int v);

vector<int> graph[1001];
int visit[1001] = {0, };
int countCC = 0;

int main(){

    int n, m;
    int temp[2];

    scanf("%d %d", &n, &m);

    for(int i=0; i<m; i++){
        scanf("%d %d", &temp[0], &temp[1]);
        graph[temp[0]].push_back(temp[1]);
        graph[temp[1]].push_back(temp[0]);
    }

    for(int i=1; i<=n; i++){
        sort(graph[i].begin(), graph[i].end());
    }

    for(int i=1; i<=n; i++){
        if(visit[i] != 1){
            countCC++;
            dfs(i);
        }
    }

    printf("%d\n", countCC);

    return 0;
}

void dfs(int v){
    int temp;
    
    visit[v] = 1;
    // printf("%d ", v);

    for(int i=0; i<graph[v].size(); i++){
        int next = graph[v][i];
        if(visit[next] != 1){
            dfs(next);
        }
    }
}

void bfs(int v){
    queue<int> q;
    int temp;
    
    memset(visit, 0, sizeof(visit));
    visit[v] = 1;
    q.push(v);

    while(!q.empty()){
        temp = q.front();
        q.pop();
        printf("%d ", temp);

        for(int i=0; i<graph[temp].size(); i++){
            int next = graph[temp][i];
            if(visit[next] != 1){
                visit[next] = 1;
                q.push(next);
            }
        }
    }

}

