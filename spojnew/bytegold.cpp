#include<iostream>
using namespace std;
#include<map>
map<long long int,long long int> m;
long long int calc(long long int n)
 {
   long long int temp;
   if(n<1)
     return 0;
   if(m.count(n)==0)  
    {
     temp=calc(n/2)+calc(n/3)+calc(n/4);
     if(temp<n)
        m[n]=n;
     else
        m[n]=temp;   
    }
   return m[n];   
 } 
   
int main()
 {
   long long int n;
   m.clear();
   while((scanf("%lld",&n))!=EOF)
     printf("%lld\n",calc(n));
   return 0;
 }        
