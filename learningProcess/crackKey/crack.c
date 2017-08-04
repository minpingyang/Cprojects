#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#define TEXT_SIZE 1000000  // Note, the longer the text the more likely you will get a good 'decode' from the start.
#define ALEN 26         // Number of chars in ENGLISH alphabet
#define CHFREQ "ETAONRISHDLFCMUGYPWBVKJXQZ" // Characters in order of appearance in English documents.
#define ALPHABET "ABCDEFGHIJKLMNOPQRSTUVWXYZ"

/* Program developed for NWEN243, Victoria University of Wellington
   Author: Kris Bubendorfer, this extended version (c) 2015
   LAB: 2

   This program applies a basic frequency analysis on a cyphertext.  It has been extened over the 2014 version to
   solve polyalphabetic cyphers - by brute force.  In this case, it applies the frequency analysis for different 
   numbers of n keys (polyalphabetic Caeser).  Obviously it will need a cypher of about n times
   the typical length for a monoalphabetic cypher.

   Program is used like this:

   Compile:  gcc -o crack crack.c

   Test file (ctext): JWRLS, XSSH PZK JH HES BJFV, UZU (this is not a realistic length piece of cypher text)

   crack n

   Argument:

   n number of keys to try

   ---

   % cat ctext | crack 1
   ALICE, MEET YOU AT THE PARK, BOB   <-- of course it won't be this correct.  Don't worry about that for the -d option.
   AMFDE, UEET LNH AT TIE RASC, ONO   <-- this is what it really looks like, a larger sample is better, this is short.


 */
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
//
void createSubtext(int n,int len,char* text){
  // printf("len: %d\n",len);//18
  int maxLenSub;
  if(len%n!=0){
    maxLenSub=1+len/n;
    // printf("maxLen:%d\n",maxLenSub);
  }else{
    maxLenSub=len/n;
  }
  
  char collectSubtext[n][maxLenSub+1];
  char frequenceSub[n][maxLenSub+1];
  // printf("n:%d maxLenSub: %d\n",n,maxLenSub);//43
  int col=0;
  int row=0;
  int indexText=0;
  //initialise collectSubtext to whitespace and \0 at each end of subtext
  for(row=0;row<n;row++){
    for(col=0;col<maxLenSub;col++){
      frequenceSub[row][col]='a';
   }
  }

  //add all chars(including punctuation and alpha) into collectSub
  for(col=0;col<maxLenSub;col++){
    for(row=0;row<n&&indexText<len;row++,indexText++){
      collectSubtext[row][col]=text[indexText];
      // printf("row:%d col: %d\n",row,col);
      // printf("index:%d char: %c\n",indexText,text[indexText]);
      // printf("\n");
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
      // printf(" Subrow: %d Subcol: %d Frech: %d",row,col,ch);
    }
    // printf("\n");
  }
  // printf("charlen: %d\n",charLen);
  int inF=0; //the index of freqAnaly
  int inMa=0; // the index of maximu value in each subtext
  char charMa; //the character of most frequence in freqAna
  int inCH=0; // the index of CHFREQ 
  // for(row=0;row<n;row++){
  //   for(col=0;col<26;col++){
  //     int f = freqAnaly[row][col];
  //     char c = col+'A';
  //     // printf(" Subrow: %d Subcol: %c Fre: %d",row,c,f);
  //   }
  // }
 
  indexText = 0;
  // for(row=0;row<n;row++)
  // {
  //   for(inF=0;inF<26;inF++){
  //     inMa =indexMax(freqAnaly[row],26);
  //     // printf("index: %d  Max(-2): %d\n",inMa,freqAnaly[row][inMa]);
  //     if(inMa==-1){break;}
  //     charMa = 'A'+inMa;
  //     printf("row: %d charMa: %c\n",row,charMa);
  //     for(col=0;col<maxLenSub&&indexText<charLen;col++,indexText++){
  //       if(collectSubtext[row][col]==charMa){
  //         // frequenceSub[row][col]=CHFREQ[inF];
  //         collectSubtext[row][col]=CHFREQ[inF];
  //         printf("row: %d col:%d charTe:%s\n",row,col,collectSubtext[row]);
  //       }
  //     }    
  //   }
  //   // col=0;
  // }
  

  for(row=0;row<n;row++)
  {
    for(inF=0;inF<26;inF++){
      inMa =indexMax(freqAnaly[row],26);
      // printf("index: %d  Max(-2): %d\n",inMa,freqAnaly[row][inMa]);
      if(inMa==-1){break;}
      charMa = 'A'+inMa;
      // printf("charMa: %c\n",charMa);
      for(col=0;col<maxLenSub&&indexText<charLen;col++){
        if(collectSubtext[row][col]==charMa){
          indexText++;
          frequenceSub[row][col]=CHFREQ[inCH];
          collectSubtext[row][col]='1';
          // printf("row: %d col:%d charTe:%s\n",row,col,frequenceSub[row]);
          
        }
      }
      inCH++;
    }
    col=0;
    inCH=0;
  }
  


  // printf("%s\n",frequenceSub[0]);
  char result[len+1];
 
  indexText=0;
  for(col=0;col<maxLenSub;col++){
    for(row=0;row<n&&indexText<len;row++,indexText++){
      result[indexText]=frequenceSub[row][col];
      // printf("row:%d col: %d\n",row,col);
      // printf("index:%d char: %c\n",indexText,result[indexText]);
      // printf("\n");
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

  /* At this point we have two things,
   *   1. The input cyphertext in "text"
   *   2. The maximum number of keys to try (n) - we'll be trying 1..n keys.
   *
   * What you need to do is as follows:
   *   1. create a for-loop that will check key lengths from 1..n
   *   2. for each i <= n, spit the cypher text into i sub-texts.  For i = 1, 1 subtext, for i = 2, 2 subtexts, of alternating characters etc.
   *   3. for each subtext: 
   *          a. count the occurance of each letter 
   *          b. then map this onto the CHFREQ, to create a map between the sub-text and english
   *          c. apply the new map to the subtext 
   *   4. merge the subtexts
   *   5. output the 'possibly' partially decoded text to stdout.  This will only look OK if i was the correct number of keys
   *
   * what you need to output (sample will be provided) - exactly:
   * i maps -> stderr
   * i 'possible' translations
   *
   * You would be wise to make seperate functions that perform various sub-tasks, and test them incrementally.  Any other approach will likely
   * make your brain revolt.  This isn't a long program, mine is 160 lines, with comments (and written in a very verbose style) - if yours is
   * getting too long, double check you're on the right track.
   *
   */
  
  // Your code here...
  //create sub-cryphertext according to number of key
  int numKey=1;
  
  	while(numKey<=n){
  		createSubtext(numKey,strlen(text),text);
  		numKey++;
  	}
  	
  		
  	
  
  
}

