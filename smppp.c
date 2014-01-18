#include<stdio.h>
int main()
 {
  long long int a,b,i,j,s=0;
  scanf("%lld%lld",&a,&b);
  for(i=a;i<=b;i++)
   {
     for(j=i;j!=0;j=j/10)
      s=s+j%10;
   }
  printf("%lld\n",s);
  return 0;
 }    
      
     
