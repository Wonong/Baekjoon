#include <cstdio>
#include <algorithm>

using namespace std;

int ropes[100000];

int main(){
    
    int n, sum = 0;
    int numOfRope = 0;

    scanf("%d", &n);
    for(int i=0; i<n; i++){
        scanf("%d", &ropes[i]);
    }

    sort(ropes, ropes+n);

    for(int i = n-1; i >= 0; i--){
        numOfRope++;
        if(sum < ropes[i] * numOfRope){
            sum = ropes[i] * numOfRope;
        }
    }

    printf("%d\n", sum);

}

