#include<stdio.h>
int main()
{
    int t,i,j;
    scanf("%d",&t);
    int m,n;
    while(t--)
    {
    scanf("%d %d",&m,&n);
    fflush(stdin);
    char s[100][100];int a[100][100];
    for(i=0;i<m;i++)
     {
       scanf("%s",s[i]);
       for(j=0;j<n;j++)
       a[i][j]=9900;
     }
    a[0][0]=0;
    for(i=0;i<m;i++)
      for(j=0;j<n;j++)
        if(s[i][j]!='#')
          {
             int jmp=s[i][j]-48;
             if(j+1<n && a[i][j]+1<a[i][j+1] && s[i][j+1]!='#')
                a[i][j+1]=a[i][j]+1;
             if(i+1<m && a[i][j]+1<a[i+1][j] && s[i+1][j]!='#')
                a[i+1][j]=a[i][j]+1;
             if(i+jmp+1<m && a[i][j]+1<a[i+jmp+1][j] && s[i+jmp+1][j]!='#')
                a[i+jmp+1][j]=a[i][j]+1;
             if(j+jmp+1<n && a[i][j]+1<a[i][j+jmp+1] && s[i][j+jmp+1]!='#')
                a[i][j+jmp+1]=a[i][j]+1;                
          }
    if(a[m-1][n-1]==9900)
      a[m-1][n-1]=-1;
     printf("%d\n",a[m-1][n-1]);
    }
    return 0;
}
 
