#include<stdio.h>
int main()
 {
   long long int a[100];
   long long int n,c;
   int t;
   scanf("%d",&t);
   long long  int i,j,k;
   for(i=0;i<t;i++)
    {
      scanf("%lld",&n);
      for(j=1;;j++)
       {
         c=0;
         for(k=1;k<=j;k+=2)
            if(j%k==0)
             c++;
         if(c==n)
           {
             a[i]=j;
             break;
           }
       }
     }
   for(i=0;i<t;i++)
    printf("%lld\n",a[i]);
   return 0;
   }            
             
