#include<iostream>
using namespace std;
//#include<conio.h>
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
   //   (*c)++;
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
   int i,t,max=0;
   cin>>t;
   int n,count,k,l,j,temp;
   for(i=0;i<t;i++)
    {
      cin>>n;
      max=0;
      int arr[n];
      for(j=0;j<n;j++)
        cin>>arr[j];
      quicksort(arr,0,n-1);
      count=0;
      for(k=0;k<n-1;)
        {
         temp=arr[k];
         while(arr[k]==temp)
          {
            count=count+temp;
            k++;
          }
         if(count>max)
           max=count;
         }   
              
      cout<<max<<"\n";
    }
  // getch();
   return 0;
 }          
              
