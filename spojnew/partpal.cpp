#include<iostream>
using namespace std;
int power(int n)
 {
   int p=1;
   int i;
   for(i=0;i<n;i++)
     p=p*10;
   return p;
 }    
int ispalindrome(int n,int d)
 {
   char str[d];
   int i=0;
   for(i=d-1;i>=0;i--)
     {
       str[i]=n%10;
       n=n/10;
     }
   str[d]='\0';  
   for(i=0;i<d/2;i++)
     if(str[i]!=str[d-1-i])
       return 0;
   return 1;    
 }
int main()
 {
   int t,a,b,start,end,j,i;
   long long int count;
   cin>>t;
   for(i=0;i<t;i++)
    {
      cin>>a>>b;
      if(a%10==0)
       {
         cout<<"0\n";
         continue;
       }  
      start=power(b-1);
      end=power(b)-1;
      count=0;
      for(j=start;;j++)
        if(j%a==0)
         break;
      for(;j<=end;j+=a)
        if(ispalindrome(j,b))
           count++;
      cout<<count<<"\n";
    }
   return 0;
 }             
