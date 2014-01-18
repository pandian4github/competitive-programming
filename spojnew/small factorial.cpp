#include<iostream.h>
#include<conio.h>

int main()
{
    int i, num;
    int fact=1;
    cout<<"enter a num...";
    cin>>num;
    for(i=1;i<=num;i++)
    {
          fact=i*fact;
         
         }
         cout<<"the factorial is..."<<fact;
         getch();
         return 0;
        
}
