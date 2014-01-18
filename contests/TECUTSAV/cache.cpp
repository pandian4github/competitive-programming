#include<stdio.h>
#include<map>
#include<queue>
#include<algorithm>
using namespace std;
int main()
{
    int t,i,n,k,size,a;
    scanf("%d",&t);
    map<int,int> mp;
    map<int,int> count;
    queue<int> q;
    while(t--)
    {
      scanf("%d %d",&n,&k);
      size=0;
      mp.clear();
      count.clear();
      for(i=0;i<n;i++)
      {
         scanf("%d",&a);
         if(mp[a]==1)
           {
            count[a]++;
            q.push(a);
            continue;
           }
         mp[a]=1;
         count[a]++;
         q.push(a);
         size++;
         if(size>k)
         {
           while(count[q.front()]>1)
           {
             count[q.front()]--;
             q.pop();
           }
           mp[q.front()]=0;
           q.pop();
           size--;
         }
      }
  //    printf("size : %d\n",size);
      int arr[n+1],l=0;
      map<int,int> ver;
      ver.clear();
      while(!q.empty())
      {
        if(ver[q.front()]==0)
        {
          arr[l++]=q.front();
          ver[q.front()]=1;
          q.pop();
        }
        else
          q.pop();
      }
    //  printf("l : %d\n",l);
      sort(arr,arr+l);
      for(i=0;i<l;i++)
        printf("%d ",arr[i]);
      printf("\n");
    }
    return 0;
}
