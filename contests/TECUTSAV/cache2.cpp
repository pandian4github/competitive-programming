#include<stdio.h>
#include<map>
#include<algorithm>
using namespace std;
int main()
{
    int t,i,n,k,l;
    scanf("%d",&t);
    map<int,int> mp;
    map<int,int> count;
    while(t--)
    {
      scanf("%d %d",&n,&k);
      mp.clear();
      count.clear();
      int array[n],arr[n];
      for(i=0;i<n;i++)
         scanf("%d",&array[i]);
      l=0;
      for(i=n-1;i>=0 && l<k;i--)
        if(mp[array[i]]==1)
          continue;
        else
          {
            arr[l++]=array[i];
            mp[array[i]]=1;
          }
      sort(arr,arr+l);
      for(i=0;i<l;i++)
        printf("%d ",arr[i]);
      printf("\n");
    }
    return 0;
}
