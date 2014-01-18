#include<iostream>
using namespace std;
#include<conio.h>
#include<math.h>
int main()
 {
   int n=1;
   while(1)
    {
      if(pow(2,n)==3*n+3)
        {
         cout<<"equal";
         break;
        } 
      else
         n++;
    }
   getch();
   return 0;
 } 
                        
