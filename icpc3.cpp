#include<iostream>
//#include<string.h>
using namespace std;
//#include<conio.h>
int absol(int sum)
 {
   return sum*(-1);
 }  
int main()
 {
   int t,n,j;
   int initial;
   int sum;
   cin>>t;
   int i;
   for(i=0;i<t;i++)
    {
     cin>>n;
     int s[n];
     sum=0;
     initial=1;
     for(j=0;j<n;j++)
       {
         cin>>s[j];
         sum+=s[j];
         if(sum<=0)
           {
             if((absol(sum)+1)>=initial)
               initial=absol(sum)+1;
           }   
           
        }
     cout<<initial<<"\n";
   }     
//   getch();
   return 0;
 } 
