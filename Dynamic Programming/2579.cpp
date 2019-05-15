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
    long long *maxSum[2];
    int ans;

    // ans = -1000;

    cin >> n;
    nums = (int*)malloc(sizeof(int)*n);
    for(int i=0; i<2; i++) maxSum[i] = (long long*)malloc(sizeof(long long)*n);

    for(int i=0; i<n; i++){
        cin >> nums[i];
    }

    maxSum[0][0] = 0;
    maxSum[1][0] = nums[0];
    maxSum[0][1] = maxSum[1][0];
    maxSum[1][1] = maxSum[1][0] + nums[1];

    for(int i=2; i<n; i++){
        maxSum[0][i] = maxSum[1][i-1];
        maxSum[1][i] = max(maxSum[0][i-2] + nums[i-1], maxSum[1][i-2]) + nums[i];
    }

    // ans = max(maxSum[0][n-3] + nums[n-2] + nums[]);

    cout << maxSum[1][n-1] << endl;

    free(nums);
    free(maxSum[0]);
    free(maxSum[1]);

    return 0;
}


