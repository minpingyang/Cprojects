#include <stdio.h>
#define SIZE 80
void contact1(char *,char*);
// void concat(char *,char *);

int main(){
	char string1[SIZE];
	char string2[SIZE];
	printf("Enter string with space :\n");
	gets(string1);
	contact1(string1,string2);
}

void contact1(char *str1,char * str2){
	

	char *conc = str2;
	
	
	while(*str1 != '\0'){
		if(*str1 == ' '){			
			str1++;
		}else {			
			*str2 = *str1;
			str1++,str2++;
		}
	}
	*str2='\0';
	puts(conc);
}







// int main()
// {
//     char string1[SIZE]="\0",string2[SIZE]="\0";

//     printf("Enter String 1:\n");
//     gets(string1);
//     printf("Enter String 2:\n");
//     gets(string2);

//     concat(string1,string2);

//     return 0;
// }

// void concat(char *str1,char *str2)
// {
//     char *conc=str1;

//     while(*str1!='\0'){
//         str1++;
//     }

//     *str1=' '; //  \0 ---> space
//     str1++;		// after space +1 index

//     while(*str2!='\0')
//     {
//         *str1=*str2; // add 
//         str1++,str2++;
//     }

//     *str1='\0';
//     printf("Concatenated String:\n");
//     puts(conc);

// }