#include<stdio.h>
int main()
 {
   int t,count;
   long long int n,row,start,i;
   char type,side;
   char types1[]="WAAMW";
   char types2[]="WMAAW";
   scanf("%d",&t);
   while(t--)
    {
      scanf("%lld",&n);
      if(n==1)
       {
        printf("poor conductor\n");
        continue;
       }
      row=(n-2)/5+1;
      start=(row-1)*5+2;
      count=1;
      for(i=start;;i++,count++)
        if(i==n)
          break;
      if(row%2==1)
       {
          if(count==1||count==2)
            side='L';
          else
            side='R';
          type=types1[count-1];
       }
      else
       {
          if(count==4||count==5)
             side='L';
          else
             side='R';
          type=types2[count-1];
       }
     printf("%lld %c %c\n",row,type,side);
    }
  return 0;
 }                         
                  
