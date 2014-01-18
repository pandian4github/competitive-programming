#include<stdio.h>
//#include<conio.h>
int main()
 {
   int t,i,j,r,c,max,x,y,z,x1,y1,x2,y2;
   scanf("%d",&t);
   while(t>0)
    {
      t--;
      max=0;
      scanf("%d%d",&r,&c);
      int arr[r][c],dp[r][c];
      for(i=0;i<r;i++)
        for(j=0;j<c;j++)
          scanf("%d",&arr[i][j]);
      for(j=0;j<c;j++)
        dp[r-1][j]=arr[r-1][j];
  /*    for(i=0;i<r;i++)
       {
        for(j=0;j<c;j++)
          printf("%10d ",dp[i][j]);
        printf("\n");
       }   */

      for(i=r-2;i>=0;i--)
       {
        x1=dp[i+1][0];
        y1=dp[i+1][1];
        x2=dp[i+1][c-1];
        y2=dp[i+1][c-2];
        dp[i][0]=(x1>y1)?x1:y1;
        dp[i][0]+=arr[i][0];
        dp[i][c-1]=(x2>y2)?x2:y2;
        dp[i][c-1]+=arr[i][c-1];
        for(j=1;j<c-1;j++)
         {
           x=dp[i+1][j-1];
           y=dp[i+1][j];
           z=dp[i+1][j+1];
           dp[i][j]=(x>y)?x:y;
           dp[i][j]=(dp[i][j]>z)?dp[i][j]:z;
           dp[i][j]+=arr[i][j];
         }
       }
 /*     for(i=0;i<r;i++)
       {
        for(j=0;j<c;j++)
          printf("%10d ",dp[i][j]);
        printf("\n");
       }   */
      for(j=0;j<c;j++)
        if(dp[0][j]>max)
          max=dp[0][j];
      printf("%d\n",max);
    }
//   getch();
   return 0;
 }       
             
      
