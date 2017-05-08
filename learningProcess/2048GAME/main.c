#include <stdio.h>
#include "k.h"

int main(){
	
	bool doesUpdate=false;// does board updated ----> if it is, then render board again
    struct game current_game;
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
    printf("\n Game intructions:\nPlayer inputs (w,a,s,d) characters to \nslide tiles up,left,down,right, respectively\n");

    

    while(does_Move){
      //if it is possible to move further, then generate a random number into board
      add_random_tile(ptr_game);
      render(current_game);

	  char answer; // user input to slide titles;
	  printf("input (w,a,s,d) below to slide titles\n");
	    do {
	      answer = getchar();
	      
	   } while(answer != 'w' && answer != 'W'&& answer != 'a'&& answer !='A'
	   		&&answer != 's' && answer != 'S'&& answer != 'd'&& answer !='D');
	    
	    //update the board(i.e. slide title),according to input character
	    //left -> (0,-1)  right->(0,1) up ->(-1,0)  down(1,0)
	   	//right
	   	if(answer == 'd'|| answer == 'D'){
	   	   doesUpdate = update(ptr_game,0,1);
	   	}
	   	//left
	   	else if(answer == 'a'|| answer == 'A'){
	   	   doesUpdate = update(ptr_game,0,-1);
	   	}
	   	
	   	//if update successfully, then render board again
	    if (doesUpdate)
	    {
	    	
	    	render(current_game);
	    }

	    does_Move = is_move_possible(current_game);


    }
	



    return 0;
}



   //  //add random A/B in board then render board
   //  add_random_tile(ptr_game);
   //  render(current_game);
   //  //read user input character
   //  char answer; // user input to slide titles;
   //  printf("input (w,a,s,d) below to slide titles\n");
   //  do {
   //    answer = getchar();
      
   // } while(answer != 'w' && answer != 'W'&& answer != 'a'&& answer !='A'
   // 		&&answer != 's' && answer != 'S'&& answer != 'd'&& answer !='D');
    
   //  //update the board(i.e. slide title),according to input character
   //  //left -> (0,-1)  right->(0,1) up ->(-1,0)  down(1,0)
   	
   // 	if(answer == 'd'|| answer == 'D'){
   // 	   doesUpdate = update(ptr_game,0,1);
   // 	}
   	
   // 	//if update successfully, then render board again
   //  if (doesUpdate)
   //  {
   //  	render(current_game);
   //  }