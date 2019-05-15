#include <cstdio>
#include <vector>

using namespace std;

int students[100001];
int visit[100001];
int visitedStep[100001];

int dfs(int start, int cnt, int step);
void dfsCheck(int start, int n);

int main(){
    int t, n, temp, tempAns;
    vector<int> ans;

    scanf("%d", &t);

    while(t--){
        scanf("%d", &n);

        for(int i=1; i<=n; i++){
            scanf("%d", &temp);
            students[i] = temp;
            visit[i] = 0;
            visitedStep[i] = 0;
        }

        for(int i=1; i<=n; i++){
            if(visit[i] == 0) tempAns += dfs(i, 1, i);
        }

        ans.push_back(n - tempAns);
        tempAns = 0;
    }
 
    for(int i=0; i<ans.size(); i++){
        printf("%d\n", ans[i]);
    }
}

int dfs(int start, int cnt, int step){
    
    if(visit[start] != 0){
        if(visitedStep[start] != step){
            return 0;
        }
        return cnt-visit[start];
    }
    visit[start] = cnt;
    visitedStep[start] = step;
    return dfs(students[start], cnt+1, step);
}

