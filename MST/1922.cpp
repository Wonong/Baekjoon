#include <cstdio>
#include <queue>

using namespace std;


// <간선값, 노드번호>
priority_queue<pair<int, int>, vector<pair<int, int> >, greater<pair<int, int> > > nodes;
vector<pair<int, int> > edges[100001];
int visit[100001];

int main(){
    int n, m, temp[3], num, ans = 0;
    scanf("%d", &n);
    scanf("%d", &m);

    for(int i=0; i<m; i++){
        scanf("%d %d %d", &temp[0], &temp[1], &temp[2]);
        edges[temp[0]].push_back(make_pair(temp[1], temp[2]));
        edges[temp[1]].push_back(make_pair(temp[0], temp[2]));
    }

    for(int i=0; i<edges[1].size(); i++){
        nodes.push(make_pair(edges[1][i].second, edges[1][i].first));
    }
    visit[1] = 1;
    
    while(!nodes.empty()){
        pair<int, int> curr;
        int len;

        curr = nodes.top();
        nodes.pop();
        
        if(visit[curr.second] == 1) continue;
        ans += curr.first;

        visit[curr.second] = 1;

        len = edges[curr.second].size();
        for(int i=0; i<len; i++){
            if(visit[edges[curr.second][i].first] == 0) nodes.push(make_pair(edges[curr.second][i].second, edges[curr.second][i].first));
        }
    }
    printf("%d\n", ans);
}