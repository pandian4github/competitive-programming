#include<stdio.h>
int main()
 {
  int a=199999;
  int r;
  r=a%100000;
  printf("\n\n%d\n\n",r);
 
  printf("\n\n%d\n\n",(int)(0.999999999*100000));
  if(r==(int)(0.99999999999*100000))
   printf("\nT ll work. . \n\n");
 else
   printf("\nBUSSSS\n");
  return 0;
 }
