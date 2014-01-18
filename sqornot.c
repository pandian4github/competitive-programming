#include<math.h>
#include<stdio.h>
int Check(long long int r,long long int s)
  {
     double q;
     q=sqrt(r);
     if(q-(int)q==0)
       return 1;
     else
       return 0;
  }       
int  main()
 {
   int t;
   scanf("%d",&t);
   long long int a,arr[t],j,k,r;
   double q;
   int i,v=0;
   for(i=0;i<t;i++)
     scanf("%lld",&arr[i]);
//      arr[i]=1000000000000;
   for(i=0;i<t;i++)
    {
      v=0;
      a=arr[i];
      q=sqrt(a);
      if(q-(int)q==0)
       {
         printf("Yes\n");
         continue;
       }
      for(j=(int)q;j>=0;j--)
       {
         r=a-(j*j);
         v=Check(r,(int)q);
         if(v)
          {
           printf("Yes\n");
           break;
          }
         else
           continue;    
       }
      if(v==0)
        printf("No\n"); 
    }
    return 0;
   }                    
            
