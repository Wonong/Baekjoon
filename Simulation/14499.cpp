#include <cstdio>

using namespace std;

int diceSurface[7];
int n, m;
int boards[20][20];
int cmds[1000];
int dir[4][2] = {
    {0, 1}, {0, -1}, {-1, 0}, {1, 0}
};

bool checkIdx(int x, int y);
int main(){
    int x, y, k;
    int cmd, temp;

    scanf("%d %d %d %d %d", &n, &m, &x, &y, &k);
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            scanf("%d", &boards[i][j]);
        }
    }

    for(int i=0; i<k; i++){
        scanf("%d", &cmds[i]);
    }

    for(int i=0; i<k; i++){
        cmd = cmds[i];
        int nx = x + dir[cmd-1][0]; int ny = y + dir[cmd-1][1];


        if(!checkIdx(nx, ny)) continue;
        else{
            x = nx;
            y = ny;
        }

        switch(cmd-1){
            case 0: // 동으로 이동.
                temp = diceSurface[1];
                diceSurface[1] = diceSurface[3];
                diceSurface[3] = diceSurface[6];
                diceSurface[6] = diceSurface[4];
                diceSurface[4] = temp;
            break;
            case 1: // 서로 이동.
                temp = diceSurface[1];
                diceSurface[1] = diceSurface[4];
                diceSurface[4] = diceSurface[6];
                diceSurface[6] = diceSurface[3];
                diceSurface[3] = temp;
            break;
            case 2: // 북으로 이동.
                temp = diceSurface[2];
                diceSurface[2] = diceSurface[6];
                diceSurface[6] = diceSurface[5];
                diceSurface[5] = diceSurface[1];
                diceSurface[1] = temp;
            break;
            case 3: // 남으로 이동
                temp = diceSurface[2];
                diceSurface[2] = diceSurface[1];
                diceSurface[1] = diceSurface[5];
                diceSurface[5] = diceSurface[6];
                diceSurface[6] = temp;
            break;
        }
        if(boards[x][y] == 0){
            boards[x][y] = diceSurface[1];
        }else{
            
            diceSurface[1] = boards[x][y];
            boards[x][y] = 0;
        }
        printf("%d\n", diceSurface[6]);
    }
}

bool checkIdx(int x, int y){
    if(x >= 0 && x < n && y >= 0 && y < m) return true;
    else return false;
}