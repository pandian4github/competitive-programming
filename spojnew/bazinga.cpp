#include<stdio.h>
#include<vector>
#include<string.h>
#include<math.h>
using namespace std;
vector<bool> vec(11000000);
int count[11000000]={0};
long int a[40000000];
void sievefunc()
 {
   int i,p,j=0,index=0;
   long long int sq;
   for(i=2;i<=5300000;i++)
     vec[i]=true;
   for(p=2;p<=5300000;p++)
     {
      sq=p*p;
      if(vec[p])
       {
        count[p]=1;
        //primes[j++]=p;
        for(i=2*p;i<=10527449;i=i+p)
          {
           if(i%sq==0)
             count[i]=10;
           else  
             count[i]++;
           vec[i]=false;
          }
       }
      }
   for(i=2;i<=10527449;i++)
     if(count[i]==2)
       a[index++]=i; 
//   printf("j = %d last two primes : %d %d\n",j,primes[j-2],primes[j-1]);    
//   for(i=0;i<20;i++)
//     printf("%d ",primes[i]);
 }         
   
int main()
 {
   int i,j,t,k,index=0;
  // long long int temp;
   scanf("%d",&t);
   sievefunc();
 /*  for(i=0;i<162662;i++)
     for(j=i+1;j<162662;j++)
       {
        temp=(long long int)primes[i]*(long long int)primes[j];
        if(temp<=10527449LL)
         a[index++]=(long int)temp;
        else
         break;
       }         */
 //  printf("index = %ld\n",index);    
 //  for(i=0;i<index;i++)
 //    printf("%ld\n",a[i]);
  // sort(a,a+index-1);
  // for(i=0;i<100;i++)
  //   printf("%ld  ",a[i]);    
 //  printf("index = %d\n",index);
   while(t--)
    {
      scanf("%d",&k);
      printf("%ld\n",a[k-1]);
    }
   return 0;
 }     
