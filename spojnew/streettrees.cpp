#include<stdio.h>
//#include<conio.h>
long long int gcdfunc(long long int a,long long int b)
 {
   if(b==0)
     return a;
   return gcdfunc(b,a%b);
 }  
int main()
 {
   int i,n,count=0;
   scanf("%d",&n);
   long long int arr[n];
   for(i=0;i<n;i++)
      scanf("%lld",&arr[i]);
   for(i=0;i<n-1;i++)
     arr[i]=arr[i+1]-arr[i];
   long long int gcd=arr[0];
   for(i=1;i<n-1;i++)
     gcd=gcdfunc(gcd,arr[i]);
  // printf("\ngcd = %lld\n",gcd);  
   for(i=0;i<n-1;i++)
     count=count+(arr[i]-1)/gcd;
   printf("%d\n",count);
  // getch();
   return 0; 
 }         
