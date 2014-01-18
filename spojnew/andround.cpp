#include<stdio.h>
#include<vector>
using namespace std;
vector<bool> vec(200001);
int main()
 {
   int flag,l,i,in,ind,j,t,var,m;
   long int ans,n,k,temp,arr[20001];
   long int andarr[20001];
   long int answer[20001];
   scanf("%d",&t);
   while(t--)
    {
      scanf("%d %ld",&n,&k);
      int index[n];
      for(i=0;i<n;i++)
        {
          scanf("%ld",&arr[i]);
          vec[i]=false;
        }
      if(k>=n/2)
       {
         ans=arr[0];
         for(i=1;i<n;i++)
           ans=ans&arr[i];
         for(i=0;i<n;i++)
           printf("%ld ",ans);
         printf("\n");  
         continue;
       }
      flag=0;
      in=0;
      for(l=k;;)
       {
        index[in++]=(n+l-k)%n;
        andarr[l]=arr[l];
        for(m=0,j=l-1;m<2*k;m++,j--)
          {
           var=(n+j)%n;
           andarr[var]=arr[var]&andarr[(var+1)%n];
          }         
         ind=index[in-1];
         var=(n+ind-k)%n;
         answer[ind]=andarr[var];
         vec[ind]=true;
         var=(var+1)%n;
         temp=arr[(ind+k+1)%n];
         answer[(ind+1)%n]=andarr[var]&temp;
         vec[(ind+1)%n]=true;
         var=(var+1)%n;
         for(m=1,j=ind+2;m<2*k;j=(j+1)%n,m++)
          {
            if(vec[j])
              {
               flag=1;
               break;
              }
            temp=temp&arr[(j+k)%n];
            answer[j]=andarr[var]&temp;
            vec[j]=true;
            var=(var+1)%n;
          }  
        if(l+k>=n-1||flag==1)
           break;
        else
          l=(l+2*k+1)%n;
       }            
      for(i=0;i<n-1;i++)
        printf("%ld ",answer[i]);
      printf("%ld \n",answer[n-1]);  
    }
   return 0;
 } 
