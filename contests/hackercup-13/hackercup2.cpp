#include<stdio.h>
int main()
{
    int i,j,k,temp,t,sum,flag,open,close,smiley;
    char ch;
    scanf("%d",&t);
    ch=getchar();
    prev='.';
    for(i=1;i<=t;i++)
    {
      open=0;
      close=0;
      opensmiley=0;
      closesmiley=0;
      flag=0;
      while((scanf("%c",&ch))!=EOF)
      {
        if(ch=='\n')
          {
           prev='.';
           break;
          }
        if(flag==1)
          continue;
        if(ch=='(')
        {
          open++;
          if(prev==':')
            opensmiley++;
        }
        else
         if(ch==')')
         {
           if(prev==':')
             closesmiley++;
           else
           {
            if(open>0)
              open--; 
            else
             if(opensmiley>0)
               opensmiley--;
             else
               flag=1;
            }
         }
         prev=ch;
      }
      printf("Case #%d: %d\n",i,sum);
    }
    return 0;
}
