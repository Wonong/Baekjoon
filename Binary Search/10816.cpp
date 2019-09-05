#include <cstdio>
#include <vector>
#include <algorithm>

#define SIZE 500000

using namespace std;

int n, m, len;
int arr[SIZE], findArr[SIZE], ans[SIZE];
pair<int, int> sorted[SIZE];

int main(){
    int cur;

    scanf("%d", &n);
    for(int i=0; i<n; i++) scanf("%d", &arr[i]);
    scanf("%d", &m);
    for(int i=0; i<m; i++) scanf("%d", &findArr[i]);

    sort(arr, arr+n);

    len = 0;
    cur = arr[0];
    sorted[len].first = cur;
    sorted[len++].second = 1;

    for(int i=1; i<n; i++){
        if(cur == arr[i]){
            sorted[len-1].second += 1;
        }else{
            cur = arr[i];
            sorted[len].first = cur;
            sorted[len++].second = 1;
        }
    }

    for(int i=0; i<m; i++){
        int search = findArr[i];
        int left = 0;
        int right = len-1;

        while(left <= right){
            int mid = (left+right)/2;
            if(sorted[mid].first == search){ ans[i] = sorted[mid].second; break;}
            else if(sorted[mid].first > search) right = mid-1;
            else left = mid+1;
        }
    }

    for(int i=0; i<m; i++) printf("%d ", ans[i]);
    printf("\n");
    
}