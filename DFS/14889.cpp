#include <cstdio>
#include <cmath>

using namespace std;

int n;
int abilities[20][20];
int minVal = 999999;

void dfs(int cnt, bool *members, int curIdx );

int main(){
    bool tempMembers[20];
    scanf("%d", &n);
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            scanf("%d", &abilities[i][j]);
        }
    }
    dfs(0, tempMembers, 0);

    printf("%d\n", minVal);
}

void dfs(int cnt, bool *members, int curIdx ){
    if(cnt == n/2){
        int team1 = 0, team2 = 0;
        for(int i=0; i<n; i++){
            // 소속 멤버마다 모든 멤버와의 협업점수 추가.
            if(members[i] == true){
                for(int j=0; j<n; j++){
                    if(members[j] == true && i != j){
                        team1 += abilities[i][j];
                    }
                }
            }else{
                // 소속 멤버가 아닌 멤버마다 그 멤버와 현재 팀이 아닌 멤버와의 협업점수 추가.
                for(int j=0; j<n; j++){
                    if(members[j] == false && i != j){
                        team2 += abilities[i][j];
                    }
                }
            }
        }
        if(minVal > abs((float)(team1-team2))){
            minVal = abs((float)(team1-team2));
        }

        return;
    }
    if(curIdx == n){
        return;
    }
    
    members[curIdx] = true;
    dfs(cnt+1, members, curIdx+1);
    members[curIdx] = false;
    dfs(cnt, members, curIdx+1);
}