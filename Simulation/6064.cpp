#include <cstdio>
#include <algorithm>
#include <vector>

using namespace std;

long long getLcm(int x, int y);

int main(){
    int t;
    vector<int> ans;

    scanf("%d", &t);

    while(t--){
        int m, n, x, y, k=0;
        int diff = 0;
        

        // 변수 입력받은 후 limit이 작은 수가 앞에 가도록 변경
        scanf("%d %d %d %d", &m, &n, &x, &y);
        if(m > n){
            swap(m, n);
            swap(x, y);
        }

        long long lcm = getLcm(m, n);

        if(x > m || y > n){
            ans.push_back(-1);
            continue;
        }

        // 최초로 해당 x 값을 가지는 달력의 해 구하기.
        int nx = x, ny = x;
        k += nx;

        while(ny != y && k <= lcm){
            ny = (ny+m)%n;
            if(ny == 0) ny = n;
            k += m;
        }

        if(k > lcm){
            ans.push_back(-1);
        }else{
            ans.push_back(k);
        }
    }
    for(int i=0; i<ans.size(); i++){
        printf("%d\n", ans[i]);
    }
}

long long getLcm(int x, int y){
    int gcd;
    long long ret;

    int ox = x, oy = y;

    while(y!=0){
        int r = x%y;
        x = y;
        y = r;
    }
    gcd = x;

    ret = (ox*oy)/gcd;

    return ret;
}