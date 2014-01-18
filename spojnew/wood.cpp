#include<stdio.h>
char arr[203][203];
int dp[203][203];
int maxfun(int a,int b)
{
    if(a>b)
      return a;
    return b;
}
void print(int m,int n)
{
     int i,j;
     printf("\n");
     for(i=0;i<=m+1;i++)
     {
       for(j=0;j<=n+1;j++)
         printf("%d  ",dp[i][j]);
       printf("\n");
     }
     printf("\n\n");
}
int main()
{
  int t,max,i,j,m,n;
  scanf("%d",&t);
  while(t--)
  {
    scanf("%d %d",&m,&n);
    for(i=0;i<m;i++)
      scanf("%s",arr[i]);
    for(i=0;i<=m+1;i++)
      {
       dp[i][0]=-1;
       dp[i][n+1]=-1;
      }
    for(j=0;j<=n+1;j++)
      {
       dp[0][j]=-1;
       dp[m+1][j]=-1;  
      }
    dp[1][0]=0;
//    print(m,n);  
    max=0;
    for(i=0;i<m;i++)
    {
      if(i%2==0)
      {
        for(j=0;j<n;j++)
        {
          if(arr[i][j]=='#')            
             dp[i+1][j+1]=-1;
          else
            if(dp[i][j+1]==-1&&dp[i+1][j]==-1)
              dp[i+1][j+1]=-1;
            else  
              if(arr[i][j]=='0')
                dp[i+1][j+1]=maxfun(dp[i][j+1],dp[i+1][j]);
              else
                dp[i+1][j+1]=maxfun(dp[i][j+1],dp[i+1][j])+1;
          max=maxfun(max,dp[i+1][j+1]);      
        }        
      }
      else
      {
        for(j=n-1;j>=0;j--)
        {
          if(arr[i][j]=='#')
             dp[i+1][j+1]=-1;
          else
           if(dp[i][j+1]==-1&&dp[i+1][j+2]==-1)
             dp[i+1][j+1]=-1;
           else
             if(arr[i][j]=='0')
               dp[i+1][j+1]=maxfun(dp[i][j+1],dp[i+1][j+2]);
             else
               dp[i+1][j+1]=maxfun(dp[i][j+1],dp[i+1][j+2])+1;
          max=maxfun(max,dp[i+1][j+1]);      
        }
      }
    }
  //  print(m,n);
    printf("%d\n",max);
  }
  return 0;
}
