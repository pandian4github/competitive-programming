#include<stdio.h>
long int power(long int x,long int y)
 {
   if(y==0)
     return 1;
   if(y%2==0)
     return ((power(x,y/2)%10000007)*(power(x,y/2)%10000007))%1000007;
   else
     return (2*(power(x,y/2)%10000007)*(power(x,y/2)%10000007))%10000007;
 }
int main()
 {
   long int n,k,ans;
   while(1)
    {
      scanf("%ld %ld",&n,&k);
      if(n==0&&k==0)
        break;
      ans=(2*power(n-1,n-1)+2*power(n-1,k)+power(n,n)+power(n,k))%10000007; 
      printf("%ld\n",ans);
    }
   return 0;
 } 
