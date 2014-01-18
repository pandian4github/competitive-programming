#include<stdio.h>
int main()
 {
   int t,p;
   long long int n;
   scanf("%d",&t);
   while(t--)
    {
      scanf("%lld %d",&n,&p);
      if(p==0)
        printf("Airborne wins.\n");
      else
        printf("Pagfloyd wins.\n");
    }
   return 0;
 }       
