#include<iostream>
using namespace std;
//#include<conio.h>
void insertionsort(long int arr[],int n,long long int *p)
 {
   int i,j;
   long int temp;
   for(i=1;i<n;i++)
    {
      temp=arr[i];
      j=i;
      while(j>0&&arr[j-1]>temp)
        {
         arr[j]=arr[j-1];
         (*p)++;
         j--;
        }
      arr[j]=temp;
    }     
 }  
        
int main()
 {
   int t,n;
   cin>>t;
   long long int count=0;
   int i,j;
   for(i=0;i<t;i++)
    {
      cin>>n;
      count=0;
      long int arr[n];
      for(j=0;j<n;j++)
        cin>>arr[j];
      insertionsort(arr,n,&count);
      cout<<count<<"\n";
    }
//   getch();
   return 0;
 }      
        
