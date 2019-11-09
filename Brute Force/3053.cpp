#include <cstdio>
#include <cmath>

using namespace std;

int main(){
    int n;
    double euclid, taxi;
    double const PI = acos(-1);

    scanf("%d", &n);

    euclid = PI * (n * n);
    taxi = (2 * n) * (2 * n) / 2;

    printf("%.6f\n", euclid);
    printf("%.6f\n", taxi);


}