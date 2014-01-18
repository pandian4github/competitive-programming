#include<stdio.h>
#include<string.h>
#include<math.h>
#include<stdlib.h>
#include<iostream>
#include<vector>
#include<map>
#include<list>
#include<algorithm>
using namespace std;
#define wait {char ccc=getchar();}
#define fori(a,b) for(i=a;i<=b;i++)
#define scani(a) scanf("%d",&a);
#define printiln(a) printf("%d\n",aa);
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
  int i,j=0,n,e;
  scani(n)
  map<int,int> mp;
  int arr[n];
  fori(1,n)
  {
    scani(e);
    if(mp[e]==0)
    {
      arr[j++]=e;
      mp[e]=1;
    }
  }
  wait
  wait  
  return 0;
}
