#include<iostream>
#include<map>
#include<vector>
//#include<conio.h>
using namespace std;
map<string,bool> boolmp;
map<string,vector<string> > mp;
int main()
 {
   int n,i,j;
   string s,str;
   scanf("%d",&n);
   for(i=0;i<n;i++)
    {
      s.clear();
      cin>>str;
      if(!boolmp[str])
      {
       for(j=0;j<str.length()-1;j++)
       {
         s.push_back(str[j]);
         mp[s].push_back(str);
       }
       boolmp[str]=true;
      }
      
    }
//   printf("fdg");
   scanf("%d",&n);
   for(i=1;i<=n;i++)
   {
     cin>>str;
     printf("Case #%d:\n",i);
 //    printf("size : %d\n",mp[str].size());
     if(mp[str].size()==0)
       printf("No match.\n");
     else
      for(j=0;j<mp[str].size();j++)
        cout<<mp[str].at(j)<<"\n";
//     printf("exit");   
   }
  // getch();
   return 0;
 }    
