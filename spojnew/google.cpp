#include<iostream>
//#include<conio.h>
using namespace std;
struct google
 {
   int v;
   char web[110];
 };  
int max(struct google g[])
 {
   int m=g[0].v;
   int i;
   for(i=1;i<10;i++)
     if(g[i].v>m)
       m=g[i].v;
   return m;
 }      
int main()
 {
   int t,m;
   cin>>t;
   int i,j;
   struct google g[10];
   for(i=1;i<=t;i++)
    {
      for(j=0;j<10;j++)
       {
        cin>>g[j].web;
        cin>>g[j].v;
       } 
      m=max(g);
      cout<<"Case #"<<i<<":\n";
      for(j=0;j<10;j++)
        if(g[j].v==m)
          cout<<g[j].web<<"\n";
    }
//   getch();
   return 0;
   
 }        
