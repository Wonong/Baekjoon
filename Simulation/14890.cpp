#include <cstdio>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

int n,l;
int checkRoad(vector<int> roads);
bool outOfIdx(int idx);

int main(){

    int vill[100][100];

    vector<int> temp;
    int ans=0;

    scanf("%d %d", &n, &l);

    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            scanf("%d", &vill[i][j]);
        }
    }

    // 가로선 체크
    for(int i=0; i<n; i++){
        temp.clear();
        for(int j=0; j<n; j++){
            temp.push_back(vill[i][j]);
        }
        ans += checkRoad(temp);
    }

    // 세로선 체크
    for(int i=0; i<n; i++){
        temp.clear();
        for(int j=0; j<n; j++){
            temp.push_back(vill[j][i]);
        }
        ans += checkRoad(temp);
    }
    printf("%d\n", ans);

    
}

int checkRoad(vector<int> roads){

    int curve[100];

    curve[0] = 0;

    // 2이상 차이나는 거 있는지 체크
    for(int i=1; i<roads.size(); i++){
        curve[i] = 0;
        if(abs(roads[i] - roads[i-1]) > 1){
            return 0;
        }
    }

    // 차이나는 것중 짧은 거의 연속길이가 l이상인 것의 경사로 배열 체크
    for(int i=1; i<roads.size(); i++){
        if(roads[i] > roads[i-1]){
            for(int j=i-1; j>=i-l; j--){
                if(outOfIdx(j) || roads[i-1] != roads[j]) return 0;
                else{
                    curve[j]++;
                }
            }
        }else if(roads[i] < roads[i-1]){
            for(int j=i; j<i+l; j++){
                if(outOfIdx(j) || roads[i] != roads[j]) return 0;
                else{
                    curve[j]++;
                }
            }
        }
    }

    // 경사로 중복 체크된 경우 0 반환.
    for(int i=0; i<n; i++){
        if(curve[i] > 1) return 0;
    }

    return 1;
}

bool outOfIdx(int idx){
    if(idx<0 || idx >= n) return true;
    else return false;
}