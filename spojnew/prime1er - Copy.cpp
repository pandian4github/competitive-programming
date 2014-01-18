#include<stdio.h>
#include<conio.h>
#include<string.h>
int primes[10000]={0};
void sievefunc()
 {
   int sieve[100001];
  // memset(sieve,1,100000);
   int i,p,j=0;
   for(i=2;i<=100000;i++)
     sieve[i]=1;
   sieve[1]=0;
   for(p=2;p<=317;p++)
     {
   //   printf("\nEntered atleast for loop !\n");
      if(sieve[p]==1)
       {
        primes[j++]=p;
        for(i=p*p;i<=100000;i=i+p)
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
   sievefunc();
   scanf("%d",&t);
   while(t--)
    {
      scanf("%lld %lld",&a,&b);
    //  printf("Numbers : \n a = %lld\n b = %lld\n",a,b);
      int sieve2[b-a+1];
      for(i=0;i<=b-a;i++)
        sieve2[i]=1;
      for(i=0;(primes[i]*primes[i])<=b;i++)
       {
    //       printf("\ni = %d\n",i);
    //       getch();
           j=primes[i]*((primes[i]+a-1)/primes[i]);
    //       printf("j = %lld\n",j);
     //      getch();
           for(p=primes[i];j<=b;j+=p)
             if(j!=primes[i])
               sieve2[j-a]=0;
       }
      if(a==1)
        sieve2[0]=0;
      for(i=0;i<=b-a;i++)
        if(sieve2[i])
          printf("%lld\n",a+i);
      printf("\n");
    }
   return 0;
 }     
