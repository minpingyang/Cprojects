#include <stdio.h>

// TODO – here you implement your swap function  
void swap_ptr(int **ppp, int **ppq,int p,int q);

int main(void)

{
	int p = 11, q = 22; 
	int *ptrp = &p, *ptrq = &q;
	int **ppp = &ptrp, **ppq = &ptrq;

	printf("Before: %d %d\n", p, q);

	swap_ptr(ppp,ppq,p,q); /* &ptrp, &ptrq passed */

	printf("After:  %d %d\n", p, q);
}

void swap_ptr(int **ppp, int **ppq,int p,int q){
	int temp = p; 	//====>temp --->11
	**ppp = q; //====> **ppp--> 22, *ptrp--->22, p--->22
	**ppq = temp;
}