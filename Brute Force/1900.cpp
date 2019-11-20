#include <cstdio>
#include <algorithm>

using namespace std;

struct player{
    int num, power, ring;
};

int numOfWinners[10000];
player wrestlers[10000];
int n;

void fight(int idx1, int idx2){
    
    int score[2];

    player p1 = wrestlers[idx1];
    player p2 = wrestlers[idx2];

    score[0] = p1.power + p1.ring * p2.power;
    score[1] = p2.power + p2.ring * p1.power;

    if(score[0] > score[1]) numOfWinners[idx1] += 1;
    else numOfWinners[idx2] += 1;
}

bool cmp(player p1, player p2){
    if(numOfWinners[p1.num-1] >= numOfWinners[p2.num-1]) return true;
    else return false;
}

int main(){

    scanf("%d", &n);

    for(int i=0; i<n; i++){
        scanf("%d %d", &wrestlers[i].power, &wrestlers[i].ring);
        wrestlers[i].num = i+1;
    }
    

    for(int i=0; i<n; i++){
        for(int j=i+1; j<n; j++){
            fight(i, j);
        }
    }

    sort(wrestlers, wrestlers+n, cmp);

    for(int i=0; i<n; i++){
        printf("%d\n", wrestlers[i].num);
    }
}