#include<stdio.h>
int partition(long int a[],int p,int r)
 {
   int i,j;
   long int x,temp;
   i=p-1;
   x=a[r];
   for(j=p;j<r;j++)
    {
      if(a[j]<=x)
       {
         i=i+1;
         temp=a[i];
         a[i]=a[j];
         a[j]=temp;
       }
    }
   temp=a[i+1];
   a[i+1]=a[r];
   a[r]=temp;
   return i+1;
 }
void quicksort(long int a[],int p,int r)
 {
   int q;
   if(p<r)
    {
      q=partition(a,p,r);
      quicksort(a,p,q-1);
      quicksort(a,q+1,r);
    }
 }
int main()
 {
   int t;
   scanf("%d",&t);
   while(t--)
    {
      scanf("%d %d",&n,&c);
      long int arr[n];
      for(i=0;i<n;i++)
        scanf("%d",&arr[i]);
      quicksort(arr,0,n-1);
      for(i=0;i<n-2;i++)
       {
        temp=arr[i+2]-arr[i];
        count[temp]=count[temp]+1;
        mp[temp].at(mpcount[temp])=i+1;
        mpcount[temp]++;
       }
      remove=n-c;
      for(j=1;j<=remove;j++)
        
        
        
        
