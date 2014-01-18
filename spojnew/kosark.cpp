#include<iostream>
using namespace std;
//#include<conio.h>
int main()
 {
   int n,m1,m2,h1,h2,i,a,b,tot1=0,tot2=0,f1=0,f2=0;
   char x;
   cin>>n;
   int team[n],time[n],tp[3]={0};
   for(i=0;i<n;i++)
    {
     cin>>team[i];
     cin>>a>>x>>b;
     time[i]=a*60+b;
    }
   for(i=0;i<n;i++)
    {
      tp[team[i]]++;
      if(tp[1]>tp[2])
       {
        f1=1;
        f2=0;
       }
      else
       if(tp[1]<tp[2])
        {
         f1=0;
         f2=1;
        }
       else
        f1=f2=0;
      if(i==n-1)
       {
        if(f1)
          tot1+=2880-time[i];
        if(f2)         
          tot2+=2880-time[i];
       }   
      else
       { 
        if(f1)
          tot1+=time[i+1]-time[i];
        if(f2)         
          tot2+=time[i+1]-time[i];
       }
    }
   m1=tot1/60;
   h1=tot1%60;
   m2=tot2/60;
   h2=tot2%60;
   printf("%d%d:%d%d\n",m1/10,m1%10,h1/10,h1%10);
   printf("%d%d:%d%d",m2/10,m2%10,h2/10,h2%10);
//   getch();
   return 0;
 } 
        
     
