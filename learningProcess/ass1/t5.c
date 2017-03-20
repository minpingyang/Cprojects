#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define START 1
#define END 100
#define ATTEMPTS 5
 //declare functions first
void guess();  
int is_game_won(const int secret, const int guess);
int get_secret(const int start, const int end);
int get_guess(const int attempt);
//declare global variables since they are used in mutiple-methods
int number_typedIn;
int max;

int main(){
    
    guess();
    return 0;
}
int get_secret(const int start, const int end){
  
    srand(time(NULL));
    
    int randomNumber = (rand()%end)+start;
    return randomNumber;
}
int is_game_won(const int secret, const int guess){
  
       if(secret == guess){
            printf("Congradulations! You are so lucky! \n");
            return 0;  //'0'represents false in this programme.
            
        }else if (secret < guess){
            printf("Hmmm... My number is bigger than yours\n");
            max --;    
        }
        else{
            printf("Hmmm... My number is smaller than yours\n");
            max --;
        }
     return 1;   //"1" represents true in this programme.
  
}

int get_guess(const int attempt){
  int restTimes = 6-attempt;
  printf("Your guess: \"%d\"\n",number_typedIn);
  printf("Times of guesses You have so far: %d\n",restTimes);
  return restTimes;
}

void guess(){
    
    int randomNumber = get_secret(START,END);
    int guessTimesLeft = 0;
    int guessFailed = 1;
    int restart = 1;
    char answer;
    max = ATTEMPTS;
    // recursion exit condition
    if(answer == 'n' || answer == 'N'){
        return;
    }
    printf("Pick a integer between 1 and 100. You have max.5 attempts\n");
    
    while (max>0) {
        
      scanf("%d",&number_typedIn);
      guessTimesLeft = get_guess(max);
      
      guessFailed = is_game_won(randomNumber, number_typedIn);
      if(randomNumber == number_typedIn)
	break;
    }
    //case1: guess failed
    if (guessFailed) {
        printf("Game Over. My number was %d\n",randomNumber);
    }
    printf("Play agian?(y/n)?");
     //case2: restart
    //clean wrong character of input buffer 
   do {
      answer = getchar();
      
   } while(answer != 'y' && answer != 'Y'&& answer != 'n'&& answer !='N'); 
    if(answer == 'n' || answer == 'N'){
        printf("Bye Bye!! \n");
        return;
    }else if(answer == 'y' || answer == 'Y'){
        guess();
    }
  
}
