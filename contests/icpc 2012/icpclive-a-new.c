#include<stdio.h>
int main()
{
    int t,r,g,b,w,i,j=0;
    char s[100];
    scanf("%d",&t);
    while(t--)
    {
                j=0;
                scanf("%s",s);
                for(i=0;s[i]!='\0';i++)
                    j=j^s[i];
                if(t>0)
                {
                if(j==0)
                  printf("YES\n");
                else
                  printf("NO\n");
                }
                else
                {
                if(j==0)
                  printf("YES");
                else
                  printf("NO");
                }
    
    }
    return 0;
}
