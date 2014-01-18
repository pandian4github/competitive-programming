#include<iostream>
#include<stdio.h>
using namespace std;
int main()
 {
   long int a,b;
   while(1)
    {
      scanf("%ld%ld",&a,&b);
      if(a==-1&&b==-1)
        break;
      if(a*37==b*1000)
        printf("Y\n");
      else
        printf("N\n");
     }
   return 0;
 }       
          
          
