#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#define TEXT_SIZE 1000000  // Note, the longer the text the more likely you will get a good 'decode' from the start.
#define ALEN 26         // Number of chars in ENGLISH alphabet
#define CHFREQ "ETAONRISHDLFCMUGYPWBVKJXQZ" // Characters in order of appearance in English documents.
#define ALPHABET "ABCDEFGHIJKLMNOPQRSTUVWXYZ"
int indexMax(int* arr,int len){
  int max=-1;
  int i=0;
  for(i=0;i<len;i++){
    if(max<arr[i]){
      max=arr[i];
    }
  }
  if(max==0){
      return -1;//have not exist 
  }
  
   for(i=0;i<len;i++){
      if(max==arr[i]){
        arr[i]=-2; // set maxium value frequence to -2
        return i;
      }
    } 
    return i;
}
char upcase(char ch){
  if(islower(ch))
    ch -= 'a' - 'A';
  return ch;
}
//len of the input test.txt
void createSubtext(int n,int len,char* text){
  int maxLenSub;
  if(len%n!=0){
    maxLenSub=1+len/n;
  }else{
    maxLenSub=len/n;
  } 
  char collectSubtext[n][maxLenSub+1];
  char frequenceSub[n][maxLenSub+1];
  int col=0;
  int row=0;
  int indexText=0;
  //initialise collectSubtext a
  for(row=0;row<n;row++){
    for(col=0;col<maxLenSub;col++){
      frequenceSub[row][col]='a';
   }
  }
  //add all chars(including punctuation and alpha) into collectSub
  for(col=0;col<maxLenSub;col++){
    for(row=0;row<n&&indexText<len;row++,indexText++){
      collectSubtext[row][col]=text[indexText];
    }
  }
  int freqAnaly[n][26];
  //initialise freqAnaly to zero
  for(row=0;row<n;row++){
    for(col=0;col<26;col++){
      freqAnaly[row][col]=0;
    }
  }
  int charLen=0; // the number of alpha of inputs
  int ch;//the index of character 
  //apply frequence to each subtext
  for(row=0;row<n;row++){
    for(col=0;col<maxLenSub;col++){
      if(!isalpha(collectSubtext[row][col])){
        frequenceSub[row][col]=collectSubtext[row][col];
        continue;
      }
      charLen++;
      ch = collectSubtext[row][col]-'A';
      freqAnaly[row][ch]++;
    }
  }
  int inF=0; //the index of freqAnaly
  int inMa=0; // the index of maximu value in each subtext
  char charMa; //the character of most frequence in freqAna
  int inCH=0; // the index of CHFREQ 
  indexText = 0;
  for(row=0;row<n;row++)
  {
    for(inF=0;inF<26;inF++){
      inMa =indexMax(freqAnaly[row],26);
      if(inMa==-1){break;}
      charMa = 'A'+inMa;
      for(col=0;col<maxLenSub&&indexText<charLen;col++){
        if(collectSubtext[row][col]==charMa){
          indexText++;
          frequenceSub[row][col]=CHFREQ[inCH];
          collectSubtext[row][col]='1';
        }
      }
      inCH++;
    }
    col=0;
    inCH=0;
  }
  char result[len+1];
  indexText=0;
  for(col=0;col<maxLenSub;col++){
    for(row=0;row<n&&indexText<len;row++,indexText++){
      result[indexText]=frequenceSub[row][col];
    }
  }
  result[len]='\0';
  printf("%s\n",result);
}
int main(int argc, char **argv){
  // first allocate some space for our input text (we will read from stdin).
  char* text = (char*)malloc(sizeof(char)*TEXT_SIZE+1);
  char ch;
  int n, i;

  if(argc > 1 && (n = atoi(argv[1])) > 0); else{ fprintf(stderr,"Malformed argument, use: crack [n], n > 0\n"); exit(-1);} // get the command line argument n
  
  // Now read TEXT_SIZE or feof worth of characters (whichever is smaller) and convert to uppercase as we do it.
  // Added: changed to count frequencies as we read it in

  for(i = 0, ch = fgetc(stdin); i < TEXT_SIZE && !feof(stdin); i++, ch = fgetc(stdin)){
    text[i] = (ch = (isalpha(ch)?upcase(ch):ch));
  }
  text[i] = '\0'; // terminate the string properly.
  //create sub-cryphertext according to number of key
  int numKey=1;
  	while(numKey<=n){
  		createSubtext(numKey,strlen(text),text);
  		numKey++;
  	}
}

