#include<stdio.h>
int main()
 {
   int i=0,t,n,s=0;
   scanf("%d",&t);
   for(;i<t;i++)
    {
     scanf("%d",&n);
     (n>0)?s+=n:s;
    } 
   printf("%d\n",s);
   return 0;
 }   
   
