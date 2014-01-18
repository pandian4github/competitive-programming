#include<iostream>
//#include<conio.h>
using namespace std;
int main()
 {
   long long int t,i,sum,j,n;
   cin>>t;
   for(i=0;i<t;i++)
    {
      cin>>n;
      sum=0;
      long long int arr[n];
      for(j=0;j<n;j++)
        {
          cin>>arr[j];
          sum+=arr[j];
          sum=sum%n;
        }  
//      cout<<sum<<"  "<<n<<"  ";  
      if(sum%n==0)
        cout<<"YES\n";
      else
        cout<<"NO\n";
    }
//   getch();
   return 0;
 }          
