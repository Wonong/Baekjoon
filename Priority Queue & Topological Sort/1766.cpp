#include <cstdio>
#include <queue>
#include <vector>

using namespace std;

vector<int> preProbs[32001];
vector<int> postProbs[32001];
// int postCnt[32001];
priority_queue<int, vector<int>, greater<int> > solvingQ;

int main(){
    int n, m, temp[2];

    scanf("%d %d", &n, &m);
    for(int i=0; i<m; i++){
        scanf("%d %d", &temp[0], &temp[1]);
        preProbs[temp[1]].push_back(temp[0]);
        postProbs[temp[0]].push_back(temp[1]);
        // postCnt[temp[1]] += temp[0];
    }

    for(int i=1; i<=n; i++){
        if(preProbs[i].size() == 0){
            solvingQ.push(i);
        }
    }

    while(!solvingQ.empty()){
        int num, len;

        // 큐에서 제일 낮은 번호의 문제 풀이
        num = solvingQ.top();
        solvingQ.pop();
        printf("%d ", num);

        len = postProbs[num].size();

        // 푼 문제의 post 문제들 중 가능한 문제 해결
        for(int i=0; i<len; i++){
            int inLen, inNum;
            inNum = postProbs[num][i];
            inLen = preProbs[inNum].size();
            for(int j=0; j<inLen; j++){
                if(preProbs[inNum][j] == num){
                    preProbs[inNum].erase(preProbs[inNum].begin() + j);
                    break;
                }
            }
            if(preProbs[inNum].size() == 0) solvingQ.push(inNum);
        }   
    }
    printf("\n");
}