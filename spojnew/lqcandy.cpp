#include<stdio.h>
#include<math.h>
int main()
 {
   long long int n,a,b;
   int t,i,count;
   scanf("%d",&t);
   long long int parr[65];
   for(i=0;i<65;i++)
     parr[i]=pow(2,i);
   while(t--)
    {
      scanf("%lld",&n);
      for(i=0;i<65;i++)
        if(parr[i]>=n)
         {
           printf("%lld ",parr[i]);
           break;
         }
      a=parr[i];
      b=n;
      count=0; 
      while(1)
      {
        if(a==b)
          break;
        count++;
        if(b>a/2)
         b=b-a/2;
        a=a/2;
      }     
      printf("%d\n",count);
    }
   return 0;
 }   
          
