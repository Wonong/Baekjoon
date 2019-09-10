#include <cstdio>

using namespace std;

// 0이면 소수
int arr[10000];

int main(){
    int n, t;
    
    for(int i=2; i<=5000; i++){
        if(arr[i] == 1) continue;
        for(int j = i*2; j <= 10000; j += i){
            arr[j] = 1;
        }
    }
    
    scanf("%d", &t);

    while(t--){
        scanf("%d", &n);

        int a, b;

        for(int i = n/2; i >= 2; i--){
            if(arr[i] == 0 && arr[n-i] == 0){
                a = i;
                b = n-i;
                break;
            }
        }

        printf("%d %d\n", a, b);
    } 


}