#include <cstdio>
#include <vector>
using namespace std;

void hanoi(int n, int from, int to, int by);

int ans;
vector<int> ansVec;

int main(){
    int n;

    scanf("%d", &n);
    hanoi(n, 1, 3, 2);
    
    printf("%d\n", ans);
    for(int i=0; i<ansVec.size(); i+=2){
        printf("%d %d\n", ansVec[i], ansVec[i+1]);
    }
}

void hanoi(int n, int from, int to, int by){

    if(n==1){
        ansVec.push_back(from);
        ansVec.push_back(to);
        ans++;
    }else{
        hanoi(n-1, from, by, to);
        ansVec.push_back(from);
        ansVec.push_back(to);
        ans++;
        hanoi(n-1, by, to, from);
    }
}
