#include<iostream>
//#include<conio.h>
using namespace std;
int main()
 {
   long int t,n,w,h,i,j,xmax,ymax,p,x,y;
   cin>>t;
   for(i=0;i<t;i++)
    {
      cin>>w>>h>>n;
//      if(n==0)
//        {
//         cout<<w*h<<"\n";
//         continue;
//        } 
      int xx[w],yy[h];
      for(j=0;j<w;j++)
        xx[j]=0;
      for(j=0;j<h;j++)
        yy[j]=0;        
      for(j=0;j<n;j++)
        {
         cin>>x>>y;
         xx[x-1]=1;
         yy[y-1]=1;
        }
      xmax=0;
      ymax=0;
      p=0;
//      for(j=0;j<w;j++)
//        cout<<xx[j]<<"   ";
//      cout<<"\n";  
//     for(j=0;j<h;j++)
//        cout<<yy[j]<<"   ";
//      cout<<"\n";  
      for(j=0;j<w;j++)
       {
        p++;
        if(j==w-1)
         {
          if(xx[j]==1)
           {
             p--;
             if(p>xmax)
              xmax=p;
             p=0;
          }
          else
           {
             if(p>xmax)
              xmax=p;
           }
         }
        else
         {
          if(xx[j]==1)
           {
            p--;
            if(p>xmax)
              xmax=p;
            p=0;
           }
         }
       }       
      p=0;
      for(j=0;j<h;j++)
       {
        p++; 
        if(j==h-1)
         {
          if(yy[j]==1)
           {
             p--;
             if(p>ymax)
              ymax=p;
             p=0;
           }
          else
           {
             if(p>ymax)
              ymax=p;
           }
         }
        else
         {
          if(yy[j]==1)
           {
            p--;
            if(p>ymax)
              ymax=p;
            p=0;
           }
         }
               
       } 
//      cout<<xmax<<"\n"<<ymax<<"\n";
      cout<<xmax*ymax<<"\n";
    }
//   getch();
   return 0;
 }               
