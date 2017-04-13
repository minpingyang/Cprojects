#include <stdio.h>

int main()

{

	int s = 65;  //65
	int* t = &s; 
//POINTER (P80,O79,I73,N78,T84,E69,R82)
	char c = 'I'; //73 
	char N = s + 'P' - 'A';  //65 + 80 -65 = 80 P
	char B = *t - s + N + 2;    //65 -65 +'P' +2 = 82 R
	char E = &s - t + 78; //78 N
	char J = *t + 19;   //65 +19 = 84 T
	char I = N + 'A' - s - 1; //80 +65 - 65 -1 =79 O
	char O = 347/5;  //69 E

	printf("%c%c%c%c%c%c%c\n",N,I,c,E,J,O,B);
	// TODO – here you do the magic
}

