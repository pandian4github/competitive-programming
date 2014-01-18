#include<stdio.h>
#include<string.h>
int lcslength(char str1[],char str2[],int len)
 {
      int i,j;
int dp[len+1][len+1];
      for(i=0;i<=len;i++)
        dp[0][i]=dp[i][0]=0;
      for(i=1;i<=len;i++)
         for(j=1;j<=len;j++)
          {
            if(str1[i-1]==str2[j-1])
              dp[i][j]=dp[i-1][j-1]+1;
            else
              dp[i][j]=(dp[i-1][j]>dp[i][j-1])?dp[i-1][j]:dp[i][j-1];
          }
    /*  for(i=0;i<=len;i++)
       {
         for(j=0;j<=len;j++)
            printf("%d  ",dp[i][j]);
         printf("\n\n");
       }*/   
      return dp[len][len];
 }         
   
int main()
 {
   int t;
   int i,j,len;
   scanf("%d",&t);
   while(t--)
    {
   char str[6101];
   char str1[6101];
      scanf("%s",str);
      len=strlen(str);
      for(i=0;i<len;i++)
        str1[len-i-1]=str[i];
      str1[len]='\0';        
      printf("%d\n",len-lcslength(str,str1,len));
    }
   return 0;
 }                     
