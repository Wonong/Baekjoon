#include <cstdio>
#include <queue>
// #include <vector>

int visit[100001];

using namespace std;

int main(){
    int n, k;

    scanf("%d %d", &n, &k);

    priority_queue<pair<int, int>, vector<pair<int, int> >, greater<pair<int, int> >> pq;

    pq.push(make_pair(0, n));
    visit[n] = 1;

    while(!pq.empty()){
        pair<int, int> current = pq.top();
        
        pq.pop();

        if(current.second == k){
            printf("%d\n", current.first);
            break;
        }

        if(current.second != 0){
            int next = current.second;
            while(next * 2 <= 100000){
                next = next * 2;
                if(visit[next] != 1){
                    pq.push(make_pair(current.first, next));
                    visit[next] = 1;
                }
            }
        }

        if(current.second > 0){
            int next = current.second - 1;
            if(visit[next] != 1){
                pq.push(make_pair(current.first + 1, next));
                visit[next] = 1;
            }
        }

        if(current.second < 99999){
            int next = current.second + 1;
            if(visit[next] != 1){
                pq.push(make_pair(current.first + 1, next));
                visit[next] = 1;
            }
        }
    }
}



