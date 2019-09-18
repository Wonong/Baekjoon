#include <cstdio>

using namespace std;



int main(){
    int n, k, ans=0;
    int coins[10];

    scanf("%d %d", &n, &k);

    for(int i=0; i<n; i++){
        scanf("%d", &coins[n-1-i]);
    }

    for(int i=0; k != 0; i++){
        if(coins[i] <= k){
            int temp = (k/coins[i]);
            k -= (temp * coins[i]);
            ans += temp;
        }
    }

    printf("%d\n", ans);

}