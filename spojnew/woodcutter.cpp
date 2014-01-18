#include<stdio.h>
char arr[201][201];
int max=0;
void dfs(int i,int j,int m,int n,int count,char cur)
{
  printf("(%d,%d) cur : %c count : %d\n",i,j,cur,count);
  if(count>max)
    max=count;  
  if(i<0||i>=m||j<0||j>=n)
    return;
  if(arr[i][j]=='#')
    return;
  switch(cur)
  {
    case 'r' : if(arr[i][j]=='T')
                 {
                  dfs(i,j+1,m,n,count+1,'r');
                  dfs(i+1,j,m,n,count+1,'l');
                 }
               else
                 {
                  dfs(i,j+1,m,n,count,'r');
                  dfs(i+1,j,m,n,count,'l');
                 }
               break;
    case 'l' : if(arr[i][j]=='T')
                 {
                  dfs(i,j+1,m,n,count+1,'l');
                  dfs(i+1,j,m,n,count+1,'r');
                 }
               else
                 {
                  dfs(i,j+1,m,n,count,'l');
                  dfs(i+1,j,m,n,count,'r');
                 }
               break;  
  }
}
                   
int main()
{
  int t,max,i,j,m,n;
  scanf("%d",&t);
  while(t--)
  {
    scanf("%d %d",&m,&n);
    for(i=0;i<m;i++)
      scanf("%s",arr[i]);
    max=0;
    dfs(0,0,m,n,0,'r');    
    printf("%d\n",max);
  }
  return 0;
}
