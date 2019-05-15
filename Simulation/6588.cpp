#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <stack>
#include <queue>
#include <math.h>



using namespace std;
void printEquation(int num);

int check[1000001] = {0, };
int primes[100001] = {0, };
int pn=0;

int main(){
    
    queue<int> inputQueue;

    int maxIn = 0, input;
    int limit;

    cin.tie(NULL);
    ios::sync_with_stdio(false);

    while(scanf("%d", &input)){
        if(input == 0) break;
        if(input > maxIn){
            maxIn = input;
        }
        inputQueue.push(input);
    }


    limit = (int)sqrt(maxIn);

    for(int i = 3; i < limit; i+=2){
        if(check[i] == 1) continue;
        primes[pn++] = i;
        for(int j = i*i; j <= maxIn; j += i){
            check[j] = 1;
        }
    }

    while(inputQueue.size() != 0){
        printEquation(inputQueue.front());
        inputQueue.pop();
    }
    return 0;
}

void printEquation(int num){
    
    while(true){
        for(int i=0; i<pn; i++){
            if(check[num-primes[i]] == 0){
                cout << num << " = " << primes[i] << " + " << num-primes[i] << '\n';
                return;
            }
        }
        
    }

    cout << "Goldbach's conjecture is wrong." << '\n';

    
    return;
}