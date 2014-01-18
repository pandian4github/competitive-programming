#include<iostream>
using namespace std;
void swap(int *a,int *b)
 {
    int x=*a;
    *a=*b;
    *b=x;
 }
int partition(int arr[],int low,int high)
 {
    int i,p,firsthigh;
    p=low+(rand()%(high-low+1));
    swap(&arr[p],&arr[high]);
    firsthigh=low;
    for(i=low;i<high;i++)
     {
      if(arr[i]<arr[high])      
        {
          swap(&arr[i],&arr[firsthigh]);
          firsthigh++;
        }
     }
    swap(&arr[high],&arr[firsthigh]);
    return firsthigh;
 }

void quicksort(int arr[],int low,int high)
 {
    int p;
    if(high>low)
     {
       p=partition(arr,low,high);
       quicksort(arr,low,p-1);
       quicksort(arr,p+1,high);
     }
 }

int main()
 {
   int n;
   while(1)
    {
      cin>>n;
      if(n==0)
        break;
      int arr[n];
      int i;
      for(i=0;i<n;i++)
        cin>>arr[i];
      quicksort(arr,0,n-1);
      int c=0;
      if(arr[n-1]<1322)
       {
         cout<<"IMPOSSIBLE\n";
         c=1;
         continue;
       }  
      for(i=0;i<n-1;i++)
       {
         if(arr[i+1]-arr[i]>200)
          {
           cout<<"IMPOSSIBLE\n";
           c=1;
           break;
          } 
       }
      if(c==0) 
       cout<<"POSSIBLE\n";
    }
   return 0;
 }           
         
          
                     
