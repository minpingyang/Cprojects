#include<stdio.h>
void inout(int *);

int main() {
	int a = 0;
	printf("%d\n", a);
	inout(&a);
	printf("%d\n", a);
}

void inout(int * test) {
	*test = *test + 1;
}
