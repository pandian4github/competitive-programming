#include<stdio.h>
#include<string.h>
int tree[1000000],lazy[1000000],tree2[1000000];
void buildtree(int node,int st,int end)
{
 // printf("%d %d %d\n",node,st,end);
  if(st>end)
    return;
  if(st==end)
  {
    tree[node]=1;
    return;
  }
  int mid=(st+end)/2;
  tree[node]=end-st+1;
  buildtree(2*node,st,mid);
  buildtree(2*node+1,mid+1,end);
}
void update(int node,int st,int end,int i,int j)
{
  //printf("node : %d\n",node);
  long long int temp;
  if(lazy[node]!=0)
  {
    if(lazy[node]==1)
    {
      temp=tree[node];
      tree[node]=tree2[node];
      tree2[node]=(end-st+1)-temp-tree2[node];
      if(st!=end)
      {
//      printf("updating lazy . . .\n");
        lazy[2*node]=(lazy[2*node]+1)%3;
        lazy[2*node+1]=(lazy[2*node+1]+1)%3;
      }
    }
    else
     if(lazy[node]==2)
     {
       temp=tree[node];
       tree[node]=(end-st+1)-tree[node]-tree2[node];
       tree2[node]=temp;
       if(st!=end)
       {
//      printf("updating lazy . . .\n");
        lazy[2*node]=(lazy[2*node]+2)%3;
        lazy[2*node+1]=(lazy[2*node+1]+2)%3;
       }
     }
    lazy[node]=0;
  }
  if(st>end || st>j || end<i)
    return;
  if(st>=i && end<=j)
  {
    temp=tree[node];
    tree[node]=tree2[node];
    tree2[node]=(end-st+1)-temp-tree2[node];
    if(st!=end)
    {
//      printf("updating lazy . . .\n");
      lazy[2*node]=(lazy[2*node]+1)%3;
      lazy[2*node+1]=(lazy[2*node+1]+1)%3;
    }
  }
  else
  {
    int mid=(st+end)/2;
    update(2*node,st,mid,i,j);
    update(2*node+1,mid+1,end,i,j);
    tree[node]=tree[2*node]+tree[2*node+1];
    tree2[node]=tree2[2*node]+tree2[2*node+1];
  }
  return;
}
int query(int node,int st,int end,int i,int j)
{
  int temp;
  if(st>end || st>j || end<i)
    return 0;
  if(lazy[node]!=0)
  {
    if(lazy[node]==1)
    {
      temp=tree[node];
      tree[node]=tree2[node];
      tree2[node]=(end-st+1)-temp-tree2[node];
      if(st!=end)
      {
//      printf("updating lazy . . .\n");
        lazy[2*node]=(lazy[2*node]+1)%3;
        lazy[2*node+1]=(lazy[2*node+1]+1)%3;
      }
    }
    else
     if(lazy[node]==2)
     {
       temp=tree[node];
       tree[node]=(end-st+1)-tree[node]-tree2[node];
       tree2[node]=temp;
       if(st!=end)
       {
//      printf("updating lazy . . .\n");
        lazy[2*node]=(lazy[2*node]+2)%3;
        lazy[2*node+1]=(lazy[2*node+1]+2)%3;
       }
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
  int t,n,c,a,b,o,u,i,x;
  char ch;
  scanf("%d %d",&n,&c);
  memset(tree,0LL,1000000);
  memset(tree2,0LL,1000000);
  memset(lazy,0LL,1000000);
  buildtree(1,0,n-1);
  ch=getchar();
  while(c--)
  {
//   scanf("%d %d %d",&o,&a,&b);
   o=0;
   while((x=getchar())!=32)
     o=o*10+x-48;
   a=0;
   while((x=getchar())!=32)
     a=a*10+x-48;
   b=0;
   while((x=getchar())!=EOF)
   {
     if(x==10)
       break;
     b=b*10+x-48;
   }
//   printf("\no : %d\na : %d\nb : %d\n",o,a,b);
   if(o==0)
     update(1,0,n-1,a,b);
   else 
     if(o==1)
       printf("%d\n",query(1,0,n-1,a,b));
 /*   printf("tree : ");
    for(i=1;i<=7;i++)
      printf("%d  ",tree[i]);
    printf("tree2 : ");
    for(i=1;i<=7;i++)
      printf("%d  ",tree2[i]);
    printf("\nlazy : ");
    for(i=1;i<=7;i++)
      printf("%d  ",lazy[i]);
    printf("\n");      */
  }
  scanf("%d",&t);
  return 0;
}
