#include<stdio.h>
int last;
void recurse(int team[],int i)
{
  if(team[i]!=-1)
    return;
  team[i]=last^1;
  
int main()
{
  int t;
  scanf("%d",&t);
  while(t--)
  {
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
      scanf("%d",rcount[i]);
      for(j=0;j<rcount[i];j++)
        scanf("%d",&rival[i][j]);
    }
    ind=0;
    int flag[n+1],team[n+1];
    for(i=0;i<=n;i++)
      team[i]=flag[i]=0;
    last=1;
    for(i=0;i<n;i++)
    {
      recurse(team,i);  
    
    team[0]=1;
    for(i=0;i<rcount[0];i++)
      
    
