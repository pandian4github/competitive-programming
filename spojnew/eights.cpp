#include<iostream>
//#include<conio.h>
//#include<math.h>
using namespace std;
int main()
 {
   long long int n;
   long long int d,r;
   int i,t;
   cin>>t;
   for(i=0;i<t;i++)
    {
     cin>>n;
     d=(n-1)/4;
     r=n%4;
     if(d!=0)
      cout<<d; 
     switch(r)
     {
      case 0 : cout<<"942\n";
               break;
      case 1 : cout<<"192\n";
               break;
      case 2 : cout<<"442\n";
               break;
      case 3 : cout<<"692\n";
               break;
     }
    }   
//   getch();
   return 0;
 }         
