#include<stdio.h>
#include<string.h>
int main()
{
    int t,i,flag;
    char str[102];
    int count[26]={0};
    scanf("%d",&t);
    while(t--)
    {
      scanf("%s",str);
      for(i=0;i<26;i++)
        count[i]=0;
      for(i=0;i<strlen(str);i++)
        count[str[i]-97]++;
      for(i=0;i<26;i++)
//        printf("%d  ",count[i]);
      flag=0;
      for(i=0;i<26;i++)
        if(count[i]%2!=0)
          flag++;
      if(flag<=1)
        printf("YES\n");
      else
        printf("NO\n");
    }
    return 0;
}
