#include<iostream>
#include<conio.h>
using namespace std;
int partition(long long int a[],int p,int r,int v[],int v1[])
{
    long long int i,j,x,temp,pos;
    i=p-1;
    pos=p+rand()%(r-p+1);
//    cout<<"\narr in partition before. . .\n";
//    for(j=p;j<=r;j++)
//      cout<<a[j]<<"   ";
//    cout<<"\n";  
    cout<<"\npos = "<<pos<<"\n";
    temp=a[pos];
    a[pos]=a[r];
    a[r]=temp;
    temp=v1[pos];
    v1[pos]=v1[r];
    v1[r]=temp;
    x=a[r];
    for(j=p;j<r;j++)
    {
            if(a[j]<=x)
            {
                 i=i+1;
                 temp=v1[i];
                 v1[i]=v1[j];
                 v1[j]=temp;                 
                 temp=a[i];
                 a[i]=a[j];
                 a[j]=temp;
            }
    }
    temp=a[i+1];
    a[i+1]=a[r];
    a[r]=temp;
    temp=v1[i+1];
    v1[i+1]=v1[r];
    v1[r]=temp;
    cout<<"\np = "<<p<<"  r = "<<r<<"\n";
    cout<<"\nq = "<<i+1<<"\n";
//    cout<<"\narr in partition. . .\n";
//    for(j=p;j<=r;j++)
//      cout<<a[j]<<"   ";
//    cout<<"\n";  
//    cout<<"\nv1 in partition. . .\n";
//    for(j=p;j<=r;j++)
//      cout<<v1[j]<<"   ";
//    cout<<"\n";  
//    cout<<"\nv in partition. . .\n";
//    for(j=p;j<=r;j++)
//      cout<<v[j]<<"   ";
//    cout<<"\n";  
    v[v1[pos]]=i+1;
//    cout<<"v["<<v1[pos]<<"] = "<<i+1<<"\n";
    return i+1;
}
void quicksort(long long int a[],int p,int r,int v[],int v1[])
{
     int q;
     if(p<r)
     {
            q=partition(a,p,r,v,v1);
            quicksort(a,p,q-1,v,v1);
            quicksort(a,q+1,r,v,v1);
     }
//     if(p==r)
//       v[v1[p]]=p;
}

int main()
 {
   long int n;
   cin>>n;
   long long int arr[n];
   int vec[n];
   int vect[n];
   int i;
   for(i=0;i<n;i++)
     cin>>arr[i];
   for(i=0;i<n;i++)
     vec[i]=vect[i]=i;
   quicksort(arr,0,n-1,vec,vect);  
   for(i=0;i<n;i++)
     cout<<arr[i]<<"   ";
   cout<<"\n";  
   for(i=0;i<n;i++)
     cout<<vec[i]<<"   ";
   cout<<"\n";  
   for(i=0;i<n;i++)
     cout<<vect[i]<<"   ";
   getch();
   return 0;
 }   
