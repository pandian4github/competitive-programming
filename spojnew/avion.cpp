#include<iostream>
//#include<conio.h>
using namespace std;
int main()
 {
   char str[5][11];
   int i;
   int arr[5]={0};
   int j=0,k;
   for(i=0;i<5;i++)
    {
     cin>>str[i];
     for(k=0;k<strlen(str[i]);k++)
      {
        if(str[i][k]=='F')
         if(str[i][k+1]=='B'&&str[i][k+2]=='I')
           {
             arr[j++]=i+1;
             break;
           } 
      }
    }
   if(j==0)
     cout<<"HE GOT AWAY!";
   else  
     for(i=0;i<j;i++)
       cout<<arr[i]<<" ";
//   getch();
   return 0;
 }     
