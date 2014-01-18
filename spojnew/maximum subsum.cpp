#include<stdio.h>
#include<string.h>
#include<math.h>
#include<stdlib.h>
#include<iostream>
#include<vector>
#include<map>
#include<list>
#include<set>
#include<algorithm>
using namespace std;
#define wait {char ccc=getchar();}
#define fori(a,b) for(i=a;i<=b;i++)
#define rfori(a,b) for(i=a;i>=b;i--)
#define forj(a,b) for(j=a;j<=b;j++)
#define rforj(a,b) for(j=a;j>=b;j--)
#define fork(a,b) for(k=a;k<=b;k++)
#define rfork(a,b) for(k=a;k>=b;k--)
#define forl(a,b) for(l=a;l<=b;l++)
#define rforl(a,b) for(l=a;l>=b;l--)
#define scani(a) scanf("%d",&a);
#define scanii(a,b) scanf("%d %d",&a,&b);
#define scaniii(a,b,c) scanf("%d %d %d",&a,&b,&c);
#define scans(s) scanf("%s",s);
#define printi(a) printf("%d ",a);
#define printiln(a) printf("%d\n",aa);
#define prints(a,b) printf("%s %d\n",a,b);
#define nl printf("\n");
#define MAX(a,b) return (a>b)?a:b;
int bin_search(int arr[],int l,int r,int key)
{
    if(l>r)
      return 0;
    int m=(l+r)/2;
    if(arr[m]==key)
      return m;
    else if(arr[m]<key)
           return bin_search(arr,m+1,r,key);
         else
           return bin_search(arr,l,m-1,key);
}
int main()
{
  int n,i,j,k,pos,a,b;
  map<int,int> mp;
  scani(n)
  int arr[n],dp[n],tmparr[n];
  fori(0,n-1)
  {
    scani(arr[i])
    dp[i]=0;
  }
  dp[0]=arr[0];
  mp[arr[0]]=arr[0];
  j=0;
  tmparr[j++]=arr[0];
  fori(1,n-1)
  {
    nl
    prints("i : ",i)
    if(mp[arr[i]]==0)
    {
      tmparr[j++]=arr[i];
      sort(tmparr,tmparr+j);
      pos=bin_search(tmparr,0,j-1,arr[i])-1;
      printf("1.tmparr[] : \n");
      fork(0,j-1)
        printi(tmparr[k])
      nl
      prints("1.pos : ",pos)
      nl
      if(pos<0)
        a=arr[i];
      else 
        a=mp[arr[pos]]+arr[i];
    }
    else
    {
      pos=bin_search(tmparr,0,j-1,arr[i])-1;
      printf("2.tmparr[] : \n");
      fork(0,j-1)
        printi(tmparr[k])
      nl
      prints("2.pos : ",pos)
      if(pos<0)
        a=arr[i];
      else 
        a=mp[arr[pos]]+arr[i];
    }
    b=dp[i-1];
    prints("a : ",a)
    prints("b : ",b)
    if(a>=b)
    { 
      mp[arr[i]]=a;
      dp[i]=a;
    }
    else
    {
       mp[arr[i]]=-1;    
       dp[i]=b;
    }
  }
  printf("DP arr : \n");
  fori(0,n-1)
    printi(dp[i])
  prints("Required sum is : ",dp[n-1])
  wait
  wait  
  return 0;
}
