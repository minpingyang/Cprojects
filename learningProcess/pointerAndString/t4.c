#include <stdio.h>

char* my_strchr(char* str, char c)
{
	// TODO – here you implement the function
}

int main()
{
	printf("Enter the string: ");
	// TODO – here you read in the string
	// TODO – the variable name is str

	printf("Enter the character: ");
	// TODO – here you read in the character
	// TODO – the variable name is c

	char* result = my_strchr(str, c); 

	if (result == NULL)
	{
		printf("Couldn't find %c.\n", c);
	}
	else
	{
		printf("Substring: %s \n", result);
	}
}
