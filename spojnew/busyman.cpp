#include<stdio.h>
#include<map>
using namespace std;
int main()
 {
   int t,start,end,n,max,count,prevend,i;
   scanf("%d",&t);
   while(t--)
    {
      scanf("%d",&n);
      max=0;
      count=0;
      prevend=0;
      map<int,int> mp;
      while(n--)
       {
         scanf("%d %d",&start,&end);
         if(end>max)
           max=end;
         if(mp.count(end)>0)
           mp[end]=(mp[end]>start)?mp[end]:start;
         else
           mp[end]=start; 
       }
  /*    map<int,int>::iterator it;
      for(it=mp.begin();it!=mp.end();++it)
        printf("%d  %d  \n",(*it).first,(*it).second); */
      for(i=1;i<=max;i++)
        if(mp.count(i)>0)
           if(mp[i]>=prevend)
             {
               count++;
               prevend=i;
             }
      printf("%d\n",count);
    }
   return 0; 
 }     
              
         
