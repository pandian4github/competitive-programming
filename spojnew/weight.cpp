#include<stdio.h>
int calc(int i,int n)
{
  int i,j;
  int ne=next[i];
  int a=2*sum[i]+remsum[i];
  int b=2*sum[ne]+remsum[ne];
  
int main()
{
  int t;
  scanf("%d",&t);
  while(t--)
  {
    scanf("%d",&n);
    for(i=0;i<n;i++)
      scanf("%d",&arr[i]);
    w[0]=1;
    for(i=1;i<n;)
    {
      if(arr[i]<0)
      {
        temp=i;
        sum=arr[i];
        i++;
        l=1;
        remsum=0;
        while(i<n && arr[i]<0)
        {
          sum=sum+arr[i];
          remsum+=l*arr[i];
          l++;
          i++;
        }
        su[temp]=sum;
        remsu[temp]=remsum;
      }
      else
      {
        next[temp]=i;
        sum=arr[i];
        temp=i;
        i++;
        l=1;
        remsum=0;
        while(i<n && arr[i]<0)
        {
          sum=sum+arr[i];
          remsum+=l*arr[i];
          l++;
          i++;
        }
        su[temp]=sum;
        remsu[temp]=remsum;
      }
    }
    for(i=1;arr[i]>=0;i++)
       w[i]=w[i-1]+1;
    for(;i<n;)
    {
      i=calc(i,n);
    }          
      
    
