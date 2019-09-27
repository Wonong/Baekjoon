#include <cstdio>
#include <queue>
#include <vector>

using namespace std;

struct cmp{
    bool operator()(pair<int, int> a, pair<int, int> b){
        if(a.first < b.first) return false;
        else if(a.first == b.first){
            if(a.second == -1) return false;
            else return true;
        }else return true;
    }
};


int main(){
    int n;
    priority_queue<pair<int, int>, vector< pair<int, int > >, cmp> q;

    scanf("%d", &n);

    for(int i=0; i<n; i++){
        pair<int, int> temp;
        scanf("%d", &temp.first);

        if(temp.first == 0){
            if(q.empty()) printf("0\n");
            else{
                int pr = q.top().first * q.top().second;
                q.pop();
                printf("%d\n", pr);
            }
            continue;
        }

        if(temp.first < 0){
            temp.first *= -1;
            temp.second = -1;
        }else temp.second = 1;
        q.push(temp);
    }
}