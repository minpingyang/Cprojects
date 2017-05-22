#include "tictactoe.h"


int sizeF;
char humanChar; //(x/o)
int insertPositionRow = 0;
int insertPositionCol = 0;

int runTicTacToe () {
  int count = 0;
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
  
  do{
      count = 0;
      humanChar = getchar();
      while(getchar() != '\n'){count++;}
      if((humanChar != 'x' && humanChar != 'X'&& humanChar != 'o'&& humanChar !='Y')|| count>0){
        printf("re-Enter a valid character: \n");
      }

  }while((humanChar != 'x' && humanChar != 'X'&& humanChar != 'o'&& humanChar !='Y')|| count>0);




     while(isSolved == 0){     

          printf("Human Player: \n" );
    
              printf("Input (row number + space + col number): ");
              scanf("%d %d",&insertPositionRow,&insertPositionCol);
              printf("row: %d  col: %d\n",insertPositionRow,insertPositionCol);
             

            //now the board array initialized with space
          doesAddCross = add_cross(sizeF, board,insertPositionRow,insertPositionCol,humanChar);
          
          checkAdding(doesAddCross,sizeF,board);

          isSolved = is_solved(sizeF,board);
          if (isSolved == 1){
            printf("Human Player won!\n");
            break;
          }
          printf("PC player: \n" );
          make_turn(sizeF, board);// PC choose valid row and col

           printf("PC choose row: %d\n",insertPositionRow);
           printf("PC choose col: %d\n",insertPositionCol);  
          // draw(sizeF, board);
          
          checkAdding(doesAddCross,sizeF,board);

          isSolved = is_solved(sizeF,board);
          if (isSolved == 1){
            printf("PC player won!\n");
            break;
          }

   }    


  return 0;
}

void checkAdding(const int add_cross,const int size,char field[][size]){
   if (add_cross == 1) {
            draw(size, field);
          }else if (add_cross == 0 ){
            printf("A character is already there!\n"); 
            
          }else if (add_cross == -1) {
              printf("Wrong position!\n");             
          }

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
   
   if(field[x-1][y-1] == ' ' && x <= size && y <=size && x > 0 && y >0){
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
   for(r = 1 ; r < size-1; r++){
    for(c = 1; c < size-1; c++) {
         //if every three of ajacency character are same in one of four directions, then return true;

      if(field[r][c] == 'X' || field[r][c] == 'O'){
        int flag1 = ((field[r][c] == field[r-1][c-1]) && (field[r][c] == field[r+1][c+1]));
        if(flag1){return 1;} //dialog
        int flag2 = ((field[r][c] == field[r-1][c+1]) && (field[r][c] == field[r+1][c-1]));
        if(flag2){return 1;}//antidialog
        int flag3 = ((field[r][c] == field[r-1][c]) && (field[r][c] == field[r+1][c]));
        if(flag3){return 1;} //horizontal check
        int flag4 = ((field[r][c] == field[r][c-1]) && (field[r][c] == field[r][c+1]));
        if(flag4){return 1;} //vertial check
      }
    }
  }
   
   return 0;  
}



