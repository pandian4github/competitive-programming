#include<conio.h>
#include<iostream>
using namespace std;
/*long int coun(long long int n)
 {
   long int c=0;
   while(n%5==0)
    {
      c++;
      n=n/5;
    }
   return c;
 }     
long int count(long long int n)
 {
   if(n<5)
     return 0;
   else
     return coun(n)+count(n-5);
 }     
/*int coun(long long int n)
 {
   long long int c=0,t=n;
   while(t%5==0)
    {
      c++;
      t=t/5;
    }
   return c;
 }  
   
int count(long long int num1,long long int num2,int n)
 {
   if(num1<5)
     return 0;
   else
      if(num2>=num1)
      
         return (num2-num1+1)*n;
       
      else
       
         return n+count(num1,num2+5,coun(num2));
       
          

 
 }*/     
 
long long int power(int n)
 {
   long long int p=1;
   int i;
   for(i=1;i<=n;i++)
     p=p*5;
   return p;
 }     
   
int val(int x)
 {
   switch(x)
    {
      case 0 :return 0;
      case 1 : return 1;
      case 2 : return 6;
      case 3 : return 31;
      case 4 : return 156;
      case 5 : return 781;
      case 6 : return 3906;
      case 7 : return 19531;
      case 8 : return 97656;
      case 9 : return 488281;
      case 10 : return 2441406;
      case 11 : return 12207031;
      case 12 : return 61035156;
    }
 }   
long int count(long long int num,int x)
 {
   int d;
   d=num/power(x);
   cout<<d<<"\n";
   if(num<5||x==-1)
     return 0;
   if(d==0)
     {
       cout<<"d=0\n";
       return count(num,x-1);
     }  
   else
    {
     cout<<"d!=0\n";
     return d*val(x)+count(num-d*power(x),x-1);       
    }
 }   
int main()
 {
   long long int n,num;
   long int cou;
   cin>>n;
   int d,j;
   long long int i;
//   for(i=0;i<12;i++)
//     cout<<"\n"<<power(i)<<"\n";
   for(i=1;i<=n;i++)
    {
      cin>>num;
      d=num%5;
      num=num-d;
      j=1;
    //  cout<<". .";
      while(1)
       {
         if(power(j)>num)
           break;
         j++; 
           
       }
      j--; 
      cout<<"\n"<<j<<"\n"; 
    //  cout<<". ."; 
      d=num/power(j);
      cout<<d<<"\n";  
      cou=d*val(j);
      cout<<cou<<"\n";
      num=num-d*power(j);
      cout<<num<<"\n";
    //  cout<<". .";
      cou+=count(num,j-1);     
      //d=num/x;
      //num=num%x;
    //  cou=count(num,x); 
      cout<<cou<<"\n";
    }
   getch(); 
   return 0;
 }     
