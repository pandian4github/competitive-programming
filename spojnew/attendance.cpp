#include<stdio.h>
int main()
 {
   long int t;
   int m,a,newm;
   double d;
   scanf("%ld",&t);
   while(t--)
    {
      scanf("%d %d",&m,&a);
      d=(m-a)*100.0/95;
      newm=(int)(d+0.5);
      if(m==newm)
        printf("same\n");
      else
        if(m<newm)
          printf("profit\n");
        else
          printf("loss\n");
    }
   return 0;
 }       
      
