#include<stdio.h>
long long int power[61]={0};
long long int combination(int n,int r)
 {
  long double p=1.0,p1=1.0;
  int i;
  for(i=n;i>r;i--)
   p=p*i/(i-r);
  return (long long int)(p); 
 }
int getlimit(long long int n)
 { 
  int i;
  for(i=1;i<=60;i++)
    if(power[i]==n)
      return i;
  return 0;
 }
int main()
 {
   int t,i,limit;
   power[0]=1;
   long long int n;
   long long int ans[62]={0};
   ans[0]=ans[1]=0;
   for(i=1;i<=60;i++)
     power[i]=2*power[i-1];
   scanf("%d",&t);
   while(t--)
   {
     scanf("%lld",&n);
     limit=getlimit(n);
     long long int sum=0LL;
     for(i=2;i<=limit;i+=2)
       sum=sum+combination(i-1,i/2-1);
     printf("%lld\n",sum);  
   }
   return 0;
 }  
