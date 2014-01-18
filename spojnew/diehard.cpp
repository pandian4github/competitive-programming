#include<stdio.h>
int main()
{
  int t;
  int h,a,count;
  scanf("%d",&t);
  while(t--)
  {
    count=1;
    scanf("%d %d",&h,&a);
    h+=3;
    a+=2;
    while(1)
    {
      if((h-5)>0 && (a-10)>0)
        {
         h=h-5;
         a=a-10;
        }
      else
       if((h-20)>0)
        {
         h=h-20;
         a=a+5;
        }
       else
         break;
      count+=2;
      h+=3;
      a+=2;      
    }
    printf("%d\n",count);
  }
  return 0;
}
      
