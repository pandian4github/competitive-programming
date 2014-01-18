#include<stdio.h>
int main()
 {
   int i,j,m,n,flag,flag2,num;
   long long int ans;
   while(1)
    {
      scanf("%d %d",&m,&n);
      if(m==0&&n==0)
        break;
      long int dp[2],rowmax;
      long long int dp2[2];
      dp2[0]=dp2[1]=0;
      for(flag2=0,i=0;i<m;i++,flag2^=1)
        {
         dp[0]=dp[1]=0;
         for(flag=0,j=0;j<n;j++,flag^=1)
          {
            scanf("%d",&num);
            if(num+dp[flag]>dp[flag^1])
              dp[flag]+=num;
            else
              dp[flag]=dp[flag^1];
          }
         rowmax=(dp[0]>dp[1])?dp[0]:dp[1];
         if(rowmax+dp2[flag2]>dp2[flag2^1])
           dp2[flag2]+=rowmax;
         else
           dp2[flag2]=dp2[flag2^1];
        }    
      ans=(dp2[0]>dp2[1])?dp2[0]:dp2[1];
      printf("%lld\n",ans);
    }
   return 0;
 }    
