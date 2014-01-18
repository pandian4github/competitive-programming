#include<stdio.h>
#include<string.h>
#include<math.h>
#include<iostream>
#include<map>
#include<vector>
#include<queue>
#include<set>
using namespace std;
#define scani(a) scanf("%d",&a);
#define fori(a,b) for(i=a;i<=b;i++)
#define forj(a,b) for(j=a;j<=b;j++)
int arr[1000001];
int findCandidate(int n)
{
    int i,max_index,count=1;
    max_index=0;
    fori(1,n-1)
    {
      if(arr[max_index]==arr[i])
        count++;
      else
        count--;
      if(count==0)
      {
        max_index=i;
        count=1;
      }
    }
    return arr[max_index];
}
bool isMajority(int n,int candidate)
{
     int i,count=0;
     fori(0,n-1)  
       if(arr[i]==candidate)
         count++;
     if(count>n/2)
       return true;
     return false;
}
int main()
{
    int t,n,i,candidate;
    scani(t)
    while(t--)
    {
      scani(n)
      fori(0,n-1)
        scani(arr[i])
      candidate = findCandidate(n);
      if(isMajority(n,candidate))
         printf("YES %d\n",candidate);
      else
         printf("NO");
    }
    return 0;
}
