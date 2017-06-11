#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
char *(*p[3])(char**, int** );
void printStr(char*(*ptr)[], int n){
	int i=0;
	for(;i<n;i++){
		char* b[] = ptr++;
		for(;*b!='\0';b++){
			printf("%c",*b);
		}
		printf("\n");
	}
}

int main()
{
    char* a[] = {"AAA","BBB","CCC"};
    int n = sizeof(a)/sizeof(char*);
    char*(*ptr)[n];
    ptr = &a;
    printStr(ptr,n);
    printf("%d\n",n);

    return 0;
}

