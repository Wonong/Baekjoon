#include <cstdio>
#include <vector>

using namespace std;

void dfs(int i, int j, int step);

int map[50][50];
int dir[2][8] = {
    {0, 1, 1, 1, 0, -1, -1, -1},
    {1, 1, 0, -1, -1, -1, 0, 1}
};
int w=1,h=1, k=2;

int main(){
    
    
    vector<int> ans;
    
    while(true){
        scanf("%d %d", &w, &h);
        if(w == 0 || h == 0) break;
        for(int i=0; i<h; i++){
            for(int j=0; j<w; j++) scanf("%d", &map[i][j]);
        }
        for(int i=0; i<h; i++){
            for(int j=0; j<w; j++){
                if(map[i][j] == 1){
                    dfs(i, j, k++);
                }
            }
        }
        ans.push_back(k-2);
        k=2;
    }
    for(int i=0; i<ans.size(); i++){
        printf("%d\n", ans[i]);
    }

}

void dfs(int i, int j, int step){
    map[i][j] = step;
    for(int k=0; k<8; k++){
        if(i+dir[0][k] >= 0 && i+dir[0][k] < h && j+dir[1][k] >= 0 && j+dir[1][k] < w){
            if(map[i+dir[0][k]][j+dir[1][k]] == 1) dfs(i+dir[0][k], j+dir[1][k], step);
        }
    }
}