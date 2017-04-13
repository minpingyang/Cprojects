#include <stdio.h>
#define SIZE 80
void spacedel_ptr(char *str1);
void spacedel_ary(char *t);

int main() {

	// TODO – do not forget to read in two strings
	// TODO – the names of the variables are strp and strq
	char *strp;
	char strq[SIZE];
	
	gets(strp);
	printf("Original strp: [%s]\n", strp);
	spacedel_ptr(strp);
	printf("Spaceless strp: [%s]\n", strp);


	gets(strq);
	printf("Original strq: [%s]\n", strq);
	spacedel_ary(strq);
	printf("Spaceless strq: [%s]\n", strq);
	return 0;
}



void spacedel_ptr(char *str1) {
	// TODO – here you implement the function for removing spaces
	// In this function you are not allowed to use array indices
	// or *(ptr + int) like expressions.
	// You have to iterate through the array elements using
	// pointers instead!
	// Do not forget that a string is concluded by a null-terminator

	
	int isSpace = 0;
	char* pointer =str1;
	while(1) {
		if(*str1 != '\0'){

			if(*str1 == ' ') {
				
				char* temp = str1;
				while(*temp != '\0'){
					*temp = *(temp+1);
					if(*temp == ' '){
						isSpace = 1;
					}
					temp++;
				}
			}
			str1++;
		}else if(isSpace){
			isSpace = 0;
			str1 = pointer;
		}else{
			break;
		}

		
	}

}




void spacedel_ary(char *t) {
	// TODO – here you implement the function for removing spaces
	// In this function you have to work with the string as an array,
	// i.e. you have to use array indices
	// Do not forget that a string is concluded by a null-terminator 
	int isSpace = 0;
	int i =0;
	int j = 0;
	while(1) {
		if(t[i] != '\0'){
			if(t[i] == ' ') {
				j = i;
				char temp = t[j];
				while(temp != '\0'){
					 t[j] =t[j+1];//index of space ---> store next element
					 temp = t[j];//temp =next element;
					 if(temp == ' '){
						isSpace = 1;
					  }
					 j++;
				}
			}
			i++; 	
		}else if (isSpace){
			isSpace = 0;
			i = 0;
			j = 0;
		}else{
			break;
		}
		
		
	}

}



