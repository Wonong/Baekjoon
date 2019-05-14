#include<stdio.h>
#include<stdlib.h>

int main(){
    
    char *str;
    int alphabet[26];
    int i, max, dupl, idx;

    str = (char*)malloc(sizeof(char)*1000001);
    i = 0;
    max = 0;
    for(int k=0; k<26; k++) alphabet[k] = 0;

    scanf("%s", str);

    while(str[i] != '\0'){
    	if(str[i] > 'Z') str[i] -= ('a'-'A');
    	alphabet[str[i] - 'A']++;
    	i++;
    }

    for(int j=0; j<26; j++){
    	if(max<alphabet[j]){
    		max = alphabet[j];
    		idx = j;
    		dupl = 0;
    	}else if(max == alphabet[j]) dupl = 1;
    }
    if(dupl != 1)printf("%c", 'A' + idx);
    else printf("?");

    return 0;
}