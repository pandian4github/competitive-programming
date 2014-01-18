#include<iostream>
using namespace std;
int main()
 {
   int i,a,b,n,cou;
   cin>>n;
   for(i=0;i<n;i++)
    {
      cin>>a>>b;
      if(a==b)
       {
        if(a%2==0)
          {
           cout<<2*a<<"\n";
           continue;
          } 
        else
          {
           cout<<2*a-1<<"\n";
           continue;
          } 
       }   
      else
       if(a-b==2)
        {
          cou=a-2;
          if(cou%2==1)
           cou--;
          cout<<a+cou<<"\n";
          continue;
        }
       else
         {
          cout<<"No Number\n";          
          continue;
         } 
    }
   return 0;
 }       
