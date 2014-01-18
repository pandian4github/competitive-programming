#include<vector>
#include<stdio.h>
using namespace std;
int count[30000];
int arr[15000];
int status[30000];
vector<bool> vec(30000);
int partition(int a[],int p,int r)
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
void luckysieve()
 {
   int i,j,k=0;
   for(i=0;i<30000;i++)
     {
      count[i]=0;
      vec[i]=true;
      status[i]=0;
     }
   for(i=2;i<1800;i++)
    {
      if(vec[i])
       for(j=i+i;j<30000;j=j+i)
        {
          count[j]++;
          vec[j]=false;
          if(count[j]==3&&j<=2664)
            {
             arr[k++]=j;
             status[j]=1;
            }
        }
    }
 //  printf("k %d\n",k); 
   quicksort(arr,0,k-1); 
 }   
int main()
 {
   int i,j=0,n,t;
   scanf("%d",&t);
   luckysieve();
   //quicksort(arr,0,999);
 //  for(i=0;i<2665;i++)
 //    if(status[i]==1)
 //      j++;
 //  printf("j %d\n",j);   
 //  printf("jj %d\n",arr[999]); 
 //  for(i=0;i<10000;i++)
   //  printf("%d\n",arr[i]);
   while(t--)
    {
      scanf("%d",&n);
      printf("%d\n",arr[n-1]);
    }
   return 0;
 }
