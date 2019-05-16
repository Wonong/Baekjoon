#include <iostream>
#include <string>
#include <stack>
#include <queue>
#include <algorithm>

using namespace std;

int main(){
    
    int n;
    int *nums;
    // longestDescSeq : 인덱스를 시작으로 하는 가장 긴 내림차순 수열의 길이
    // longestAscSeq : 인덱스를 끝으로 하는 가장 긴 오름차순 수열의 길이
    int tempMax, *longestDescSeq, *longestAscSeq, *longestBitonicSeq;
    int maxAsc=0, maxDesc=0;
    int ans;

    ans = 0;

    cin >> n;
    nums = (int*)malloc(sizeof(int)*n);
    longestDescSeq = (int*)malloc(sizeof(int)*n);
    longestAscSeq = (int*)malloc(sizeof(int)*n);

    for(int i=0; i<n; i++){
        cin >> nums[i];
    }

    longestDescSeq[n-1] = 1;
    
    for(int i=n-2; i>=0; i--){
        tempMax = 0;
        for(int j=n-1; j>i; j--){
            if(nums[j] < nums[i] && longestDescSeq[j] > tempMax) tempMax = longestDescSeq[j];
        }
        longestDescSeq[i] = tempMax + 1;
    }

    longestAscSeq[0] = 1;

    for(int i=0; i<n; i++){
        tempMax = 0;
        for(int j=0; j<i; j++){
            if(nums[j] < nums[i] && longestAscSeq[j] > tempMax) tempMax = longestAscSeq[j];
        }
        longestAscSeq[i] = tempMax + 1;
    }

    for(int i=0; i<n; i++){
        if(ans < longestDescSeq[i] + longestAscSeq[i]) ans = longestDescSeq[i] + longestAscSeq[i] - 1;
    }

    cout << ans << endl;

    free(nums);
    free(longestDescSeq);
    free(longestAscSeq);

    return 0;
}


