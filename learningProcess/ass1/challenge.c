#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define START 1
#define END 100
#define ATTEMPTS 5

void guessGame();   //declare functions first
int get_PCguess(const int start, const int end);
int restTime_showPCGuess(const int attempt);
int is_game_won(const int secret, const int guess);


int PCguessNum;
int max; //**used
int start;
int end;


int main(){
    
    guessGame();
    return 0;
}


void guessGame(){

 printf("Pick a integer between 1 and 100. Let PC guess (5 times Maximum Attempts!) \n");
   int number_typedIn = 1;
   PCguessNum = get_PCguess(START,END);
    start = 1;
   end = 100;  // initial interval 
   max = ATTEMPTS;
   int guessTimesLeft = 0;
   int guessFailed = 1;
   int restart = 1;
   char answer;
   scanf("%d",&number_typedIn);      // user types in a number
   
   while (max>0) {      
      PCguessNum = get_PCguess(start,end);  // PC guess a number
      guessTimesLeft = restTime_showPCGuess(max); // show what PC guess and number of remaining opportunities 
      guessFailed = is_game_won(number_typedIn,PCguessNum); // check if pc failed    
      guessFailed = is_game_won(number_typedIn,PCguessNum);
      if(PCguessNum == number_typedIn){
          break;  
      }
	      
    }
    //case1: guess failed
    if (guessFailed) {
        printf("Game Over. My number was %d\n",number_typedIn);
    }
    //case2: restart
    getchar();    //eat a    "\n" of input buffer   
    printf("Play agian?(y/n)?");
    answer = getchar();
    if(answer == 78 || answer == 110){
        printf("Bye Bye!! \n");
        return;
    }else if(answer == 89 || answer == 121){
        guessGame();
    }else{
        printf("\nonly options Y/y/N/n can be recognised\n");
	      printf("\n you shoud run the program again\n");
    }
  

}
//good
int get_PCguess(const int start, const int end){
  
    srand(time(NULL));
    
    int randomNumber = (rand()%end)+start;
    return randomNumber;
}



int is_game_won(const int secret, const int guess){
    char userHelp;
   //case1  : GUESS SUCCESS
       if(secret == guess){
            printf("Congradulations! Your PC are so lucky! \n");
            return 0;
            
        }
   //CASE2 : FAILED   
    userHelp = getchar();
   
    if(userHelp == 76 || userHelp == 108){
        printf("my number is lower, maybe try again \n");   //L &L
        end = PCguessNum;
        
    }else if(userHelp == 72 || userHelp == 104){
        printf("my number is higher, maybe try again \n");   //H &h
        start = PCguessNum;
    }
     return 1;
  
}


int restTime_showPCGuess(const int attempt){
  int restTimes = 6-attempt;
  printf("PC guess: \"%d\"\n",PCguessNum);
  printf("Times of guesses PC has so far: %d\n",restTimes);
  return restTimes;
}

