#include<stdio.h>
int dp[201][201],arr[201][201];
char symbol[201][201];
void recur(in
int main()
 {
   int t;
   scanf("%d",&t);
   while(t--)
    {
      scanf("%d %d",&m,&n);
      for(i=0;i<m;i++)
        scanf("%s",&symbol[i]);
      for(i=0;i<m;i++)
        for(j=0;j<n;j++)
          {
            scanf("%d",&time[i][j]);
            dp[i][j]=-1;
          }
      scanf("%d %d",x1,y1);
      scanf("%d %d",x2,y2);
      recur(x1,y1);
      
          
