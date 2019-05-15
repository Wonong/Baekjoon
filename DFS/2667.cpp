#include <cstdio>
#include <vector>
#include <algorithm>
#include <functional>

using namespace std;

int town[25][25];
vector<int> danji;
int n;

void dfs(int i, int j, int step);

int main(){

    int k=2;

    scanf("%d", &n);

    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++) scanf("%1d", &town[i][j]);
    }

    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            if(town[i][j] == 1){
                danji.push_back(0);
                dfs(i, j, k++);
                
            }
        }
    }

    printf("%lu\n", danji.size());
    sort(danji.begin(), danji.end());
    for(int i=0; i<danji.size(); i++){
        printf("%d\n", danji[i]);
    }

}

void dfs(int i, int j, int step){

    town[i][j] = step;
    danji[step-2]++;

    if(i>0 && town[i-1][j] == 1){
        dfs(i-1, j, step);
    }
    if(i<n-1 && town[i+1][j] == 1){
        dfs(i+1, j, step);
    }
    if(j>0 && town[i][j-1] == 1){
        dfs(i, j-1, step);
    }
    if(j<n-1 && town[i][j+1] == 1){
        dfs(i, j+1, step);
    }
}

