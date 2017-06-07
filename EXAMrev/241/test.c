#include <stdio.h>

int main()
{
    int a[4] = {11,41,22,73};
    
    int *pj;
    int i = 0;
    for(pj = a; pj < a+4; pj++){
        
        (*pj)++;
        printf("%d\n",*pj);
        
    }

    return 0;
}
