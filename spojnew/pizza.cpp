#include<iostream>
//#include<conio.h>
using namespace std;
int main()
 { 
   int n;
   cin>>n;
   int i;
   int x,z;
   char y;
   int a,b,c;
   int ans=1,m;
   a=0;
   b=0;
   c=0;
   for(i=0;i<n;i++)
    {
      cin>>x>>y>>z;
      if(x==1)
       {
         if(z==4)
           a++;
         else
           b++;
       }
      else
       c++;
    }
   ans=ans+(b/2)+(b%2);
   if(a<c)
     m=a;
   else
     m=c;
   if(c>=a)
    ans=ans+a+c-m;
   else
    {
      if(b%2==1)
       {
         if(a-c==1||a-c==2)
           ans=ans+m;
         else
          {
            a=a-2; 
            ans=ans+m+1+(a-m-1)/4; 
          } 
       }
      else  
       ans=ans+m+(a-m-1)/4+1; 
    }  
   cout<<ans;
//   getch();
   return 0;
 }                   
