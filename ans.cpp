#include<conio.h>
//#include<stdio.h>
#include<iostream>
using namespace std;
int main()
 {
  int k=1,c,i,n; 
  cin>>n;
  int a[n];
  for(i=0;i<1000;i++)
   a[i]=i+1;
  while(1)
   {
    for(i=k;i<n;i+=2)
     a[i]=0;
    if(a[n-1]!=0)
     k=0;
    else
     k=1;
    c=0;
    for(i=0;i<n;i++)
     {
      if(a[i]!=0)
       {
        a[c]=a[i];
        c++;
       }
     }
    if(n==2)
     break;
    else
     if(n%2==1&&k==0)
      n=(n-1)/2+1;       
     else
      if(n%2==1&&k==1)
       n=(n-1)/2;
      else
       n=n/2;
   }
  cout<<a[0]<<"\n";
  getch();
  return 0;
 }
         
