#include<iostream>
using namespace std;
//#include<conio.h>
int main()
 {
   int a,b,c;
   while(1)
    {
      cin>>a>>b>>c;
      if(a==0&&b==0&&c==0)
        break;
      if((b-a)==(c-b))
        cout<<"AP "<<c+c-b<<"\n";
      else
        cout<<"GP "<<c*c/b<<"\n";
    }
//   getch();
   return 0;
 }          
