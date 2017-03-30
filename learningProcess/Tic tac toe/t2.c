#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void draw(const int size, char field[][size]);
int add_cross(const int size, char field[][size], const int x, const int y, const char player);
int is_solved(const int size, char field[][size]);

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
      if(doesAddCross == 1){
          printf("Player A: " );
              printf("choose row: ");
              scanf("%d",&insertPositionRow);
              printf("choose col: ");
              scanf("%d",&insertPositionCol);

            //now the board array initialized with space
          doesAddCross = add_cross(sizeF, board,insertPositionRow,insertPositionCol,'A');
          
          if (doesAddCross == 1) {
            draw(sizeF, board);
          }

          isSolved = is_solved(sizeF,board);
          if (isSolved == 1){
            printf("Player A won\n");
            break;
          }
          printf("Player B: " );
           printf("choose row: ");
              scanf("%d",&insertPositionRow);
              printf("choose col: ");
              scanf("%d",&insertPositionCol);

          doesAddCross = add_cross(sizeF, board,insertPositionRow,insertPositionCol,'B');    
          
          if (doesAddCross == 1) {
            draw(sizeF, board);
          }

          isSolved = is_solved(sizeF,board);
          if (isSolved == 1){
            printf("Player B won\n");
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
    }
      field[x-1][y-1] = 'O';  
    return 1;
   }else if(field[x-1][y-1] != ' '&& x <= size && y <=size){
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


// int main(){
//  
//     int sizeF;
//     int position;
//     int isSolved = 0; //a flag judge if game solve
//     int insertPosition = 0;
//     int doesAddCross = 1;
//     printf("Enter the size of field: ");
    
//     //user type in a size of field
//     scanf("%d",&sizeF);
//     char board[sizeF];
//     int i;
//     int count = 0; // count how many cross was added
//     for(i = 0; i <sizeF ; i ++){
//       board [i] = ' ';
//     }
//    // board [sizeF] = {' '};
//     draw(sizeF, board);  //  draw initial board

//    while(isSolved == 0){     
//       if(doesAddCross == 1){
//           printf("Player A: " );
//           scanf("%d",&insertPosition);
//             //now the board array initialized with space
//           doesAddCross = add_cross(sizeF,board,insertPosition);
          
//           if (doesAddCross == 1) {
//             draw(sizeF, board);
//           }

//           isSolved = is_solved(sizeF,board);
//           if (isSolved == 1){
//             printf("Player A won\n");
//             break;
//           }
//           printf("Player B: " );
//           scanf("%d",&insertPosition);
//           doesAddCross = add_cross(sizeF,board,insertPosition);      
          
//           if (doesAddCross == 1) {
//             draw(sizeF, board);
//           }

//           isSolved = is_solved(sizeF,board);
//           if (isSolved == 1){
//             printf("Player B won\n");
//             break;
//           }

//       }else if (doesAddCross == 0 ){
//           printf("X is already there!\n"); 
//           doesAddCross = 1;
//       }else if (doesAddCross == -1) {
//              printf("Wrong position!\n");
//           doesAddCross = 1;
//       }
//    }    
    
   
//     return 0;
// }




























// int add_cross(const int size, char field[], const int position){
//    //check if the possition is free
   
//    if(field[position-1] == ' ' && position <= size){
//     field[position-1] = 'X';
//     // draw(size, field);
//     return 1;
//    }else if(field[position-1] == 'X' && position <= size){
      
//     return 0;
//    }
//    return -1;

// }

// int is_solved(const int size, char field[]){

//    int i;
//    for (i = 0; i < size - 2 ; i++) {
//       if(field[i] == 'X' && field[i+1] == 'X' && field[i+2] == 'X'){
//         return 1;
//       }  
//    }

//    return 0;

// }












