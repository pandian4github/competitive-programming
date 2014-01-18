#include<stdio.h>
int v[2002],w[2002],dp[2002][2002];
int max(int a,int b)
 {
   return (a>b)? a:b;
 }  
void knapsack(int n,int W)
 {
   int i,j;
   for(i=0;i<=W;i++)
     dp[0][i]=0;
   for(i=1;i<=n;i++)
    {
      dp[i][0]=0;
      for(j=1;j<=W;j++)
        {
          if(j>=w[i])
            dp[i][j]=max(v[i]+dp[i-1][j-w[i]],dp[i-1][j]);
          else
            dp[i][j]=dp[i-1][j];       
        }
    }
 }
int main()
 {
   int W,n,i;
   v[0]=w[0]=0;
   scanf("%d %d",&W,&n);
   for(i=1;i<=n;i++)
     scanf("%d %d",&w[i],&v[i]);
   knapsack(n,W);
   printf("%d\n",dp[n][W]);
   return 0;
 }      
                 
