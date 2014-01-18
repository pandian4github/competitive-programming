#include<iostream>
//#include<conio.h>
using namespace std;
int main()
 {
   long int n;
   long long int e,ans=0;
   scanf("%ld",&n);
   while(n>0)
    {
     scanf("%lld",&e);
     ans=ans^e;
     n--;
    }    
   printf("%lld",ans);
  // getch(); 
   return 0; 
 }   

