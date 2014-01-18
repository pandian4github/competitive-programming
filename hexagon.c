#include<stdio.h>
int main()
 {
   char a,b,c;
   a='_';
   b='\\';
   c='/';
   printf("%2c\n",a);
   printf("%c%2c\n",c,b);
   printf("%c%c%c\n",b,a,c);
   printf("\n");
   return 0;
 }  
   
