#include<stdio.h>
#include<vector>
using namespace std;
vector<bool> vec(1000000000,false);
int main()
 {
   long int i,n,k,count=0;
   scanf("%ld %ld",&n,&k);
   int arr[n];
   for(i=0;i<n;i++)
    {
      scanf("%d",&arr[i]);
      vec[arr[i]]=true;
    }
   for(i=0;i<n;i++)
    if(arr[i]+k<1000000000)
      if(vec[arr[i]+k])
        count++;
   printf("%ld\n",count);
   return 0;
 } 
