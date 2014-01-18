#include<iostream>
//#include<conio.h>
using namespace std;
struct array
 {
   long long int data;
   int index;
   int status;
 };  
int partition(struct array a[],int p,int r,int v[])
{
    long long int i,j,x,pos;
    struct array temp;
    i=p-1;
    pos=p+rand()%(r-p+1);
    temp=a[pos];
    a[pos]=a[r];
    a[r]=temp;
    x=a[r].data;
    for(j=p;j<r;j++)
      if(a[j].data<=x)
       {
        i=i+1;
        temp=a[i];
        a[i]=a[j];
        a[j]=temp;
       }
    temp=a[i+1];
    a[i+1]=a[r];
    a[r]=temp;
    v[a[i+1].index]=i+1;
    return i+1;
}
void quicksort(struct array a[],int p,int r,int v[])
{
     int q;
     if(p<r)
     {
            q=partition(a,p,r,v);
            quicksort(a,p,q-1,v);
            quicksort(a,q+1,r,v);
     }
     if(p==r)
       v[a[p].index]=p;
}

int main()
 {
   long long int n,cost=0,t1,t2;
   scanf("%lld",&n);
   struct array arr[n];
   long long int arr1[n];
   int vec[n],vect[n],i,pos1,pos2,j;
   for(i=0;i<n;i++)
     {
      scanf("%lld",&arr1[i]);
      arr[i].data=arr1[i];      
      arr[i].index=i;
      arr[i].status=0;
     } 
//   for(i=0;i<n;i++)
//     vect[i]=i;
   quicksort(arr,0,n-1,vect);
   for(i=0;i<n;i++)
     vec[vect[i]]=i;  
//   cout<<"\n";
//   for(i=0;i<n;i++)
//     cout<<vec[i]<<"  ";
   for(i=0;i<n;i++)
    {
//      cout<<"\n";
//      cout<<"Status. . .\n";
//      for(j=0;j<n;j++)
//        cout<<arr[j].status<<"   ";
      pos1=pos2=vec[i];
//      cout<<"pos1 = "<<pos1;
      arr[pos1].status=1;
      while(pos1>=0&&arr[pos1].status!=0)
        pos1--;
//      cout<<"\npos1 = "<<pos1;  
      if(pos1>=0)
        t1=arr1[pos1];    
      while(pos2<n&&arr[pos2].status!=0)
        pos2++; 
//      cout<<"\npos2 = "<<pos2;  
      if(pos2<n)
        t2=arr1[pos2];
      if(pos1<0)
       {
        if(pos2>=n)
          break;
        else
          cost+=arr1[pos2];
       }
      else
       {
        if(pos2>=n)
          cost+=arr1[pos1];
        else
         {
          if(arr1[pos1]<arr1[pos2])
            cost+=arr1[pos1];
          else
            cost+=arr1[pos2];
         }
       }       
//      cout<<"\nCost = "<<cost<<"\n";  
    }
   cout<<cost;             
//   getch();
   return 0;
 }   
