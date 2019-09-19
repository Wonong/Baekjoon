#include <cstdio>
#include <cstring>

using namespace std;

int main(){
    char equation[51];
    char beforeOp = '+';
    int num = 0, len, ans = 0;

    scanf("%s", equation);
    
    len = strlen(equation);

    for(int i=0; i<=len; i++){
        // 숫자인 경우
        if(equation[i] >= '0' && equation[i] <= '9'){
                num *= 10;
                num += (equation[i] - '0');
        }else{
            // 기존 숫자 처리
            if(beforeOp == '-') ans -= num;
            else ans += num;
            num = 0;

            // 연산자 처리
            if(beforeOp == '-' && equation[i] == '+') beforeOp = '-';
            else beforeOp = equation[i];
            
        }
    }

    printf("%d\n", ans);

}