#include<stdio.h>
#include<string.h>
char str[3002],rev[3002];
int mat[3002][3002]={0};
int main()
{
    int t,i,j,max,count,len,d,q,k;
    int indexes[26][3002];
    int indcount[26]={0};
    scanf("%d",&t);
    while(t--)
    {
              scanf("%s",str);
              max=-1;
              count=0;
              len=strlen(str);
              for(i=0;i<26;i++)
                indcount[i]=0;
              for(i=0;i<len;i++)
                indexes[str[i]-97][indcount[str[i]-97]++]=i;
              memset(mat,0,sizeof(mat));
              for(j=0;j<len;j++)
              {
                d=str[len-j-1]-97;
                for(k=0;k<indcount[d];k++)
                {
                  q=indexes[d][k];
                  mat[q+1][j+1]=mat[q][j]+1;
                  if(mat[q+1][j+1]==max)
                    count++;
                  else
                   if(mat[q+1][j+1]>max)
                   {
                     max=mat[q+1][j+1];
                     count=1;
                   }
                }
              }
              printf("%d %d\n",max,count);
    }
    return 0;
}
              
