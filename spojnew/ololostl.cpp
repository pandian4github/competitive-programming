#include<iostream>
#include<map>
using namespace std;
//#include<conio.h>
int main()
 {
   long int n;
   long long int x;
   map<long long int,int> m;
   map<long long int,int>::iterator it;
   scanf("%ld",&n);
   while(n>0)
    {
      scanf("%lld",&x);
      if(m.count(x)==0)
        m[x]=1;
      else
        m[x]=1-m[x];
      
      n--;  
    }
   for(it=m.begin();it!=m.end();it++) 
    if(it->second==1)
     {
       cout<<it->first;
       break;
     } 
 //  it=m.begin();
 //  cout<<it->first;
  // getch();
   return 0;
 } 
                
