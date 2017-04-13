#include <stdio.h>
char* my_strchr(char* str, char c);
#define SIZE 80

int main()
{	
	char str[80];
	char c;
	printf("Enter the string: ");
	// TODO – here you read in the string
	// TODO – the variable name is str
	gets(str);

	printf("Enter the character: ");
	// TODO – here you read in the character
	// TODO – the variable name is c
	scanf("%c",&c);

	char* result = my_strchr(str, c); 
	// printf("Substring: %s \n", result);
	if (result == NULL)
	{
		printf("Couldn't find %c.\n", c);
	}
	else
	{
		printf("Substring: %s \n", result);
	}
}
char* my_strchr(char* str, char c)
{
	// TODO – here you implement the function

	//remeber the first character mermory address
	char* temp;
	while(*str != '\0'){

		if(*str == c){
		
		return temp = str;
				
		}
		str++;
	}
	return NULL;
}
