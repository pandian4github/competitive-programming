#include<stdio.h>
int main()
{
    int n;
    char ch,str[1000];
    int ans[26]={11,12,13,14,15,21,22,23,24,24,25,31,32,33,34,35,41,42,43,44,45,51,52,53,54,55};
    scanf("%d",&n);
    while((scanf("%c",&ch))!=EOF)
    {
       if(ch==10)
         printf("\n");
       else
         if(ch>='A' && ch<='Z')
           printf("%d ",ans[ch-65]);
    }   
    scanf("%d",&n);
    return 0;
} 
