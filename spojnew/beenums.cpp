#include<iostream>
//#include<conio.h>
using namespace std;
int main()
 {
   long int n;
   while(1)
    {
      scanf("%ld",&n);
      if(n==-1)
        break;
      n--;
      if(n%6==0)
       {
        n=n/6;
        long int p=1;
        while(n>0)
         {
          n=n-p;
          p++;
         }
        if(n==0)
          cout<<"Y\n";
        else
          cout<<"N\n";
       }
      else
        cout<<"N\n";
//      getch();
    }
   return 0;
//   getch();
 }             
            
