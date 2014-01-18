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
vector<string> vec(100000);
vector<string> printvec(100000);
vector<int> indexarr(100000);
vector<int> dp(100000,0);
int arr[100001]={0};
map<string,int> givenmap;
map<string,int> reqmap;
map<string,int> reqmap2;
map<string,int> remmap;
map<string,vector<int> > indexmap;
map<string,vector<int> >::iterator it2;
map<string,int>::iterator it;
vector<int>::iterator itvec;
/*void printremmap()
{
  printf("\nRem map :\n");
  for(it=remmap.begin();it!=remmap.end();++it)
    cout<<(*it).first<<"   "<<(*it).second<<"\n";
}
void printindexmap()
 {
   printf("\nIndex map : \n");
   for(it2=indexmap.begin();it2!=indexmap.end();++it2)
    {
      cout<<(*it2).first<<" . . ";
      for(itvec=((*it2).second).begin();itvec!=((*it2).second).end();++itvec)
        cout<<(*itvec)<<"  ";
 /*       
      for(int i=0;i<(*it2).second.length;i++)
        cout<<"   "<<(*it2).second[i];
      printf("\n");
    }
 }*/ 
int main()
 {
   int index,ansindex,i,j,min,max,k,arrindex,flag,temp;
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
          givenmap[vec[index]]++;
          indexmap[vec[index]].push_back(index);
          index++;
         }
     }
   if((str[strlen(str)-1]>=65&&str[strlen(str)-1]<=90)||(str[strlen(str)-1]>=97&&str[strlen(str)-1]<=122))    
     {
      transform(vec[index].begin(), vec[index].end(), vec[index].begin(), ::tolower);
      givenmap[vec[index]]++;
      indexmap[vec[index]].push_back(index);
      index++;
     }
   fflush(stdin);  
   scanf("%d",&k);
   while(k--)
   {
     cin>>s;
     transform(s.begin(), s.end(), s.begin(), ::tolower);
     reqmap2[s]++;
     reqmap[s]++;
   }
   arrindex=0;
   for(i=0;i<index;i++)
     if(reqmap2[vec[i]]!=0)
       indexarr[arrindex++]=i;
/*   for(i=0;i<arrindex;i++)
     cout<<indexarr[i]<<"  "<<vec[indexarr[i]]<<"\n";*/
 //  getch();    
   max=0;
   flag=0;
 /*  for(it=reqmap.begin();it!=reqmap.end();++it)
   {
     cout<<".."<<(*it).first<<"  "<<(*it).second<<"..\n";
     getch();
   }*/     
   for(it=reqmap.begin();it!=reqmap.end();++it)
   {
  //   cout<<".."<<(*it).first<<" req :  "<<(*it).second<<" given :  "<<givenmap[(*it).first]<<"..\n";
  //   getch();
     if(givenmap[(*it).first]<(*it).second)
      {
        printf("NO SUBSEGMENT FOUND\n");
        flag=1;
        break;
      }
//     indexmap[(*it).first].erase(indexmap[(*it).first].begin(),indexmap[(*it).first].begin()+(*it).second-1);
     temp=indexmap[(*it).first].at((*it).second-1);
  //   printf("temp : %d\n",temp);
     if(temp>max)
       max=temp;
   }
   printf("max : %d\n",max);
   
   //printindexmap();
   if(flag==0)
   {
    for(i=0;indexarr[i]<=max;i++)
      {
  //     printf("max loop : %d\n",i);
       remmap[vec[indexarr[i]]]++;
       indexmap[vec[indexarr[i]]].erase(indexmap[vec[indexarr[i]]].begin());
      }     
  //   printremmap();
  //   printindexmap(); 
   //  getch(); 
     dp[0]=max;
     min=max;
     for(i=1;i<arrindex;i++)
     {
    //  getch();
      remmap[vec[indexarr[i-1]]]--;
      givenmap[vec[indexarr[i-1]]]--;
      if(givenmap[vec[indexarr[i-1]]]<reqmap[vec[indexarr[i-1]]])
       {
//         printf("\nbreak\n");
         break;
       }
      if(remmap[vec[indexarr[i-1]]]>=reqmap[vec[indexarr[i-1]]])
        {
  //       printf("\nno change\n");
         dp[i]=dp[i-1];
        }
      else
        {
    //     printf("\nsearching for next one ..\n");
         remmap[vec[indexarr[i-1]]]++;
         dp[i]=(dp[i-1]>indexmap[vec[indexarr[i-1]]].at(0))?dp[i-1]:indexmap[vec[indexarr[i-1]]].at(0);
         indexmap[vec[indexarr[i-1]]].erase(indexmap[vec[indexarr[i-1]]].begin());
        } 
     }
  /*   printf("\ndp array\n");
     for(i=0;i<arrindex;i++)
       printf("%d  ",dp[i]);
     printf("\n");*/
     dp[0]=dp[0]-indexarr[0]+1;
     min=dp[0];
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
   /*  printf("\ndp array\n");
     for(i=0;i<arrindex;i++)
       printf("%d  ",dp[i]);
     printf("\n");*/
     for(j=0,i=ansindex;j<min;j++,i++)
       cout<<printvec[i]<<" "; 
   } 
      
                                                    
   
   getch();
   return 0;
 }  
