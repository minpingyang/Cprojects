#include <stdio.h>
int strcmp1(char*, char*);


int main()
{
    char s1[] = "11112222";
    char s2[] = "11112223";
    int i = strcmp2(s1,s2);
    printf("%d\n",i);
   
}
int strcmp1(char*s1, char*s2){
    int i=0;
    for(;s1[i]==s2[i];i++){
        if(s1[i] == '\0'){
            return 0;
        }
    }
    return s1[i]-s2[i];
}

int strcmp2(char*s1, char*s2){
    for(;*s1 == *s2;s1++,s2++){
        if(*s1 =='\0'){
            return 0;
        }
    }
    return *s1 - *s2;
}
