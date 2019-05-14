#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <string>
#include <queue>
#include <algorithm>
#include <cctype>


using namespace std;

int checkAvailable(int n);
int digits(int n);
int bfs(int ch, int n);

// 0이면 정상, 1이면 고장
int buttons[10] = {0, };
int visit[1000001] = {0, };

int main(){
    
    int ch=100, n, errorNum, temp;

    cin >> n;
    cin >> errorNum;

    // 고장난 버튼 저장.
    for(int i=0; i<errorNum-1; i++){
        scanf("%d ", &temp);
        buttons[temp] = 1;
    }
    if(errorNum > 0){
        scanf("%d", &temp);
        buttons[temp] = 1;
    }
    

    cout << bfs(ch, n) << '\n'; 

    return 0;
}

int bfs(int ch, int n){
    
    queue<int> q;
    int temp, time = 0;

    q.push(n);

    while(true){
        int size = q.size();
        int min = 1000000;
        for(int i=0; i<size; i++){

            temp = q.front();
            q.pop();
            if(digits(temp) > abs(temp-ch)){
                if(time + abs(temp-ch) < min) min = time + abs(temp-ch);
            }
            if(checkAvailable(temp)){
                if(time + digits(temp) < min) min = time + digits(temp);
            }
            if(temp-1 >= 0 && visit[temp-1] == 0){
                visit[temp-1] = 1;
                q.push(temp-1);
            }
            if(temp+1 <= 1000000 && visit[temp+1] == 0){
                visit[temp+1] = 1;
                q.push(temp+1);
            }
        }
        if(min != 1000000) return min;
        time++;
    }

    return 1;
}

int checkAvailable(int n){
    vector<int> nums;

    if(n==0) nums.push_back(0);
    while(n>0){
        nums.push_back(n%10);
        n /= 10;
    }

    for(int i=0; i<nums.size(); i++){
        if(buttons[nums[i]] == 1) return 0;
    }
    return 1;
}

int digits(int n){

    int ret = 0;

    if(n==0) return 1;
    while(n>0){
        n /= 10;
        ret++;
    }

    return ret;
}


