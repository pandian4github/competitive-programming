#include <sstream> //stringstream library
#include<stdio.h>
#include<conio.h>
#include<iostream>
#include<fstream>
using namespace std;
int partition(int a[],int p,int r,int index[])
 {
   int i,j;
   int x,temp;
   i=p-1;
   x=a[r];
   for(j=p;j<r;j++)
    {
      if(a[j]<=x)
       {
         i=i+1;
         temp=a[i];
         a[i]=a[j];
         a[j]=temp;
         temp=index[i];
         index[i]=index[j];
         index[j]=temp;
         
       }
    }
   temp=a[i+1];
   a[i+1]=a[r];
   a[r]=temp;
   temp=index[i+1];
   index[i+1]=index[r];
   index[r]=temp;
   
   return i+1;
 }
void quicksort(int a[],int p,int r,int index[])
 {
   int q;
   if(p<r)
    {
      q=partition(a,p,r,index);
      quicksort(a,p,q-1,index);
      quicksort(a,q+1,r,index);
    }
 }
int main()
 {
   int t,n,i,j,a,b;
   string str; //string containing a number
   ofstream myfile;
   ifstream inpfile;
   inpfile.open("test2inp.txt");
   myfile.open("test2.txt");
  // scanf("%d",&t);
  // myfile<<"hi\nhello\n";
   inpfile>>t;
 //  cout<<str<<"\n";
  // stringstream myStream(str); //create the stringstream
  // myStream>>t; //convert the string to an integer 
 //  printf("%d\n",t);
   //cout<<t<<"\n";
  // getch();
   while(t--)
    {
      //scanf("%d",&n);
      inpfile>>n;
      int contA[n+1],contB[n+1],arr[n+1],index[n+1];
      long int sum=0,avg;
      a=0;
      b=0;
      for(i=0;i<n;i++)
        {
         //scanf("%d",&arr[i]);
         inpfile>>arr[i];
         sum=sum+arr[i];
         index[i]=i;
        }
      avg=sum/2;  
      quicksort(arr,0,n-1,index);
      for(i=n-2;i>=0;i--)
       {
        if(avg>=arr[i])
          {
           contA[a++]=index[i]+1;
           avg=avg-arr[i];
           arr[i]=-1;
          }
         if(avg==0)
           break; 
       }
      for(i=n-2;i>=0;i--)
         if(arr[i]!=-1)
          contB[b++]=index[i]+1;
      myfile<<a<<" ";
      for(i=0;i<a;i++)
        myfile<<contA[i]<<" ";
      myfile<<"\n";
      myfile<<b<<" ";
      for(i=0;i<b;i++)
        myfile<<contB[i]<<" ";
      myfile<<"\n";    
      /*printf("%d ",a);
      for(i=0;i<a;i++)
        printf("%d ",contA[i]);
      printf("\n");     
      printf("%d ",b);
      for(i=0;i<b;i++)
        printf("%d ",contB[i]);
      printf("\n");*/     
    }
  return 0;
 }      
