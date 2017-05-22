#include <stdio.h>
#include "menue.h"
#include "guessNumber.h"
#include "k.h"
#include "tictactoe.h"


int main(){
	char answer = ' '; // user input
	int count = 0; // count how many times the user inputs
	//welcome note 
	printf("\n------>>>>Welcome to the menue of games<<<<<---------\n");
 	
    return 0;
}

void mainMenue(){

	printf("instruction: run the game depending on the single character\n");
 	printf(" 'q'  ----quite the game \n");
 	
 	printf("Enter: \n");
  	//quit or run game

  	do{
  		count = 0;
  		answer = getchar();
  		while(getchar() != '\n'){count++;}
  		if((answer != 'q' && answer != 's') || count>0){
  			printf("re-Enter a valid character: \n");
  		}

  	}while((answer != 'q' && answer != 's') || count>0);
  	

	  // quite the game case.
	 if(answer == 'q' || answer == 'Q'){
	 	return 0;
	 }//step into game
	 //choose which game you want to run.
	 else if(answer == 's'){
	 	printf("'1' -----run guess number game\n");
	 	printf("'2' -----run tic-tac-toe  game\n");
	 	printf("'3' -----run K            game\n");
	 	//chose a game
	 	do{
	  		count = 0;
	  		answer = getchar();
	  		while(getchar() != '\n'){count++;}
	  		if((answer != '1' && answer != '2' &&answer != '3') || count>0){
	  			printf("re-Enter a valid character: \n");
	  		}

  		}while((answer != '1' && answer != '2' &&answer != '3')|| count>0);
  	
  		//run guess number game
  		if(answer == '1'){
  			menueGuessGame();
  		}else if(answer == '2'){
  			runTicTacToe();
  		}else if(answer == '3'){
  			runKgame();
  		}

	 }
}


int menueGuessGame(){
	int count = 0;
	char answer = ' ';
		printf("'s' -----start run guess number game\n");
	 	printf("'m' -----back  to the menue\n");
	 	//chose a run/back to menue
		do{
	  		count = 0;
	  		answer = getchar();
	  		while(getchar() != '\n'){count++;}
	  		if((answer != 's' && answer != 'm') || count>0){
	  			printf("re-Enter a valid character: \n");
	  		}

  		}while((answer != 's' && answer != 'm')|| count>0);
  	
		if(answer == 's'){
			runGuess();
  		}else if(answer == 'm'){
  			 mainMenue();
  		}

  	return 0;
}


