#include<stdio.h>
int main()
 {
   int n,count;
   while(1)
    {
      scanf("%d",&n);
      if(n==0)
        break;
      count=0;  
      while(1)
       {
         if(n==1)
           break;
         count++;
         n=n/2;
       }
      printf("%d\n",count);
    }
   return 0;
 }   
    
