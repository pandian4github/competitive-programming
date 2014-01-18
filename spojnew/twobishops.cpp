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
#define wait char ccc=getchar();
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
int main()
{
  int t,i,j,k,a,b;
  int x[5],y[5];
  char str[8][8];
  scani(t)
  while(t--)
  {
            fori(0,7)
              scans(str[i])
            k=0;
            fori(0,7)
              forj(0,7)
                if(str[i][j]=='B')
                  {
                   x[k]=i;
                   y[k++]=j;
                  }
            a=x[0]-x[1];
            b=y[0]-y[1];
            if(a==b || a+b==0)
              printf("Yes\n");
            else
              printf("No\n");             
  }
  return 0;
}
