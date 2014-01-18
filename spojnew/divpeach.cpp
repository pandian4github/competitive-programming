#include<iostream>
using namespace std;
#include<math.h>
int main()
 {
   long int m,temp,k;
   int i,c,c1;
   while(1)
   {
     scanf("%ld",&m);
     if(m<0)
       break;
     c=1;
     k=sqrt(m);
//     cout<<"k = "<<k<<"\n";
     for(;k>=2;k--)
      {
       c1=0;
       temp=m;
       for(i=1;i<=k;i++)
        {
         temp--;
         if(temp%k!=0)
          {
           c1=1;
           break;
          } 
         temp=temp-(temp/k);  
         if(temp==0)
           break;
        }
       if(c1)
         continue;
       if(temp%k==0)
        {
         c=0;
         printf("%ld peaches, %d adventurers and 1 dog\n",m,k);
         break;
        }  
      }
     if(c)
       printf("%ld peaches, no solution\n",m);
   }
  return 0;       
 } 
      
