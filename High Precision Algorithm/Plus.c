#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *Reverse(char *num){
    int len=strlen(num);
    char *re=(char *)malloc(len + 1);
    if(!re){
        return NULL;
    }

    int j = 0;
    for(int i = len-1; i >= 0; i--){
        if(num[i] == '.'){
            int pos = i;
            continue;
        }
        re[j++] = num[i];
    }
    re[j] = '\0';
    return re;
}

int main(){
    char num[]="3.1415926";

    char *re = Reverse(num);

    free(re);
    return 0;
}
