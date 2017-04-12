
/* strlen example */
#include <stdio.h>
#include <string.h>

int main ()
{
  	char *strp;
  	char *pointer;
  	char temp;
  	int i = 0;
  	int j = 0;
	printf("Enter a string: \n");
	scanf("%[^\n]",strp);
	printf("%s\n",strp );


	while (strp[i] != '\0'){
		
		if(strp[i] != ' '){
			temp = strp[i];
			printf("%c\n",temp);
		}
		
		i++;
	}
	printf("done\n");
	// int i= 0;
	// 
	// while(strp[i] !='\0'){
		
	// 	if(strp[i] != ' '){
	// 		temp= strp[i];
	// 		j++;
	// 	}
	// 	i++;
	// }
	
	// printf("%s\n",strp );
  return 0;
}