#include<iostream>
using namespace std;
//#include<conio.h>
int main()
 {
   int t;
   cin>>t;
   while(t>0)
    {
      t--;
      int i,n,p,as=0,es=0;
      cin>>n;
      char str[n][10];
      for(i=0;i<n;i++)
       {
        cin>>str[i];
        if(str[i][0]=='#')
          as=1;
        else 
         if((int)str[i][0]>=97&&(int)str[i][0]<=122)
          {
           es=1;
           p=i;
          } 
       }  
      if(as*es==0)
       {
        for(i=0;i<n-1;i++)
         cout<<str[i]<<" ";
        cout<<str[n-1]<<"\n";
       }
      else
       {
         for(i=p+1;i<n;i++)
          cout<<str[i]<<" ";
         cout<<str[p];
         for(i=0;i<p;i++)
           cout<<" "<<str[i];
         cout<<"\n";  
       }
    }
  // getch();
   return 0;
 }              
