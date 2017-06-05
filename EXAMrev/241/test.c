#include <stdio.h>
int main(void)
   { int x, y;
     y = 1234;
     for (x = 5; x>=0; x--)
       y = y/x;
     printf("%d\n", y);
     return 0;
}