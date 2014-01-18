#include<iostream>
//#include<conio.h>
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
   int n,k,j,l,count=0;
   cin>>n>>k;
   int arr[n];
   int i;
   for(i=0;i<n;i++)
    cin>>arr[i];
   quicksort(arr,0,n-1);
   for(i=0;i<n-1;i++)
    {
     for(l=i+1;l<i+k;l++)
      {
        if(arr[i]-arr[l]==2||arr[l]-arr[i]==2)
          {
           count++;
           break;
          } 
      }    
    }   
    cout<<count;
//    getch();
    return 0;
 }       
