#include<stdio.h>
#include<iostream>
#include<algorithm>
#include<map>
#include<vector>
#include<utility>
using namespace std;
#define fori(a,b) for(i=a;i<=b;i++)
#define forj(a,b) for(j=a;j<=b;j++)
#define scani(a) scanf("%d",&a);
bool recurse(char l[],char s[],int i,int j,int m,int n)
{
//  printf("i : %d j : %d m : %d n : %d\n\n",i,j,m,n);
  if(i>=m && j>=n)
    return true;
  else
    if(i>=m || j>=n)
      return false;
  if(l[i]==s[i] || l[i]=='?')
    return recurse(l,s,i+1,j+1,m,n);
  if(l[i]=='*')
  {
    bool b=false;
    int k;
    for(k=j;k<n;k++)
    {
      b=b || recurse(l,s,i+1,k,m,n);
    }
    return b;
  }
}
int main()
{
    int t,l1,l2;
    int b[51],r[51];
    char l[100],s[100];
    scani(t)
    while(t--)
    {
      scanf("%s",l);
      scanf("%s",s);
      l1=strlen(l);
      l2=strlen(s);
      if(recurse(l,s,0,0,l1,l2))
        printf("Yes\n");
      else
        printf("No\n");
    }
    return 0;
}
