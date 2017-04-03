#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void draw(const int size, char field[]);
int add_cross(const int size, char field[], const int position);
int is_solved(const int size, char field[]);
void checkAdding(const int add_cross,const int size,char field[]);



int main(){
    
    int sizeF;
    int position;
    int isSolved = 0; //a flag judge if game solve
    int insertPosition = 0;
    int doesAddCross = 1;
    printf("Enter the size of field: ");
    
    //user type in a size of field
    scanf("%d",&sizeF);
    char board[sizeF];
    int i;
    int count = 0; // count how many cross was added
    for(i = 0; i <sizeF ; i ++){
      board [i] = ' ';
    }
   // board [sizeF] = {' '};
    draw(sizeF, board);  //  draw initial board

   while(isSolved == 0){     
      
          printf("Player A: " );
          scanf("%d",&insertPosition);
           
          doesAddCross = add_cross(sizeF,board,insertPosition);
          
          checkAdding(doesAddCross,sizeF,board);

          isSolved = is_solved(sizeF,board);
          if (isSolved == 1){
            printf("Player A won\n");
            break;
          }
          printf("Player B: " );
          scanf("%d",&insertPosition);
          doesAddCross = add_cross(sizeF,board,insertPosition);      
          
          checkAdding(doesAddCross,sizeF,board);

          isSolved = is_solved(sizeF,board);
          if (isSolved == 1){
            printf("Player B won\n");
            break;
          }

   }    
    
   
    return 0;
}

void checkAdding(const int add_cross,const int size,char field[]){
 
   if (add_cross == 1) {
            draw(size, field);
    }else if (add_cross == 0 ){
            printf("X is already there!\n"); 

    }else if (add_cross == -1) {
              printf("Wrong position!\n");
    }

}
void draw(const int size, char field[]){

   int i = 1;
      
   // draw "+-"
  while(i <= size){
   printf("+-");
   i++;
  }
  printf("+\n");
  i = 0;
  // draw "| "
  while(i < size){
   printf("|%c",field[i++]);
  }
  printf("|\n");
  i = 1;
  //draw "+-" 
  while(i <= size){
   printf("+-");
   i++;
  }
  printf("+\n");
  i = 1;
  //draw number
  while(i <= size){
   printf(" %d",i++);
  }
  printf(" \n");
  printf(" \n");
 
 
}

int add_cross(const int size, char field[], const int position){
   //check if the possition is free
   
   if(field[position-1] == ' ' && position <= size && position > 0){
    field[position-1] = 'X';
    // draw(size, field);
    return 1;
   }else if(field[position-1] == 'X' && position <= size){
      
    return 0;
   }
   return -1;

}

int is_solved(const int size, char field[]){

   int i;
   for (i = 0; i < size - 2 ; i++) {
      if(field[i] == 'X' && field[i+1] == 'X' && field[i+2] == 'X'){
        return 1;
      }  
   }

   return 0;
//
}












