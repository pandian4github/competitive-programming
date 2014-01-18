#include<stdio.h>
int arr[101][101],visited[101][101];
long long int count;
void recurse(int i,int j,int a,int b)
{
    if(i>a || j>b || i<0 || j<0)
       return; 
    if(arr[i][j]==1 || visited[i][j]==1)
      return;
    if(i==a && j==b)
    {
      count=count+1LL;
      return;
    }
    visited[i][j]=1;
    recurse(i-1,j,a,b);
    recurse(i,j-1,a,b);
    recurse(i,j+1,a,b);
    recurse(i+1,j,a,b);
    visited[i][j]=0;
    return;
}
int main()
{
    int n,i,j;
    scanf("%d",&n);
    for(i=0;i<n;i++)
      for(j=0;j<n;j++)
      {
        scanf("%d",&arr[i][j]);
        visited[i][j]=0;
      }
    count=0LL;
    recurse(0,0,n-1,n-1);
    printf("%lld\n",count);
  //  scanf("%d",&n);
    return 0;
}
