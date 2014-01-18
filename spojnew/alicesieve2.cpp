#include<stdio.h>
#include<math.h>
#include<map>
using namespace std;
bool flag[1000001];
map<long int,int> mp;
int sieve(long int n)
 {
   int count=0;
 //  bool flag[n+1];
   int i,j;
   for(i=0;i<=n;i++)
     flag[i]=true;
   flag[0]=flag[1]=false;
   for(i=n;i>=2;i--)
    {
      if(flag[i])
      {
        count++;
        for(j=2;j<=sqrt(i);j++)
          if(i%j==0)
            flag[j]=flag[i/j]=false;
      }
    }
   return count;
 }        
int main()
 {
   int t;
   long int num;
   scanf("%d",&t);
   while(t--)
    {
      scanf("%d",&num);
      printf("%ld\n",sieve(num));
    }
   return 0;
 } 
