#include <cstdio>
#include <vector>
#include <cmath>

using namespace std;

int city[50][50];
int n, m;
int minTotalDist = 9999999;
vector<pair<int, int> > totalChicks;
vector<pair<int, int> > totalHomes;

void dfs(int cnt, vector<pair<int, int> > chicks, int curIdx);
int getTotalDist(vector<pair<int, int> > chicks);

int main(){

    vector<pair<int, int> > temp;

    scanf("%d %d", &n, &m);
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            scanf("%d", &city[i][j]);
            if(city[i][j] == 2) totalChicks.push_back(make_pair(i, j));
            else if(city[i][j] == 1) totalHomes.push_back(make_pair(i, j));
        }
    }
    dfs(0, temp, 0);
    printf("%d\n", minTotalDist);
}

void dfs(int cnt, vector<pair<int, int> > chicks, int curIdx){
    if(cnt == m){
        int temp = getTotalDist(chicks);
        if(temp < minTotalDist) minTotalDist = temp;
        return;
    }else if(curIdx == totalChicks.size()){
        return;
    }
    // 현재 인덱스 치킨집 안 넣은 거 dfs
    dfs(cnt, chicks, curIdx+1);
    // 현재 인덱스 치킨집 넣은 거 dfs
    chicks.push_back(make_pair(totalChicks[curIdx].first, totalChicks[curIdx].second));
    dfs(cnt+1, chicks, curIdx+1);
    chicks.erase(chicks.begin() + (chicks.size()-1));

}

int getTotalDist(vector<pair<int, int> > chicks){
    int ret = 0;
    int min = 1000;
    int cx, cy;

    // vector 쓴 걸로 변경.
    for(int i=0; i<totalHomes.size(); i++){
        min = 1000;
        cx = totalHomes[i].first;
        cy = totalHomes[i].second;
        for(int k=0; k<chicks.size(); k++){
            if(min > abs(chicks[k].first-cx) + abs(chicks[k].second-cy)){
                min = abs(chicks[k].first-cx) + abs(chicks[k].second-cy);
            }
        }
        // printf("%d, %d --> %d\n", cx, cy, min);
        ret += min;
    }



    // for(int i =0; i<n; i++){
    //     for(int j =0; j<n; j++){
    //         if(city[i][j] == 1){
    //             // 해당 집에 대해서 모든 치킨집과의 거리 중 최솟값 구함.
    //             min = 1000;
    //             for(int k=0; k<chicks.size(); k++){
    //                 if(min > abs(chicks[k].first-i) + abs(chicks[k].second-j)){
    //                     min = abs(chicks[k].first-i) + abs(chicks[k].second-j);
    //                 }
    //             }
    //             printf("%d, %d --> %d\n", i, j, min);
    //             ret += min;
    //         }
    //     }
    // }

    return ret;
}