#include<stdio.h>
#include<vector>
using namespace std;
vector<long int> mp1(53687091,0);
int main()
 {
   int n,i,j;
   long int arr1[4001],arr2[4001],arr3[4001],arr4[4001];
   long int count=0;
   scanf("%d",&n);
   for(i=0;i<n;i++)
      scanf("%ld %ld %ld %ld",&arr1[i],&arr2[i],&arr3[i],&arr4[i]);
   for(i=0;i<n;i++)
     for(j=0;j<n;j++)
       mp1[arr1[i]+arr2[j]]++;
   for(i=0;i<n;i++)
     for(j=0;j<n;j++)
       count=count+mp1[0-(arr3[i]+arr4[j])];
   printf("%ld\n",count);
   return 0;
 }

