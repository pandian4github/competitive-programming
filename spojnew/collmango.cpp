#include<iostream>
using namespace std;
//#include<conio.h>
/*void print(long int arr[][100],int p,int q)
 {
   int i,j;
   printf("\n");
   for(i=0;i<p;i++)
    {
     for(j=0;j<q;j++)
       printf("%d  ",arr[i][j]);
     printf("\n");
    }
   printf("\n");
 }*/    
   
int main()
 {
   long int max;
   int t,p,q,i,j;
   scanf("%d",&t);
   long int arr[100][100],dp[100][100]={0};
   while(t>0)
    {
      t--;
      scanf("%d%d",&p,&q);
      for(i=0;i<p;i++)
        for(j=0;j<q;j++)
          scanf("%d",&arr[i][j]);
      dp[p-1][q-1]=arr[p-1][q-1];
      for(j=q-2;j>=0;j--)
        dp[p-1][j]=arr[p-1][j]+dp[p-1][j+1];
//      print(dp,p,q);  
      for(i=p-2;i>=0;i--)
       {
        dp[i][q-1]=arr[i][q-1]+dp[i+1][q-1];
        for(j=q-2;j>=0;j--)
         {
          if(dp[i+1][j]>dp[i][j+1])
            max=dp[i+1][j];
          else
            max=dp[i][j+1];
          dp[i][j]=arr[i][j]+max;    
         } 
       }
   //   print(dp,p,q);
    //  cout<<dp[0][0]<<"\n";
      printf("%ld\n",dp[0][0]);
    }
  // getch();
   return 0;
 }       
