#include<stdio.h>
int main()
 {
   int i,t;
   scanf("%d",&t);
   long double a[t],d;
   for(i=0;i<t;i++)
    scanf("%Lf",&a[i]);
   for(i=0;i<t;i++)
      {
       d=4*a[i]*a[i]+0.25;
       printf("Case %d: %0.2Lf\n",i+1,d); 
      } 
   return 0;
 }     
