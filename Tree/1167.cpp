#include <cstdio>
#include <vector>

#define SIZE 100000

using namespace std;
void dfs(int parent, int node, int cost);
vector<pair<int, int> > trees[SIZE+1];
int n, farNode;
long long longestDist = 0;
// int callDfs = 0;

int main(){

    int to, cost, node;

    scanf("%d", &n);

    for(int i=0; i<n; i++){
        scanf("%d", &node);
        while(true){
            scanf("%d", &to);
            if(to != -1){
                scanf("%d", &cost);
                trees[node].push_back(make_pair(to, cost));
            }else break;
        }
    }

    // 1번 노드로부터 제일 먼 노드 구함.
    dfs(0, 1, 0);
    longestDist = 0;
    // 이전에 구한 노드로부터 제일 먼 노드 구함.
    dfs(0, farNode, 0);

    printf("%lld\n", longestDist);
    // printf("%d\n", callDfs);
}

void dfs(int parent, int node, int cost){
    // callDfs++;
    // printf("parent: %d, node: %d, cost: %d\n", parent, node, cost);
    int len;
    // 현재 노드까지 탐색한 코스트 값 저장
    if(longestDist < cost){
        longestDist = cost;
        farNode = node;
    }
    len = trees[node].size();
    for(int i=0; i<len; i++){
        if(trees[node][i].first == parent) continue;
        dfs(node, trees[node][i].first, cost + trees[node][i].second);
    }
}