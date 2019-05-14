#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
#include <stack>
#include <queue>

using namespace std;

bool dfs(int v, int flag);

vector<int> graph[20001];
int visit[20001] = {0, };

int main(){

    int caseNo, n, m;
    int temp[2];
    bool ok;

    scanf("%d", &caseNo);

    for(int i=0; i<caseNo; i++){
        // 노드, 간선 갯수 입력
        scanf("%d %d", &n, &m);

        // 기존 graph vecotr 초기화
        for(int j=1; j<=n; j++){
            graph[j].clear();
            visit[j] = 0;
        }

        // 간선 정보 입력
        for(int j=0; j<m; j++){
            scanf("%d %d", &temp[0], &temp[1]);
            graph[temp[0]].push_back(temp[1]);
            graph[temp[1]].push_back(temp[0]);
        }

        ok = true;
        // 모든 미방문 노드에 대해 dfs.
        for(int j=1; j<=n; j++){
            if(visit[j] == 0){
                if(dfs(j,1) == false){
                    ok = false;
                    // break;
                }
            }
        }

        if(ok) printf("YES\n");
        else printf("NO\n");
    }


    return 0;
}

bool dfs(int v, int flag){
    
    visit[v] = flag;

    for(int i=0; i<graph[v].size(); i++){
        int next = graph[v][i];
        if(visit[next] == 0){
            if(dfs(next, 3 - flag) == false){
                return false;
            }
        }else if(visit[next] == visit[v]) return false;
    }
    return true;
}

