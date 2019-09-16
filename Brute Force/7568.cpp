#include <cstdio>
#include <vector>

using namespace std;

int main(){
    int n, ans[50];
    pair<int, int> people[50];

    scanf("%d", &n);
    for(int i=0; i<n; i++){
        scanf("%d %d", &people[i].first, &people[i].second);
    }

    for(int i=0; i<n; i++){
        ans[i] = 1;
        pair<int, int> temp = people[i];
        for(int j=0; j<n; j++){
            if(j == i) continue;
            if(people[j].first > temp.first && people[j].second > temp.second){
                ans[i] += 1;
            }
        }
    }

    for(int i=0; i<n; i++) printf("%d ", ans[i]);
    printf("\n");

}