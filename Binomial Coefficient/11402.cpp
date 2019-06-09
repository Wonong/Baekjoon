#include <cstdio>
#include <stack>

using namespace std;

long long getBe(int n, int k);

long be[2001][2001];
stack<int> nums[2];
long long n, k;
int m;

int main(){
    
    long long sum = 1;

    scanf("%lld %lld %d", &n, &k, &m);

    while(n != 0){
        int temp = n%m;
        nums[0].push(temp);
        n /= m;
    }

    while(k != 0){
        int temp = k%m;
        nums[1].push(temp);
        k /= m;
    }

    while(nums[0].size() > nums[1].size()) nums[1].push(0);

    int len = nums[0].size();

    while(!nums[0].empty()){
        int ni = nums[0].top();
        int ki = nums[1].top();
        nums[0].pop();
        nums[1].pop();
        sum *= getBe(ni, ki);
    }

    printf("%lld\n", sum%m);

}

long long getBe(int n, int k){
    if(n < k || k < 0) return 0;
    if(n == k || k == 0){
        be[n][k] = 1;
        return be[n][k];
    }
    if(be[n][k] != 0) return be[n][k];
    else{
        be[n][k] = (getBe(n-1, k-1) + getBe(n-1, k))%m;
        return be[n][k];
    }
}