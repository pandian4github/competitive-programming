#include<iostream>
//#include<conio.h>
using namespace std;
int partition(int a[],int p,int r)
{
    int i,j,x,temp,pos;
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
void quicksort(int a[],int p,int r)
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
   int n,k,s;
   cin>>n>>k>>s;
   int i,arr[n];
   for(i=0;i<n;i++)
     cin>>arr[i];
   quicksort(arr,0,n-1);
   int sum=0;
   for(i=n-1;i>=0;i--)
    {
      sum+=arr[i];
      if(sum>=s*k)
        {
          cout<<n-i;
          break;
        }
    }
//   getch();
   return 0;
 }      
   
