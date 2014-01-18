#include<stdio.h>
#include<math.h>
long int mod;
void multiply(long long int F[][2],long long int M[][2])
 {
  long long int x =  F[0][0]*M[0][0] + F[0][1]*M[1][0];
  long long int y =  F[0][0]*M[0][1] + F[0][1]*M[1][1];
  long long int z =  F[1][0]*M[0][0] + F[1][1]*M[1][0];
  long long int w =  F[1][0]*M[0][1] + F[1][1]*M[1][1]; 
  F[0][0] = x%mod;
  F[0][1] = y%mod;
  F[1][0] = z%mod;
  F[1][1] = w%mod;
 }
void power(long long int F[][2],long long int n)
 {
   if(n==0||n==1)
     return;
   long long int M[2][2]={{1LL,1LL},{1LL,0LL}};
   power(F,n/2);
   multiply(F,F);
   if(n%2!=0)
     multiply(F,M);
 }   
long long int fibo(long long int n)
 {
   long long int F[2][2]={{1LL,1LL},{1LL,0LL}};
   if(n==0)
     return 0;
   power(F,n-1);
   return F[0][0];
 }
     
int main()
 {
   int t;
   long long int n,N;
   scanf("%d",&t);
   while(t--)
   {
     scanf("%lld %lld",&n,&mod);
     N=fibo(n+2);
     printf("%lld\n",(2*N-n-2)%mod);
   }
  return 0;
 } 
