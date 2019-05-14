#include <iostream>
#include <stdio.h>
#include <stdlib.h>

using namespace std;

long long getNumOf5(long long num);
long long getNumOf2(long long num);

int main(){
    
    long long n,m;
    long long numOf5[3], numOf2[3];
    long long div5, div2;

    cin >> n >> m;

    numOf5[0] = getNumOf5(m);
    numOf5[1] = getNumOf5(n-m);
    numOf5[2] = getNumOf5(n);

    numOf2[0] = getNumOf2(m);
    numOf2[1] = getNumOf2(n-m);
    numOf2[2] = getNumOf2(n);

    div5 = numOf5[2] - (numOf5[0] + numOf5[1]);
    div2 = numOf2[2] - (numOf2[0] + numOf2[1]);

    cout << min(div5, div2) << endl;
}

long long getNumOf5(long long num){
    long long d;
    long long ret;

    d = 5;
    ret = 0;

    while(d <= num){
        ret += num/d;
        d *= 5;
    }

    return ret;
}

long long getNumOf2(long long num){
    long long d;
    long long ret;

    d = 2;
    ret = 0;

    while(d <= num){
        ret += num/d;
        d *= 2;
    }

    return ret;
}