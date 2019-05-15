#include <cstdio>
#include <vector>

using namespace std;

int boards[100][100];       //0: 낫띵, 1: 뱀이 차지, 4: 사과
int k, n, l;
int cmd[10001];     //1:왼쪽, 2:오른쪽
int dir[4][2] = {
    {0, 1}, {-1, 0}, {0, -1}, {1, 0}
};

int main(){

    char tempCmd;
    int temp[2], tempSec;
    int sec = 0, nowDir = 0;
    int x=0, y=0;
    int snakeLen = 1;
    vector<pair<int, int> > snake;

    boards[x][y] = 1;
    snake.push_back(make_pair(0, 0));

    scanf("%d", &n);
    scanf("%d", &k);

    // 사과 정보 입력
    for(int i=0; i<k; i++){
        scanf("%d %d", &temp[0], &temp[1]);
        boards[temp[0]-1][temp[1]-1] = 4;
    }

    // 방향전환 명령 입력
    scanf("%d", &l);   
    for(int i=0; i<l; i++){
        scanf("%d %c", &tempSec, &tempCmd);
        if(tempCmd == 'L') cmd[tempSec+1] = 1;
        else cmd[tempSec+1] = 2;
    }

    // snake moving
    while(true){
        bool outFlag = false;
        
        // 방향전환 명령 확인 및 방향전환
        if(cmd[++sec] != 0){
            // printf("cmd: %d %d\n", sec-1, cmd[sec-1]);
            switch(cmd[sec]){
                case 1:
                    nowDir = (nowDir+1)%4;
                break;
                case 2:
                    nowDir = (nowDir+3)%4;
                break;
            }
        }

        // 다음 머리 위치 계산
        x = snake[0].first + dir[nowDir][0];
        y = snake[0].second + dir[nowDir][1];

        // 벽에 충돌
        if( !(x >= 0 && x <n && y>=0 && y<n)){
            outFlag = true;
            break;
        }
        

        
        if(boards[x][y] == 1){
            // 꼬리 아닌 몸통을 만남
            if(!(snake[snake.size()-1].first == x && snake[snake.size()-1].second == y)) outFlag = true;
            else{
                // // 꼬리를 만남.
                // // 머리 위치를 해당 위치로 바꿈.
                // boards[x][y] = 1;
                // snake.insert(snake.begin(), make_pair(x, y));
                // // vector에 저장된 꼬리 삭제.
                // boards[snake[snake.size()-1].first][snake[snake.size()-1].second] = 0;
                // snake.pop_back();
                outFlag = true;

            }
        // 사과 만남.
        }else if(boards[x][y] == 4){
            // 해당 지점이 새 머리.
            boards[x][y] = 1;
            snake.insert(snake.begin(), make_pair(x, y));
        // 아무것도 없음.
        }else{
            // 해당 지점이 새 머리.
            boards[x][y] = 1;
            snake.insert(snake.begin(), make_pair(x, y));
            // vector에 저장된 꼬리 삭제.
            boards[snake[snake.size()-1].first][snake[snake.size()-1].second] = 0;
            snake.pop_back();
        }

        

        if(outFlag) break;

        // printf("sec %d\nsnake:", sec);
        // for(int j=0; j<snake.size(); j++) printf("(%d, %d)", snake[j].first, snake[j].second);
        // printf("\n");
    }

    printf("%d\n", sec);
}