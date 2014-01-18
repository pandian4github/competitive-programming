#include<iostream>
using namespace std;
#include<conio.h>
void brutesum(long long int a,long long int b,long int arr[])
 {
   long long int n,temp;
//   cout<<"\nEntered brutesum\n\n a = "<<a<<"  b = "<<b<<"  d = "<<d<<"\n";
   for(n=a;n<=b;n++)
    {
      temp=n;
      while(temp>0)
       {
        arr[temp%10]++;
        temp=temp/10;
       }
    }
 }                 
int main()
 {
   long long int a,b;
   int d1,d2,i,c1,c2;
   long int arr[10]={0};
   while(1)
    {
     for(i=0;i<10;i++)
       arr[i]=0;
     scanf("%lld%lld",&a,&b);
     if(a==0&&b==0)
       break;
     brutesum(a,b,arr);
     for(i=0;i<9;i++)
       printf("%d ",arr[i]);
     printf("%d\n",arr[9]);
    }
   return 0;
 }                    
