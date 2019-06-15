#include <cstdio>
#include <cmath>

using namespace std;

int n, dice[6];
long long ans = 0;

int main(){
    int comb3[8][3];
    int comb2[12][2];
    int used[3];

    // 3개의 면이 보이는 조합.
    comb3[0][0] = 0; comb3[0][1] = 1; comb3[0][2] = 2;
    comb3[1][0] = 0; comb3[1][1] = 2; comb3[1][2] = 4;
    comb3[2][0] = 0; comb3[2][1] = 4; comb3[2][2] = 3;
    comb3[3][0] = 0; comb3[3][1] = 3; comb3[3][2] = 1;
    comb3[4][0] = 5; comb3[4][1] = 1; comb3[4][2] = 2;
    comb3[5][0] = 5; comb3[5][1] = 2; comb3[5][2] = 4;
    comb3[6][0] = 5; comb3[6][1] = 4; comb3[6][2] = 3;
    comb3[7][0] = 5; comb3[7][1] = 3; comb3[7][2] = 1;

    // 2개의 면이 보이는 조합
    comb2[0][0] = 0; comb2[0][1] = 1;
    comb2[1][0] = 0; comb2[1][1] = 2;
    comb2[2][0] = 0; comb2[2][1] = 3;
    comb2[3][0] = 0; comb2[3][1] = 4;
    comb2[4][0] = 5; comb2[4][1] = 1;
    comb2[5][0] = 5; comb2[5][1] = 2;
    comb2[6][0] = 5; comb2[6][1] = 3;
    comb2[7][0] = 5; comb2[7][1] = 4;
    comb2[8][0] = 1; comb2[8][1] = 2;
    comb2[9][0] = 2; comb2[9][1] = 4;
    comb2[10][0] = 4; comb2[10][1] = 3;
    comb2[11][0] = 3; comb2[11][1] = 1;

    scanf("%d", &n);
    scanf("%d %d %d %d %d %d", &dice[0], &dice[1], &dice[2], &dice[3], &dice[4], &dice[5]);

    if(n == 1){
        int max = 0;
        for(int i=0; i<6; i++){
            if(max < dice[i]) max = dice[i];
            ans += dice[i];
        }
        ans -= max;
    }else{
        // 가장 작은 수를 가지는 면의 수 구하기.
        used[0] = dice[0];
        for(int i=0; i<6; i++){
            if(used[0] > dice[i]) used[0] = dice[i];
        }
        // 가장 작은 합을 가지는 두 면 조합의 합 구하기
        used[1] = dice[comb2[0][0]] + dice[comb2[0][1]];
        for(int i=1; i<12; i++){
            if(used[1] > dice[comb2[i][0]] + dice[comb2[i][1]]) used[1] = dice[comb2[i][0]] + dice[comb2[i][1]];
        }
        // 가장 작은 합을 가지는 세 면 조합의 합 구하기
        used[2] = dice[comb3[0][0]] + dice[comb3[0][1]] + dice[comb3[0][2]];
        for(int i=1; i<8; i++){
            if(used[2] > dice[comb3[i][0]] + dice[comb3[i][1]] + dice[comb3[i][2]]) used[2] = dice[comb3[i][0]] + dice[comb3[i][1]] + dice[comb3[i][2]];
        }

        ans += (used[0] * (5*pow(n,2) - 16*n + 12));
        ans += (used[1] * (8*n - 12));
        ans += (4*used[2]);
    }
    printf("%lld\n", ans);
    return 0;

}