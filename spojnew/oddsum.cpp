#include<iostream>
//#include<conio.h>
using namespace std;
int main()
 {
   int i,t,j,a,b,sum;
   cin>>t;
   for(i=0;i<t;i++)
    {
      sum=0;
      cin>>a>>b;
      if(a%2==0)
        a++;
      for(j=a;j<=b;j+=2)
        sum+=j;
      cout<<"Case "<<i+1<<": "<<sum<<"\n";
    }
 //  getch();
   return 0;
 }      
