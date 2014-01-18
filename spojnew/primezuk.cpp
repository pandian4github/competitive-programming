#include<stdio.h>
#include<conio.h>
#include<string.h>
int sieve[100001];
int primes[10000]={0};
void sievefunc()
 {
   int i,p,j=0;
   for(i=2;i<=100000;i++)
     sieve[i]=1;
   sieve[1]=0;
   for(p=2;p<=316;p++)
     {
      if(sieve[p]==1)
       {
        primes[j++]=p;
        for(i=p*p;i<=100000;i=i+p)
          sieve[i]=0;
       }
      }
   for(i=317;i<=100000;i++)
     if(sieve[i]==1)
       primes[j++]=i;
 }         
   
int main()
 {
   int t,i,j,m,n,k,p;
   sievefunc();
   scanf("%d",&t);
   for(j=1;j<=t;j++)
    {
      scanf("%d",&n);
      m=1;
      for(i=0;i<n;i++)
       {
         scanf("%d",&p);
         m=m*p;
       }
 //     printf("\nm = %d\n",m);
  //    getch(); 
      m++;
      if(sieve[m]==1)
        printf("Case #%d: %d\n",j,m);
      else
        {
          for(i=0;;i++)
            if(primes[i]>m)
             {
               i--;
               break;
             }
          for(k=i;;k--)
            if(m%primes[k]==0)
             {
              printf("Case #%d: %d\n",j,primes[k]);
              break;
             }
        }
    }
   return 0; 
 }                     
