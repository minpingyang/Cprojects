#include <stdio.h>
#include "k.h"

int main(){
	char answer =' '; // user input to slide titles;
	bool isContent_Changed = false;
	bool isSpace = true;
	bool doesUpdate=false;// does board updated ----> if it is, then render board again
	bool doesWin = false;
    struct game current_game;
    struct game beforeMove_game;
    struct game* ptr_game = &current_game; //create a pointer to point to game struct
    int i, j;
    //initial board
    for(i=0; i<4; i++){
    	for(j=0; j<4; j++){
    		
    		
    		ptr_game->board[i][j] = ' ';
    	}
    }
    // initial score
    ptr_game->score = 0;
    bool does_Move = is_move_possible(current_game);// check if it is possible to move 
    //Show intructions of the game
    //(i.e. what character user should input to slide tiles )
    //(w,a,s,d)--> up,left,down,right, respectively
    printf("\n------>>>>Game intructions<<<<<---------\nPlayer inputs a single (w,a,s,d) character to move up,left,down,right, respectively\ninput (1 or 2 )for saving and loading game respectively\n\n");

    printf("\nStart Game:\n");
    printf("Firtly, add a random character in board\n");
    //if it is possible to move further, then generate a random number into board
    bool moveNotChanged = false;
    add_random_tile(ptr_game);
	render(current_game);

    while(does_Move){
      if (!moveNotChanged&& answer == 'N')
      {
	      //if it is possible to move further, then generate a random number into board
	      printf("\nPossible to move by input direction, so add an random title\n");
	      add_random_tile(ptr_game);
	      render(current_game);
      }
      


      beforeMove_game = current_game;
	 
	  printf("Now, continue game to input (w,a,s,d) below to slide titles\n");
	    do {
	      answer = getchar();
	      
	   } while(answer != 'w' && answer != 'W'&& answer != 'a'&& answer !='A'
	   		&&answer != 's' && answer != 'S'&& answer != 'd'&& answer !='D'
	   		&&answer != '1' && answer != '2'
	   		);
	    
	    //update the board(i.e. slide title),according to input character
	    //left -> (0,-1)  right->(0,1) up ->(-1,0)  down(1,0)
	   	//right
	   	if(answer == 'd'|| answer == 'D'){
	   		 printf("\nMove titles to right\n");
	   	   doesUpdate = update(ptr_game,0,1);
	   	   answer = 'N'; // allow to add random
	   	}
	   	//left
	   	else if(answer == 'a'|| answer == 'A'){
	   	   printf("\nMove titles to left\n");
	   	   doesUpdate = update(ptr_game,0,-1);
	   	   answer = 'N'; // allow to add random
	   	}
	   	//down
	   	else if(answer == 's'|| answer == 'S'){
	   		 printf("\nMove titles to bottom\n");
	   	   doesUpdate = update(ptr_game,1,0);
	   	   answer = 'N'; // allow to add random
	   	}
	    //up
	   	else if(answer == 'w'|| answer == 'W'){
	   		 printf("\nMove titles to top\n");
	   	   doesUpdate = update(ptr_game,-1,0);
	   	   answer = 'N'; // allow to add random
	   	}
	   	else if(answer == '1'){
	   	   printf("\nSave current game state...............\n");
	   	   saveGame(current_game);
	   	   answer = 'm'; // allow to add random
	   	}
	   	else if(answer == '2'){
	   	   printf("\nLoading privous game state...............\n");
	   	   loadGame(ptr_game);
	   	   answer = 'm'; // allow to add random
	   	}

	   	does_Move = is_move_possible(current_game); // check if it is possible to move
	   	doesWin  = is_game_won(current_game);
	   	if(doesWin){
	   		printf("You win!\n");
	   		return 0;
	   	} 


	   	//create a flag to check if the content of update changed after moving
	   	isContent_Changed = compareBoard(beforeMove_game, current_game);
	   	isSpace = is_Space(current_game);
	   	//if update successfully, 
	   	// move is possible
	   	//content of board is changed
	   	//then render board again
	    if (doesUpdate && does_Move && isContent_Changed)
	    {
	    	moveNotChanged = false;	
	    	render(current_game);
	    }
	    //if it is possbile to move, and content of board is not changed
	    else if (does_Move && !isContent_Changed)
	    {	
	    	
		    	moveNotChanged = true;
		    	printf("You should changed to other direction to move titles\n");	
	    	
	    	
	    }
    }
    
	printf("GAME OVER!\n");

    return 0;
}


