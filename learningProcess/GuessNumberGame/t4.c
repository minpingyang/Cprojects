#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define START 1   //declare macro
#define END 100
#define ATTEMPTS 5

void guess();   //declare functions first


int main(){
    
    guess();
    return 0;
}

void guess(){
    //
    int number_typedIn;
    srand(time(NULL));
   //change 100 ->END , 1 ->START
    int randomNumber = (rand()%END)+START;
   
    int guessFailed = 1;  //use non-zero integer to represent 'true' 
    int restart = 1;     //use non-zero integer to represent 'true' 
    char answer;    //user input character if restart game
    int max = ATTEMPTS;   //change 5 --- > ATTEMPTS
    // recursion exit condition
    if(answer == 'n' || answer == 'N'){
        return;
    }
    printf("Pick a integer between 1 and 100. You have max.5 attempts\n");
    
    while (max>0) {
  
    scanf("%d",&number_typedIn);
    printf("Your guess: \"%d\"\n",number_typedIn);
        if(number_typedIn == randomNumber){
            printf("Congradulations! You are so lucky! \n");
            guessFailed = 0;
            break;
        }else if (number_typedIn < randomNumber){
            printf("Hmmm... My number is bigger than yours\n");
            max --;
        }
        else{
            printf("Hmmm... My number is smaller than yours\n");
            max --;
        }
    }
    //case1: guess failed
    if (guessFailed) {
        printf("Game Over. My number was %d\n",randomNumber);
    }
    //case2: restart
   
    printf("Play agian?(y/n)?");
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
