#include <algorithm>
#include <string> 
#include<stdio.h>
#include<vector>
#include<iostream>
#include<conio.h>
#include<string.h>
#include<map>
using namespace std;
char str[200001];
vector<string> vec(100000,0);
vector<int> intvec(100000,0);
vector<string> printvec(100000,0);
vector<int> indexarr(100000,0);
vector<int> dp(100000,0);
vector<int> givenvec;
vector<int> reqvec;
vector<vector<int> > indexvec(100000);
vector<int>::iterator itvec,tmpit;
vector<bool> boolvec(100000,true);
map<string,int> mp;
int main()
 {
   int index,ansindex,i,j,min,max,k,arrindex,flag,temp,reqcount;
   string s;
   fflush(stdin);
   gets(str);
   index=0;
   for(i=0;i<strlen(str);i++)
    if((str[i]>=65&&str[i]<=90)||(str[i]>=97&&str[i]<=122))
      {
       vec[index].push_back(str[i]);
       printvec[index].push_back(str[i]);
      }
    else
     {
       if(vec[index].length()>0)
         {
          transform(vec[index].begin(), vec[index].end(), vec[index].begin(), ::tolower);          
          index++;
         }
     }
   if((str[strlen(str)-1]>=65&&str[strlen(str)-1]<=90)||(str[strlen(str)-1]>=97&&str[strlen(str)-1]<=122))    
     {
      transform(vec[index].begin(), vec[index].end(), vec[index].begin(), ::tolower);
      index++;
     }
   fflush(stdin);  
   scanf("%d",&k);
   int commonid=1;
   while(k--)
   {
     cin>>s;
     transform(s.begin(), s.end(), s.begin(), ::tolower);
     if(mp[s]==0)
      mp[s]=commonid++;
     reqvec[mp[s]]++; 
   }
   reqcount=commonid-1;
   arrindex=0;
   for(i=0;i<index;i++)
    {
     if(mp[vec[i]]==0)
       mp[vec[i]]=commonid++;
     temp=mp[vec[i]];
     intvec[i]=temp;
     givenvec[temp]++;
     if(boolvec[temp]&&reqvec[temp]!=0)
     {
       boolvec[temp]=false;
       indexarr[arrindex++]=i;
     }
     if(intvec[i]<=reqcount)
     {
       indexvec[intvec[i]].push_back(i);
     }
    }
   max=0;
   flag=0;
   for(i=1;i<=reqcount;i++)
   {
     if(givenvec[i]<reqvec[i])
      {
        printf("NO SUBSEGMENT FOUND\n");
        flag=1;
        break;
      }
     temp=indexvec[i].at(reqvec[i]-1);
     if(temp>max)
       max=temp;
     tmpit=indexvec[i].begin();
     temp=reqvec[i];
     indexvec[i].erase(tmpit,tmpit+temp); 
   }
   if(flag==0)
   {
     dp[0]=max;
     for(i=1;i<arrindex;i++)
     {
      if(indexvec[intvec[indexarr[i-1]]].size()==0)
        break;
      int tmp=indexvec[intvec[indexarr[i-1]]].at(0);
      dp[i]=(dp[i-1]>tmp)?dp[i-1]:tmp;   
      indexvec[intvec[indexarr[i-1]]].erase(indexvec[intvec[indexarr[i-1]]].begin());
     } 
     dp[0]=dp[0]-indexarr[0]+1;
     min=dp[0];
     ansindex=indexarr[0];
     for(j=1;j<arrindex;j++)
      {
        if(dp[j]==0)
          break;
        dp[j]=dp[j]-indexarr[j]+1;
        if(dp[j]<min)
        {
          min=dp[j];
          ansindex=indexarr[j];
        }                                                
      }
  /*   printf("\ndp array\n");
     for(i=0;i<arrindex;i++)
       printf("%d  ",dp[i]);
     printf("\n");*/
     for(j=0,i=ansindex;j<min;j++,i++)
       cout<<printvec[i]<<" "; 
   }                                                             
   getch();
   return 0;
 }  
