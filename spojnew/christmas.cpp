#include<iostream>
//#include<conio.h>
using namespace std;
int partition(long long int a[],int p,int r)
{
    long long int i,j,x,temp,pos;
    i=p-1;
    pos=p+rand()%(r-p+1);
    temp=a[pos];
    a[pos]=a[r];
    a[r]=temp;
    x=a[r];
    for(j=p;j<r;j++)
    {
            if(a[j]<=x)
            {
                 i=i+1;
                 temp=a[i];
                 a[i]=a[j];
                 a[j]=temp;
            }
    }
            temp=a[i+1];
            a[i+1]=a[r];
            a[r]=temp;
            return i+1;
}
void quicksort(long long int a[],int p,int r)
{
     int q;
     if(p<r)
     {
            q=partition(a,p,r);
            quicksort(a,p,q-1);
            quicksort(a,q+1,r);
     }
}

int main()
 {
   int i,j,l,t,n,k;
   long long int min;
   cin>>t;
   for(i=0;i<t;i++)
    {
      cin>>n>>k;
      long long int arr[n];
      for(j=0;j<n;j++)
        scanf("%lld",&arr[j]);
      quicksort(arr,0,n-1);
//      for(l=0;l<n;l++)
//        cout<<arr[l]<<"   ";
      min=arr[n-1]-arr[0];
      for(l=0;l<=n-k;l++)
        if(arr[l+k-1]-arr[l]<min)
          min=arr[l+k-1]-arr[l];
      cout<<min<<"\n";
    }
  // getch();
   return 0;
 }         
