#include <cstdio>

using namespace std;

int paper[2187][2187];
int bucket[3];      //2: -1로만 채워진 종이의 개수
int n;

void checkPaper(int startRow, int startCol, int division);
int main(){
    int division = 1;
    
    scanf("%d", &n);

    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            scanf("%d", &paper[i][j]);
        }
    }

    checkPaper(0, 0, division);
    
    printf("%d\n", bucket[2]);
    printf("%d\n", bucket[0]);
    printf("%d\n", bucket[1]);
}

void checkPaper(int startRow, int startCol, int division){
    int num = paper[startRow][startCol];
    bool flag = true;

    for(int i = startRow; i < startRow + n/division && flag; i++){
        for(int j = startCol; j< startCol + n/division && flag; j++){
            if(num != paper[i][j]){
                flag = false;
                break;
            }
        }
    }
    if(flag){
        bucket[(num+3)%3]++;
    }else{
        division *= 3;
        for(int i=0; i<3; i++){
            for(int j=0; j<3; j++){
                checkPaper(startRow+i*(n/division), startCol+j*(n/division), division);
            }
        }
    }
}