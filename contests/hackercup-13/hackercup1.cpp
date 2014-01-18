#include<stdio.h>
int main()
{
    int i,j,k,temp,t,sum;
    char ch;
    scanf("%d",&t);
    ch=getchar();
    for(i=1;i<=t;i++)
    {
      int count[26]={0};
      while((scanf("%c",&ch))!=EOF)
      {
        if(ch=='\n')
          break;
        if(ch>=65 && ch<=90)
          count[ch-65]++;
        else
          if(ch>=97 && ch<=122)
            count[ch-97]++;
      }
      for(j=0;j<26;j++)
        for(k=j+1;k<26;k++)
          if(count[j]<count[k])
          {
            temp=count[j];
            count[j]=count[k];
            count[k]=temp;
          }
      sum=0;
    //  for(j=0;j<26;j++)
    //    printf("%d ",count[j]);
    //  printf("\n");
      for(j=0;j<26;j++)
        sum=sum+count[j]*(26-j);
      printf("Case #%d: %d\n",i,sum);
    }
    return 0;
}
