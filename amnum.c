#include<stdio.h>
long long int power(int a,int b)
 {
  long long int x=1;
  int i;
  for(i=1;i<=b;i++)
   x=x*a;
  return x;
 }
int main()
 {
  long long int t,x,z,y;
  int r,k,i;
  scanf("%lld",&t);
  if(t==1)
    printf("5");
  else
    if(t==2)
     printf("6");
    else
     {
      for(k=3;;k++)
       {
        if(t>=(power(2,k-1)-1)&&t<=(power(2,k)-2))
         {
          r=k-1;
          break;
         }
       }
       x=power(2,r)-1;
       y=power(2,r+1)-2;
       for(i=1;i<=r;i++)
       { 
        z=(x+y)/2;
        if(t<=z)
         {
          printf("5");
          y=z;
         }
        else
         {
          printf("6");
          x=z;
         }
       }
     }
   printf("\n");
   return 0; 
 }
     
