#include <stdio.h>

int main()

{
	int q = 70;
	int p = 65;  
	int *ptrp, *ptrq;
	//pointer to store adress 

	//ptep --> 
	ptrp = &p;  //65
	ptrq = &q;	//70
	printf("*ptrp=%d; *ptrq=%d \n",*ptrp,*ptrq);
	printf("p=%d; q=%d ; \n",p,q);
	int temp; 
	temp = p;   //65--meemory addre to temp 
	// printf("p=%d; q=%d ; temp=%d\n",p,q,temp);
	//*ptrp ---> 70now   65usedto
	*ptrp = q;   //70
	//q-->70 ====> *ptrq--->70
	//*ptrp--70 ===> p ---->70
	//*ptrp --> 65now   70usedto
	*ptrq = p;   //
	printf("*ptrp=%d; *ptrq=%d \n",*ptrp,*ptrq);
	printf("p=%d; q=%d ; \n",p,q);
	// printf("p=%d; q=%d ; temp=%d\n",p,q,temp);
	// TODO – here you do the magic
}
//test summary:
//ptrp = &p      change together,both them point to same value
//once p store different valueA,then *ptrp will store diffrent valueA
//once *ptrp store different valueA,then p will store diffrent valueA
//if it print *ptrq