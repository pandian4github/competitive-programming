#include<math.h>
#include<stdio.h>
int main()
 {
   int t,i,q=0;
   scanf("%d",&t);
   long int a[t],b[t],j,k;
   for(i=0;i<t;i++)
      scanf("%ld%ld",&a[i],&b[i]);
   for(i=0;i<t;i++)
   {   
    q=0;
    if(a[i]==1)
     {
       if(b[i]==1)
         break;
       printf("2\n");
       a[i]=3;
     }
      else
       if(a[i]==2)
       {
         printf("2\n");
         a[i]++;
       }
       if(a[i]%2==0)
        a[i]++;
       for(j=a[i];j<=b[i];j+=2)
        {
         for(k=2;k<=sqrt(j);k++)
          {
            if(j%k!=0)
             continue;
            q=1;
            goto l;
          }
        l: if(q==0)
          printf("%ld\n",j);  
         }
        printf("\n");         
      }
     return 0;
   }           
                
        
            
      
