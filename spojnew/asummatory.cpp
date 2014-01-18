#include<stdio.h>
long int f[1000001],g[1000001];
int main()
 {
   long long int i;
   int t,n;
   f[1]=g[1]=1L;
   for(i=2;i<=1000000;i=i+1LL)
     {
      f[i]=(f[i-1]+(i*i*i))%1000000003;
      g[i]=(g[i-1]+f[i])%1000000003;
     }
   scanf("%d",&t);
   while(t--)
    {
      scanf("%d",&n);
      printf("%ld\n",g[n]);
    }
   return 0;
 } 
      
   
