#include<stdio.h>
int main()
 {
   int t;
   long int i,n;
   long long int power[1000001];
   power[0]=1LL;
   power[1]=2LL;
   for(i=2;i<=1000000;i++)
     power[i]=(power[i-1]*power[i-2])%1000000007LL;
   scanf("%d",&t);
   while(t--)
    {
      scanf("%ld",&n);
      printf("%lld\n",power[n]);
    }
   return 0;
 } 
