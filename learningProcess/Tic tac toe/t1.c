#include <stdio.h>
#include <stdlib.h>

void draw(const int size, char field[]);
//int add_cross(const int size, char field[], const int position);
//int is_solved(const int size, char field[]);
char board[];

int main(){
    int sizeF;
    int position;
    printf("Enter the size of field: ");
    
    //user type in a size of field
    scanf("%d",&sizeF);
    board [sizeF];
    draw(sizeF, board);
    //add_cross(sizeF,board,position);
    
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
  
   
}
/*
int add_cross(const int size, char field[], const int position){
//che
   if(){
    return 1;
   }else if(){
    return 0;
   }
   return -1;

}

int is_solved(const int size, char field[]){
   if(){
   
   return 1;
   }
   return 0;

}
*/











