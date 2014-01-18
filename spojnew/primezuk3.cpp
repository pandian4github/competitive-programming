#include<stdio.h>
//#include<conio.h>
#include<math.h>
int sieve[100001]={1};
int primes[10000]={0};
void sievefunc()
 {
   long int i,p,j=0;
   for(i=2;i<=100000;i++)
     sieve[i]=1;
   sieve[1]=0;
 //  for(i=0;i<10000;i++)
 //    printf("%d   ",sieve[i]);
   for(p=2;p<=316;p++)
     {
   //   printf("\nEntered atleast for loop !\n");
      if(sieve[p]==1)
       {
  //      printf("\nEntered .. \n");
  //      printf("\n p = %ld\n",p);
        primes[j++]=p;
        for(i=p*p;i<=100000;i=i+p)
          sieve[i]=0;
 //       getch();  
       }
      }
 //  printf("\nj = %d\n",j);
 //  printf("\nPrimes :\n");
 //  for(i=0;i<j;i++)
 //    printf("%d   ",primes[i]);
 //  getch();   
 
   for(i=317;i<=100000;i++)
     if(sieve[i]==1)
       primes[j++]=i;
  // getch();       
  // printf("\nj = %d\n",j);
  // printf("\nPrimes :\n");
 //  for(i=0;i<j;i++)
  //   printf("\n%d   \n",primes[j-1]);
  // getch();    
 }         
   
bool second_seive(long long int m)
 {
      int i,p;
      if(m<=10000)
        return (sieve[m]==0)?false:true;
    //  printf("\n i n m = %lld\n",m);
      long long int j;
      for(i=0;(primes[i]*primes[i])<=m;i++)
           if(m%primes[i]==0)
               return false;
      return true;
  }      
           
int main()
 {
   long long int a,m,j,n;
   long int l;
   int ch,t,i,k;
//   getch();
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
      ch=0;
      for(l=1;l<=(long int)sqrt(m*1.0);l++)
       {
         if(m%l==0)
          if(second_seive(m/l))
           {
             ch=1;
             printf("Case #%d: %lld\n",k,m/l);
             break;
           }
       }
      if(ch==0)
       for(l=(long int)sqrt(m);l>=2;l--)
        {
          if(m%l==0)
          if(sieve[l]==1)
           {
             printf("Case #%d: %lld\n",k,l);
             break;
           }
        }         
    //  printf("Numbers : \n a = %lld\n b = %lld\n",a,b);
    //  printf("\n");
    }
   return 0;
 }     
