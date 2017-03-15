#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define START 1
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
    //? randomNumber = (rand()%100)+1;
    int randomNumber = (rand()%END)+START;
   
    int guessFailed = 1;
    int restart = 1;
    char answer;
    int max = ATTEMPTS;
    // recursion exit condition
    if(answer == 78 || answer == 110){
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
    }
    
  
}
