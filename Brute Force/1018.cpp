#include <cstdio>
#include <algorithm>

using namespace std;

int n, m, ans = 64;
char board[51][51];
char white[8][8]= {
    {'W','B','W','B','W','B','W','B'},
    {'B','W','B','W','B','W','B','W'},
    {'W','B','W','B','W','B','W','B'},
    {'B','W','B','W','B','W','B','W'},
    {'W','B','W','B','W','B','W','B'},
    {'B','W','B','W','B','W','B','W'},
    {'W','B','W','B','W','B','W','B'},
    {'B','W','B','W','B','W','B','W'}
};

int checkChess(int x1, int y1){
    
    int whiteCnt = 0, blackCnt = 0;
    for(int i=0; i < 8; i++){
        for(int j=0; j<8; j++){
            if(white[i][j] != board[x1+i][y1+j]) whiteCnt += 1;
            else blackCnt += 1;
        }
    }
    return min(whiteCnt, blackCnt);
}

int main(){

    scanf("%d %d", &n, &m);
    for(int i=0; i<n; i++){
        scanf("%s", &board[i]);
    }

    for(int i=0; i <= n-8; i++){
        for(int j=0; j <= m-8; j++){
            int temp = checkChess(i, j);
            if(ans > temp) ans = temp;
        }
    }

    printf("%d\n", ans);
}