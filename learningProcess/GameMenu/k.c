#include "k.h"



void saveKGame(const struct game current_game){
	char ch; // declare a charcter to write a character to a file
	FILE * fp; // pointer to data type File
	fp = fopen ("savedGame.txt", "w"); // create and open a writable txt file to save data of game
	int i,j;
	
    // store all characters after first line
    for(i = 0; i <4; i++ )
    {
        for(j= 0; j < 4; j++)
        {
            ch = current_game.board[i][j];
            putc(ch,fp);
        }
    }
    //finally, write the score 
    fprintf(fp, "%d",current_game.score);

	fclose(fp); // close file
	printf("saved current game state to savedGame.txt\n");
}


void loadGame(struct game *game){
	FILE *fptr;
	int score; 
	// open
	fptr = fopen ("savedGame.txt", "r") ;
	
	if (fptr == NULL) { 
		printf ("File open failed.\n"); 
		return;
	}


	//change all character of current board
	int i,j;
    for(i = 0; i <4; i++ )
    {
        for(j= 0; j < 4; j++)
        {
            game->board[i][j] = fgetc(fptr);
        }
    }

	fscanf(fptr, "%d", &score);
	game->score = score;

	fclose(fptr); // close file
}

bool is_Space(const struct game current_game){
  int i,j;
    for(i = 0; i <4; i++ )
    {
        for(j= 0; j < 4; j++)
        {
            if(current_game.board[i][j] == ' ')
            {
                return true;
            }
            
        }
    }
    return false;
}

bool compareBoard(const struct game copy_game, const struct game current_game){
	if(copy_game.score != current_game.score){
		return true;
	}
	int i,j;
    for(i = 0; i <4; i++ )
    {
        for(j= 0; j < 4; j++)
        {
            if(current_game.board[i][j] != copy_game.board[i][j])
            {
                return true;
            }
            
        }
    }
    return false;
}



/**
 * Adds random A or B tile to the game
 * This is very dumb function. The board must have at least one empty tile. 
 * If there is no empty tile, function will end in infinite loop.
 * @param game reference to the game object
 */
void add_random_tile(struct game *game){
	int row, col;
	
	// find random, but empty tile
	do{
		row = rand() % 4;
		col = rand() % 4;
	}while(game->board[row][col] != ' ');

	// place to the random position 'A' or 'B' tile
	int tile = 'A' + (rand() % 2);
	game->board[row][col] = tile;
}

/**
 * Renders the game
 * @param game the game object with board and score to render
 */
void render(const struct game game){

		int row=0, col= 0;
		int size = 4; //board size
		//print out the score
		printf("score: %d\n",game.score);
		//draw one row of board throught the loop, line by line 
		while (row < size){
		    
		    
		    
		     // draw "+-"
		    col = 0;
		    while(col < size){
		     printf("+-");
		     col++;
		    }
		    printf("+\n");
		    
		    /******above code is used to draw top line**************/
		   	col = 0; //reset index
		    // draw first row 
		    while(col < size){
		     
		     printf("|%c",game.board[row][col]);
		     col++;
		    }    
		    printf("|\n");
		    row++;
		}
		//draw the bottom edege of the board
		 
		  col = 0;  
		  //draw "+-" 
		  while(col < size){
		   printf("+-");
		   col++;
		  }
		  printf("+\n");
	
}
/**
 * Checks whether it is possible to make move
 * Function checks game board if it is possible to make another move. The
 * move is possible, if there are two tiles with the same letter nearby or
 * there is at least one empty tile.
 * @param game the game object with board to check
 * @return true, if another movement is possible, or false otherwise.
 */
