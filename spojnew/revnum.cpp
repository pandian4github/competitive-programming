#include<iostream.h>
#include<conio.h>

int main()
{
    
    int i,a[5];
    int num;
    cin>>num;
    for(i=1;i<=5;i++)
    {   
         a[i]=num%10;
         num=num/10;
         }
    for(i=5;i>=1;i--)
    {
       cout<<a[i];
       if(i==1)
       break;
    }
   getch();   
  return 0;  
}
