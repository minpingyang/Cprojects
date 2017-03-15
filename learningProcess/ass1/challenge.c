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

int main(){
    
    guessGame();
    return 0;
}


void guessGame(){

 printf("Pick a integer between 1 and 100. Let PC guess (5 times Maximum Attempts!) \n");
   int number_typedIn = 1;
   PCguessNum = get_PCguess(START,END);
   int start = 1;
   int end = 100;  // initial interval 
   max = ATTEMPTS;
   int guessTimesLeft = 0;
   int guessFailed = 1;
   int restart = 1;
   char answer;
   
   while (max>0) {      
      scanf("%d",&number_typedIn);      // user types in a number
      
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
        printf("Game Over. My number was %d\n",randomNumber);
    }
    //case2: restart
    getchar();    //eat a    "\n" of input buffer
    
    printf("Play agian?(y/n)?");
    answer = getchar();
    if(answer == 78 || answer == 110){
        printf("Bye Bye!! \n");
        return;
    }else if(answer == 89 || answer == 121){
        guess();
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
       
       if(secret == guess){
            printf("Congradulations! Your PC are so lucky! \n");
            return 0;
            
        }
        
      getchar();    //eat a    "enter" of input buffer
     useHelp = getchar();
    printf("Play agian?(y/n)?");
   
    if(userHelp == 76 || userHelp == 108){
        printf("my number is lower, maybe try again \n");   //L &L
        return;
    }else if(answer == 89 || answer == 121){
        guess();
    }else{
        printf("\nonly options Y/y/N/n can be recognised\n");
	printf("\n you shoud run the program again\n");
    }
        
        
        else{
            
            printf("Hmmm... My number is smaller than yours\n");
            max --;
        }
     return 1;
  
}


int restTime_showPCGuess(const int attempt){
  int restTimes = 6-attempt;
  printf("PC guess: \"%d\"\n",PCguessNum);
  printf("Times of guesses PC has so far: %d\n",restTimes);
  return restTimes;
}

















int is_game_won(const int secret, const int guess){
  
       if(secret == guess){
            printf("Congradulations! You are so lucky! \n");
            return 0;
            
        }else if (secret < guess){
            printf("Hmmm... My number is bigger than yours\n");
            max --;    
        }
        else{
            printf("Hmmm... My number is smaller than yours\n");
            max --;
        }
     return 1;
  
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
    if(answer == 78 || answer == 110){
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
    //case2: restart
    getchar();    //eat a    "\n"
    
    printf("Play agian?(y/n)?");
    answer = getchar();
    if(answer == 78 || answer == 110){
        printf("Bye Bye!! \n");
        return;
    }else if(answer == 89 || answer == 121){
        guess();
    }else{
        printf("\nonly options Y/y/N/n can be recognised\n");
	printf("\n you shoud run the program again\n");
    }
    
  
}
