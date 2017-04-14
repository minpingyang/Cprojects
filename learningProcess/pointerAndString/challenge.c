#include <stdio.h>
void trim(char *str, char *dst); 


int main() {
    char s1[80];
    char s2[80];
    // char s3[80];
    // TODO – here you read the input
    
    // trim(s1, s2);

 	printf("Enter a string with leading and trailling space\n");
    gets(s1);
    printf("Before: [%s]\n", s1);
    trim(s1,s2);
    printf("After:  [%s]\n", s2);
 	//puts(s2);
}

void trim(char *str, char *dst) {
    // TODO – here you implement your trimmer function 
   char* oneSpace = dst;   /* Destination to copy to */
    int removeLeading = 0;
	while(*str != '\0'){

		if(*str == ' ' && !removeLeading){
		  str++;
		  	
		}else if(*str != ' '|| removeLeading){
			removeLeading = 1;
			*dst = *str;
			dst++,str++;
			
		}
		
	}
	//check if exist trailling space after the string
	//remove the trailling space
	dst--;
	while(*dst == ' '){
			dst--;
	}
	
	dst++;
	*dst ='\0';
	
	// remove multiple sapce

	dst = oneSpace;
	char* source = dst;
	

    /* While we're not at the end of the string, loop... */
    while (*dst != '\0')
    {
        /* Loop while the current character is a space, AND the next
         * character is a space
         */
        while (*dst == ' ' && *(dst+ 1) == ' ')
            dst++;  /* Just skip to next character */

       /* Copy from the "source" string to the "destination" string,
        * while advancing to the next character in both
        */
       *source++ = *dst++;
    }

    /* Make sure the string is properly terminated */    
    *source= '\0';
	

	
	
	
}