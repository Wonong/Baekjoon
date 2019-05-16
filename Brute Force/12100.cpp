#include <cstdio>
#include <vector>

using namespace std;

int map[20][20];
int maxVal = 0;
int dir[2][4] = {
    {1, 0 ,-1 ,0},
    {0, 1, 0, -1}
};
int n;

vector<int> vectorSum(vector<int> vec);
void dfs(int cnt);

int main(){


    scanf("%d", &n);

    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            scanf("%d", &map[i][j]);
        }
    }

    dfs(1);
    printf("%d\n", maxVal);
}

void dfs(int cnt){ 

    // for(int i=0; i<n; i++){
    //     for(int j=0; j<n; j++){
    //         printf("%d  ", map[i][j]);
    //     }
    //     printf("\n");
    // }
    // printf("\n");

    if(cnt>5) return;

    int idx = 0;
    vector<int> temp[20], temp2;
    
    for(int i=0; i<4; i++){
        switch(i){
            case 0:
                for(int j=0; j<n; j++){
                    temp[j].clear();
                    for(int k=n-1; k>-1; k--){
                        temp[j].push_back(map[j][k]);
                    }
                    temp2 = vectorSum(temp[j]);
                    idx = 0;
                    for(int k=n-1; k>=0; k--){
                        if(idx < temp2.size()){
                            map[j][k] = temp2[idx++];
                            if(map[j][k] > maxVal) maxVal = map[j][k];
                        }else map[j][k] = 0;
                    }
                }
                dfs(cnt+1);
                for(int j=0; j<n; j++){
                    for(int k=n-1; k>=0; k--){
                        map[j][k] = temp[j][n-1 - k];
                    }
                }
            break;
                
            case 1:
                for(int j=0; j<n; j++){
                    temp[j].clear();
                    for(int k=0; k<n; k++){
                        temp[j].push_back(map[j][k]);
                    }
                    temp2 = vectorSum(temp[j]);
                    idx = 0;
                    for(int k=0; k<n; k++){
                        if(idx < temp2.size()){
                            map[j][k] = temp2[idx++];
                            if(map[j][k] > maxVal) maxVal = map[j][k];
                        }else map[j][k] = 0;
                    }
                }
                dfs(cnt+1);
                for(int j=0; j<n; j++){
                    for(int k=0; k<n; k++){
                        map[j][k] = temp[j][k];
                    }
                }
            break;

            case 2:
                for(int j=0; j<n; j++){
                    temp[j].clear();
                    for(int k=0; k<n; k++){
                        temp[j].push_back(map[k][j]);
                    }
                    temp2 = vectorSum(temp[j]);
                    idx = 0;
                    for(int k=0; k<n; k++){
                        if(idx < temp2.size()){
                            map[k][j] = temp2[idx++];
                            if(map[k][j] > maxVal) maxVal = map[k][j];
                        }else map[k][j] = 0;
                    }
                }
                dfs(cnt+1);
                for(int j=0; j<n; j++){
                    for(int k=0; k<n; k++){
                        map[k][j] = temp[j][k];
                    }
                }
            break;

            case 3:
                for(int j=0; j<n; j++){
                    temp[j].clear();
                    for(int k=n-1; k>=0; k--){
                        temp[j].push_back(map[k][j]);
                    }
                    temp2 = vectorSum(temp[j]);
                    idx = 0;
                    for(int k=n-1; k>=0; k--){
                        if(idx < temp2.size()){
                            map[k][j] = temp2[idx++];
                            if(map[k][j] > maxVal) maxVal = map[k][j];
                        }else map[k][j] = 0;
                    }
                }
                dfs(cnt+1);
                for(int j=0; j<n; j++){
                    for(int k=n-1; k>=0; k--){
                        map[k][j] = temp[j][n-1-k];
                    }
                }
            break;
        }
    }
}

vector<int> vectorSum(vector<int> vec){
    // printf("vec: ");
    // for(int i=0; i<vec.size(); i++) printf("%d ", vec[i]);
    
    vector<int> ret;
    for(int i=0; i<vec.size(); i++){
        if(vec[i] == 0){
            vec.erase(vec.begin()+i);
            i--;
        }
    }
    for(int i=0; i<vec.size(); i++){
        if(vec[i] == vec[i+1] && i+1 < vec.size()){
            ret.push_back(2*vec[i]);
            i++;
        }else{
            ret.push_back(vec[i]);
        }
    }

    // printf("\nret: ");
    // for(int i=0; i<vec.size(); i++) printf("%d ", ret[i]);
    // printf("\n");
    return ret;
}