bool is_move_possible(const struct game game){
    
    int i, j;
    for(i = 0; i <4; i++ ){
        for(j= 0; j < 4; j++){
            //check two adjacent tiles same kind horizontally
            if(j<3){
                if(game.board[i][j] == game.board[i][j+1] && game.board[i][j] != ' '){
                    return true;
                }
            }
            //check two adjacent tiles same kind vertically
            if(i<3){
                if(game.board[i][j] == game.board[i+1][j]&&game.board[i][j] != ' '){
                    return true;
                }
            }
            
            // check if there is at least one empty field
            if(game.board[i][j] == ' '){
                return true;
            }
            
            
        }
    }
    return false;
}
/**
 * Checks whether game is already won
 * Returns true, if tile with letter 'K' is located on the board. Returns
 * false, if it is not.
 * @param game the game object with board to check
 * @return true, if game is won, or false otherwise.
 */
bool is_game_won(const struct game game)
{
    

    //check if there is a character on the board
    int i,j;
    for(i = 0; i <4; i++ )
    {
        for(j= 0; j < 4; j++)
        {
            if(game.board[i][j] == 'K')
            {
                return true;
            }
            
        }
    }
    return false;
}
/**
 * Makes move in given direction
 * If it is possible, function makes move in given direction, updates the 
 * current game state (board and score) and returns true. If it is not 
 * possible to move, returns false.
 * @param game reference to the game object
 * @param dy movement in y-axe
 * @param dx movement in x-axe
 * @return true, if game state was updated, false otherwise
 */
