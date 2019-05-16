#include <cstdio>
#include <vector>

using namespace std;

int n;
vector<int> trees[100001];
int parents[100001];

void dfs(int parent, int child);

int main(){

    int temp1, temp2;

    scanf("%d", &n);
    for(int i=1; i<n; i++){
        scanf("%d %d", &temp1, &temp2);
        trees[temp1].push_back(temp2);
        trees[temp2].push_back(temp1);
    }

    for(int i=0; i < trees[1].size(); i++){
        parents[trees[1][i]] = 1;
        dfs(1, trees[1][i]);
    }

    for(int i=2; i<=n; i++) printf("%d\n", parents[i]);
}

void dfs(int parent, int child){
    for(int i=0; i<trees[child].size(); i++){
        // printf("child: %d, i: %d\n", child, i);
        if(trees[child][i] != parent){
            // printf("parent: %d, child: %d\n", child, trees[child][i]);
            parents[trees[child][i]] = child;
            dfs(child, trees[child][i]);
        }
    }

}