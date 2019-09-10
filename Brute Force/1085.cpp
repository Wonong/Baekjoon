#include <cstdio>
#include <algorithm>

using namespace std;

int main(){
    int x,y,w,h;

    scanf("%d %d %d %d", &x, &y, &w, &h);

    int min1 = min(x, y);
    int min2 = min(w-x, h-y);
    int ans = min(min1, min2);
    printf("%d\n", ans);
}