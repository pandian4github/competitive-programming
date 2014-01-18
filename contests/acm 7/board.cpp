#include<stdio.h>
#include<string.h>
#include<math.h>
#include<iostream>
#include<map>
#include<vector>
#include<queue>
#include<set>
using namespace std;
#define scani(a) scanf("%d",&a);
#define fori(a,b) for(i=a;i<=b;i++)
#define forj(a,b) for(j=a;j<=b;j++)
#define fork(a,b) for(k=a;k<=b;k++)
#define forl(a,b) for(l=a;l<=b;l++)
#define wait { char ch; scanf("%c",&ch); }
int main()
{
    int t,m,n,r,c,te,i,j,k,l,y;
    char x[3];
    scani(t)
    while(t--)
    {
    scani(m)
    scani(n)
    scani(r)
    scani(c)
    te=0;
    fori(1,r)
    {
      forj(1,m)
      {
        if((te/2)%2==0)
        {
          x[0]='X';
          x[1]='.';
        }
        else
        {
          x[0]='.';
          x[1]='X';
        }
        y=0;
        fork(1,n)
        {
          forl(1,c)
            printf("%c",x[y]);
          y=1-y;
        }
        te++;
        printf("\n");            
      }
    }
    }
    wait
    wait
    return 0;
}
