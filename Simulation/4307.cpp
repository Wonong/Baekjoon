#include <cstdio>
#include <algorithm>

using namespace std;

int main(){
    int t;
    scanf("%d", &t);
    
    while(t--){
        int l, n, temp[2], minTime, maxTime;

        minTime = 0;
        maxTime = 0;
        scanf("%d %d", &l, &n);

        for(int i=0; i<n; i++){
            scanf("%d", &temp[0]);
            temp[1] = l - temp[0];
            if(temp[0] > temp[1]) swap(temp[0], temp[1]);

            if(temp[0] > minTime) minTime = temp[0];
            if(temp[1] > maxTime) maxTime = temp[1];
        }

        printf("%d %d\n", minTime, maxTime);
    }
}