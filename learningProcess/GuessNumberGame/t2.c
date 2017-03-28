#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void guess();   //declare functions first


int main(){
    
    guess();
    return 0;
}

void guess(){
    int number_typedIn;
    srand(time(NULL));
    int randomNumber = (rand()%100)+1;
    int MAX_TRIES = 5;   //declare maximum attempts allowed 
    int guessFailed = 1;    // use non-zero integer to represent 'true'
    
    printf("Pick a integer between 1 and 100. You have max.5 attempts\n");
    
    while (MAX_TRIES>0) {
  
    scanf("%d",&number_typedIn);
    printf("Your guess: \"%d\"\n",number_typedIn);
        if(number_typedIn == randomNumber){
            printf("Congradulations! You are so lucky! \n");
            guessFailed = 0;  //guess succeed
            break;  //exit the loop
        }else if (number_typedIn < randomNumber){
            printf("Hmmm... My number is bigger than yours\n");
            MAX_TRIES --;   //decreasing attempts
        }
        else{
            printf("Hmmm... My number is smaller than yours\n");
            MAX_TRIES --;
        }
    }
    //case1: guess failed
    if (guessFailed) {
      //GG --> show the answer then.
        printf("Game Over. My number was %d\n",randomNumber);
    }
  
}

