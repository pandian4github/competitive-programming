#include<stdio.h>
int main()
 {
   int a[10],i,s=0,d,s1,s2,q=1;
   for(i=0;i<10;i++)
     scanf("%d",&a[i]);
   for(i=0;i<10;i++)
    {
      s=s+a[i];
      if(s==100)
       {
         printf("100\n");
         q=0;
         break;
       }
      d=s+a[i+1];     
      if(d>100)
       {
         s1=100-s;
         s2=d-100;
         if(s1>=s2)
            printf("%d\n",d);
          else
            printf("%d\n",s);
          q=0;
          break;
         }
       
    }
    if(q)
     printf("%d\n",s);
    return 0;
  }        
         
                 
