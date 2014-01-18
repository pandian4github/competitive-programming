#include<stdio.h>
long long int combination(int n,int a)
 {
   long long int c=1LL;   
   if(n==a)
    return 1;
   c=n*combination(n-1,a);
   c=c/combination((n-a),1);
   return c;
 }  
int main()
 {
   int a,b,n,r,t;
   scanf("%d",&t);
   while(t--)
    {
      scanf("%d %d",&a,&b);
      a=a-b;
      n=a+b-1;
      r=a;
      printf("%lld\n",combination(n,r));
    }
   return 0;
 } 
