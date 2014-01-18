#include<stdio.h>
#include<conio.h>
#include<string.h>
int primes[10000]={0};
int sievefunc()
 {
   long long int num=735695760561LL;
   int sieve[1000001];
  // memset(sieve,1,100000);
   int i,p,j=0;
   for(i=2;i<=100000;i++)
     sieve[i]=1;
   sieve[1]=0;
   for(p=2;p<=1000;p++)
     {
   //   printf("\nEntered atleast for loop !\n");
      if(sieve[p]==1)
       {
        primes[j++]=p;
        for(i=p*p;i<=1000000;i=i+p)
          sieve[i]=0;
       }
      }
  // printf("\nj = %d\n",j);
  // printf("\nPrimes :\n");
  // for(i=0;i<j;i++)
  //   printf("%lld   ",primes[i]);
  // getch();   
   for(i=318;i<=100000;i++)
     if(sieve[i]==1)
       primes[j++]=i;
   printf("%d\n\n",primes[j-1]);
   for(i=j-1;i>=1;i--)
     if(num%i==0)
       return i;
  // getch();       
  // printf("\nj = %d\n",j);
  // printf("\nPrimes :\n");
 //  for(i=0;i<j;i++)
   //  printf("%lld   ",primes[9591]);
  // getch();    
 }         
   
int main()
 {
   long long int a,b,j;
   int t,i,p;
   printf("%d\n",sievefunc());
   scanf("%d",&t);
   return 0;
 }     
