#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>

/* Program developed for NWEN243, Victoria University of Wellington
   Author: Kris Bubendorfer (c) 2014-15.
   Uses a modified caeser I & II (in 2015)

   Compile:  gcc -o decode decode.c

   See encode for  examples on using it
 */

int in(char c, char* s, int pos){
    // Assume everything is already in the same case
    int i;
    
    for(i = 0; i < pos; i++)
        if(c == s[i]) return 1;
    
    return 0;
}


char upcase(char ch){
    if(islower(ch))
        ch -= 'a' - 'A';
    return ch;
}

char* fixkey(char* s){
    int i, j;
    char plain[26]; // assume key < length of alphabet, local array on stack, will go away!
    
    for(i = 0, j = 0; i < strlen(s); i++){
        if(isalpha(s[i])&&(in(upcase(s[i]),plain,strlen(plain))!=1)){
            plain[j++] = upcase(s[i]);
        }
    }
    plain[j] = '\0';
    return strcpy(s, plain);
}
int isDuplicate(char nextC, char* table){
    int i = 0;
    for(;i<26;i++){
        if(nextC==table[i]){
            // printf("!!!!i: %d, c: %c\n",i,table[i]);
            return 1;
        }
    }
    return 0;
}

char next(char lastC_Key,char* table){
    char nextC;
    int isD=0;
    do{
        
        if(lastC_Key<'Z'){
            nextC = lastC_Key+1;
        }else{
            nextC = 'A';
        }
        isD= isDuplicate(nextC,table);
        // printf("isD?: %d\n",isD);
        if(isD==1){
            lastC_Key = nextC;
        }
    }while(isD==1);
    return nextC;
}



void buildtableEncode (char* key, char* encode){
    // This function needs to build an array of mappings in the 'encode' array from plaintext characters
    // to encypered characters.  The encode array will be indexed by the plaintext char.  To
    // make this a useful 0-26 index for the array, 'A' will be stubtracted from it (yes you
    // can do this in C).  You can see this in the main(){} below.  The values in the array
    // will be the cipher value, in the example at the top A -> H, B -> J, etc.
    
    // You are implementing a Caesar 1 & 2 combo Cypher as given in handout.
    // Your code here:
    
    // probably need to declare some stuff here!
    int offset= strlen(key);//13
    fixkey(key); //7 fix the key, i.e., uppercase and remove whitespace and punctuation
    int restNum= (int)(26-strlen(key));
    char table[27];
    //initialise
    int j=0;
    for(;j<26;j++){
        table[j] = ' ';
    }
    table[26]='\0';
    
    int i = offset-1; //12
    // Do some stuff here to make a translation between plain and cypher maps.
    //add fixed key to the table
    for(;i<i+strlen(key);i++,key++){
        table[i]=*key;
        // printf("%d:,%c\n",i,table[i]);
    }
    int nextIndex;
    int count=0;
    char nextC;
    
    
    while(count<restNum){
        nextC = next(table[i-1],table);
        nextIndex = i%26;
        // printf("nextCh:%c,  nextIndex: %d, i: %d\n",nextC, nextIndex,i);
        table[nextIndex] = nextC;
        if(i==26){
            i=0;
        }
        i++;
        count++;
    }
          // printf("%s\n",table);
          strcpy(encode, table);
 }
     


void buildtable (char* key, char* decode){ // this changed from encode
  
  // This function needs to build an array of mappings in 'encode' from plaintext characters
  // to encihered characters.

  // You are implementing a Caesar 1 & 2 combo Cypher as given in the lab handout.
  // Your code here:

  // probably need to declare some stuff here!
  char temp[27];
  temp[26] = '\0';

  buildtableEncode(key,temp);
  char temp2[27];
  temp2[26]='\0';

  printf("%s\n",temp);
  int i = 0;
  int orderIndex;
  for(;i<26;i++){
    char nextC= temp[i];
    orderIndex = nextC - 'A';
    // printf("index:%d, char: %c\n",orderIndex,nextC);
    temp2[orderIndex] = nextC;
  }
  strcpy(decode, temp2);
  printf("%s\n",decode);

  // the simplest way to do this is to do exactly the same as you did when creating the 
  // encode table, and then look up the encode table to get the translations, and build the
  // decode table from this.  This isn't the most efficient approach, but it will get the 
  // job done unless you want to be fancy.


}

int main(int argc, char **argv){
  // format will be: 'program' key {encode|decode}
  // We'll be using stdin and stdout for files to encode and decode.

  // first allocate some space for our translation table.

  char* decode = (char*)malloc(sizeof(char)*26); // this changed from encode
  char ch;

  if(argc != 2){
    fprintf(stderr,"format is: '%s' key", argv[0]);
    exit(1);
  }

  // Build translation tables, and ensure key is upcased and alpha chars only.

  buildtable(argv[1], decode); // this changed from encode

  // write the key to stderr (so it doesn't break our pipes)

  fprintf(stderr,"key: %s - %d\n", decode, strlen(decode));


  // the following code does the translations.  Characters are read 
  // one-by-one from stdin, translated and written to stdout.

    ch = fgetc(stdin);
    while (!feof(stdin)) {
      if(isalpha(ch))          // only decrypt alpha chars
      	{ch = upcase(ch);
        fputc(decode[ch-'A'], stdout);
      }
     else {
        fputc(ch, stdout);
     }
      ch = fgetc(stdin);      // get next char from stdin
    }
}

