#include <cstdio>
#include <string.h>

using namespace std;

int main(){
    char input[20];
    int numOfCmd, s=0;
    
    scanf("%d", &numOfCmd);

    while(numOfCmd--){
        
        scanf("%s", input);

        // 인자 필요없는 커맨드
        if(strcmp(input, "all") == 0){
            s = ((1 << 20) - 1);
            continue;
        }else if(strcmp(input, "empty") == 0){
            s = 0;
            continue;
        }
        int param;
        scanf("%d", &param);
        
        param -= 1;
        if(strcmp(input, "add") == 0){
            s = (s | (1 << param));
        }else if(strcmp(input, "remove") == 0){
            s = (s & ~(1 << param));
        }else if(strcmp(input, "check") == 0){
            bool check = (s & (1 << param));
            if(check) printf("1\n");
            else printf("0\n");
        }else if(strcmp(input, "toggle") == 0){
            s = (s ^ (1 << param));
        }
    }
}