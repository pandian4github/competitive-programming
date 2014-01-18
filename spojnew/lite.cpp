#include<stdio.h>
#include<string.h>
long long int tree[1000000],lazy[1000000];
void update(int node,int st,int end,int i,int j)
{
  //printf("node : %d\n",node);
  if(lazy[node]!=0)
  {
    tree[node]=(end-st+1)-tree[node];
    if(st!=end)
    {
      lazy[2*node]=1-lazy[2*node];
      lazy[2*node+1]=1-lazy[2*node+1];
    }
    lazy[node]=0;
  }
  if(st>end || st>j || end<i)
    return;
  if(st>=i && end<=j)
  {
    tree[node]=(end-st+1)-tree[node];
    if(st!=end)
    {
//      printf("updating lazy . . .\n");
      lazy[2*node]=1-lazy[2*node];
      lazy[2*node+1]=1-lazy[2*node+1];
    }
  }
  else
  {
    int mid=(st+end)/2;
    update(2*node,st,mid,i,j);
    update(2*node+1,mid+1,end,i,j);
    tree[node]=tree[2*node]+tree[2*node+1];
  }
  return;
}
long long int query(int node,int st,int end,int i,int j)
{
  if(st>end || st>j || end<i)
    return 0;
  if(lazy[node]!=0)
  {
    tree[node]=(end-st+1)-tree[node];
    if(st!=end)
    {
      lazy[2*node]=1-lazy[2*node];
      lazy[2*node+1]=1-lazy[2*node+1];
    }
    lazy[node]=0;
  }
  if(st>=i && end<=j)
    return tree[node];
  int mid=(st+end)/2;
  return query(2*node,st,mid,i,j)+query(2*node+1,mid+1,end,i,j);
}
int main()
{
  int t,n,c,a,b,o,u,i;
  scanf("%d",&n);
  memset(tree,0LL,1000000);
  memset(lazy,0LL,1000000);
  scanf("%d",&c);
  while(c--)
  {
   scanf("%d %d %d",&o,&a,&b);
   if(o==0)
     update(1,0,n-1,a-1,b-1);
   else 
     if(o==1)
       printf("%lld\n",query(1,0,n-1,a-1,b-1));
  //  printf("tree : ");
  //  for(i=1;i<=15;i++)
  //    printf("%d  ",tree[i]);
  //  printf("\nlazy : ");
  //  for(i=1;i<=15;i++)
  //    printf("%d  ",lazy[i]);
  //  printf("\n");      
  }
//  scanf("%d",&t);
  return 0;
}
