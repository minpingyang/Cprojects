#include <stdbool.h>

struct game {
	// game board
	char board[4][4];
	// current score
	int score;
};
/***save game state***/
void saveGame(const struct game current_game);
/***load previous game file**********/
void loadGame(struct game *game);
//check if the board has any space avaiable;
bool is_Space(const struct game current_game);
/**
compare two struct 
*/
bool compareBoard(const struct game copy_game, const struct game current_game);


/**
 * Adds random A or B tile to the game
 * This is very dumb function. The board must have at least one empty tile. If 
 * there is no empty tile, function will end in infinite loop.
 * @param game reference to the game object
 */
void add_random_tile(struct game *game);


/**
 * Renders the game
 * @param game the game object with board and score to render
 */
void render(const struct game game);


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
bool update(struct game *game, int dy, int dx);


/**
 * Checks whether it is possible to make move
 * Function checks game board if it is possible to make another move. The
 * move is possible, if there are two tiles with the same letter nearby or
 * there is at least one empty tile.
 * @param game the game object with board to check
 * @return true, if another movement is possible, or false otherwise.
 */
bool is_move_possible(const struct game game);


/**
 * Checks whether game is already won
 * Returns true, if tile with letter 'K' is located on the board. Returns
 * false, if it is not.
 * @param game the game object with board to check
 * @return true, if game is won, or false otherwise.
 */
bool is_game_won(const struct game game);
