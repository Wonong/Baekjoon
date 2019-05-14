#include <iostream>
#include <string>
#include <stack>
#include <algorithm>

using namespace std;

int main(){

    stack<char> left, right;        //right는 역방향
    string s, input, ans;
    int count;
    char temp, trash;

    getline(cin, s);
    scanf("%d\n", &count);

    for(int i=0; i< s.size(); i++){
        left.push(s.at(i));
    }

    for(int i=0; i<count; i++){
        
        getline(cin, input);
        switch(input.at(0)){
            case 'L':
                // left에서 가장 오른쪽 글자를 right의 가장 왼쪽 글자로(push) 옮김
                // left크기가 0이면 무시
                if(left.size() != 0){
                    temp = left.top();
                    left.pop();
                    right.push(temp);
                }
                break;
            case 'D':
                // right에서 가장 왼쪽 글자를 left의 가장 오른쪽 글자로 옮김
                // right 크기가 0이면 무시
                if(right.size() != 0){
                    temp = right.top();
                    right.pop();
                    left.push(temp);
                }
                break;
            case 'B':
                // left에서 가장 오른쪽 글자 삭제
                if(left.size() != 0){
                    left.pop();
                }
                break;
            case 'P':
                //left의 가장 오른쪽에 글자 push
                temp = input.at(2);
                left.push(temp);
                break;
        }
        
    }
    
    while(left.size() != 0){
        ans += left.top();
        left.pop();
    }

    if(ans.size() > 1){
        reverse(ans.begin(), ans.end());
    }
    

    while(right.size() != 0){
        ans += right.top();
        right.pop();
    }

    cout << ans << endl;

    return 0;
}