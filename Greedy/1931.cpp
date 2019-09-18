#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

pair<int, int> meeting[100000];

int main(){
    int n, startTime = 0, ans=0;

    scanf("%d", &n);

    for(int i=0; i<n; i++){
        scanf("%d %d", &meeting[i].second, &meeting[i].first);
    }

    sort(meeting, meeting+n);

    for(int i=0; i<n; i++){
        if(meeting[i].second >= startTime){
            ans++;
            startTime = meeting[i].first;
        }
    }
    printf("%d\n", ans);
}