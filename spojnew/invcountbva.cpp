#include<stdio.h>
long int a[200001],temp[200001];
void Merge(int lpos,int rpos,int rtend,long long int *pt)
 {
    int i,lfend,tmppos,l1=lpos;
    lfend=rpos-1;
    tmppos=lpos;
    while(lpos<=lfend&&rpos<=rtend)
       {
         if(a[lpos]<=a[rpos])
           temp[tmppos++]=a[lpos++];
         else
           {
             temp[tmppos++]=a[rpos++];
             (*pt)+=(lfend-lpos+1);
           }  
       }  
    while(lpos<=lfend)
       temp[tmppos++]=a[lpos++];
    while(rpos<=rtend)
       temp[tmppos++]=a[rpos++];
    for(i=l1;i<=rtend;i++)
       a[i]=temp[i];
 }


void Msort(int left,int right,long long int *pt)
 {
   int center;
   if(left<right)
    {
       center=(left+right)/2;
       Msort(left,center,pt);
       Msort(center+1,right,pt);
       Merge(left,center+1,right,pt);
    }
 }
int main()
 {
   int t=5,i,n;
  // scanf("%d",&t);
   while(t--)
    {
      scanf("%d",&n);
      for(i=0;i<n;i++)
        {
        //  scanf("%ld",&a[i]);
          temp[i]=a[i]=n-i;
        }
      long long int inv=0;
      Msort(0,n-1,&inv);
      printf("%lld\n",inv);
    }
   return 0;
 }     
