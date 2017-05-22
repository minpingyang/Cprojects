#include "guessNumber.h"

#define START 1
#define END 100
#define ATTEMPTS 5

//declare global variables
int PCguessNum;
int max; //**used
int start;
int end;
int randomNumber;



int main(){
    guessGame();
    return 0;
}
int get_PCguess(const int start, const int end){
    max --;
    
    randomNumber = (start + end)/2; 
    return randomNumber;   //return PC guess
}
void startGuess(){
  main();
}


int is_Ggame_won(const int secret, const int guess){
  int count = 0;
    
    
   //case1  : GUESS SUCCESS
       if(secret == guess){
            printf("Congratulations! Your PC are so lucky! \n");
            return 0;           
        }
   //if attempts equals 0
      if(max==0) return 1;
   //CASE2 : FAILED 
     printf("----------------------------------------------\n");
     printf("Seems like PC guess a wrong number.");
     printf("Can you give a hint for PC? \n type in (l/L) means your number lower than PC guess \n");
     printf(" type in (h/H) means your number higher than PC guess\n");
  
    char userHelp;
   //clean remaining characters of input buffer if character is not l/L or H/h
    do{
      count = 0;
      userHelp = getchar();
      while(getchar() != '\n'){count++;}
      if((userHelp != 'l' && userHelp != 'h'&& userHelp != 'L'&& userHelp !='H')|| count>0){
        printf("re-Enter a valid character: \n");
      }

    }while((userHelp != 'l' && userHelp != 'h'&& userHelp != 'L'&& userHelp !='H')|| count>0);
     

    if((userHelp == 'l' || userHelp == 'L')&&(guess>secret)){
        printf("my number is lower, PC try again \n");   //L &L
        end = guess;
        
        
    }else if((userHelp == 'h' || userHelp == 'H')&&(guess<secret)){
        printf("my number is higher, PC try again \n");   //H &h
        start = guess;
    }else {
       printf("You have not given the right hint，Could u next time give the right hint? \n");
    }
     return 1;
  
}


int restTime_showPCGuess(const int attempt){
  int restTimes = 5-attempt;
  printf("PC guess: \"%d\"\n",PCguessNum);
  printf("Times of guesses PC has so far: %d\n",restTimes);
  return restTimes;
}


void guessGame(){

 printf("Pick a integer between 1 and 100. Let PC guess (5 times Maximum Attempts!) \n");
   int number_typedIn = 1;  
   start = 1;
   end = 100;  // initial interval 
   max = ATTEMPTS;
   int guessTimesLeft = 0;
   int guessFailed = 1;
   char answer;

   printf("The number you chose is:  ");
   scanf("%d",&number_typedIn);      // user types in a number
   
      do {      
      PCguessNum = get_PCguess(start,end);  // PC guess a number
      guessTimesLeft = restTime_showPCGuess(max); // show what PC guess and number of remaining opportunities 
      guessFailed = is_Ggame_won(number_typedIn,PCguessNum); // check if pc failed    
      if(PCguessNum == number_typedIn){
          break;  
      }
	      
    } while (max>0);
    //case1: guess failed
    if (guessFailed) {
        printf("Game Over. PC runs out of attempts. My number was %d\n",number_typedIn);
    }
    //case2: restart
  //  getchar();    //eat a    "\n" of input buffer   
    printf("Play agian?(y/n)?");
    
  do {
      answer = getchar();
      
   } while(answer != 'y' && answer != 'Y'&& answer != 'n'&& answer !='N');
    
    if(answer == 'n' || answer == 'N'){
        printf("Bye Bye!! \n");
        return;
    }else if(answer == 'y' || answer == 'Y'){
        guessGame();
    }
  

}


