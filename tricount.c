#include<stdio.h>
int main()
 {
   unsigned int t,i,j;
   double n;
   scanf("%d",&t);
   double arr[t];
   for(j=0;j<t;j++)
    {
      scanf("%lf",&n);
      arr[j]=n*(n*n+6*n-1)/6;
 //     for(i=1;i <n;i++)
 //       if(n-i>=i)
   //       arr[j]+=i*(i-1)/2;
     //   else
       //   arr[j]+=i*(4*n-3*i)-n*(n+1);      
     }
   for(i=0;i<t;i++)
    printf("%.0lf\n",arr[i]);
   return 0;
  }      
    
 
