#include <cstdio>

using namespace std;

int places[1000000];
int n;
int b, c;

int main(){

    long long ans = 0;

    scanf("%d", &n);
    for(int i=0; i<n; i++){
        scanf("%d", &places[i]);
    }
    scanf("%d %d", &b, &c);

    for(int i=0; i<n; i++){
        int pops = places[i];
        // 주감독관 등장
        ans++;
        pops -= b;
        // 주 감독관만으로 가능한 경우 부감독관 스킵.
        if(pops <= 0) continue;
        else{
            // 부감독관으로 나누어 떨어지는 경우 나눈 수만큼 증가.
            // 아닌 경우에는 +1
            if(pops % c != 0){
                ans++;
            }
            ans += pops/c;
        }
    }

    printf("%lld\n", ans);
}