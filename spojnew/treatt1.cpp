#include<iostream>
#include<conio.h>
using namespace std;
int main()
 {
   int i,j,n,k,l,q,q1;
   cin>>n;
   int dp[n+1][n+1];
   int arr[n+1];
   for(i=1;i<=n;i++)
     cin>>arr[i];
   for(i=0;i<=n;i++)
     for(j=0;j<=n;j++)
       dp[i][j]=0;
   for(i=1;i<=n;i++)
     dp[i][i]=arr[i];
   for(l=2;l<=n;l++)
    {
      for(i=1;i<=n-l+1;i++)
       {
         j=i+l-1;
    //     for(k=i;k<j;k++)
    //      {
            cout<<"\ni = "<<i<<"   j = "<<j<<"  k = "<<k<<"\n";
            q=l*dp[i][i]+dp[i+1][j];
            q1=dp[i][j-1]+l*dp[j][j];
            cout<<"q = "<<q<<"  q1 = "<<q1<<"\n";
            if(q1>q)
              q=q1;
            if(q>dp[i][j])
              dp[i][j]=q;
      //    }
       }
    }
   for(i=1;i<=n;i++)
    {
      for(j=1;j<=n;j++)
        cout<<dp[i][j]<<"  ";
      cout<<"\n";
    }    
   cout<<dp[1][n];
   getch();
   return 0;
 }                     
   
   
