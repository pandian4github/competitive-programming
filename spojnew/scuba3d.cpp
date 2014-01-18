#include<stdio.h>
#include<string.h>
int dp[1002][100][100];
int max(int a,int b)
{
  if(a>b)
    return a;
  return b;
}
int min(int a,int b)
{
  if(a<b)
    return a;
  return b;
}
/*void print(int x[],int n)
{
  int i;
  printf("--------------------\n");
  for(i=1;i<=n;i++)
    printf("%d  ",x[i]);
  printf("\n--------------------\n");
}
void printk(int n,int o,int ni)
{
  int i,j,k;
  for(k=1;k<=n;k++)
  {
  printf("k : %d\n",k);
  printf("------------------------------------------------------------------------------\n");
  for(i=1;i<=o;i++)
  {
    for(j=1;j<=ni;j++)
      printf("%7d ",dp[k][i][j]);
    printf("\n\n");
  }
  printf("------------------------------------------------------------------------------\n");
  }
}*/
void knapsack(int oxy[],int nit[],int we[],int n,int ox,int ni)
{
  int i,j,k;
  dp[1][0][0]=0;
  for(i=1;i<=ox;i++)
    for(j=1;j<=ni;j++)
      if(oxy[1]>=i && nit[1]>=j)
        dp[1][i][j]=we[1];
      else
        dp[1][i][j]=100000;
  for(i=2;i<=n;i++)
  {
    dp[i][0][0]=0;
    for(j=1;j<=ox;j++)
      for(k=1;k<=ni;k++)
        if(j<oxy[i])
        {
          if(k<nit[i])
            dp[i][j][k]=min(dp[i-1][j][k],we[i]);
          else
            dp[i][j][k]=min(dp[i-1][j][k],we[i]+dp[i-1][j][k-nit[i]]);
        }
        else
        {
          if(k<nit[i])
            dp[i][j][k]=min(dp[i-1][j][k],we[i]+dp[i-1][j-oxy[i]][k]);
          else
            dp[i][j][k]=min(dp[i-1][j][k],we[i]+dp[i-1][j-oxy[i]][k-nit[i]]);
        }
  } 
}   
/*void calculate(int i,int j,int w[])
 {
   if(i==0||j==0)
     return ;
   if(K[i-1][j]==K[i][j])
     calculate(i-1,j,w);
   else
    {
      calculate(i-1,j-w[i],w);
      oxb[i]=1;
    }
 }
void calculate2(int i,int j,int w[])
 {
   if(i==0||j==0)
     return ;
   if(K[i-1][j]==K[i][j])
     calculate2(i-1,j,w);
   else
    {
      calculate2(i-1,j-w[i],w);
      nib[i]=1;
    }
 }
10
8 6
5
2 3 10
3 10 15
6 3 1
1 1 10
4 3 11

10
8 6
5
2 3 10
3 10 10
6 3 10
1 1 10
4 3 10
 */
int main()
{
  int i,sum,t,ox,ni,n,col;
  int oxygen[1002],nitrogen[1002],weight[1002];
  scanf("%d",&t);
  while(t--)
  {
    scanf("%d %d",&ox,&ni);
    scanf("%d",&n);
    col=max(ox,ni);
    oxygen[0]=nitrogen[0]=weight[0]=0;
    for(i=1;i<=n;i++)
       scanf("%d %d %d",&oxygen[i],&nitrogen[i],&weight[i]);
    knapsack(oxygen,nitrogen,weight,n,ox,ni);
   // printk(n,ox,ni);
//    printk(n,col);
    printf("%d\n",dp[n][ox][ni]);
  }
  return 0;
}    
    
