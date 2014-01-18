#include<stdio.h>
#include<string.h>
int div252(char str[])
{
    int i,j;
    int rem=0;
    for(i=0;i<strlen(str);i++)
    {
      rem=rem*10+str[i]-48;
      rem=rem%252;
    }
    if(rem==0)
      return 0;
    return 1;
}
int div525(char str[])
{
    int i,j;
    int rem=0;
    for(i=0;i<strlen(str);i++)
    {
      rem=rem*10+str[i]-48;
      rem=rem%525;
    }
    if(rem==0)
      return 0;
    return 1;
}
int main()
{
    int t,i,j;
    char ans[2][4]={"Yes","No"},str[50002];
    scanf("%d",&t);
    while(t--)
    {
              scanf("%s",str);
              i=div252(str);
              j=div525(str);
              printf("%s %s\n",ans[i],ans[j]);
    }
    return 0;
}
