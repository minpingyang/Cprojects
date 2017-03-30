#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

void draw(const int size, char field[][size]);
int add_cross(const int size, char field[][size], const int x, const int y, const char preferChar);
int is_solved(const int size, char field[][size]);
void make_turn(const int size, char field[][size]);

int sizeF;
char humanChar; //(x/o)
int insertPositionRow = 0;
int insertPositionCol = 0;

int main () {
  
  int isSolved = 0; //a flag judge if game solve

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
   printf("what character you want to use(X/O): ");
   do {
        humanChar = getchar();
      } while(humanChar != 'x' && humanChar != 'X'&& humanChar != 'o'&& humanChar !='Y');
          

     while(isSolved == 0){     
      if(doesAddCross == 1){
          printf("Human Player: \n" );
    
              printf("what row you wana choose: ");
              scanf("%d",&insertPositionRow);
              printf("what col you wana choose: ");
              scanf("%d",&insertPositionCol);

            //now the board array initialized with space
          doesAddCross = add_cross(sizeF, board,insertPositionRow,insertPositionCol,humanChar);
          
          if (doesAddCross == 1) {
            draw(sizeF, board);
          }

          isSolved = is_solved(sizeF,board);
          if (isSolved == 1){
            printf("Human Player won!\n");
            break;
          }
          printf("PC player: \n" );
          make_turn(sizeF, board);// PC choose valid row and col

           printf("PC choose row: %d\n",insertPositionRow);
           printf("PC choose col: %d\n",insertPositionCol);  
           draw(sizeF, board);
          

          isSolved = is_solved(sizeF,board);
          if (isSolved == 1){
            printf("PC player won!\n");
            break;
          }

      }else if (doesAddCross == 0 ){
          printf("X is already there!\n"); 
          doesAddCross = 1;
      }else if (doesAddCross == -1) {
             printf("Wrong position!\n");
          doesAddCross = 1;
      }
   }    


  return 0;


}
//This  function   will  serve   as  the   PC  opponent  to  the   human   player.
//in  this function  you will  implement the PC  logic – it  will put  an  ‘X’ (or ‘O’,  you can decide the  user  
//will  play  with  which character)  
//at  a random  VALID (not  in  use)  position  in  the grid.
void make_turn(const int size, char field[][size]){
//make random vaild choice in the grid
  int pcChar;
  if(humanChar == 'X' || humanChar == 'x' ){pcChar = 'O';}
  else if (humanChar == 'O' || humanChar == 'o'){pcChar = 'X';}
  int validCoord= 0;
  do{
      srand(time(NULL));
      insertPositionRow = (rand()%size)+1;
      insertPositionCol = (rand()%size)+1;
      validCoord = add_cross(sizeF, field,insertPositionRow,insertPositionCol,pcChar);
  } while(validCoord != 1);
    

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

int add_cross(const int size, char field[][size], const int x, const int y, const char preferChar){
   //check if the possition is free
   
   if(field[x-1][y-1] == ' ' && x <= size && y <=size){
    if(preferChar == 'X'|| preferChar == 'x'){
      field[x-1][y-1] = 'X';
    }else if(preferChar == 'O'|| preferChar == 'o'){
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



