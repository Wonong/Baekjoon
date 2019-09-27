#include <cstdio>
#include <algorithm>

using namespace std;

int homes[200000];
int n;

bool checkDist(int dist, int cnt){
    int c = 1, pos = homes[0];

    for(int i = 1; i < n; i++){
        if(homes[i] - pos >= dist){
            c++;
            pos = homes[i];
            if(c == cnt) return true;
        }
    }
    return false;
}

int main(){
    int c, l, r, ans = 0;

    scanf("%d %d", &n, &c);

    for(int i=0; i<n; i++){
        scanf("%d", &homes[i]);
    }
    sort(homes, homes + n);


    l = 1;
    r = homes[n-1] - homes[0];

    while (l <= r){
        int mid = (l+r)/2;
        if(checkDist(mid, c)){
            ans = mid;
            l = mid + 1;
        }else{
            r = mid - 1;
        }
    }
    printf("%d\n", ans);

}