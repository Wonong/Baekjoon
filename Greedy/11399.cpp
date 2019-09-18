#include <cstdio>
#include <algorithm>

using namespace std;

int main(){
    int n, ans=0;
    int people[1000];

    scanf("%d", &n);
    for(int i=0; i<n; i++){
        scanf("%d", &people[i]);
    }

    sort(people, people+n);
    for(int i=0; i<n; i++){
        ans += people[i] * (n-i);
    }
    printf("%d\n", ans);
}