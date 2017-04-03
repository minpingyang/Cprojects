#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void draw(const int size, char field[][size]);
int add_cross(const int size, char field[][size], const int x, const int y, const char player);
int is_solved(const int size, char field[][size]);
void checkAdding(int add_cross,const int size,char field[][size]);

int sizeF;

int main () {
  int isSolved = 0; //a flag judge if game solve
  int insertPositionRow = 0;
  int insertPositionCol = 0;
  int doesAddCross = 1;

  printf("Enter the size of field: ");
  scanf("%d",&sizeF);
  int r,c;
  char board[sizeF][sizeF];

  for(r = 0; r < sizeF ; r++){
    for(c = 0; c <sizeF; c++){
      board[r][c] = ' ';
    }     
  }
  draw(sizeF,board);
     while(isSolved == 0){     

          printf("Player A: \n" );
              
              printf("Input (row number + space + col number): ");
              scanf("%d %d",&insertPositionRow,&insertPositionCol);
              printf("row: %d  col: %d\n",insertPositionRow,insertPositionCol);

            //now the board array initialized with space
          doesAddCross = add_cross(sizeF, board,insertPositionRow,insertPositionCol,'A');
          checkAdding(doesAddCross,sizeF,board);
          // if (doesAddCross == 1) {
          //   draw(sizeF, board);
          // }else if (doesAddCross == 0 ){
          //   printf("X is already there!\n"); 
          //   doesAddCross = 1;
          // }else if (doesAddCross == -1) {
          //     printf("Wrong position!\n");
          //     doesAddCross = 1;
          // }

          isSolved = is_solved(sizeF,board);
          if (isSolved == 1){
            printf("Player A won\n");
            break;
          }
          printf("Player B: \n" );
           
              printf("Input (row number + space + col number): ");
              scanf("%d %d",&insertPositionRow,&insertPositionCol);
              printf("row: %d  col: %d\n",insertPositionRow,insertPositionCol);

          doesAddCross = add_cross(sizeF, board,insertPositionRow,insertPositionCol,'B');    
          
          checkAdding(doesAddCross,sizeF,board);
          // if (doesAddCross == 1) {
          //     draw(sizeF, board);
          // }else if (doesAddCross == 0 ){
          //     printf("X is already there!\n"); 
          //     doesAddCross = 1;
          // }else if (doesAddCross == -1) {
          //     printf("Wrong position!\n");
          //     doesAddCross = 1;
          // }

          isSolved = is_solved(sizeF,board);
          if (isSolved == 1){
            printf("Player B won\n");
            break;
          }
   }    


  return 0;


}

void checkAdding(int add_cross,const int size,char field[][size]){
   if (add_cross == 1) {
            draw(size, field);
          }else if (add_cross == 0 ){
            printf("X is already there!\n"); 
            add_cross = 1;
          }else if (add_cross == -1) {
              printf("Wrong position!\n");
              add_cross = 1;
          }

}


void draw(const int size, char field[][size]){

int i;
int tempSize = size;
while (tempSize != 0){
    int i = 1;    
    //draw a ' ' in each literate. 
    printf(" ");

     // draw "+-"
    while(i <= size){
     printf("+-");
     i++;
    }
    printf("+\n");
    i = 0;
    
   
    // draw a size number in each literate
    printf("%d",tempSize);

    // draw "| "
    while(i < size){
     printf("|%c",field[i++][tempSize-1]);
    }
    printf("|\n");
    tempSize--;
}

  printf(" ");
  i = 1;  
  //draw "+-" 
  while(i <= size){
   printf("+-");
   i++;
  }
  printf("+\n");
  i = 1;

  printf(" ");
  //draw number (left to right)
  while(i <= size){
   printf(" %d",i++);
  }
  printf(" \n");
  printf(" \n");
  
}

int add_cross(const int size, char field[][size], const int x, const int y, const char player){
   //check if the possition is free
   
   if(field[x-1][y-1] == ' ' && x <= size && y <=size){
    if(player == 'A'){
      field[x-1][y-1] = 'X';
    }else{
      field[x-1][y-1] = 'O';
    }
      return 1;   
   }else if((field[x-1][y-1] == 'X'||field[x-1][y-1] == 'O')&& x <= size && y <=size){
    return 0;
   }
   return -1;

}

int is_solved(const int size, char field[][size]){
   int r,c;
   for(r = 0 ; r < size; r++){
    for(c = 0; c < size; c++) {
      
      if(field[r][c] == 'X' || field[r][c] == 'O'){
        int flag1 = ((field[r][c] == field[r-1][c-1]) && (field[r][c] == field[r+1][c+1]));
        if(flag1){return 1;} //dialog
        int flag2 = ((field[r][c] == field[r-1][c+1]) && (field[r][c] == field[r+1][c-1]));
        if(flag2){return 1;}//antidialog
        int flag3 = ((field[r][c] == field[r-1][c]) && (field[r][c] == field[r+1][c]));
        if(flag3){return 1;} //horizontal check
        int flag4 = ((field[r][c] == field[r][c-1]) && (field[r][c] == field[r][c+1]));
        if(flag4){return 1;}
      }
    }
  }
   
   return 0;  
}












