#include<stdio.h>
#include<math.h>
long int gcd(long int a,long int b)
 {
   if(b==0)
     return a;
   return gcd(b,a%b);
 }
int comdiv(long int a)
 {
   int count=0,i;
   for(i=1;i<=(int)sqrt(a);i++)
     if(a%i==0)
       count+=2;
   if((long int)((int)sqrt(a)*(int)sqrt(a))==a)
     count--;
   return count;
 }           
int main()
 {
   long int t,a,b;
   scanf("%ld",&t);
   while(t--)
   {
     scanf("%ld %ld",&a,&b);
     printf("%d\n",comdiv(gcd(a,b)));
   }
 }    
     
