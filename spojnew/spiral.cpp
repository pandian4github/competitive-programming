#include<stdio.h>
int main()
 {
   int t;
   long int n,cnt; 
   scanf("%d",&t);
   while(t--)
    {
      scanf("%ld",&n);
      if(n==0)
       {
         printf("North\n");
         continue;
       } 
      for(cnt=1;;cnt+=2)
       {
         //0;
         n=n-cnt;
         if(n==0)
          {
            printf("East\n");
            break;
          }
         else
           if(n<0)
            {
              printf("North\n");
              break;
            }
         n=n-cnt;
         if(n==0)
          {
            printf("South\n");
            break;
          }
         else
           if(n<0)
            {
              printf("East\n");
              break;
            }
         n=n-cnt-1;
         if(n==0)
          {
            printf("West\n");
            break;
          }
         else
           if(n<0)
            {
              printf("South\n");
              break;
            }
         n=n-cnt-1;
         if(n==0)
          {
            printf("North\n");
            break;
          }
         else
           if(n<0)
            {
              printf("West\n");
              break;
            }
      }
    }
   return 0;
 }      
            
         
