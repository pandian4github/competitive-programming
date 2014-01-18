#include<math.h>
#include<stdio.h>
char ch;
int Digits(long long int n)
 {
   int c=0;
   while(n!=0)
    {
      c++;
      n=n/10;
    } 
   return c;
 }   

int main()
 {
   int a,k;
   long long int n,i,j,s=0;
   scanf("%d%lld",&a,&n);
   int d=1;
   int di,dii;
   for(i=a;i<=n;i++)
    {
     di=Digits(i);
     j=i;
    dii=di;
    for(k=0;k<dii;k++)
       {
         s=s+d*(int)(j/pow(10,--di));
         d=-1*d;
         j=j-(int)(j/pow(10,di))*pow(10,di);
       }
    }
   printf("%lld\n",s);
   return 0;
 } 
        
