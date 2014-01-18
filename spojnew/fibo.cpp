#include<iostream>
#include<conio.h>
using namespace std;
int main()
 {
   int t,i;
   cin>>t;
   long long int n,a,b,c,count;
   for(i=0;i<t;i++)
    {
      count=-1;
      cin>>n;
      a=-1;
      b=1;
      while(1)
       {
         c=a+b;
         count++;
         c=c%1000000007;
         a=b;
         b=c;
         cout<<c<<"\n";
         if(count==n)
           {
  //        cout<<c<<"\n";
            break;
           } 
       } 
    }
   getch();
   return 0;
 }     
