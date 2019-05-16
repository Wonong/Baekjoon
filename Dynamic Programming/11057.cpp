#include <iostream>
#include <string>
#include <stack>
#include <queue>
#include <algorithm>

using namespace std;

int main(){
    
    int n;
    long long *ascdNum[10], ans = 0;

    cin >> n;

    for(int i=0; i<10; i++){
        ascdNum[i] = (long long*)calloc(n, sizeof(long long));
        ascdNum[i][0] = 1;
    }

    for(int i=1; i<n; i++){
        ascdNum[0][i] = 1;
        for(int j=1; j<10; j++){
            ascdNum[j][i] = (ascdNum[j-1][i] + ascdNum[j][i-1])%10007;
        }
    }

    for(int i=0; i<10; i++){
        ans += ascdNum[i][n-1];
    }

    cout << ans%10007 << endl;

    return 0;
}



