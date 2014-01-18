#include<stdio.h>
int main()
 {
   int t;
   long long int n,count;
   scanf("%d",&t);
   while(t--)
    {
      scanf("%lld",&n);
      if(n==0||n==1)
       {
         printf("0\n");
         continue;
       }
      count=((n+1)*(n))/6LL;
      printf("%lld\n",count);
    }
   return 0;
 }      
