#include<stdio.h>
int main()
 {
   long long int n,mg,mn,t,i,j,temp,max1;
   int c;
   scanf("%lld",&t);
   for(i=0;i<t;i++)
    {
      c=0;
      scanf("%lld%lld",&mg,&mn);
      max1=max2=0;
      for(j=0;j<mg;j++)
       {
         scanf("%lld",&temp);
         if(temp>max1)
          max1=temp;
       }
      for(j=0;j<mn;j++)
       {
         scanf("%lld",&temp);
         if(temp>max1)
          {
           c=1;
           break;
          } 
       }
      if(!c)
        printf("Godzilla\n");
      else
        printf("MechaGodzilla\n");
    }
   return 0;
 }         
         
