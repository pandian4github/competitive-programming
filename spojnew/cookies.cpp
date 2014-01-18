#include<iostream>
//#include<conio.h>
using namespace std;
int main()
 {
   int t;
   int i;
   int n,a,d,sum,temp,j;
   cin>>t;
   for(i=0;i<t;i++)
    {
      cin>>n>>a>>d;
      sum=0;
      temp=a;
      for(j=0;j<n;j++)
        {
          sum=sum+temp;   
          temp=temp+d;
        }
      cout<<sum<<"\n";
    }
//   getch();
   return 0;
 }       
