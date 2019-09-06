#include <cstdio>

using namespace std;

long long n, k, maxLen=0;
long long left, right;
long long arr[10000];

bool check(long long len){
    int num = 0;

    for(int i=0; i<k; i++){
        num += (arr[i]/len);
    }

    return (num >= n);
}

int main(){

    long long ans = 0;

    scanf("%lld %lld", &k, &n);
    for(int i=0; i<k; i++) scanf("%lld", &arr[i]);
    for(int i=0; i<k; i++){
        if(maxLen < arr[i]) maxLen = arr[i];
    }

    left = 1;
    right = maxLen;

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