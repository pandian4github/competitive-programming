#include<stdio.h>
int flag=0;
void recurse(char str[],int index,int open,int close,int len)
{
  //   printf("in recurse : %d %d %d %d \n",index,open,close,len);
     if(index==len)
       {
         if(open==close)
          flag=1;
         return;
       }
     if(open<close)
       return;
     if(str[index]=='(')
     {
       if(str[index-1]==':')
         recurse(str,index+1,open,close,len);
       recurse(str,index+1,open+1,close,len);
     }
     else
      if(str[index]==')')
      {
        if(str[index-1]==':')
          recurse(str,index+1,open,close,len);
        recurse(str,index+1,open,close+1,len);
      }
      else
        recurse(str,index+1,open,close,len);
     return;
      
}
int main()
{
    int i,t,index;
    char ch;
    char str[103];
    char ans[2][5]={"YES","NO"};
    scanf("%d",&t);
    ch=getchar();
    for(i=1;i<=t;i++)
    {
      flag=0;
      str[0]='.';
      index=1;
      while((scanf("%c",&ch))!=EOF)
      {
        if(ch=='\n')
           break;
        str[index++]=ch;
      }
      str[index]='\0';
     // printf("%s\n",str);
      recurse(str,1,0,0,index);
      printf("Case #%d: %s\n",i,ans[1-flag]);
    }
    return 0;
}
