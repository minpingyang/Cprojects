#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

void printStr(char*(*ptr), int n){
	int i=0;
	for(;i<n;i++){
		printf("%s\n",*(ptr++));
	}
}

int main()
{
    char* a[] = {"AAA","BBB","CCC"};
    int n = sizeof(a)/sizeof(char*);
    char*(*ptr);
    ptr = &a;
    printStr(ptr,n);
    return 0;
}

