#include<stdio.h>
void Merge(int a[],int temp[],int lpos,int rpos,int rtend)
 {
    int i,lfend,tmppos,l1=lpos;
    lfend=rpos-1;
    tmppos=lpos;
    while(lpos<=lfend&&rpos<=rtend)
       {
         if(a[lpos]<=a[rpos])
           temp[tmppos++]=a[lpos++];
         else
           temp[tmppos++]=a[rpos++];
       }  
    while(lpos<=lfend)
       temp[tmppos++]=a[lpos++];
    while(rpos<=rtend)
       temp[tmppos++]=a[rpos++];
    for(i=l1;i<=rtend;i++)
       a[i]=temp[i];
 }
void Msort(int a[],int temp[],int left,int right)
 {
   int center;
   if(left<right)
    {
       center=(left+right)/2;
       Msort(a,temp,left,center);
       Msort(a,temp,center+1,right);
       Merge(a,temp,left,center+1,right);
    }
 }
void Mergesort(int a[],int n)
 {
   int *temp;
   temp=new int(n);
   Msort(a,temp,0,n-1);
//   delete temp;
 }
int main()
 {
   int n,t,i;
   int a[1001],b[1001],ans;
   scanf("%d",&t);
   while(t--)
    {
      scanf("%d",&n);
      ans=0;
      for(i=0;i<n;i++)
        scanf("%d",&a[i]);
      for(i=0;i<n;i++)
        scanf("%d",&b[i]);
      Mergesort(a,n);
      Mergesort(b,n);
      for(i=0;i<n;i++)
        ans+=(a[i]*b[i]);
      printf("%d\n",ans);  
    }     
   return 0;
 }  
        
