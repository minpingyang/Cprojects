#include <stdio.h>
// #include "k.h"

int main(){
	char answer =' '; // user input to slide titles;
	//welcome note 
	printf("\n------>>>>Welcome to the menue of games<<<<<---------\n");
 	printf("instruction: run the game by inputing a single character\n");
 	printf(" 'q'  ----quite the game \n");

 	printf("Now, continue game to input (w,a,s,d) below to slide titles\n");
	 do {
	      answer = getchar();	      
	   } while(answer != 'q' && answer != 'Q'&& answer != 'a'&& answer !='A'
	   		&&answer != 's' && answer != 'S'&& answer != 'd'&& answer !='D'
	   		&&answer != '1' && answer != '2');

	  // quite the game case.
	 if(answer == 'q' && answer == 'Q'){
	 	return 0;
	 }


    return 0;
}


