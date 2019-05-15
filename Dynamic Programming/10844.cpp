#include <iostream>
#include <string>
#include <stack>
#include <queue>
#include <algorithm>

using namespace std;

int main(){
    
    int n;
    long long ans = 0;
    long long  r[10] = {0,1,1,1,1,1,1,1,1,1};
    long long rr[10] = {0,1,1,1,1,1,1,1,1,1};

    cin >> n;

    for(int i=1; i<n; i++){
        rr[0] = r[1];
        rr[1] = r[0] + r[2];
        rr[2] = r[1] + r[3];
        rr[3] = r[2] + r[4];
        rr[4] = r[3] + r[5];
        rr[5] = r[4] + r[6];
        rr[6] = r[5] + r[7];
        rr[7] = r[6] + r[8];
        rr[8] = r[7] + r[9];
        rr[9] = r[8];
        for(int j=0; j<10; j++) r[j] = rr[j] % 1000000000;
    }

    for(int i=0; i<10; i++){
        ans += r[i];
    }
    ans %= 1000000000;

    cout << ans << endl;
    return 0;
}



