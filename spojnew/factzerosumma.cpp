#include<conio.h>
#include<iostream>
using namespace std;
long int count(long long int five)
 {
   if(five==0)
     return 0;
   return five+count(five/5);
 }  
int main()
 {
   long long int n,num,temp;
   long int cou;
   cin>>n;
   int d;
   long long int five;
   long long int i,j;
   for(i=1;i<=n;i++)
    {
      cou=0;
      cin>>num;
      temp=num;
      five=temp/5;
      cou=count(five);
      cout<<cou<<"\n";
    }
   getch(); 
   return 0;
 }     
