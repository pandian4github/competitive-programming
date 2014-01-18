#include<iostream>
//#include<conio.h>
using namespace std;
long long int pow(int a,int b)
 {
   long long int p=1;
   int i;
   for(i=0;i<b;i++)
     p=p*a;
   return p;
 }    
long long int makep2(long long int n,int *p)
 {
   for(int i=0;;i++)
    {
      long long int pp=pow(2,i);
      if(n==pp)
        {
         *p=i;
         return 0;
        } 
      if(n<pp)
         {
          *p=i;
          return (pp-n);  
         } 
    }
 }      
int main()
 {
   long long int g,t,a,d,add,nott;
   long long int tot;
   int p,i;
   while(1)
    {
      tot=0;
      add=0;
      p=0;
      scanf("%lld%lld%lld%lld",&g,&t,&a,&d);
//      cin>>g>>t>>a>>d;
      if(g==-1&&t==-1&&a==-1&&d==-1)
        break;
      tot+=g*t*(t-1)/2;
      nott=a*g+d;
      add=makep2(nott,&p);
      for(i=p-1;i>=0;i--)
        tot+=pow(2,i);
      printf("%lld*%lld/%lld+%lld=%lld+%lld\n",g,a,t,d,tot,add);            
  //    cout<<g<<"*"<<a<<"/"<<t<<"+"<<d<<"="<<tot<<"+"<<add<<"\n";
    }
   return 0;
 }      
