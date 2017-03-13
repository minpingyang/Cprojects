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
    int MAX_TRIES = 5;
    int guessFailed = 1;
    printf("Pick a integer between 1 and 100. You have max.5 attempts\n");
    
    while (MAX_TRIES>0) {
  
    scanf("%d",&number_typedIn);
    printf("Your guess: \"%d\"\n",number_typedIn);
        if(number_typedIn == randomNumber){
            printf("Congradulations!\n");
            guessFailed = 0;
            break;
        }else if (number_typedIn < randomNumber){
            printf("Hmmm... My number is bigger than yours\n");
            MAX_TRIES --;
        }
        else{
            printf("Hmmm... My number is smaller than yours\n");
            MAX_TRIES --;
        }
    }
    
    if (guessFailed) {
        printf("Game Over. My number was %d\n",randomNumber);
    }
  
}

