#include<stdio.h>
int main()
 {
   long long int t,i,init,p,p1,n,j;
   scanf("%lld",&t);
   for(i=1;i<=t;i++)
    {
      scanf("%lld",&n);
      init=0;
      p=0;
      for(j=0;j<n;j++)
        {
          scanf("%lld",&p1);
          if(p+p1<=0)
            {
              init+=(-1)*(p+p1)+1;
              p=1;
            }
          else
            p=p+p1;  
        }
      if(init==0)
        init++;  
      printf("Scenario #%lld: %lld\n",i,init);
    }
   return 0;
 }         
            
