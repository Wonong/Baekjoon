#include <cstdio>
#include <cmath>

using namespace std;

int main(){
    int n, r, c, ans = 0;

    scanf("%d %d %d", &n, &r, &c);

    while(n >= 1){
        if(r < pow(2,n)/2){
            if(c >= pow(2,n)/2){
                ans += pow(2,n) * pow(2,n) / 4;
            }
        }else{
            ans += pow(2,n) * pow(2,n) / 2;
            if(c >= pow(2,n)/2){
                ans += pow(2,n) * pow(2,n) / 4;
            }
        }
        n--;
        r = (r-pow(2,n)) >= 0 ? (r-pow(2,n)) : r;
        c = (c-pow(2,n)) >= 0 ? (c-pow(2,n)) : c;
    }
    printf("%d\n", ans);
}