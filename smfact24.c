#include<stdio.h>
int main()
 {
   int t;
   scanf("%d",&t);
   int i,n;
   long long int res[t];
   for(i=0;i<t;i++)
    {
      res[i]=1;
      scanf("%d",&n);
      while(n!=0)
       {
         res[i]*=n;
         n--;
       }
    }
   for(i=0;i<t;i++)
     printf("\n%lld",res[i]);
   return 0;  
  }        
      
            
