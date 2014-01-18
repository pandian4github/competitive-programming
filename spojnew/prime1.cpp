#include<stdio.h>
bool sieve[1000][100000]={true};
int main()
 {
   long long int temp,i,p;
   for(p=2;p<=100000000;)
    {
      for(i=p*p;i<=1000000000;i=i+p)
        sieve[(i-1)/100000][(i-1)%100000]=false;
      temp=p;
      for(i=p+1;i<=1000000000;i++)
        if(sieve[(i-1)/100000][(i-1)%10000]==true)
         {
           p=i;
           break;
         }
      if(p==temp)
        break;   
    }    
   int t;
   long long int a,b;
   sieve[0][0]=false;
   scanf("%d",&t);
   while(t--)
    {
      scanf("%lld %lld",&a,&b);
      for(i=a;i<=b;i++)
        if(sieve[(i-1)/100000][(i-1)%100000])
          printf("%lld\n",i);
      printf("\n");
    }
   return 0;
 }     
