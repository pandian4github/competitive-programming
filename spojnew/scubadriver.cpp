#include<stdio.h>
#include<string.h>
int K[1002][100];
int oxb[1001],nib[1001];
int max(int a,int b)
{
  if(a>b)
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
  printf("-------------------------------\n");
  for(i=0;i<=n;i++)
  {
    for(j=0;j<=c;j++)
      printf("%d ",K[i][j]);
    printf("\n\n");
  }
  printf("-------------------------------\n");
}
void knapsack(int v[],int we[],int n,int col)
{
  int i,j;
  printf("col : %d\n",col);
  for(i=0;i<=col;i++)
    K[0][i]=0;
  for(i=1;i<=n;i++)
  {
    K[i][0]=0;
    for(j=1;j<=col;j++)
    {
      if(j>=v[i])
        K[i][j]=max(we[i]+K[i-1][j-v[i]],K[i-1][j]);
      else
        K[i][j]=K[i-1][j];
    }
  }
}   
void calculate(int i,int j,int w[])
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
int main()
{
  int i,sum,c,oxsum,nisum,ox,ni,n;
  int oxygen[1001],nitrogen[1001],weight[1001];
  scanf("%d",&c);
  while(c--)
  {
    scanf("%d %d",&ox,&ni);
    scanf("%d",&n);
    oxsum=nisum=0;
    for(i=1;i<=n;i++)
      {
       scanf("%d %d %d",&oxygen[i],&nitrogen[i],&weight[i]);
       oxsum+=oxygen[i];
       nisum+=nitrogen[i];
      }
   // col=(ox>ni)?ox:ni;
    memset(oxb,0,sizeof(oxb));
    memset(nib,0,sizeof(nib));    
    knapsack(oxygen,weight,n,oxsum-ox);
    printk(n,oxsum-ox);
    calculate(n,ox,oxygen);
    knapsack(nitrogen,weight,n,nisum-ni);
    calculate2(n,ni,nitrogen);
    print(oxb,n);
    print(nib,n);
    sum=0;
    for(i=1;i<=n;i++)
      if(oxb[i]==0 || nib[i]==0)
        sum+=weight[i];
    printf("%d\n",sum);
  }
  return 0;
}    
    
