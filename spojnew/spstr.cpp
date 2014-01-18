#include<iostream>
using namespace std;
int permut(int n)
 {
   int i,p=1;
   for(i=n;i>n-3;i--)
     p=p*i;
   return p;
 }    
int main()
 {
   int n,i,t,p;
   cin>>n;
   for(i=0;i<n;i++)
    {
      cin>>t;
      if(t==1)
       {
         cout<<"3\n";
         continue;
       }
      if(t==2)
       {
         cout<<"9\n";
         continue;
       }
      p=permut(t)-3;
      cout<<p<<"\n";
    }
   return 0;
 }        
         
     
