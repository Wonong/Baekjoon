#include <cstdio>
#define SIZE 500000
using namespace std;

long long arr[SIZE], sorted[SIZE];
int n;

long long merge(int start, int end, int mid){
    int i = start;
    int j = mid+1;
    int k = start;
    long long ret = 0;

    while(i <= mid && j <= end){
        if(arr[i] <= arr[j]) sorted[k++] = arr[i++];
        else{
            ret += (long long)(mid-i+1);
            sorted[k++] = arr[j++];
        }
    }
    if(i<=mid){
        while(i <= mid) sorted[k++] = arr[i++];
    }else{
        while(j <= end) sorted[k++] = arr[j++];
    }

    for(int l = start; l<=end; l++){
        arr[l] = sorted[l];
    }

    return ret;
}

long long mergeSort(int start, int end){
    if(start == end) return 0;

    int mid = (start+end)/2;
    long long inversion1 = mergeSort(start, mid);
    long long inversion2 = mergeSort(mid+1, end);
    long long inversion3 = merge(start, end, mid);

    return (inversion1 + inversion2 + inversion3);
}

int main(){
    long long ans;

    scanf("%d", &n);
    for(int i=0; i<n; i++) scanf("%lld", &arr[i]);
    ans = mergeSort(0, n-1);
    printf("%lld\n", ans);
}