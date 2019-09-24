#include <cstdio>
#include <queue>
#include <vector>

using namespace std;

int workTime[10001];
// int preWorkDone[10001];
vector<int> workPre[10001];
priority_queue<pair<int, int>, vector<pair<int, int> >, greater<pair<int, int> > > jobQ;
int ans;

int main(){
    int n, m, l;

    scanf("%d", &n);

    for(int i=1; i<=n; i++){
        scanf("%d", &workTime[i]);

        scanf("%d", &m);
        for(int j=0; j<m; j++){
            scanf("%d", &l);
            workPre[i].push_back(l);
        }
    }

    // 선수 작업 없는 작업들 push
    for(int i=1; i<=n; i++){
        if(workPre[i].size() == 0){
            jobQ.push(make_pair(workTime[i], i));       
        }
    }

    while(!jobQ.empty()){

        int len = jobQ.size();

        for(int i=0; i<len; i++){
            pair<int, int> curr;
            int endTime;
        
            curr = jobQ.top();
            jobQ.pop();
            endTime = curr.first;

            for(int j = curr.second+1; j<=n; j++){
                if(workPre[j].size() == 0) continue;
                for(int k = 0; k<workPre[j].size(); k++){
                    if(workPre[j][k] == curr.second){
                        workPre[j].erase(workPre[j].begin() + k);
                        k--;
                    }
                }
                if(workPre[j].size() == 0) jobQ.push(make_pair(endTime + workTime[j], j));
            }
            if(ans < endTime) ans = endTime;
        }
        
    }
    printf("%d\n", ans);


}