#include <cstdio>
#include <algorithm>

using namespace std;

int main(){
    int n, k, ans;
    long long cnt = 0;

    scanf("%d", &n);
    scanf("%d", &k);

    int left = 1, right = k;

    while(left <= right){
        cnt = 0;
        int mid = (left+right)/2;
        for(int i=1; i<=n; i++) cnt += min(mid/i, n);
        if(cnt < k) left = mid+1;
        else{
            ans = mid;
            right = mid-1;
        }
    }

    printf("%d\n", ans);
}