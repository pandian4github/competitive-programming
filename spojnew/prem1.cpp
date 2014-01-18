#include<iostream.h>
#include<conio.h>
int main()
 {
   int n,i=0,a=-1,b=1,c;
   cin>>n;
   while(1)
    {
      c=a+b;
      cout<<c<<"  ";
      i++;
      if(i==n)
        break;
      a=b;
      b=c;
    }    
   getch();
   return 0;
 } 
