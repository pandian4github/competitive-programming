#include<stdio.h>
int main()
 {
   int t;
   scanf("%d",&t);
   long long int a,arr[t],i,j,k,c=0;
   for(i=0;i<t;i++)
    scanf("%lld",&arr[i]);
   for(i=0;i<t;i++)
    {
      c=0;
      a=arr[i];
      for(j=1;;j++)
       {
     l:    for(k=1;k<=j;k+=2)
          if(j%k==0)
            {
             c++; 
             if(c>a)
              {
               j++;
               goto l;
              }
            } 
        if(c==a)
         {
          printf("%lld\n",j);
          break;
         }
      }
    } 
    return 0;
  }        
             
             
   
