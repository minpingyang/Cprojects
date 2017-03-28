#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void guess();   //declare guess() function first


int main(){
    
    guess();
    return 0;
}

void guess(){
//declare local variable first
    int number_typedIn;
    srand(time(NULL));
    int randomNumber = (rand()%100)+1;
   
    printf("Pick a integer between 1 and 100.\n");
  //read user input by using scanf()
    scanf("%d",&number_typedIn);
    printf("Your guess: \"%d\"\n",number_typedIn);
        if(number_typedIn == randomNumber){
            printf("Congradulations! You are so lucky! \n");
        }else if (number_typedIn < randomNumber){
            printf("Hmmm... My number is bigger than yours\n");
            
        }
        else{
            printf("Hmmm... My number is smaller than yours\n");
            
        }
     
}

