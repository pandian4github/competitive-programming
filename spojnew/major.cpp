#include<iostream>
using namespace std;
//#include<conio.h>
int main()
 {
   int i,t,j;
   cin>>t;
   long int n;
   for(i=0;i<t;i++)
    {
      cin>>n;
      int arr[n];
      for(j=0;j<n;j++)
        cin>>arr[j];
      int count[6001]={0};
      for(j=0;j<n;j++)
        count[(arr[j]+3000)]++;
      int c=0;
      for(j=0;j<6001;j++)
       if(count[j]>n/2)
        {
          cout<<"YES "<<j-3000<<endl;
          c=1;
          break;
        }    
      if(!c)
        cout<<"NO\n";
    }
//   getch();
   return 0;
 }        
          
