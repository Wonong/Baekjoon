#include <cstdio>
#include <algorithm>
#define SIZE 500000

using namespace std;

int n, m;
int arr[SIZE], arrFind[SIZE], ans[SIZE];

int main(){
    int cur = 0;
    int left, right, mid;

    scanf("%d", &n);
    for(int i=0; i<n; i++) scanf("%d", &arr[i]);
    scanf("%d", &m);
    for(int i=0; i<m; i++) scanf("%d", &arrFind[i]);

    sort(arr, arr + n);
    // sort(arrFind, arrFind + m);

    for(int i=0; i<m; i++){
        int search = arrFind[i];
        left = 0;
        right = n-1;
        while(left <= right){
            mid = (left + right)/2;
            if(arr[mid] == search){ ans[i] = 1; break; }
            else if(arr[mid] > search) right = mid-1;
            else left = mid + 1;
        }
    }

    for(int i=0; i<m; i++) printf("%d ", ans[i]);
    printf("\n");

}