#include<stdio.h>
//#include<conio.h>
long int min(long int a,long int b)
 {
    return (a<b)?a:b;
 }
int main()
 {
   int n,a,b,c,i,j,t=1;
   while(1)
    {   
      scanf("%d",&n);
      if(n==0)
        break;
      int arr[n][3];
      long int dp[n][3];
      for(i=0;i<n;i++)
        for(j=0;j<3;j++)
         {
          scanf("%d",&arr[i][j]);
          dp[i][j]=arr[i][j];
         }
      dp[0][2]+=dp[0][1];    
      dp[1][0]+=dp[0][1];
      dp[1][1]+=min(min(dp[1][0],dp[0][1]),dp[0][2]);
      dp[1][2]+=min(min(dp[1][1],dp[0][1]),dp[0][2]);
      for(i=2;i<n;i++)
       {
         dp[i][0]+=min(dp[i-1][0],dp[i-1][1]);
         dp[i][1]+=min(min(dp[i-1][0],dp[i-1][1]),min(dp[i-1][2],dp[i][0]));
         dp[i][2]+=min(min(dp[i-1][1],dp[i-1][2]),dp[i][1]);
       }
   //   cost=arr[0][1]+min(min(dp[n-2][0],dp[n-2][1]),dp[n-2][2])+arr[n-1][1];
   //   getch(); 
  //    for(i=0;i<n;i++)
  //      printf("%ld  %ld  %ld\n\n",dp[i][0],dp[i][1],dp[i][2]);
      printf("%ld. %ld\n",t++,dp[n-1][1]);
    }
//   getch();
   return 0;
 } 
