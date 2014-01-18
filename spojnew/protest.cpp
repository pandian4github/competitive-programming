#include<stdio.h>
   #include<conio.h>
   int a=5;
   int change();
   int main()
   {
    int x;
    x=!a+change();
    printf("%d",x);
    getch();
    return 0;
   }
   int change()
   {
    a=0;
    return 0;
   }

