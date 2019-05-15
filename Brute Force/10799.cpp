#include <iostream>
#include <stack>

using namespace std;

int main(){

    string s;
    stack<int> steels;
    int cnt, tmp;

    cnt = 0;
    cin >> s;

    for(int i=0; i<s.size(); i++){
        if(s.at(i) == '('){
            steels.push(i);
        }else if(s.at(i) == ')'){
            tmp = steels.top();
            steels.pop();
            if(i - tmp == 1){
                cnt += steels.size();
            }else{
                cnt++;
            }
            
        }
    }

    cout << cnt << endl;

    return 0;
}