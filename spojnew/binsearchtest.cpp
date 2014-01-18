#include<stdio.h>
#include<iostream>
using namespace std;
int binarysearch(int arr[],int l,int r,int k)
{
    int m=(l+r)/2;
    if(k<arr[l])
      return arr[l];
    if(k>arr[r])
      return -1;
    if(arr[m]==k)
      return arr[m];
    else
     if(arr[m]<k)
       {
                 if(arr[m+1]>=k)
                   return arr[m+1];
                 return binarysearch(arr,m+1,r,k);
       }
     else
       {
                 if(arr[m-1]<k)
                   return arr[m];
                 return binarysearch(arr,l,m-1,k);
       }
}
int main()
{
    int t,n,i,j,a,l,r,key;
    int arr[100001];
    scanf("%d",&t);
    while(t--)
    {
              scanf("%d",&n);
              for(i=0;i<n;i++)
                scanf("%d",&arr[i]);
              printf("\nArray : ");
              for(i=0;i<n;i++)
                printf(" %d  ",arr[i]);
              printf("\n");
              while(1)
              {
                      printf("Enter key : ");
                      scanf("%d",&key);
                      if(key==-1)
                        break;
                      l=binarysearch(arr,0,n-1,key);
                      printf("%d\n",l);
              }
    }   
    return 0;
}   
              
