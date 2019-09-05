#include <cstdio>
#include <vector>
#define SIZE 100000
using namespace std;

int inOrder[SIZE], postOrder[SIZE], inPosition[SIZE];
int n;

void printRoot(int startPost, int endPost, int startIn, int endIn){
    int root, mid, leftLen, rightLen;

    root = postOrder[endPost];
    
    printf("%d ", root);

    for(int i=startIn; i<=endIn; i++){
        if(inOrder[i] == root) mid = i;
    }
    // mid = inPosition[root];

    leftLen = mid - startIn;
    rightLen = endIn - mid;

    if(leftLen > 0) printRoot(startPost, startPost + leftLen-1, startIn, startIn + leftLen-1);
    if(rightLen > 0) printRoot(startPost+leftLen, endPost-1, startIn + leftLen + 1, endIn);
}

int main(){
    scanf("%d", &n);
    for(int i=0; i<n; i++) scanf("%d", &inOrder[i]);
    for(int i=0; i<n; i++) scanf("%d", &postOrder[i]);
    // for(int i=0; i<n; i++) inPosition[inOrder[i]] = i;

    printRoot(0, n-1, 0, n-1);
    printf("\n");

}
