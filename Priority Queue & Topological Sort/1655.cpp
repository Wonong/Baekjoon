#include <cstdio>
#include <queue>

using namespace std;

priority_queue<int, vector<int>, less<int> > maxPQ;
priority_queue<int, vector<int>, greater<int> > minPQ;

int main(){
    int n, temp;

    scanf("%d", &n);
    for(int i=0; i<n; i++){
        scanf("%d", &temp);
        // 수 넣기
        if(maxPQ.size() == minPQ.size()){
            maxPQ.push(temp);
        }else{
            minPQ.push(temp);
        }

        if(minPQ.size() != 0 && maxPQ.top() > minPQ.top()){
            int qTemp[2];

            qTemp[0] = maxPQ.top(); maxPQ.pop();
            qTemp[1] = minPQ.top(); minPQ.pop();

            maxPQ.push(qTemp[1]);
            minPQ.push(qTemp[0]);
        }

        printf("%d\n", maxPQ.top());
    }
}