#include<stdio.h>
int main()
 {
   int t;
   long int m,n,temp;
   scanf("%d",&t);
   while(t--)
    {
      scanf("%ld %ld",&m,&n);
      temp=(n+1)/2;
      if(m==0||n==0)
        temp=0;
      if(m==n)
        temp=1;
      printf("%d\n",temp%2);
    }
   return 0;
 } 
