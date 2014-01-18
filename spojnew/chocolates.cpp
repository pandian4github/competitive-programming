#include<stdio.h>
int main()
 {
   int t,a,b,n,cnt,temp,wrappers;
   scanf("%d",&t);
   while(t--)
    {
      scanf("%d %d %d",&a,&b,&n);
      cnt=wrappers=temp=0;
      cnt=(int)(n*1.0/a);
      wrappers=cnt;
      while(wrappers>=b)
       {
         temp=(int)(wrappers*1.0/b);
         cnt=cnt+temp;
         wrappers=wrappers-temp*b+temp;
       }
      printf("%d\n",cnt);
    }
   return 0; 
 }      
