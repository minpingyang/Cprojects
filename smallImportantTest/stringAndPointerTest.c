#include <stdio.h>
#include <string.h>
#include <unistd.h>
int main()

{	
	//The standard fornat specifier for readin strings with scanf() is %s
	//that the & is not require in the case of strings, since the string is memory
	//address itseef
	//scanf() appends a \0 to the end of the character string stored
	// scanf() does skip ober any any leading whitespace characters in characters
	//in order to find the first non-whitespace character
	// the width field can be used to limit the maximum number of characters to read from the input
	// You should use one character less as inout than the size of the array used for holding the result

	// char str[6];
	// printf("Hi\n");
	// scanf ("%5s",str); //if you enter "HelloBello123xyz"
	// printf("%s\n",str); //only the first 5 characters be read and a concluding \0 will be put at the end

	//scanf() reads un a strung if characters only up to the first non-whitespcae character
	//it stops reading when it encounters a space,tab or newLine character

	//C supports a format specification known as the edit se conversion code %[..]
	//-it can be used to read a line containing a variety of characters,including white space
	// char str [1];
	// printf("Enter a string :\n");
	// scanf("%3[^' ']",str);
	// printf("0:%c\n",str[0]);
	
	// printf("%2s\n",str);
	//always use the width field to limit the maximum number of characters to read with "%s" and "%[..]" in all production quality code!
	//-No exceptions!

	//gets() is used to scan a line of text from a standard input device
	//The gets() function will be terminated by newline character
	//the newline character won't be included as part of the string
	//the string may include white space characters
	//\0 is always appended to the end of the string of stored characters;
	//reading strings character by character
	//read in hcaracter by character is useful when
	//-you don't know how long the string might be
	//-or if you want to consider other stopping conditions besodes spaces and newLines
	//eg. stop on periods, or when two successive slashes //are envountered
	//The scanf() format specifier for reading individual character is %c
	//-here you must use & symbol
	// if a width greater than 1 is given (%2c).then multiple characters are read,
	//???????????and stored in successive, and stored in successive positions in a char array???
	//sscanf() and sprintf() are used for the same goal,but instead of the standard input/output they use strings
	//one of their main advantage is when you need to prepare a string for later use
	//The ctype.h header
	//ctype.h declares a set of functions to classify and transform individula chars
	//#include<ctype.h> is required to use any of these functions
	//some of the more commonly used functions:
	//-isupper() --checks if a character is an uppercase letter
	// a value different from zero is returned if the character is an uppercase alphabetic letter, zero otherwised
	//-toupper() -converts a character to its uppercase equivalent if the character is an lowercase
	//if no such conversion is possible, the returned value is unchanged
	//#include<string.h> defines several functions to manipulate null-byte terminated arrays of chars
	//-#include <string,h> is required to use any of these fuctions
	//-strcpy() --
	//strcat() -----concatenates (appends) source to the end of destination 
	//strlen()  --returns length of the string,not counting the \0;
	//strcmp(s1,s2) -0 negative positive   first-second
	// char str[15];
	// printf("Enter your name: \n");
	// gets(str);
	// printf("%s\n",str );
	//stdlib.h defines several functions including searching, sorting and converting
	//-#include <stdlib.h> is required to use any of tehse functions
	//coomon used atoi(),atof(),atol(),atoll()parses a stirn of numeric characters into a number of type int,double,long int,long long int.


//Copy string
// Copies the C string pointed by source into the array pointed by 
	// destination, including the terminating null character (and 
	// 	stopping at that point).

	// char str1[]="Sample string";
 //  	char str2[40];
 //  	char str3[40];
 //  	strcpy (str2,str1);
 //  	strcpy (str3,"copy successful");
 //  	printf ("str1: %s\nstr2: %s\nstr3: %s\n",str1,str2,str3);
 
 //Concatenate strings	
// Appends a copy of the source string to the destination string. 
//The terminating null character in destination is overwritten by
// the first character of source, and a null-character is included
// at the end of the new string formed by the concatenation of both
// in destination.

// destination and source shall not overlap.

  	// char str[80];
  	// strcpy (str,"these ");
  	// strcat (str,"strings ");
  	// strcat (str,"are ");
  	// strcat (str,"concatenated.");
  	// printf("%s\n",str );
  	// puts (str);


	  char key[] = "apple";
	  char buffer[80];
	  do {

	     printf ("Guess my favorite fruit? ");
	     fflush (stdout);
	     //sleep(1);
	     scanf ("%79s",buffer);
	      printf("%d\n",strcmp (key,buffer));
	  } while (strcmp (key,buffer) != 0);
	  puts ("Correct answer!");
  	

	  // int     i;
   //      for( i=0; i<12; i++ )
   //      {
   //              printf( "a" );
   //              // fflush( stdout ); //输出并清空
   //              sleep( 1 );
   //      }

        

	// char str[]="This is an ";
	// printf("%s",str);
	// puts("example string.");
	// printf("See??\n");

	// char* str = "Hello world";
	// char str[] = "Onedfdfdfdf\0Two";
	// printf("%.5s\n","abcdefghi");
	// printf("%5s\n","abcdefghi"); //show at least 5characters
	// printf("%5s\n","a");
	// printf("-2:%c\n", str[-2]);
	// printf("-1:%c\n", str[-1]);
	// printf("0:%c\n", str[0]);
	// printf("5:%c\n", str[5]);//space
	// printf("6:%c\n", str[6]);
	// printf("10:%c\n", str[10]);//d
	// printf("11:%c\n", str[11]);//nykk
	// printf("12:%c\n", str[12]);
	// printf("13:%c\n", str[13]);
	// printf("13:%c\n", str[14]);
	// printf("25:%c\n", str[25]);
	return 0;
}
