#include <cstdio>
#include <cmath>
#include <vector>

using namespace std;

int n;
vector<pair<int, int> > works[15];  // 끝나는 날짜 기준 / first: 걸리는 시간, second: 버는 돈.
int dp[15];         // i일까지의 bset

int getDp(int days);

int main(){

    int temp1, temp2;

    for(int i=0; i<15; i++){
            dp[i] = -1;
    }

    scanf("%d", &n);
    for(int i=0; i<n; i++){
        scanf("%d %d", &temp1, &temp2);
        if(i+temp1-1 < n) works[i+temp1-1].push_back(make_pair(temp1, temp2));
    }

    // 첫번째 요소 초기화
    dp[0] = 0;
    if(works[0].size() > 0){
        for(int i=0; i<works[0].size(); i++){
            if(dp[0] < works[0][i].second) dp[0] = works[0][i].second;
        }
    }

    printf("%d\n", getDp(n-1));

}

int getDp(int days){
    int temp;
    if(dp[days]!= -1) return dp[days];
    else{
        dp[days] = 0;
        // 해당 일에 끝나는 업무가 없으면 전날까지 끝나는 업무 중 best로 초기화
        if(works[days].size() == 0){
            dp[days] = getDp(days-1);
        }else{
            for(int i=0; i<works[days].size(); i++){
                temp = max(getDp(days-works[days][i].first) + works[days][i].second, getDp(days-1));
                if(temp > dp[days]) dp[days] = temp;
            }
        }
        return dp[days];
        
    }
    
    
    
}