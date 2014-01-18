#include<iostream>
using namespace std;
#include<conio.h>
#include<math.h>
void findsum(long long int x,long long int &s)
 {
   int co=0;
   while(1)
    {
      if(x%2==1)
        break;
      x=x/2;  
      co++;
    }
   s+=pow(2,co);
 }      
int main()
 {
   long long int a,b,i;
   cin>>a>>b;
   long long int sum=0;
   for(i=a;i<=b;i++)
     findsum(i,sum);
   cout<<sum;
   getch();
   return 0;
 }   
