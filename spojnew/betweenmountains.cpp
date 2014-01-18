#include<stdio.h>
#include<algorithm>
using namespace std;
int binarysearch1(int arr[],int l,int r,int k)
{
    int m=(l+r)/2;
    if(k<arr[l])
      return arr[l];
    if(k>arr[r])
      return -1;
    if(arr[m]==k)
      return arr[m];
    else
     if(arr[m]<k)
       return binarysearch1(arr,m+1,r,k);
     else
       return binarysearch1(arr,l,m-1,k);
}
int binarysearch2(int arr[],int l,int r,int k)
{
    int m=(l+r)/2;
    if(k<arr[l])
      return -1;
    if(k>arr[r])
      return arr[r];
    if(arr[m]==k)
      return arr[m];
    else
     if(arr[m]<k)
       return binarysearch2(arr,m+1,r,k);
     else
       return binarysearch2(arr,l,m-1,k);
}

int main()
{
  int t,m,n,x,y,t1,t2,min,i;
  scanf("%d",&t);
  while(t--)
  {
    scanf("%d",&m);
    int a[m];
    for(i=0;i<m;i++)
      scanf("%d",&a[i]);
    scanf("%d",&n);
    int b[n];
    for(i=0;i<n;i++)
      scanf("%d",&b[i]);
    sort(b,b+n);
    min=1000000000;
    for(i=0;i<m;i++)
    {      
      x=binarysearch1(b,0,n-1,a[i]);
      y=binarysearch2(b,0,n-1,a[i]);
    //  printf("a[%d] : %d  x : %d y : %d\n",i,a[i],x,y);
      if(x!=-1)
        t1=x-a[i];
      else
        t1=1000000000;
      if(y!=-1)
        t2=a[i]-y;
      else
        t2=1000000000;
      if(min>t1)
        min=t1;
      if(min>t2)
        min=t2;
    }
    printf("%d\n",min);
  }
  return 0;
}
      
    
