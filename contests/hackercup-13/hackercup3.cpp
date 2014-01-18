#include<stdio.h>
#include<vector>
#include<iostream>
using namespace std;
long long int power(long long int a,long long int b,long long int r)
{
     if(b==0)
       return 1LL;
     long long int e=power(a,b/2,r);
     if(b%2==0)
       return (e*e)%r;
     else
       return (e*e*2LL)%r;
}
long long int power2(long long int a,long long int b,long long int r,int d)
{
     if(b==0)
       return 1LL;
     long long int e=power(a,b/2,r);
     if(b%2==0)
       return (e*e)%r;
     else
       return (e*e*2LL)%r;
}
int main()
{
    int i,t,j,index,n,k,a,b,l,c,r;
    long long int d,f,h;
    double g;
    scanf("%d",&t);
    for(i=1;i<=t;i++)
    {
      scanf("%d %d",&n,&k);
      long long int arr[k+1];
      scanf("%d %d %d %d",&a,&b,&c,&r);
      vector<bool> vec(1000000002,true);
    //  prev=a;
    //  for(l=1;l<=n-k;l++)
    //    prev=(b*prev+c)%r;
    //  printf("prev : %lld\n",prev);
      j=n-k;
      index=1;
      d=power(b,j-1,r);
      f=(d*b)%r;
      g=(double)(d)*(b/b-1)-(1.0/b-1);
      h=g;
      printf("d : %lld f : %lld\n",d,f);
      arr[0]=((f*a)%r+(h*c)%r)%r;
      printf("arr[0] : %lld\n",arr[0]);
      vec[arr[0]]=false;
      for(j=1;j<k;j++)
      {
         arr[index]=(b*arr[index-1]+c)%r;
         vec[arr[index]]=false;
         index++;
      }
      for(j=1;j<=k;j++)
        cout<<vec[j];
      for(j=1;j<1000000002;j++)
      {
        if(vec[j])
          break;
      }
      printf("Case #%d: %d\n",i,j);    
    }
    return 0;
}
