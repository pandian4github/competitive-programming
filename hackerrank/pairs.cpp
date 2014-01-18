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
#define decl int i,j;
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
#define printiln(a) printf("%d\n",a);
int main()
{
  int n,k,count=0;
  decl
  map<int,int> mp;
  scanii(n,k);
  int arr[n];
  fori(0,n-1)
  {
    scani(arr[i]);
    mp[arr[i]]=1;
  }
  fori(0,n-1)
  {
    if(arr[i]+k<=2147483647)
      if(mp[arr[i]+k]==1)
        count++;
  }
  printiln(count)
//  wait
//  wait
  return 0;
}
