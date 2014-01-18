#include<stdio.h>
int main()
 {
   int n,s=0,i;
   scanf("%d",&n);
   s=n*(n*n+6*n-1)/6;
   for(i=1;i <n;i++)
    if(n-i>=i)
       s=s+i*(i-1)/2;
    else
     s=s+i*(4*n-3*i)-n*(n+1);
   printf("\n\n%d\n\n",s);
   return 1;
  }           
