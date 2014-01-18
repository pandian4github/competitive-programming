#include<iostream>
using namespace std;
//#include<conio.h>
int main()
 {
   int n;
   cin>>n;
   long long int a[n],b[n],c[n],d[n];
   int i=0;
   for(;i<n;i++)
     cin>>a[i]>>b[i]>>c[i]>>d[i];
   int j,k,l,count=0;
   for(i=0;i<n;i++)
     for(j=0;j<n;j++)
       for(k=0;k<n;k++)
         for(l=0;l<n;l++)
           {
   //          cout<<a[i]<<"  "<<b[j]<<"  "<<c[k]<<"  "<<d[l]<<"\n\n";
             if(a[i]+b[j]+c[k]+d[l]==0)
             count++;
           }  
    cout<<count<<endl;
//    getch();
    return 0;
 }          
     
