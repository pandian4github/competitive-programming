#include<stdio.h>
int main()
 {
   int t;
   long int m,n;
   scanf("%d",&t);
   while(t--)
    {
      scanf("%ld %ld",&m,&n);
      if((m==0||n==0)&&!(m==0&&n==0))
      {
        printf("0\n");
        continue;
      }
      if(((m-n)&((n-1)/2))==0)
        printf("1\n");
      else
        printf("0\n");
    }
   return 0;
 } 
