#include<stdio.h>
#include<conio.h>
long long int pow(long long int i)
 {
   long long int p=1,j;
   for(j=1;j<=i;j++)
     p=(p*2LL)%1000000007;
   return p;
 }
int main()
 {
   long long int power[100],fibo[100];
   int i;
   power[0]=0;
   power[1]=1;
   fibo[0]=0;
   fibo[1]=1;
   for(i=2;i<=20;i++)
     {
      power[i]=pow(fibo[i-1]);
      fibo[i]=fibo[i-1]+fibo[i-2];
     } 
   for(i=0;i<=20;i++)
     printf("%d  %lld\n",i,power[i]);
   getch();  
   return 0; 
 }  
