#include <cstdio>
#include <vector>
#include <algorithm>
#define INF 9999

using namespace std;

int n;
pair<int, int> lines[500];

int main(){
    int temp[2], num, ans = 0;
    vector<int> lis;

    scanf("%d", &n);

    for(int i=0; i<n; i++){
        scanf("%d %d", &lines[i].first, &lines[i].second);
    }
    sort(lines, lines+n);
    lis.push_back(-INF);

    for(int i=0; i<n; i++){
        if(lis.back() < lines[i].second){
            lis.push_back(lines[i].second);
        }else{
            auto it = lower_bound(lis.begin(), lis.end(), lines[i].second);
            *it = lines[i].second;
            ans++;
        }
    }
    printf("%d\n", ans);
}