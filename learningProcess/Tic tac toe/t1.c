#include <stdio.h>
#include <stdlib.h>

void draw(const int size, char field[]);
int add_cross(const int size, char field[], const int position);

int main(){
    int sizeF;
    printf("Enter the size of field: ");
    
    //user type in a size of field
    scanf("%d",&sizeF);
    char board [sizeF];
    draw(sizeF, board);
    return 0;
}
void draw(const int size, char field[]){
   int i = 1;
   // draw "+-"
  while(i <= size){
   printf("+-");
   i++;
  }
  printf("+\n");
  i = 1;
  // draw "| "
  while(i <= size){
   printf("| ");
   i++;
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

int add_cross(const int size, char field[], const int position){
return 0;
}