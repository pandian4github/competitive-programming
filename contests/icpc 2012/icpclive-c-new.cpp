#include<stdio.h>
#include<algorithm>
using namespace std;
int binarysearch1(int arr[],int l,int r,int k,int left,int right) // smallest element >= key
{
    int t,m=(l+r)/2;
    if(l>r)
      return -1;
    if(k<arr[l])
      return l;
    if(k>arr[r])
      return -1;
    if(arr[m]==k)
      {
       t=m;
       while(t>=0 && t-1>=left)
       {
         if(arr[t-1]==k)
           t--;
         else
           break;
       }
       return t;
      }
    else
     if(arr[m]<k)
        return binarysearch1(arr,m+1,r,k,left,right);
     else
       return binarysearch1(arr,l,m-1,k,left,right);
}
int binarysearch2(int arr[],int l,int r,int k,int left,int right)  // greatest element <=key
{
    int t,m=(l+r)/2;
    if(l>r)
      return -1;
    if(k<arr[l])
      return -1;
    if(k>arr[r])
      return r;
    if(arr[m]==k)
    {
      t=m;
      while(t<=r && t+1<=right)
      {
        if(arr[t]==m)
          t++;
        else
          break;
      }
      return t;
    }
    else
     if(arr[m]<k)
        return binarysearch2(arr,m+1,r,k,left,right);
     else
       return binarysearch2(arr,l,m-1,k,left,right);
}
int main()
{
  int t,sum,n,i,j,k,count,l,r,ind,l1,r1,l1ind,r1ind,lind,rind;
  scanf("%d",&t);
  while(t--)
  {
    count=0;
    scanf("%d %d %d",&n,&l,&r);
    int arr[n];
    for(i=0;i<n;i++)
      scanf("%d",&arr[i]);
    sort(arr,arr+n);
    count=0;
    for(i=0;i<n;i++)
    {
      for(j=i+1;j<n;j++)
      {
   //     printf("i : %d  j : %d\n\n",i,j);
        sum=arr[i]+arr[j];
        l1=l-sum;
        r1=r-sum;
   //     printf("sum : %d  l1 : %d  r1 : %d\n",sum,l1,r1);
        lind=binarysearch1(arr,j+1,n-1,l1,j+1,n-1);
        rind=binarysearch2(arr,j+1,n-1,r1,j+1,n-1);
        if(lind!=-1 && rind!=-1)
          count=count+rind-lind+1;
   //     printf("%d %d lind : %d rind : %d\n",j+1,n-1,lind,rind);
   //     printf("count : %d\n",count);
      }
    }
   printf("%d\n",count);
  }
  return 0;
}
