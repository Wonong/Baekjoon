#include <iostream>
#include <algorithm>

using namespace std;

int main(){
    
    int n;
    int *nums;
    int tempMax, *seqSum;
    int ans;

    cin >> n;
    nums = (int*)malloc(sizeof(int)*n);
    seqSum = (int*)malloc(sizeof(int)*n);

    for(int i=0; i<n; i++){
        cin >> nums[i];
    }

    seqSum[n-1] = nums[n-1];
    ans = 0;

    for(int i=n-2; i>=0; i--){
        tempMax = 0;
        for(int j=n-1; j>i; j--){
            if(nums[j] > nums[i] && seqSum[j] > tempMax) tempMax = seqSum[j];
        }
        seqSum[i] = tempMax + nums[i];
        
    }
    
    for(int i=0; i<n; i++){
        if(ans < seqSum[i]) ans = seqSum[i];
    }
    cout << ans << endl;

    free(nums);
    free(seqSum);

    return 0;
}

