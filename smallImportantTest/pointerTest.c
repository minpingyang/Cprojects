#include <stdio.h>

int main()

{
	int q = 70;
	int p = 65;  
	//int *ptrp, *ptrq;
	//pointer to store adress 
	int *ptrp = &p;   //65
	int *ptrq = &q;  //70
	printf("*ptrp=%d; *ptrq=%d \n",*ptrp,*ptrq);
	printf("p=%d; q=%d \n",p,q);   
	//ptep --> 
	//70
	ptrp = &q;  //70
	ptrq = &p;	//65
// value of p and q does not change
    //65 65
	printf("*ptrp=%d; *ptrq=%d \n",*ptrp,*ptrq);
	printf("p=%d; q=%d \n",p,q);
	//printf("p=%d; q=%d ; \n",p,q);

	*ptrp = p;
	*ptrq = q;
	printf("*ptrp=%d; *ptrq=%d \n",*ptrp,*ptrq);
	printf("p=%d; q=%d \n",p,q);
}
//test summary:
//ptrp = &p      change together,both them point to same value
//once p store different valueA,then *ptrp will store diffrent valueA
//once *ptrp store different valueA,then p will store diffrent valueA
//if it print *ptrq
//int * 