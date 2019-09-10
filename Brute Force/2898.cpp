#include <cstdio>

using namespace std;

int cards[100];

int main(){
    int n, m, ans = 0;

    scanf("%d %d", &n, &m);
    for(int i=0; i<n; i++) scanf("%d", &cards[i]);
    
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            for(int k=0; k<n; k++){
                if(i==j || j==k || i==k) continue;
                if(cards[i]+cards[j]+cards[k] > ans && cards[i]+cards[j]+cards[k] <= m) ans = cards[i]+cards[j]+cards[k];
            }
        }
    }

    printf("%d\n", ans);
}