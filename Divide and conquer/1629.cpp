#include <cstdio>

using namespace std;

int a, b, c;

long long getPow(int n, int m);

int main(){
    
    scanf("%d %d %d", &a, &b, &c);

    a %= c;

    printf("%lld\n", getPow(a, b));
}

long long getPow(int n, int m){
    long long temp;
    switch(m){
        case 0:
            return 1;
            break;
        case 1:
            return n;
            break;
        default:
            switch(m%2){
                case 0:
                    temp = getPow(n, m/2);
                    temp %= c;
                    return temp*temp%c;
                    break;
                case 1:
                    return n * getPow(n, m-1)%c;
            }
    }
}