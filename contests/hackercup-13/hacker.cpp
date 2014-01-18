#include<stdio.h>
#include<algorithm>
#include<fstream.h>
using namespace std;
long long int combination(int n,int a)
 {
   long long int c=1LL;   
   if(n==a)
    return 1LL;
   c=(n*combination(n-1,a))%1000000007;
   c=c/combination((n-a),1);
   return c%1000000007;
 }  
int main()
{
    int t,i,ans,k,j,key,n,l;
    scanf("%d",&t);
    ofstream oup("output.txt");
    long long int c;
    for(i=1;i<=t;i++)
    {
      scanf("%d %d",&n,&k);
      int arr[n];
      for(j=0;j<n;j++)
        scanf("%d",&arr[j]);
      sort(arr,arr+j);
      ans=0;
      for(l=1;l<n;l++)
      {
        key=arr[n-l];
        if(n-l<k-1)
          break;
        c=combination(n-l,k-1);
        ans=ans+(c*key)%1000000007;        
      }      
      oup<<"Case #"<<i<<": "<<ans<<"\n";
    }
    return 0;
}
