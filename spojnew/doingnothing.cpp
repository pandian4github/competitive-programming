//#include<conio.h>
#include<iostream>
using namespace std;
int main()
 {
   long long int n,m,i,ans,c;
   long int j=0,k;
   while(1)
    {
      ans=0;
      cin>>n>>m;
      if(n==-1&&m==-1)
        break;
      for(i=n;i>=1;i--)
       {
         cin>>c;
         ans=ans+c*i*m;
       }
      cout<<ans<<"\n"; 
    }
 //  for(k=0;k<j;k++)
 //    cout<<ans[k]<<"\n";
//   getch();   
   return 0;
 }  
        
