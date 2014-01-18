#include<iostream>
using namespace std;
#include<conio.h>
int main()
 {
   int t,m,n,i,j,c1;
   cin>>t;
   while(t>0)
    {
      t--;
    //  cin>>n>>m;
      scanf("%d%d",&n,&m);
      int len[m],arr1[m],arr2[m];
      int status[n];
      long long int count=0;
      int min,max,pos;
      for(i=0;i<n;i++)
        status[i]=1;
      for(i=0;i<m;i++)
        scanf("%d%d%d",&arr1[i],&arr2[i],&len[i]);
      max=0;
      for(i=0;i<m;i++)
        if(len[i]>m)
          max=len[i];
      while(1)
       {
        c1=0;
        for(i=0;i<n;i++)
          if(status[i]==1)
           {
            c1=1;
            break;
           }
        if(c1==0)    
         {
           printf("%lld\n",count);
           break;
         }
        else
         {
          min=max+1;
          for(i=0;i<m;i++)
            if(len[i]<min)
             {
              pos=i;
              min=len[i];
             }
          count+=min;
          status[arr1[pos]-1]=0;
          status[arr2[pos]-1]=0;
          len[pos]=max+1;
         }
       }
    }
   getch();
   return 0;
 }    
              
              
                 
