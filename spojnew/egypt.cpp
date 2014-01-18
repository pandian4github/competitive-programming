#include<iostream>
using namespace std;
void swap(long long int *p,long long int *q)
 {
   long long int t;
   t=*p;
   *p=*q;
   *q=t;
 }  
int main()
 {
   long long int a[3];
   while(1)
    {
      cin>>a[0]>>a[1]>>a[2];
      if(a[0]+a[1]+a[2]==0)
        break;
      if(a[1]>a[0])
        swap(&a[0],&a[1]);
      if(a[2]>a[0])
        swap(&a[0],&a[2]);
      if((a[0]*a[0])==((a[1]*a[1])+(a[2]*a[2])))
        cout<<"right\n";
      else
        cout<<"wrong\n";
    }
   return 0;
 }      
              
