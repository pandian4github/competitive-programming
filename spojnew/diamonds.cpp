#include<stdio.h>
#include<string.h>
#include<math.h>
#include<stdlib.h>
#include<iostream>
#include<vector>
#include<map>
#include<list>-
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
#define printiln(a) printf("%d\n",a);
#define max(a,b) { return (a>b)?a:b; }
int main()
{
  int t,n,i,j;
  int arr[200][200],dp[200][200];
  scani(t)
  while(t--)
  {
    scani(n)
    memset(dp,0,sizeof(dp));
    fori(0,n/2)
      forj(0,i)
       {
        scani(arr[i][j])
        dp[i][j]=arr[i][j];
       }
    fori(n/2+1,n-1)
      forj(0,n-1-i)
       {
        scani(arr[i][j])
        dp[i][j]=arr[i][j];
       }
    fori(1,n/2)
    {
     dp[i][0]+=dp[i-1][0];
     dp[i][i]+=dp[i-1][i-1];
     forj(1,i-1)
       dp[i][j]+=(dp[i-1][j-1]>dp[i-1][j])?dp[i-1][j-1]:dp[i-1][j];
    }
    fori(n/2+1,n-1)
      forj(0,n-1-i)
        dp[i][j]+=(dp[i-1][j+1]>dp[i-1][j])?dp[i-1][j+1]:dp[i-1][j];
   // printf("dp arr : \n");
   // fori(0,n-1)
   // {
   //   forj(0,n/2)
   //     printi(dp[i][j])
   //   printf("\n");
   // }
    printiln(dp[n-1][0]);
  }  
  return 0;
}
