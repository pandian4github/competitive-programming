#include<stdio.h>
#include<math.h>
int main()
 {
   long long int fibo[100],a,b,c;
   a=2LL;
   b=3LL;
   fibo[0]=a;
   fibo[1]=b;   
   int index=2,i,j,flag,k,min,t;
   long long int max;
   while(1)
    {
      c=a+b;
      if(c>=1000000000000000000LL)
        break;
      fibo[index++]=c;
      a=b;
      b=c;
    }
   scanf("%d",&t);
   while(t--)
    {
      scanf("%d",&k);
      flag=0;
      for(i=0;i<85;i++)
       {
         if(k<=fibo[i])
          {
            min=k;
            max=fibo[i];
          }
         else
          {
            min=fibo[i];
            max=k;
          }
         for(j=2;j<=sqrt(min);j++)
           if(min%j==0&&max%j==0)
            {
              printf("%lld %d\n",fibo[i],j);
              flag=1;
              break;
            }
         if(flag==1)
           break;
         for(j=sqrt(min);j>=1;j--)
          if(min%j==0&&max%(min/j)==0)
           {
              printf("%lld %d\n",fibo[i],min/j);
              flag=1;
              break;
           }
         if(flag==1)
           break;                           
       }
    }    

       
   return 0;
 } 
