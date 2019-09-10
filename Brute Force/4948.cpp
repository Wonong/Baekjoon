#include <cstdio>

using namespace std;

int main(){
    int n;

    while(true){
        scanf("%d", &n);

        if(n == 0) break;

        int ans = n ;
        int arr[123456 * 2 + 1];

        for(int i = n+1; i<= 2*n; i++) arr[i] = 0;

        for(int i=2; i <= n; i++){
            int curr;
            curr = n + (i - (n % i));

            while(curr <= 2 * n){
                if(arr[curr] == 0){
                    arr[curr] = 1;
                    ans -= 1;
                }
                curr += i;
            }
        }
        printf("%d\n", ans);
    }
}