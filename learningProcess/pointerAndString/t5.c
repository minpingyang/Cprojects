#include <stdio.h>
void trim(char *str, char *dst); 


int main() {
    char s1[80];
    char s2[80];
    
    // TODO – here you read the input
    
    trim(s1, s2);

 	printf("Enter a string with leading and trailling space\n");
    gets(s1);
    printf("Before: [%s]\n", s1);
    trim(s1,s2);
    printf("After:  [%s]\n", s2);
 	//puts(s2);
}

void trim(char *str, char *dst) {
    // TODO – here you implement your trimmer function 
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
	*dst ='\0';
	
}