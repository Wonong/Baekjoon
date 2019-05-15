#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
#include <stack>
#include <queue>

using namespace std;

void dfs(int node);

vector<int> graph[1001];
int visit[1001];
int nodes[1001];

int main(){
    int t, n, count;

    scanf("%d", &t);

    while(t--){
        scanf("%d", &n);

        // 기존 그래프 정보 초기화
        for(int i = 1; i<=n; i++){
            graph[i].clear();
            visit[i] = 0;
        }

        for(int i=1; i<=n; i++){
            scanf("%d", &nodes[i]);
            graph[i].push_back(nodes[i]);
            // graph[nodes[i]].push_back(i);
        }

        count = 0;

        for(int i=1; i<=n; i++){
            if(visit[i] == 0){
                count++;
                dfs(i);
            }

        }
        printf("%d\n", count);
    }
}

void dfs(int node){
    
    visit[node] = 1;

    for(int i=0; i<graph[node].size(); i++){
        if(visit[graph[node][i]] == 0){
            dfs(graph[node][i]);
        }
    }
}