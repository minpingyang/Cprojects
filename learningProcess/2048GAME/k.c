#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include "k.h"


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
		printf("\n\nscore: %d\n",game.score);
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
		  printf("+\n\n");
	
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
	
	if(isMove){
		//move right most
		if(dx == 1)
		{

			//move everything to right
			int i,j,b,count;
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

		else if(dx == -1){
		
		}
		//move up
		else if(dy == -1){
			
		}
		//move down
		else if(dy == 1){
			
		}

	}
	return false;
	
}



