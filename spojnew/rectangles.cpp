#include<iostream>
#include<conio.h>
using namespace std;
#include<math.h>
int main()
 {
   long int i,n,tot;
   cin>>n;
   tot=n;
//   if(n%2==1)
//     n--;
   for(i=n;i>0;i--)
    {
      int j;
      for(j=2;j<=sqrt(i);j++)
        if(i%j==0)
          tot++;
    }        
   cout<<tot;
   getch();
   return 0;
 }  
     
       
