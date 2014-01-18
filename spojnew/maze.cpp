#include<stdio.h>
int dp[21][21];
char arr[21][21];
void dpfunc(int i,int j,int m,int n)
 {
   int i1,j1,i2,j2;
   dp[i][j]=1;
   if(i!=0)
     if(arr[i-1][j]=='.'&&dp[i-1][j]!=1)
       dpfunc(i-1,j,m,n);
   if(j!=0)
     if(arr[i][j-1]=='.'&&dp[i][j-1]!=1)
       dpfunc(i,j-1,m,n);
   if(i!=m-1)
     if(arr[i+1][j]=='.'&&dp[i+1][j]!=1)
       dpfunc(i+1,j,m,n);
   if(j!=n-1)
     if(arr[i][j+1]=='.'&&dp[i][j+1]!=1)
       dpfunc(i,j+1,m,n); 
 }             
               
int main()
 {
   int t,i1,j1,i2,j2,i,j,m,n,cnt;
   char c;
   char st[5];
   scanf("%d",&t);
   while(t--)
    {
      scanf("%d %d",&m,&n);
      for(i=0;i<m;i++)
        {
            scanf("%s",arr[i]);
            for(j=0;j<n;j++)
              {
         //       arr[i][j]=st[j];
                dp[i][j]=0;
              }
        } 
/*      for(i=0;i<m;i++)
       {
          for(j=0;j<n;j++)
            printf("%c   ",arr[i][j]);
          printf("\n");
       }*/  
      cnt=0;
      for(i=0;i<m;i++)
       {
         if(arr[i][0]=='.')
           {
            if(cnt==0)
             {
               i1=i;
               j1=0;
             }
            else
             {
               i2=i;
               j2=0;
             } 
            cnt++;
           }
         if(n!=1)   
          if(arr[i][n-1]=='.')
           {
            if(cnt==0)
             {
              i1=i;
              j1=n-1;
             }
            else
             {
              i2=i;
              j2=n-1;
             }  
            cnt++;
           } 
       }
      for(j=1;j<n-1;j++)
       {
         if(arr[0][j]=='.')
           {
            if(cnt==0)
             {
              i1=0;
              j1=j;
             }
            else
             {
              i2=0;
              j2=j;
             }  
            cnt++;
           } 
         if(m!=1)
          if(arr[m-1][j]=='.')
           {
            if(cnt==0)
             {
              i1=m-1;
              j1=j;
             }
            else
             {
              i2=m-1;
              j2=j;
             }  
            cnt++;
           } 
       }
  //    printf("\ncount = %d\n\n",cnt); 
      if(cnt!=2)
       {
         printf("invalid\n");
         continue;
       }
  //    printf("\ni1 = %d  j1 = %d\ni2 = %d  j2 = %d\n\n",i1,j1,i2,j2); 
      dpfunc(i1,j1,m,n);
      if(dp[i2][j2]==1)
        printf("valid\n");
      else
        printf("invalid\n");
    }
   return 0; 
 }    
                               
