#include <algorithm>
#include <string> 
#include<stdio.h>
#include<vector>
#include<iostream>
#include<conio.h>
#include<string.h>
#include<map>
using namespace std;
char str[200005];
vector<string> vec(200005);
vector<string> printvec(200005);
vector<int> reqvec(200005,0);
vector<int> intvec(200005,0);
vector<int> indexarr(200005,0);
vector<int> dp(200005,0);
map<string,int> mp;
vector<vector<int> > indexvec(200005);
int main()
 {
   int index,ansindex,i,j,min,max,k,arrindex,flag,temp,l;
   char word[20];
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
       if(vec[index].length()>0&&str[i]==' ')
         {
          transform(vec[index].begin(), vec[index].end(), vec[index].begin(), ::tolower);
          index++;
         }         
     }
   if(vec[index].length()>0)
     {
      transform(vec[index].begin(), vec[index].end(), vec[index].begin(), ::tolower);
      index++;
     }
   fflush(stdin);  
   scanf("%d",&k);
  // printf("k : %d\n",k);
//   char ch=getchar();
   for(j=1,i=1;i<=k;i++)
   {
     scanf("%s",word);
//     getch();
     s.clear();
     for(l=0;l<strlen(word);l++)
      if(word[l]>=97&&word[l]<=122)
        s.push_back(word[l]);
      else
       if(word[l]>=65&&word[l]<=90)
         s.push_back(word[l]+32);
       else
        continue;
     //cout<<s<<"\n";   
     if(mp[s]==0)
      mp[s]=j++;
     reqvec[mp[s]]=1;
   }
  /* printf("j : %d\nreqvec : ",j);
   for(i=1;i<j;i++)
     printf("%d  ",reqvec[i]);
   printf("\n");*/
   arrindex=0;
   for(i=0;i<index;i++)
     {
      intvec[i]=mp[vec[i]];
      if(intvec[i]!=0)
        {
         indexarr[arrindex++]=i;
         indexvec[intvec[i]].push_back(i);
        }
     }
/*   printf("intvec : \n");  
   for(i=0;i<index;i++)
     printf("%d  ",intvec[i]);
   printf("\n");  */
     
   max=0;
   flag=0;
   for(i=1;i<j;i++)
   {
     if(indexvec[i].size()<reqvec[i])
      {
        printf("NO SUBSEGMENT FOUND\n");
        flag=1;
        break;
      }
     if(indexvec[i].at(reqvec[i]-1)>max)
       max=indexvec[i].at(reqvec[i]-1);
     indexvec[i].erase(indexvec[i].begin(),indexvec[i].begin()+reqvec[i]);
   }
   if(flag==0)
   {
    dp[0]=max;
    for(i=1;i<arrindex;i++)
    {
     temp=intvec[indexarr[i-1]];
     if(indexvec[temp].size()==0)
       break;
     dp[i]=(dp[i-1]>indexvec[temp].at(0))?dp[i-1]:indexvec[temp].at(0);
     indexvec[temp].erase(indexvec[temp].begin());
    }
   //  printf("\ndp array\n");
   //  for(i=0;i<arrindex;i++)
   //    printf("%d  ",dp[i]);
   //  printf("\n");
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
