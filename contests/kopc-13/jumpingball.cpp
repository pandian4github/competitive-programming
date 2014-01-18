#include<stdio.h>
/*int power(int a,int b)
{
  int p=1;
  for(int i=1;i<=b;i++)
    p=p*a;
  return p;
}*/
int main()
{
    int t,h,b,n,count;
    scanf("%d",&t);
    while(t--)
    {
      scanf("%d %d",&h,&b);
      count=0;
      while(h!=0)
      {
        count++;
        h=h/b;
      }
      printf("%d\n",count-1);
    }
    return 0;
}
