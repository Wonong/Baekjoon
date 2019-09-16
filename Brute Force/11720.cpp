#include <cstdio>

using namespace std;

int main(){
    int n, ans = 0;
    int arr[100];

    scanf("%d", &n);

    for(int i=0; i<n; i++){
        scanf("%1d", &arr[i]);
        ans += arr[i];
    }

    printf("%d\n", ans);

}