bool update(struct game* game, int dy, int dx)
{
	//no direction
	//more than one direction
	if( (dy == 0 && dx == 0) || ( dy != 0 && dx != 0)){
		return false;
	}
	//check if possible to move
	//???
	bool isMove = is_move_possible(*game);
	int i,j,b,count; // index

	if(isMove){
		//move right most
		if(dx == 1){

			//move everything to right
			
            for(i = 0; i <4; i++ ){
				for(j= 0, count =0; j < 4 && count < 4; j++, count++ ){

					//go through form right to left
					//if there is a space, then move everything right by one step
					if(game -> board[i][3-j] == ' '){
							// there is a space now
							b = j;
							while(b<3){
								game ->board[i][3-b] = game ->board[i][2-b];
								b++;
							}
							//current left most tile should be empty	
							game ->board[i][0] = ' ';
							j--;

					}
					
				}
			}
			//merge
			//check from right to left
			
			for(i = 0; i <4; i++ )
			{
				for(j= 3; j > 0; j--)
				{
						//check from right to left					
							if(game ->board[i][j] == game ->board[i][j-1] && game ->board[i][j] != ' '  )
							{
								
								if(game ->board[i][j] == 'A'){
									game ->board[i][j] = 'B';
									game ->board[i][j-1] = ' ';
									j--;	
									game ->score += 2;
								}else if(game ->board[i][j] == 'B') {
									game ->board[i][j] = 'C';
									game ->board[i][j-1] = ' ';
									j--;	
									game ->score += 4;								
								}else if(game ->board[i][j] == 'C') {
									game ->board[i][j] = 'D';
									game ->board[i][j-1] = ' ';
									j--;
									game ->score += 8;									
								}else if(game ->board[i][j] == 'D') {
									game ->board[i][j] = 'E';
									game ->board[i][j-1] = ' ';
									j--;
									game ->score += 16;									
								}else if(game ->board[i][j] == 'E') {
									game ->board[i][j] = 'F';
									game ->board[i][j-1] = ' ';
									j--;
									game ->score += 32;										
								}else if(game ->board[i][j] == 'F') {
									game ->board[i][j] = 'G';
									game ->board[i][j-1] = ' ';
									j--;
									game ->score += 64;										
								}else if(game ->board[i][j] == 'G') {
									game ->board[i][j] = 'H';
									game ->board[i][j-1] = ' ';
									j--;
									game ->score += 128;										
								}else if(game ->board[i][j] == 'H') {
									game ->board[i][j] = 'I';
									game ->board[i][j-1] = ' ';
									j--;
									game ->score += 256;										
								}else if(game ->board[i][j] == 'I') {
									game ->board[i][j] = 'J';
									game ->board[i][j-1] = ' ';
									j--;
									game ->score += 512;										
								}else if(game ->board[i][j] == 'J') {
									game ->board[i][j] = 'K';
									game ->board[i][j-1] = ' ';
									j--;
									game ->score += 1024;										
								}

								game ->board[i][j] = ' ';
							}
										
				}

			}
			//move everything to right again
            for(i = 0; i <4; i++ ){
				for(j= 0, count =0; j < 4 && count < 4; j++, count++ ){

					//go through form right to left
					//if there is a space, then move everything right by one step
					if(game -> board[i][3-j] == ' '){
							// there is a space now
							b = j;
							while(b<3){
								game ->board[i][3-b] = game ->board[i][2-b];
								b++;
							}
							//current left most tile should be empty	
							game ->board[i][0] = ' ';
							j--;

					}
					
				}
			}
			return true;
		}
/******move left *************/
		else if(dx == -1){
			//move everything to left
            for(i = 0; i <4; i++ ){
				for(j= 0, count =0; j < 4 && count < 4; j++, count++ ){

					//go through form left to right
					//if there is a space, then move everything left by one step
					if(game -> board[i][j] == ' '){
							// there is a space now
							b = j;
							while(b<3){
								game ->board[i][b] = game ->board[i][b+1];
								b++;
							}
							//current right most tile should be empty	
							game ->board[i][3] = ' ';
							j--;

					}
					
				}
			}
			//merge
			//check from left to right
			
			for(i = 0; i <4; i++ )
			{
				for(j= 0; j < 3; j++)
				{
						//check from left to right					
							if(game ->board[i][j] == game ->board[i][j+1] && game ->board[i][j] != ' '  )
							{
								
								if(game ->board[i][j] == 'A'){
									game ->board[i][j] = 'B';
									game ->board[i][j+1] = ' ';
									j++;	
									game ->score += 2;
								}else if(game ->board[i][j] == 'B') {
									game ->board[i][j] = 'C';
									game ->board[i][j+1] = ' ';
									j++;	
									game ->score += 4;								
								}else if(game ->board[i][j] == 'C') {
									game ->board[i][j] = 'D';
									game ->board[i][j+1] = ' ';
									j++;
									game ->score += 8;									
								}else if(game ->board[i][j] == 'D') {
									game ->board[i][j] = 'E';
									game ->board[i][j+1] = ' ';
									j++;
									game ->score += 16;									
								}else if(game ->board[i][j] == 'E') {
									game ->board[i][j] = 'F';
									game ->board[i][j+1] = ' ';
									j++;
									game ->score += 32;										
								}else if(game ->board[i][j] == 'F') {
									game ->board[i][j] = 'G';
									game ->board[i][j+1] = ' ';
									j++;
									game ->score += 64;										
								}else if(game ->board[i][j] == 'G') {
									game ->board[i][j] = 'H';
									game ->board[i][j+1] = ' ';
									j++;
									game ->score += 128;										
								}else if(game ->board[i][j] == 'H') {
									game ->board[i][j] = 'I';
									game ->board[i][j+1] = ' ';
									j++;
									game ->score += 256;										
								}else if(game ->board[i][j] == 'I') {
									game ->board[i][j] = 'J';
									game ->board[i][j+1] = ' ';
									j++;
									game ->score += 512;										
								}else if(game ->board[i][j] == 'J') {
									game ->board[i][j] = 'K';
									game ->board[i][j+1] = ' ';
									j++;
									game ->score += 1024;										
								}
								//from left to right, the second one is changed to space
								game ->board[i][j] = ' ';
							}
										
				}

			}
			//move everything to left again
             for(i = 0; i <4; i++ ){
				for(j= 0, count =0; j < 4 && count < 4; j++, count++ ){

					//go through form left to right
					//if there is a space, then move everything left by one step
					if(game -> board[i][j] == ' '){
							// there is a space now
							b = j;
							while(b<3){
								game ->board[i][b] = game ->board[i][b+1];
								b++;
							}
							//current right most tile should be empty	
							game ->board[i][3] = ' ';
							j--;

					}
					
				}
			}
			return true;


		
		}
/*******move up***/
		else if(dy == -1){
			//move everything to top (similarly, move left)
            for(i = 0; i <4; i++ ){
				for(j= 0, count =0; j < 4 && count < 4; j++, count++ ){

					//go through form top to bottom
					//if there is a space, then move everything top by one step
					if(game -> board[j][i] == ' '){
							// there is a space now
							b = j;
							while(b<3){
								game ->board[b][i] = game ->board[b+1][i];
								b++;
							}
							//current bottom most tile should be empty	
							game ->board[3][i] = ' ';
							j--;

					}
					
				}
			}
			//merge
			//check from top to bottom
			
			for(i = 0; i <4; i++ )
			{
				for(j= 0; j < 3; j++)
				{
						//check from top to bottom					
							if(game ->board[j][i] == game ->board[j+1][i] && game ->board[j][i] != ' '  )
							{
								
								if(game ->board[j][i] == 'A'){
									game ->board[j][i] = 'B';
									game ->board[j+1][i] = ' ';
									j++;	
									game ->score += 2;
								}else if(game ->board[j][i] == 'B') {
									game ->board[j][i] = 'C';
									game ->board[j+1][i] = ' ';
									j++;	
									game ->score += 4;								
								}else if(game ->board[j][i] == 'C') {
									game ->board[j][i] = 'D';
									game ->board[j+1][i] = ' ';
									j++;
									game ->score += 8;									
								}else if(game ->board[j][i] == 'D') {
									game ->board[j][i] = 'E';
									game ->board[j+1][i] = ' ';
									j++;
									game ->score += 16;									
								}else if(game ->board[j][i] == 'E') {
									game ->board[j][i] = 'F';
									game ->board[j+1][i] = ' ';
									j++;
									game ->score += 32;										
								}else if(game ->board[j][i] == 'F') {
									game ->board[j][i] = 'G';
									game ->board[j+1][i] = ' ';
									j++;
									game ->score += 64;										
								}else if(game ->board[j][i] == 'G') {
									game ->board[j][i] = 'H';
									game ->board[j+1][i] = ' ';
									j++;
									game ->score += 128;										
								}else if(game ->board[j][i] == 'H') {
									game ->board[j][i] = 'I';
									game ->board[j+1][i] = ' ';
									j++;
									game ->score += 256;										
								}else if(game ->board[j][i] == 'I') {
									game ->board[j][i] = 'J';
									game ->board[j+1][i] = ' ';
									j++;
									game ->score += 512;										
								}else if(game ->board[j][i] == 'J') {
									game ->board[j][i] = 'K';
									game ->board[j+1][i] = ' ';
									j++;
									game ->score += 1024;										
								}
								//from top to bottom, the second one is changed to space
								game ->board[j][i] = ' ';
							}
										
				}

			}
			//move everything to top again(similarly, move left)
            for(i = 0; i <4; i++ ){
				for(j= 0, count =0; j < 4 && count < 4; j++, count++ ){

					//go through form top to bottom
					//if there is a space, then move everything top by one step
					if(game -> board[j][i] == ' '){
							// there is a space now
							b = j;
							while(b<3){
								game ->board[b][i] = game ->board[b+1][i];
								b++;
							}
							//current bottom most tile should be empty	
							game ->board[3][i] = ' ';
							j--;

					}
					
				}
			}
			return true;
		}
//move down most
		else if(dy == 1)
		{
			//move everything to down(similarly, move right)
			
            for(i = 0; i <4; i++ ){
				for(j= 0, count =0; j < 4 && count < 4; j++, count++ ){

					//go through form top to bottom
					//if there is a space, then move everything down by one step
					if(game -> board[3-j][i] == ' '){
							// there is a space now
							b = j;
							while(b<3){
								game ->board[3-b][i] = game ->board[2-b][i];
								b++;
							}
							//current top most tile should be empty	
							game ->board[0][i] = ' ';
							j--;

					}
					
				}
			}
			//merge
			//check from top to right
			
			for(i = 0; i <4; i++ )
			{
				for(j= 3; j > 0; j--)
				{
						//check from top to bottom				
							if(game ->board[j][i] == game ->board[j-1][i] && game ->board[j][i] != ' '  )
							{
								
								if(game ->board[j][i] == 'A'){
									game ->board[j][i] = 'B';
									game ->board[j-1][i] = ' ';
									j--;	
									game ->score += 2;
								}else if(game ->board[j][i] == 'B') {
									game ->board[j][i] = 'C';
									game ->board[j-1][i] = ' ';
									j--;	
									game ->score += 4;								
								}else if(game ->board[j][i] == 'C') {
									game ->board[j][i] = 'D';
									game ->board[j-1][i] = ' ';
									j--;
									game ->score += 8;									
								}else if(game ->board[j][i] == 'D') {
									game ->board[j][i] = 'E';
									game ->board[j-1][i] = ' ';
									j--;
									game ->score += 16;									
								}else if(game ->board[j][i] == 'E') {
									game ->board[j][i] = 'F';
									game ->board[j-1][i] = ' ';
									j--;
									game ->score += 32;										
								}else if(game ->board[j][i] == 'F') {
									game ->board[j][i] = 'G';
									game ->board[j-1][i] = ' ';
									j--;
									game ->score += 64;										
								}else if(game ->board[j][i] == 'G') {
									game ->board[j][i] = 'H';
									game ->board[j-1][i] = ' ';
									j--;
									game ->score += 128;										
								}else if(game ->board[j][i] == 'H') {
									game ->board[j][i] = 'I';
									game ->board[j-1][i] = ' ';
									j--;
									game ->score += 256;										
								}else if(game ->board[j][i] == 'I') {
									game ->board[j][i] = 'J';
									game ->board[j-1][i] = ' ';
									j--;
									game ->score += 512;										
								}else if(game ->board[j][i] == 'J') {
									game ->board[j][i] = 'K';
									game ->board[j-1][i] = ' ';
									j--;
									game ->score += 1024;										
								}

								game ->board[j][i] = ' ';
							}
										
				}

			}
			//move everything to down(similarly, move right)
			
            for(i = 0; i <4; i++ ){
				for(j= 0, count =0; j < 4 && count < 4; j++, count++ ){

					//go through form top to bottom
					//if there is a space, then move everything down by one step
					if(game -> board[3-j][i] == ' '){
							// there is a space now
							b = j;
							while(b<3){
								game ->board[3-b][i] = game ->board[2-b][i];
								b++;
							}
							//current top most tile should be empty	
							game ->board[0][i] = ' ';
							j--;

					}
					
				}
			}
			return true;			
		}
		

	}
	return false;
	
}

// void runK(){
// 	main();
// }

int startKgame(){
	int count =0;
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
	  
	   do{
  		count = 0;
  		answer = getchar();
  		while(getchar() != '\n'){count++;}
  		if((answer != 'w' && answer != 'W'&& answer != 'a'&& answer !='A'
	   		&&answer != 's' && answer != 'S'&& answer != 'd'&& answer !='D'
	   		&&answer != '1' && answer != '2') || count>0){
  			printf("re-Enter a valid character: \n");
  		}

  		}while((answer != 'w' && answer != 'W'&& answer != 'a'&& answer !='A'
	   		&&answer != 's' && answer != 'S'&& answer != 'd'&& answer !='D'
	   		&&answer != '1' && answer != '2') || count>0);
  	 

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
	   	   saveKGame(current_game);
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
	   		render(current_game);
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

