#include <stdio.h>

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
	char str [1];
	printf("Enter a string :\n");
	scanf("%3[^' ']",str);
	printf("0:%c\n",str[0]);
	
	printf("%2s\n",str);
	//always use the width field to limit the maximum number of characters to read with "%s" and "%[..]" in all production quality code!
	//-No exceptions!



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
