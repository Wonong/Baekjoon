#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

typedef struct{
    vector<int> liveTree;
    vector<int> deadTree;
    int energy;
    int refillWinter;
}land;

int dir[8][2] = {
    {0,1}, {1,1}, {1, 0}, {1, -1}, {0, -1}, {-1, -1}, {-1, 0}, {-1, 1}
};

land landData[10][10];
int n, m, k;        //n:땅 전체크기, m: 초기 나무 갯수, k: 지날 년도

bool checkIndex(int x, int y);

int main(){

    int temp[3], livedTrees = 0;
    land tempLand;

    scanf("%d %d %d", &n, &m, &k);

    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            scanf("%d", &landData[i][j].refillWinter);
            landData[i][j].energy = 5;
        }
    }

    // 나무 정보 입력
    for(int i=0; i<m; i++){
        scanf("%d %d %d", &temp[0], &temp[1], &temp[2]);
        landData[temp[0]-1][temp[1]-1].liveTree.push_back(temp[2]);
    }

    for(int i=0; i<k; i++){
        // 봄(모든 땅에 대해 순회)
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                tempLand = landData[i][j];
                sort(tempLand.liveTree.begin(), tempLand.liveTree.end());
                // 각 땅의 모든 살아있는 나무에 대해 순회.
                for(int k=0; k<tempLand.liveTree.size(); k++){
                    // 양분이 충분한 경우 양분 흡수.
                    if(tempLand.liveTree[k] <= tempLand.energy){
                        tempLand.energy -= tempLand.liveTree[k];
                        tempLand.liveTree[k]++;
                    }else{
                        //양분 부족한 경우 나머지 나무 즉사 후 봄을 빠져나옴.
                        for(int l = k; l<tempLand.liveTree.size();){
                            tempLand.deadTree.push_back(tempLand.liveTree[l]);
                            tempLand.liveTree.erase(tempLand.liveTree.begin() + l);
                        }
                        break;
                    }
                }
                landData[i][j] = tempLand;
            }
        }
        // 여름
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                tempLand = landData[i][j];
                for(int k=0; k<tempLand.deadTree.size(); k++){
                    tempLand.energy += tempLand.deadTree[k]/2;
                }
                tempLand.deadTree.clear();
                landData[i][j] = tempLand;
            }
        }
        // 가을
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                tempLand = landData[i][j];
                for(int k=0; k<tempLand.liveTree.size(); k++){
                    if(tempLand.liveTree[k] % 5 == 0){
                        for(int l=0; l<8; l++){
                            if(checkIndex(i+dir[l][0], j+dir[l][1])) landData[i+dir[l][0]][j+dir[l][1]].liveTree.push_back(1);
                        }
                    }
                }
            }
        }
        // 겨울
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                landData[i][j].energy += landData[i][j].refillWinter;
            }
        }
    }

    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            livedTrees += landData[i][j].liveTree.size();
        }
    }

    printf("%d\n", livedTrees);

}

bool checkIndex(int x, int y){
    if(x>=0 && x < n && y>=0 && y<n){
        return true;
    }else return false;
}