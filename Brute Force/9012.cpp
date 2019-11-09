#include <cstdio>
#include <stack>
#include <string>
#include <iostream>

using namespace std;

int main(){
    int t;

    scanf("%d", &t);
    getchar();

    for(int i=0; i<t; i++){
        stack<char> s;
        string temp;
        int len;

        getline(cin, temp);
        len = temp.size();
        for(int i=0; i<len; i++){
            if(temp[i] == '('){
                s.push(temp[i]);
            }else{
                if(s.size() == 0){
                    s.push(temp[i]);
                    break;
                }else{
                    s.pop();
                }
            }
        }
        if(s.size() == 0) printf("YES\n");
        else printf("NO\n");
    }
}