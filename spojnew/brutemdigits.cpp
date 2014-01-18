#include<iostream>
using namespace std;
#include<conio.h>
long long int power(int x)
 {
   long long int p=1;
   for(int i=1;i<=x;i++)
     p=p*10;
   return p;
 }   
int nodig(long long int x)
 {
  int cou=0;
  while(x>0)
   {
     cou++;
     x=x/10;
   } 
  return cou;
 }
void actualsum(int d,long int arr[])
 {
    int i;
    switch(d)
     {
      case 1 : arr[0]+=0;
               for(i=1;i<=9;i++)
                 arr[i]+=1;
               break;
      case 2 : arr[0]+=9;
               for(i=1;i<=9;i++)
                 arr[i]+=19;
               break;  
      case 3 : arr[0]+=180;
               for(i=1;i<=9;i++)
                 arr[i]+=280;
               break;  
      case 4 : arr[0]+=2700;
               for(i=1;i<=9;i++)
                 arr[i]+=3700;
               break;  
      case 5 : arr[0]+=36000;
               for(i=1;i<=9;i++)
                 arr[i]+=46000;
               break;  
      case 6 : arr[0]+=450000;
               for(i=1;i<=9;i++)
                 arr[i]+=550000;
               break;  
      case 7 : arr[0]+=5400000;
               for(i=1;i<=9;i++)
                 arr[i]+=6400000;
               break;   
      case 8 : arr[0]+=63000000;
               for(i=1;i<=9;i++)
                 arr[i]+=73000000;
               break;  
     }
 }                 
void brutesum(long long int a,long long int b,int d,long int arr[])
 {
   long long int n,temp;
   cout<<"\nEntered brutesum\n\n a = "<<a<<"  b = "<<b<<"  d = "<<d<<"\n";
   for(n=a;n<=b;n++)
    {
      temp=n;
      while(temp>0)
       {
        arr[temp%10]++;
        temp=temp/10;
       }
    }
 }                 
int main()
 {
   long long int a,b;
   int d1,d2,i,c1,c2;
   long int arr[10]={0};
   while(1)
    {
     for(i=0;i<10;i++)
       arr[i]=0;
     scanf("%lld%lld",&a,&b);
     if(a==0&&b==0)
       break;
     c1=c2=0;  
     d1=nodig(a);
     d2=nodig(b);  
 //    cout<<d1<<"  "<<d2;
     if(a==power(d1-1))
       c1=1;
     if(b==power(d2)-1)
       c2=1;
 //    cout<<c1<<"  "<<c2;
     if(c1)
      {
       if(c2)
        {
         for(i=d1;i<=d2;i++)
           actualsum(i,arr);
        }
       else
        {
         for(i=d1;i<d2;i++)
           actualsum(i,arr);
      //   getch();  
         brutesum(power(d2-1),b,d2,arr);
        }
      }
     else
      { 
       if(c2)
        {
         for(i=d1+1;i<=d2;i++)
           actualsum(i,arr);
         brutesum(a,power(d1)-1,d1,arr);
        }
       else
        {
         for(i=d1+1;i<d2;i++)
           actualsum(i,arr);
         if(d1==d2)
           brutesum(a,b,d1,arr);
         else  
          {
           brutesum(a,power(d1)-1,d1,arr);
           brutesum(power(d2-1),b,d2,arr);
          } 
        }
      }
//     arr[0]--;                 
     for(i=0;i<9;i++)
       printf("%d ",arr[i]);
     printf("%d\n",arr[9]);
    }
   return 0;
 }                    
