#include <cstdio>
#include <stack>

using namespace std;

int n;
int boards[101][101];
int dir[4][2] = {
    {0,1}, {-1,0}, {0,-1}, {1, 0}
};
int endPt[2];

typedef struct{
    int from[2];
    int to[2];
    int dir;
}curve;

void generateCurve(curve c, int g);
void checkPtr(int x, int y);

int main(){

    curve curves[20];
    int gen[20];
    int ans = 0;

    scanf("%d", &n);
    for(int i=0; i<n; i++){
        scanf("%d %d %d %d", &curves[i].from[1], &curves[i].from[0], &curves[i].dir, &gen[i]);
        curves[i].to[0] = curves[i].from[0] + dir[curves[i].dir][0];
        curves[i].to[1] = curves[i].from[1] + dir[curves[i].dir][1];
        generateCurve(curves[i], gen[i]);
    }

    for(int i=0; i<100; i++){
        for(int j=0; j<100; j++){
            if(boards[i][j] == 1 && boards[i+1][j] == 1 && boards[i][j+1] == 1 && boards[i+1][j+1] == 1){
                ans++;
            }
        }
    }

    printf("%d\n", ans);

}

void generateCurve(curve c, int g){
    stack<curve> s, tempS;
    curve temp;
    bool isTo = true;

    s.push(c);
    endPt[0] = c.to[0];
    endPt[1] = c.to[1];

    for(int i=0; i<=g; i++){

        int size = s.size();
        tempS = s;

        for(int j=0; j<size; j++){
            temp = tempS.top();
            tempS.pop();
            checkPtr(temp.to[0], temp.to[1]);
            checkPtr(temp.from[0], temp.from[1]);

            curve newC;
            newC.dir = (temp.dir+3)%4;
            if(isTo){
                
                newC.to[0] = endPt[0];
                newC.to[1] = endPt[1];
                newC.from[0] = endPt[0] = newC.to[0]-dir[(temp.dir+3)%4][0];
                newC.from[1] = endPt[1] = newC.to[1]-dir[(temp.dir+3)%4][1];
            }else{
                newC.from[0] = endPt[0];
                newC.from[1] = endPt[1];
                newC.to[0] = endPt[0] = newC.from[0]+dir[(temp.dir+3)%4][0];
                newC.to[1] = endPt[1] = newC.from[1]+dir[(temp.dir+3)%4][1];
            }
            isTo = !isTo;
            s.push(newC);
            
        }   
    }
}

bool checkIdx(int x, int y){
    if(x >= 0 && x < 100 && y >= 0 && y<100) return true;
    else return false;
}

void checkPtr(int x, int y){
    boards[x][y] = 1;
}