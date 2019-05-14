#include <iostream>
#include <string>
#include <stack>
#include <queue>
#include <algorithm>

using namespace std;

int main(){

    int m, n, temp;

    cin >> n >> m;

    queue<int> numQ;

    for(int i = 1; i<=n; i++){
        numQ.push(i);
    }

    cout << '<';

    for(int i=1; numQ.size() != 1; i++){
        temp = numQ.front();
        if(i%m == 0){
            cout << temp << ", ";
        }else{
            numQ.push(temp);
        }
        numQ.pop();
    }

    cout << numQ.front() << ">\n";

    return 0;
}