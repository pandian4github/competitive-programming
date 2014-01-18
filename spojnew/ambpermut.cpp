#include<iostream>
using namespace std;
int main()
 {
   int c,n,i;
   while(1)
    {
      c=0;
      scanf("%d",&n);
      if(n==0)
        break;
      int arr[n],arr1[n];
      for(i=0;i<n;i++)
        scanf("%d",&arr[i]);
      for(i=0;i<n;i++)
        arr1[arr[i]-1]=i+1;
      for(i=0;i<n;i++)
        if(arr[i]!=arr1[i])
         {
          c=1;
          break;
         }
      if(c)
        printf("not ambiguous\n");
      else
        printf("ambiguous\n");
    }
   return 0;
 }             
