#include<stdio.h>
int main()
{ 
  long long int a,b;
  scanf("%lld%lld",&a,&b);
  long long int i,j;
  long long int s=0;
  for(i=a;i<=b;i++)
   {
     j=i;
     while(j!=0)
      {
       s=s+j%10;
       j/=10;
      }
   }
  printf("%lld\n",s);
  return 0;
 }     
       