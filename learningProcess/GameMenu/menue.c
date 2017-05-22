//include all external header file
#include "menue.h"
#include "guessNumber.h"
#include "k.h"
#include "tictactoe.h"


int main(){

	char answer = ' '; // user input to operate the game
	int count = 0; // used to count how many characters user input
	int exitBack = 0; // a flag used to determine if exit back to the main menue
	
	
	do{
		//welcome note 
		printf("\n------>>>>Welcome to the menue of games<<<<<---------\n");
	 	printf("instruction: run the game depending on the single character\n");
	 	printf("when you start run the game, \nthen one of stage of game will ask user to save the current state into a specific txt file\n");
	 	printf(" 'q'  ----quite the game \n");
	 	printf(" 's'  ----start select the game \n");
	 	
	 	printf("Enter: \n");
	  	//quit or run game

	 	//
	  	do{
	  		count = 0; // used to indicate user input multiple characters instead of singe char
	  		answer = getchar(); // get the first single character
	  		while(getchar() != '\n'){count++;} // clean all inputs before \n
	  		//invalid input
	  		if((answer != 'q' && answer != 's') || count>0){
	  			printf("re-Enter a valid character: \n");
	  		}

	  	}while((answer != 'q' && answer != 's') || count>0);
	  	

		  // quite the game.
		 if(answer == 'q'){
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
	  			exitBack = menueGuessGame(); // check if exit back to main menue according the return value
	  		}else if(answer == '2'){
	  			exitBack = menueTicTacToe();
	  		}else if(answer == '3'){
	  			exitBack = menueKgame();
	  		}

		 }	
	}while(exitBack);
	

    return 0;
}

int menueTicTacToe(){
	int exitBack = 0;
	do{
		int count = 0;
		char answer = ' ';
		printf("'s' -----start run guess number game\n");
	 	printf("'m' -----back to main menue\n");
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

	        printf("'s' -----start the game from beginning\n");
	        printf("'e' -----end the game\n");
	        //chose a run/back to menue
	        do{
	            count = 0;
	            answer = getchar();
	            while(getchar() != '\n'){count++;}
	            if((answer != 's' && answer != 'e') || count>0){
	              printf("re-Enter a valid character: \n");
	            }

	          }while((answer != 's' && answer != 'e')|| count>0);
	        
	        if(answer == 's'){
	              startTicTacToe(); //run the game from beginning
	          }else if(answer == 'e'){
	              exitBack = 1; // return to the menu of the game (not the main menu).
	          }

  		}else if(answer == 'm'){
  			 return 1; // return back to main menue
  		}
	}while(exitBack);
	return 0;
}

int menueKgame(){
	int exitBack = 0;
	do{
		int count = 0;
		char answer = ' ';
		printf("'s' -----start run guess number game\n");
	 	printf("'m' -----back to main menue\n");
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

	        printf("'s' -----start the game from beginning\n");
	        printf("'e' -----end the game\n");
	        //chose a run/back to menue
	        do{
	            count = 0;
	            answer = getchar();
	            while(getchar() != '\n'){count++;}
	            if((answer != 's' && answer != 'e') || count>0){
	              printf("re-Enter a valid character: \n");
	            }

	          }while((answer != 's' && answer != 'e')|| count>0);
	        
	        if(answer == 's'){
	              startKgame(); //run the game from beginning
	          }else if(answer == 'e'){
	              exitBack = 1; // return to the menu of the game (not the main menu).
	          }

  		}else if(answer == 'm'){
  			 return 1; // return back to main menue
  		}
	}while(exitBack);
	return 0;
}

int menueGuessGame(){
	int exitBack = 0;
	do{
		int count = 0;
		char answer = ' ';
		printf("'s' -----start run guess number game\n");
	 	printf("'m' -----back to main menue\n");
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

	        printf("'s' -----start the game from beginning\n");
	        printf("'e' -----end the game\n");
	        //chose a run/back to menue
	        do{
	            count = 0;
	            answer = getchar();
	            while(getchar() != '\n'){count++;}
	            if((answer != 's' && answer != 'e') || count>0){
	              printf("re-Enter a valid character: \n");
	            }

	          }while((answer != 's' && answer != 'e')|| count>0);
	        
	        if(answer == 's'){
	               startGuessGame(); //run the game from beginning
	          }else if(answer == 'e'){
	              exitBack = 1; // return to the menu of the game (not the main menu).
	          }

  		}else if(answer == 'm'){
  			 return 1; // return back to main menue
  		}
	}while(exitBack);
	

  	return 0;
}








