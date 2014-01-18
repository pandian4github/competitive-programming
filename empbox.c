#include<stdio.h>
int main()
 {
   int t,i;
   scanf("%d",&t);
   long long int arr[t],n,T,f,k;
   for(i=0;i<t;i++)
    {
      fflush(0);
      scanf("%lld%lld%lld%lld",&n,&k,&T,&f);
      arr[i]=(f-n)/(k-1)+f;
    }
   for(i=0;i<t;i++)
    printf("%lld\n",arr[i]);
  return 0;  
 }      
