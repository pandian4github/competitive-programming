#include<stdio.h>
#include<string.h>
int main()
{
    int i=0,j,k,max,l;
    char str[102][102],ch;
    max=0;
    j=0;
    while(scanf("%c",&ch)!=EOF)
    {
            if(ch=='\n')
             {
               if(j>max)
                 max=j;
               str[i][j]='\0';
               i++;
               j=0;
               continue;
             }
            str[i][j++]=ch;
    }
    str[i][j]='\0';
    if(j>max)
       max=j;
    i++;
    for(l=0;l<max;l++)
    {
       for(k=i-1;k>=0;k--)
          printf("%c",str[k][l]);
        printf("\n");
    }
}               
