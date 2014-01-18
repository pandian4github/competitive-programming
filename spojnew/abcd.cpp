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
   long int N=2*n;
   long int str[N],out[N];
   for(i=0;i<N;i++)
    {
  //   fflush(0);
//     scanf("%c",&ch);
     cin>>ch;
     ic=(int)ch-65;
  //   getch();
     str[i]=ic;
//     cout<<ic<<"\n";
     ar[ic]=ar[ic]+1;
    }
 //  for(i=0;i<4;i++)
 //    cout<<ar[i]<<"  ";
 //  cout<<"\n";      
   for(i=0;i<4;i++)
     ar[i]=n-ar[i]; 
 //  for(i=0;i<4;i++)
 //    cout<<ar[i]<<"  ";
 //  cout<<"\n";  
   t1=0;
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
     t1=-1;
     for(j=0;j<4;j++)
       if(j!=str[i]&&j!=temp1)
         if(ar[j]!=0&&ar[j]>t1)
           {
            t1=ar[j];
            temp=j;
           } 
     out[i]=temp;
  //   printf("%c",temp+65);
     if(t1==-1)
      {
 //      cout<<"\nEntered.v.\n"<<i<<"\n";          
       temp=str[i];
//       cout<<"temp = "<<temp<<" I = "<<i<<" str[i] = "<<str[i]<<"\n";
       for(j=i-1;j>=0;j--)
        {
//         cout<<"j = "<<j<<"  str[j] = "<<str[j]<<"  out[j] = "<<out[j]<<"  out[j-1] = "<<out[j-1]<<" out[j+1] = "<<out[j+1]<<"\n";
         if(temp!=str[j]&&out[j]!=str[i]&&((j==i-1)||(out[j]!=out[i-1]))&&temp!=out[j-1]&&temp!=out[j+1])
         {
          tt=out[j];
          out[j]=temp;
          out[i]=tt;
//          cout<<j<<"\n";
          break;  
         }
        }  
      }          
     ar[temp]--;
     temp1=temp;
    }
   for(i=0;i<N;i++)
     printf("%c",out[i]+65);        
   printf("\n");  
//   cin>>n;  
 //  getch();
   return 0;
 } 
                 
   
