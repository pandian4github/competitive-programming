#include<stdio.h>
#include<map>
#include<iostream>
using namespace std;
int main()
 {
   int n,m,i;
   char str[22];
   while(1)
   {
     scanf("%d%d",&n,&m);
     if(m==0&&n==0)
       break;
     map<string,int> mp;
     map<string,int>::iterator it;
     int count[n];
     for(i=0;i<n;i++)
      {
        count[i]=0;             
        cin>>str;
        mp[str]=mp[str]+1;
      }
     for(it=mp.begin();it!=mp.end();it++)
       count[(*it).second-1]++; 
     for(i=0;i<n;i++)
       printf("%d\n",count[i]);
   }
   return 0;
 }        
