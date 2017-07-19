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

char upcase(char ch){
  if(islower(ch))
    ch -= 'a' - 'A';
  return ch;
}

// char* fixkey(char* s){
//   int i, j;
//   char plain[26]; // assume key < length of alphabet, local array on stack, will go away!

//   for(i = 0, j = 0; i < strlen(s); i++){
//     if(isalpha(s[i])){
//       plain[j++] = upcase(s[i]);
//     }
//   }
//   plain[j] = '\0'; 
//   return strcpy(s, plain);
// }


// int in(char c, char* s, int pos){
//   // Assume everything is already in the same case
//   int i;

//   for(i = 0; i < pos; i++)
//     if(c == s[i]) return 1;
    
//   return 0;
// } 


char* fixkey(char* s){
  int i, j;        
  char plain[26]; //(!!probably need check the length of the key) assume key < length of alphabet, local array on stack, will go away!
  
  for(i = 0, j = 0; i < strlen(s); i++){
    char upLetter = upcase(s[i]);  //add condition to avoid duplicates
    if(isalpha(s[i])&&isDuplicate(plain,upLetter)){ //skip punction
      plain[j++] = upLetter;
    }
  }
  plain[j] = '\0'; 
  return strcpy(s, plain);
}

//check the next letter if it is already existing
int isDuplicate(char* encode,char nextLett){ 
  char* iniEncode = encode; //remember the initial key 
 
  while(*encode != '\0'){//!!not sure if end with '\0'
    if(*encode != nextLett){ // no duplicate case
       encode++;
    }else{//duplicate with key
       return 1;
    }
  }
  //now, *encode == '\0', then add the letter to encode
  *encode = nextLett;
  *(encode++) = '\0';
  //point back to the first char of the key
  encode = iniEncode;
  return 0;
}

char nextChar(char* encode,char finalCh){
  char nextCh;
  if(finalCh < 'Z'){ // to sure 
    nextCh = final+1; 
  }else{
    nextCh = 'A'; 
  }

  int isDu = isDuplicate(encode,nextCh);
  if(isDu ==0){//sans duplicate and update the encode
    return nextCh;
  }else{
    nextChar(encode, nextCh);
  }
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
  int offset= strlen(key);//the length couting white space and punctions
  
  fixkey(key); // fix the key, i.e., uppercase and remove whitespace and punctuation
  int index = offset+strlen(key)-2; // the index of final letter of fixedKey
  // Do some stuff here to make a translation between plain and cypher maps.
  //creat a array to store the key
  //go through the key
  encode = key;
  //keep adding letter and updating encypered text
  int len;
  char nextCh;
  char encypered[27];//include '\0' at the end
  int i;
  // store fixed key to the encrypted array in correct index.
  for(i=offset-1;i<index;i++){
    encypered[i] = *key;
    key++;
  }


  while(len<26){
    len = strlen(encode);
    //find the final char of the key
    char finalCh = *(encode+=(len-1));
    nextCh = nextChar(encode,finalCh);
    index++;
    if(index==26){
      index = 0;
    }
      encypered[index]=nextCh;
  }
  encypered[26]='\0';
  strcpy(encode, encypered);
}
void buildtable (char* key, char* decode){ // this changed from encode
  char* encode = decode;
  buildtableEncode(key,encode);
  int i = 0;
  int orderIndex;
  for(;i<26;i++){
    char encyperedCh = encode[i];
    orderIndex = encyperedCh - 'A';
    decode[orderIndex]=encyperedCh;
  }

  // This function needs to build an array of mappings in 'encode' from plaintext characters
  // to encihered characters.

  // You are implementing a Caesar 1 & 2 combo Cypher as given in the lab handout.
  // Your code here:

  // probably need to declare some stuff here!
  
  

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
  ch = upcase(ch);
	fputc(decode[ch-'A'], stdout);
     else 
	fputc(ch, stdout);
      ch = fgetc(stdin);      // get next char from stdin
    }
}

