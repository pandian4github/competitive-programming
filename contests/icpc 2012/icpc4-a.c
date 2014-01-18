#include<stdio.h>
int main()
{
  int t,n,q,i,l,r;
  scanf("%d",&t);
  while(t--)
  {
    scanf("%d %d",&n,&q);
    int arr[n];
    long long int sumarr[n];
    for(i=0;i<n;i++)
      scanf("%d",&arr[i]);
    sumarr[0]=arr[0];
    for(i=1;i<n;i++)
      sumarr[i]=arr[i]+sumarr[i-1];
    for(i=0;i<q;i++)
    {
      scanf("%d %d",&l,&r);
      if(l==0)
        printf("%lld\n",sumarr[r]);
      else
        printf("%lld\n",sumarr[r]-sumarr[l-1]);
    }
  }
  return 0;
}
      
