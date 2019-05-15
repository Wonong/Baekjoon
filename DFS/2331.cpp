#include <cstdio>
#include <vector>
#include <cmath>

using namespace std;

int getNext(int current, int p);
int initGraph(int a, int cnt);

vector<int> graph;
int visit[1000000];
int p;

int main(){

    int a, startVal;

    scanf("%d %d", &a, &p);

    visit[a] = 1;

    printf("%d\n", initGraph(a, 2));
}

int getNext(int current, int p){

    int ret = 0;

    while(current>0){
        ret += pow((current%10), p);
        current /= 10;
    }

    return ret;
}

int initGraph(int a, int cnt){
    int temp;

    temp = getNext(a, p);

    if(visit[temp] == 0){
        visit[temp] = cnt;
        return initGraph(temp, cnt+1);
    }else{
        return visit[temp]-1;
    }
}