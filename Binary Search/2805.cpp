#include <cstdio>

using namespace std;

int n, m;
long long arr[1000000];

bool check(long long height){
    long long num = 0;

    for(int i=0; i<n; i++){
        if(arr[i] > height) num += (arr[i] - height);
    }
    return num >= m;
}

int main(){
    long long left, right, maxHeight = 0;
    long long ans = 0;

    scanf("%d %d", &n, &m);
    for(int i=0; i<n; i++){
        scanf("%lld", &arr[i]);
        if(maxHeight < arr[i]) maxHeight = arr[i];
    }

    left = 0;
    right = maxHeight;

    while(left <= right){
        long long mid = (left + right)/2;
        if(check(mid)){
            if(ans < mid) ans = mid;
            left = mid + 1;
        }else{
            right = mid - 1;
        }
    }

    printf("%lld\n", ans);
}