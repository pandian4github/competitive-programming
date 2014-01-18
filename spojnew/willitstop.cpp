#include<iostream>
#include<conio.h>
#include<math.h>
using namespace std;
int main() 
 {
   long long int n;
   cin>>n;
   int i;
   int c=0;
   for(i=0;i<50;i++)
     if(pow(2,i)==n)
      {
        c=1;
        break;
      }  
   if(c)
     cout<<"TAK";
   else
     cout<<"NIE";
//   getch();
   return 0;
 }        
