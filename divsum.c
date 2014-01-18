#include<stdio.h>
#include<math.h>
int main()
 {
   int t,s,i,j,a,q;
   scanf("%d",&t);
   for(i=0;i<t;i++)
    {
      scanf("%d",&a);
      if(a==1||a==0)
        {
         printf("0\n");
         continue;
        } 
      s=1;  
      q=sqrt(a);
      for(j=2;j<=q;j++)
        if(a%j==0)
           s=s+j+a/j;
       if(q*q==a)
         s=s-q;    
       printf("%d\n",s);
     }
    return 0;
  }         
