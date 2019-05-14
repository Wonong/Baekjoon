#include <iostream>
#include <string>
#include <stack>
#include <queue>
#include <algorithm>

using namespace std;

int main(){
    
    int n;
    int *nums;
    int tempMax;
    long long *maxSeqSum;
    int ans;

    ans = -1000;

    cin >> n;
    nums = (int*)malloc(sizeof(int)*n);
    maxSeqSum = (long long*)malloc(sizeof(long long)*n);

    for(int i=0; i<n; i++){
        cin >> nums[i];
    }

    maxSeqSum[n-1] = nums[n-1];

    for(int i=n-2; i>=0; i--){
        if(maxSeqSum[i+1] > 0){
            maxSeqSum[i] = maxSeqSum[i+1] + nums[i];
        }else{
            maxSeqSum[i] = nums[i];
        }
    }

    for(int i=0; i<n; i++){
        if(ans < maxSeqSum[i]) ans = maxSeqSum[i];
    }

    cout << ans << endl;

    free(nums);
    free(maxSeqSum);

    return 0;
}


