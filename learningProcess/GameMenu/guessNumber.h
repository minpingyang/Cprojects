#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void guessGame();  
int get_PCguess(const int start, const int end);
int restTime_showPCGuess(const int attempt);
int is_Ggame_won(const int secret, const int guess);
void startGuessNumberGame();