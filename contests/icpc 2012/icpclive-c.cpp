#include<stdio.h>
#include<algorithm>
using namespace std;
int binarysearch1(int arr[],int l,int r,int k) // smallest element >= key
{
    int t,m=(l+r)/2;
    if(k<arr[l])
      return l;
    if(k>arr[r])
      return -1;
    if(arr[m]==k)
      {
       t=m;
       while(t>=0)
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
        return binarysearch1(arr,m+1,r,k);
     else
       return binarysearch1(arr,l,m-1,k);
}
int binarysearch2(int arr[],int l,int r,int k)  // greatest element <=key
{
    int t,m=(l+r)/2;
    if(k<arr[l])
      return4 l-1;
    if(k>arr[r])
      return r;
    if(arr[m]==k)
    {
      t=m;
      while(arr[t+1]==m)
        t++;
      return t;
    }
    else
     if(arr[m]<k)
     //  {
     //   if(m+1<n && arr[m+1]>k)
     //     return m;
        return binarysearch2(arr,m+1,r,k);
    //   }
     else
       return binarysearch2(arr,l,m-1,k);
}
int main()
{
  int t,n,i,j,k,count,l,r,ind,l1,r1,l1ind,r1ind;
  scanf("%d",&t);
  while(t--)
  {
    count=0;
    scanf("%d %d %d",&n,&l,&r);
    int arr[n];
    int arr2[n*n+2];
    for(i=0;i<n;i++)
      scanf("%d",&arr[i]);
    for(i=0;i<n;i++)
      for(j=i+1;j<n;j++)
        arr2[ind++]=arr[i]+arr[j];
    for(i=0;i<ind;i++)
      printf("%d  ",arr2[i]);
    printf("\n\n");
    sort(arr,arr+n);
    for(i=0;i<n;i++)
      printf("%d  ",arr[i]);
    printf("\n\n");
    count=0;
    for(i=0;i<n;i++)
    {
      for(j=i+1;j<n;j++)
      {
        sum=arr[i]+arr[j];
        l1=l-sum;
        r1=r-sum;
        lind=binarysearch1(arr,0,i-1,l1);
        rind=binarysearch2(arr,0,i-1,r1);
        if(lind!=-1 && rind!=-1)
          count=count+rind-lind+1;
        lind=binarysearch1(arr,i+1,j-1,l1);
        rind=binarysearch2(arr,i+1,j-1,r1);
        if(lind!=-1 && rind!=-1)
          count=count+rind-lind+1;
        lind=binarysearch1(arr,j+1,n-1,l1);
        rind=binarysearch2(arr,j+1,n-1,r1);
        if(lind!=-1 && rind!=-1)
          count=count+rind-lind+1;
        printf("%d\n",count);
        
        
    for(i=0;i<ind;i++)
    {
      l1=l-arr2[i];
      r1=r-arr2[i];
      printf("arr2[%d] : %d  l1 : %d  r1 : %d  \n",i,arr2[i],l1,r1);
      l1ind=binarysearch1(arr,0,n-1,l1);
      r1ind=binarysearch2(arr,0,n-1,r1);
      printf("lind : %d  rind : %d\n",l1ind,r1ind);
      if(l1ind!=-1 || r1ind!=-1)
        count=count+r1ind-l1ind+1;
      printf("count : %d \n\n",count);
    }
    printf("%d\n",count);
  }
  return 0;
}
