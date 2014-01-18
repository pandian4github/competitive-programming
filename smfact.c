#include<stdio.h>
int main()
 {
   int n;
   long double x;
   scanf("%d",&n);
   int i,j;
   int a[n];
   for(i=0;i<n;i++)
     scanf("%d",&a[i]);
   for(i=0;i<n;i++)
    {
     x=a[i];
     for(j=1;j<a[i];j++)
       x=j*x;
     printf("%0.0Lf\n",x);
    }
   return 0; 
 }
  
