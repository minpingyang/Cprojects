#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void draw(const int size, char field[]);
int add_cross(const int size, char field[], const int position);
// int is_solved(const int size, char field[]);
char board[80];



int main(){
    
    int sizeF;
    int position;
    int is_solved = 0; //a flag judge if game solve
    int insertPosition = 0;
    printf("Enter the size of field: ");
    
    //user type in a size of field
    scanf("%d",&sizeF);
    board [sizeF];
    draw(sizeF, board);  //  draw initial board

    // while-loop to sun this gamme Player A add cross player B add ac
    //loop end until is_solved == 1 || cross is fulled in the board (draw) || 
    // while (is_solved != 1 ) {
    //   printf("Player A: " );
    //   scanf("%d",&insertPosition);
    //   //now the board array initialized with space
    //   add_cross(sizeF,board,insertPosition);
    //   is_solved =1 ;
    // }
    printf("Player A: " );
    scanf("%d",&insertPosition);
      //now the board array initialized with space
    add_cross(sizeF,board,insertPosition);

    
    return 0;
}
void draw(const int size, char field[]){

   int i = 1;
   
    //initialise field with " "space
   i = 0;
   while(i < size){
      field[i++] =' ';     
   }
   
   i = 1;
   
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
  //copy field array to board array ???
  strcpy(board,field);
}

int add_cross(const int size, char field[], const int position){
   //check if the possition is free
   
   if(field[position-1] == ' ' && position <= size){
    field[position-1] = 'X';
    draw(size, field);
    return 1;
   }else if(field[position-1] == 'X' && position <= size){
    printf("X is already there\n");   
    return 0;
   }
   printf("Wrong position\n");
   return -1;

}

// int is_solved(const int size, char field[]){
//    if(){
   
//    return 1;
//    }
//    return 0;

// }












