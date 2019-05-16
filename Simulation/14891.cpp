#include <cstdio>
#include <vector>
#include <cmath>

using namespace std;

typedef struct{
    int mag[8];        // 0이면 N극, 1이면 S극
    int right, left;    // 각각 우측, 좌측의 mag 인덱스 저장.
}wheel;

vector<pair<int, int> > rolls;
// 1이면 시계, -1이면 반시계
wheel rollWheel(wheel wh, int dir);
int main(){
    
    wheel wheels[4];
    int k, temp1, temp2;
    int point=0;
    vector<pair<int, int> > rollNow;

    for(int i=0; i<4; i++){
        for(int j=0; j<8; j++){
            scanf("%1d", &wheels[i].mag[j]);
        }
        wheels[i].right = 2;
        wheels[i].left = 6;
    }

    scanf("%d", &k);

    for(int i=0; i<k; i++){
        scanf("%d %d", &temp1, &temp2);
        rolls.push_back(make_pair(temp1-1, temp2));
    }

    for(int i=0; i<k; i++){
        rollNow.clear();
        int rollDir = rolls[i].second;
        // 현재 톱니 변경
        rollNow.push_back(make_pair(rolls[i].first, rolls[i].second));
        // 앞의 톱니들 변경
        for(int j=rolls[i].first-1; j>=0; j-- ){
            
            wheel left = wheels[j];
            wheel right = wheels[j+1];

            // 극이 다른 경우.
            if(left.mag[left.right] != right.mag[right.left]){
                // 현재 톱니를 우측 톱니의 반대방향으로 돌림.
                rollNow.push_back(make_pair(j, -rollDir));
                rollDir = -rollDir;
            }else{
                // 극이 같은 경우 하나라도 발생시 그 앞에 톱니는 보지 않음.
                break;
            }
        }

        rollDir = rolls[i].second;
        // 뒤의 톱니들 변경
        for(int j=rolls[i].first+1; j<4; j++ ){
            wheel left = wheels[j-1];
            wheel right = wheels[j];
            // 극이 다른 경우.
            if(right.mag[right.left] != left.mag[left.right]){
                // 현재 톱니를 좌측 톱니의 반대방향으로 돌림.
                rollNow.push_back(make_pair(j, -rollDir));
                rollDir = -rollDir;
            }else{
                // 극이 같은 경우 하나라도 발생시 그 앞에 톱니는 보지 않음.
                break;
            }
        }
        for(int j=0; j<rollNow.size(); j++){
            wheels[rollNow[j].first] = rollWheel(wheels[rollNow[j].first], rollNow[j].second);
        }
    }

    for(int i=0; i<4; i++){
        wheels[i].right = (wheels[i].right+7)%8;
        wheels[i].right = (wheels[i].right+7)%8;
        if(wheels[i].mag[wheels[i].right] == 1){
            point += pow(2, i);
        }
    }
    printf("%d\n", point);

}

wheel rollWheel(wheel wh, int dir){
    // 시계방향 회전
    if(dir == 1){
        wh.right = (wh.right+7)%8;
        wh.left = (wh.left+7)%8;
    }else{
        // 반시계
        wh.right = (wh.right+1)%8;
        wh.left = (wh.left+1)%8;
    }
    return wh;
}