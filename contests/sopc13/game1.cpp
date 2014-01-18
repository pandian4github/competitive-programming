#include<stdio.h>
#include<iostream>
#include<algorithm>
using namespace std;
#define fori(a,b) for(i=a;i<=b;i++)
#define forj(a,b) for(j=a;j<=b;j++)
#define scani(a) scanf("%d",&a);
int main()
{
    int t,n,i,j,count,key;
    int b[51],r[51];
    scani(t)
    while(t--)
    {
      scani(n)
      count=0;
      fori(0,n-1)
        scani(b[i])
      fori(0,n-1)
        scani(r[i])
      sort(b,b+n);
      sort(r,r+n);
      i=n-1;
      j=n-1;
      while(i>=0)
      {
        key=b[i];
        while(j>=0)
        {
          if(r[j]<key)
          {
            count=count+b[i];
            j--;
            break;
          }
          j--;
        }
        if(j<0)
          break;
        i--;
      }
      printf("%d\n",count);
    }
    return 0;
}
