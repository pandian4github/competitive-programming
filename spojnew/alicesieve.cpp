#include<stdio.h>
#include<math.h>
//#include<string.h>
int sieve[1000001];
int arr[1000001];
void sievefunc()
 {
//   memset(sieve,1,100000);
   int i,p,j=0;
   for(i=2;i<=1000000;i++)
     sieve[i]=0;     
   for(p=2;p<=1000;p++)
      if(sieve[p]==0)
        for(i=p*p;i<=1000000;i=i+p)
          sieve[i]++;
   arr[1]=0;
   for(i=2;i<=1000000;i++)
     arr[i]=arr[i-1]+1-sieve[i];   
   for(i=1;i<=100;i++)
     printf("%d   %d  %d\n\n",i,sieve[i],arr[i]);       
 }         
int main()
 {
   int t,num;
   sievefunc();
   scanf("%d",&t);
  // printf("t = %d\n",t);
   while(t--)
    {
      scanf("%d",&num);
      printf("%d\n",arr[num]);
    }
   return 0;
 } 
