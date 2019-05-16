#include <iostream>
#include <string>
#include <stack>
#include <queue>
#include <algorithm>

using namespace std;

int main(){
    
    int n;
    int *nums;
    int tempMax, *longestSeq;
    int ans;

    cin >> n;
    nums = (int*)malloc(sizeof(int)*n);
    longestSeq = (int*)malloc(sizeof(int)*n);

    for(int i=0; i<n; i++){
        cin >> nums[i];
    }

    longestSeq[n-1] = 1;
    ans = 0;

    for(int i=n-2; i>=0; i--){
        tempMax = 0;
        for(int j=n-1; j>i; j--){
            if(nums[j] < nums[i] && longestSeq[j] > tempMax) tempMax = longestSeq[j];
        }
        longestSeq[i] = tempMax + 1;
    }

    for(int i=0; i<n; i++){
        if(ans < longestSeq[i]) ans = longestSeq[i];
    }

    cout << ans << endl;

    free(nums);
    free(longestSeq);

    return 0;
}


