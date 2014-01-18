#include<stdio.h>
int gcd(int a,int b)
{
    if(b==0)
      return a;
    return gcd(b,a%b);
}
int main()
{
    int t,i,j,n;
    int count=0;
    scanf("%d",&t);
    while(t--)
    {
      scanf("%d",&n);
      int arr[n];
      count=0;
      for(i=0;i<n;i++)
        scanf("%d",&arr[i]);
      for(i=0;i<n;i++)
        for(j=i+1;j<n;j++)
          if(gcd(arr[i],arr[j])==1)
            count++;
      printf("%d\n",count);
    }
    return 0;
}
