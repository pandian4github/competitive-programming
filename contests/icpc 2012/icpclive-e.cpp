#include<stdio.h>
int main()
{
  int t,n,q,a,b,i;
  char str[100002],ch;
  scanf("%d",&t);
  while(t--)
  {
    scanf("%d",&n);
    int count[n+1];
    count[0]=0;
    scanf("%s",str);
    for(i=1;i<=n;i++)
    {
      ch=str[i-1];
      if(ch=='1')
        count[i]=count[i-1]+1;
      else
        count[i]=count[i-1];
    }
    scanf("%d",&q);
    printf("q : %d\n\n",q);
    for(i=0;i<=n;i++)
      printf("%d  ",count[i]);
    printf("\n");
    while(q--)
    {
      scanf("%d %d",&a,&b);
      printf("%d\n",count[b]-count[a-1]);
    }
  }
  return 0;
}
