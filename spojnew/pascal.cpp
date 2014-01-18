#include<iostream>
//#include<conio.h>
using namespace std;
int main()
 {
   int t,n;
   int i,x,var,var1;
   cin>>t;
   for(i=0;i<t;i++)
    {
      cin>>n;
      int arr[n],arr1[n];
      if(n==1)
       {
         cout<<"1\n";
         continue;
       }
      if(n==2)
       {
         cout<<"1\n";
         cout<<"1 1\n";
         continue;
       }     
      x=2;
      cout<<"1\n";
      cout<<"1 1\n";
      arr[0]=arr[1]=1;
      while(1)
       {                        
         var1=0;
         arr1[var1++]=1;
         for(var=0;var<x-1;var++)
          arr1[var1++]=arr[var]+arr[var+1];
         arr1[var1++]=1;
         for(x=0;x<var1;x++)
          {
           cout<<arr1[x]<<" "; 
           arr[x]=arr1[x];
          }
         cout<<"\n"; 
         if(x==n)
           break; 
       }  
     }
//   getch();
   return 0;
 }             
