#include <iostream>
#include <string>
#include <stack>
#include <queue>
#include <algorithm>

using namespace std;

int main(){
    
    int n,t;
    int *plate[2];
    int *dp[3];
    int *ans;

    cin >> t;

    ans = (int*)malloc(sizeof(int)*t);

    for(int i=0; i<t; i++){
        
        cin >> n;

        for(int j=0; j<2; j++) plate[j] = (int*)malloc(sizeof(int)*n);
        for(int j=0; j<3; j++) dp[j] = (int*)malloc(sizeof(int)*n);

        //첫번째 행 입력
        for(int j=0; j<n; j++){
            cin >> plate[0][j];
        }

        // 두번째 행 입력
        for(int j=0; j<n; j++){
            cin >> plate[1][j];
        }

        dp[0][0] = plate[0][0];
        dp[1][0] = plate[1][0];
        dp[2][0] = 0;

        for(int j=1; j<n; j++){
            dp[0][j] = max(dp[2][j-1], dp[1][j-1]) + plate[0][j];
            dp[1][j] = max(dp[2][j-1], dp[0][j-1]) + plate[1][j];
            dp[2][j] = max(max(dp[0][j-1], dp[1][j-1]), dp[2][j-1]);
        }

        ans[i] = max(max(dp[0][n-1], dp[1][n-1]), dp[2][n-1]);

        for(int j=0; j<2; j++) free(plate[j]);
        for(int j=0; j<3; j++) free(dp[j]);
    }

    for(int i=0; i<t; i++) cout << ans[i] << endl;
    free(ans);

    return 0;
}

