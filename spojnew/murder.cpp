#include<stdio.h>
long int a[200001],temp[200001];
long long sum;
void Merge(int lpos,int rpos,int rtend)
 {
    int i,lfend,tmppos,l1=lpos;
    lfend=rpos-1;
    tmppos=lpos;
    while(lpos<=lfend&&rpos<=rtend)
       {
         if(a[lpos]<a[rpos])
           {
            sum=sum+a[lpos]*(rtend-rpos+1);
            temp[tmppos++]=a[lpos++];
           }
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


void Msort(int left,int right)
 {
   int center;
   if(left<right)
    {
       center=(left+right)/2;
       Msort(left,center);
       Msort(center+1,right);
       Merge(left,center+1,right);
    }
 }
int main()
 {
   int t,i,n;
   scanf("%d",&t);
 //  printf("%d\n",t);
   while(t--)
    {
      scanf("%d",&n);
      sum=0LL;
      for(i=0;i<n;i++)
        {
          scanf("%ld",&a[i]);
          temp[i]=a[i];
        }
      long long int inv=0;
      Msort(0,n-1);
      printf("%lld\n",sum);
    }
   return 0;
 }     
