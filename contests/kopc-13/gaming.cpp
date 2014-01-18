#include<stdio.h>
int main()
{
    int t,n,k,l,w,sum;
    double router,lan;
    scanf("%d",&t);
    while(t--)
    {
      scanf("%d %d %d %d",&n,&k,&l,&w);
      router=w/(k*1.0);
      lan=l/2.0;
      sum=0;
      if(lan<=router)
        printf("%d\n",l*(n-1));
      else
      {
        while(n>1)
        {
          sum=sum+(n/k)*w;
          n=n%k+n/k;
        }
        printf("%d\n",sum);
      }
    }
    return 0;
}
      
        
      
