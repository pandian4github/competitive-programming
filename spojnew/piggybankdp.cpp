#include<stdio.h>
vector<vector<int> > dp;
vector<int> v(502),w(502);
/*void printk(int n,int w)
{
  int i,j;
  printf("--------------------------------------------------\n");
  for(i=1;i<=n;i++)
  {
    for(j=1;j<=w;j++)
      printf("%5d",dp[i][j]);
    printf("\n\n");
  }
  printf("--------------------------------------------------\n");
}*/
void knapsack(int n,int W)
{
  int i,j,temp,l;
  for(i=0;i<=W;i++)
    dp[1][i]=1000000000;
  dp[1][0]=0;
  for(j=1,i=w[1];i<=W;i+=w[1],j++)
    dp[1][i]=j*v[1];
  for(i=2;i<=n;i++)
   {
    dp[i][0]=0; 
    for(j=1;j<=W;j++)
    {
      if(j>=w[i])
      {
        temp=j-w[i];
        dp[i][j]=dp[i-1][j];
        l=1;
        while(temp>=0)
        {
          if(l*v[i]+dp[i-1][temp]<dp[i][j])
            dp[i][j]=l*v[i]+dp[i-1][temp];
          temp=temp-w[i];
          l++;
        }
      }
      else
        dp[i][j]=dp[i-1][j];
    }
   }
}  
int main()
{
  int t,f,e,W,n,i;
  scanf("%d",&t);
  while(t--)
  {
    scanf("%d %d",&e,&f);
    W=f-e;
    scanf("%d",&n);
    v[0]=w[0]=0;
    for(i=1;i<=n;i++)
      scanf("%d %d",&v[i],&w[i]);
    knapsack(n,W);
 //   printk(n,W);
    if(dp[n][W]!=1000000000)
      printf("The minimum amount of money in the piggy-bank is %d.\n",dp[n][W]);
    else
      printf("This is impossible.\n"); 
  }
  return 0;
}
