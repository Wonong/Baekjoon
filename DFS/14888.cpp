#include <cstdio>
#include <vector>

#define MAX_INF 1000000000
#define MIN_INF -1000000000

using namespace std;

int n;      // 수의 갯수.
int numSeq[11];     // 수열 저장.

long long minVal = MAX_INF, maxVal = MIN_INF;
int op[4];     // 각 연산자 갯수 저장.   더하기,빼기,곱하기,나누기.
void dfs(long long sum, int nowOp, int cnt);
long long customDiv(long long x, int y);

int main(){

    long long temp;

    scanf("%d", &n);
    for(int i=0; i<n; i++) scanf("%d", &numSeq[i]);
    scanf("%d %d %d %d", &op[0], &op[1], &op[2], &op[3]);

    temp = numSeq[0];

    dfs(temp, -1, 0);

    printf("%lld\n", maxVal);
    printf("%lld\n", minVal);

}

void dfs(long long sum, int nowOp, int cnt){
    

    switch(nowOp){
        case 0:
            sum += numSeq[cnt];
        break;
        case 1:
            sum -= numSeq[cnt];
        break;
        case 2:
            sum *= numSeq[cnt];
        break;
        case 3:
            sum = customDiv(sum, numSeq[cnt]);
        break;
        default:
        break;
    }

    if(cnt == n-1){
        if(sum > maxVal) maxVal = sum;
        if(sum < minVal) minVal = sum;
        return;
    }
    
    for(int i=0; i<4; i++){
        if(op[i] > 0){
            op[i]--;
            dfs(sum, i, cnt+1);
            op[i]++;
        }
    }

}

long long customDiv(long long x, int y){
    if(x == 0) return 0;
    if(x < 0 && y > 0){
        x = -x;
        return -(x/y);
    }else return x/y;
}