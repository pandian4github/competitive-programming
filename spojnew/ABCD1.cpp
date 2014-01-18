#include<iostream>
using namespace std;
//#include<conio.h>
int main()
 {
   long int i,n;
   long int temp,temp1,ic,j,tt,t1;
   long int ar[4]={0};
   char ch;
   scanf("%ld",&n);
   if(n==0)
    return 0;
   long int N=2*n;
   long int str[N],out[N];
   for(i=0;i<N;i++)
    {
     cin>>ch;
     ic=(int)ch-65;
     str[i]=ic;
     ar[ic]=ar[ic]+1;
    }
   for(i=0;i<4;i++)
     ar[i]=n-ar[i]; 
   t1=0;
   cout<<str[0]<<"\n";
   for(i=0;i<4;i++)
    if(i!=str[0])
      if(ar[i]>t1)
        {
         t1=ar[i];
         temp=i;
        } 
   out[0]=temp;
   temp1=temp;
   ar[temp]--;
   for(i=1;i<N;i++)
    {
     t1=0;
     for(j=0;j<4;j++)
       if(j!=str[i]&&j!=temp1)
         if(ar[j]>t1)
           {
            t1=ar[j];
            temp=j;  
           } 
     out[i]=temp;
     ar[temp]--;
     temp1=temp;
    }
   for(i=0;i<N;i++)
     printf("%c",out[i]+65);        
   cout<<"\n";  
   cin>>n;
//   getch();
   return 0;
 } 
                 
   
