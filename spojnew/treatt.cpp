#include<iostream>
#include<conio.h>
using namespace std;
int check(int a[],int i,int j)
 {
   if(i<j)
   {
     if(a[i+1]==a[j-1])
       return check(a,i+1,j-1);
     else
      if(a[i+1]>a[j-1])
        return 1;
      else
        return 0;
   }
   else
     return 1; 
 }         
int main()
 {
   int n,sum=0,p,c;
   cin>>n;
   int a[n];
   int i;
   for(i=0;i<n;i++)
     cin>>a[i];
   p=1;
   i=0;
   int j=n-1;
   while(1)  
    {
      if(i>j)
        break;
      if(a[i]<a[j])
        sum+=a[i++]*p;
      else
       if(a[i]>a[j])
         sum+=a[j--]*p;
       else
         {
           c=check(a,i,j);  
           if(c==1)
             sum+=a[j--]*p;
           else
             sum+=a[i++]*p;
         }     
      p++;
    }
   cout<<sum<<"\n";
   getch();
   return 0;
 }         
