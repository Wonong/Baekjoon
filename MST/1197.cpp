#include <cstdio>
#include <algorithm>

using namespace std;

struct edge{
    int from, to, weight;
};

bool cmp(edge a, edge b){
    if(a.weight < b.weight) return true;
    else return false;
}
edge edges[100000];
int parentNode[10001];

int findGroup(int x){
    if(x == parentNode[x]) return x;
    return parentNode[x] = findGroup(parentNode[x]);
}

void unionGroup(int x, int y){
    x = findGroup(x);
    y = findGroup(y);
    parentNode[y] = x;
}

int main(){
    int n, m, ans, cnt;

    ans = 0;
    cnt = 0;

    scanf("%d %d", &n, &m);

    for(int i = 1; i <= n; i++) parentNode[i] = i;
    for(int i=0; i<m; i++) scanf("%d %d %d", &edges[i].from, &edges[i].to, &edges[i].weight);

    sort(edges, edges+m, cmp);
    
    for(int i=0; i<m && cnt != (n-1); i++){
        edge e = edges[i];
        if(findGroup(e.from) == findGroup(e.to)) continue;
        ans += e.weight;
        cnt++;
        unionGroup(e.from, e.to);
    }
    printf("%d\n", ans);
}