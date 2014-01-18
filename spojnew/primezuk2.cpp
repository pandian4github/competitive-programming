#include<stdio.h>
#include<conio.h>
#include<string.h>
int primes[10000]={0};
int it;
void sievefunc()
 {
//   scanf("%d",&primes[5]);
//   getch(); 
   int sieve[100001];
  // memset(sieve,1,100000);
   long int i,p,j=0;
   for(i=2;i<=100000;i++)
     sieve[i]=1;
   sieve[1]=0;
 //  getch();
   for(p=2;p<=316;p++)
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
   //  printf("%lld   ",primes[i]);
  // getch();   
 
   for(i=317;i<=100000;i++)
     if(sieve[i]==1)
       primes[j++]=i;
  // getch();       
  // printf("\nj = %d\n",j);
  // printf("\nPrimes :\n");
 //  for(i=0;i<j;i++)
     printf("%lld   ",primes[j-1]);
  // getch();    
 }         
   
long long int second_seive(long long int a,long long int b,int req,int *ptr,long long int m)
 {
      int i,p;
      int pp[10000];
      int cnt=0;
      long long int j;
      if(a<0)
        a=1;
      int sieve2[b-a+1];
      for(i=0;i<=b-a;i++)
        sieve2[i]=1;
      for(i=0;(primes[i]*primes[i])<=b;i++)
       {
           j=primes[i]*((primes[i]+a-1)/primes[i]);
           for(p=primes[i];j<=b;j+=p)
             if(j!=primes[i])
               {
                sieve2[j-a]=0;
                pp[cnt++]=a+j;
       }
      if(a==1)
        sieve2[0]=0;
      if(req==1)
       {
        if(sieve2[b-a]==1)
         {
          (*ptr)=1;
          return b;
         }   
        else
         {
          for(i=b-a-1;i>=0;i--)
            if(sieve2[i]==1&&m%(a+i)==0)
             {
               (*ptr)=0;
               return a+i;
             }
         }
        }
       else
        {
           for(i=b-a;i>=0;i--)
             if(sieve2[i]==1&&m%(a+i)==0)
              {
                (*ptr)=0;
                return a+i;
              }
        }
      return -1;
  }      
           
int main()
 {
   long long int a,m,j,an,x,n;
   int t,i,p,k,st;
   getch();
   sievefunc();
   scanf("%d",&t);
   for(k=1;k<=t;k++)
    {
      scanf("%lld",&n);
      m=1;
      for(i=0;i<n;i++)
       {
         scanf("%lld",&a);
         m=m*a;
       }
      m++;
  //    printf("\nm = %d\n",m);
      st=2;
      an=second_seive(m-100000,m,1,&st,m);
      x=m-100000;
      if(st==1)
       {
          printf("Case #%d: %lld\n",k,an);
          continue;
       }
      else
       while(1)
        {
          if(st==0)
           {
            printf("Case #%d: %lld\n",k,an);
            break;
           }
          an=second_seive(x-100000,x,0,&st,m);
          x=x-100000;
        } 
           
               
    //  printf("Numbers : \n a = %lld\n b = %lld\n",a,b);
    //  printf("\n");
    }
   return 0;
 }     
