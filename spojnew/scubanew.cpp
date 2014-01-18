#include<stdio.h>
#include<string.h>
int dp[1002][100];
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
void print(int x[],int n)
{
  int i;
  printf("--------------------\n");
  for(i=1;i<=n;i++)
    printf("%d  ",x[i]);
  printf("\n--------------------\n");
}
void printk(int n,int c)
{
  int i,j;
  printf("------------------------------------------------------------------------------\n");
  for(i=1;i<=n;i++)
  {
    for(j=1;j<=c;j++)
      printf("%7d ",dp[i][j]);
    printf("\n\n");
  }
  printf("------------------------------------------------------------------------------\n");
}
void knapsack(int oxy[],int nit[],int we[],int n,int ox,int ni)
{
  int i,j,m,col,mi,ma;
  m=min(oxy[1],nit[1]);
  printf("ox : %d ni : %d\n",ox,ni);
  printf("m : %d\n",m);
  col=max(ox,ni);
  printf("col : %d\n",col);
  dp[1][0]=0;
  for(i=1;i<=m;i++)
    dp[1][i]=we[1];
  for(;i<=col;i++)
    dp[1][i]=100000;
 // printk(n,col);
  for(i=2;i<=n;i++)
  {
    dp[i][0]=0;
    for(j=1;j<=col;j++)
    {
      mi=min(oxy[i],nit[i]);
      ma=max(oxy[i],nit[i]);
      if(j<mi)
        dp[i][j]=min(dp[i-1][j],we[i]);
      else
        dp[i][j]=min(dp[i-1][j],we[i]+dp[i-1][j-mi]);
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
3 10 5
6 3 1
1 1 10
4 3 9
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
    printk(n,col);
    printf("%d\n",dp[n][col]);
  }
  return 0;
}    
    
