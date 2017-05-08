#include <stdio.h>
#include "k.h"

int main(){
	
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
    
    add_random_tile(ptr_game);
    render(current_game);
        
    return 0;
}
