#include<iostream>
using namespace std;
#include<string.h>
int main()
 {
char str[10000];
   char init;
   int i,j;
   int count,len;
   int tcase=1;
   while((scanf("%s",str))!=EOF)
    {
      len=strlen(str);
      i=0;
      while(str[i]!='1'&&i<len)
       i++;
      if(i>=len)
       {
         cout<<"Game #"<<tcase++<<": 0\n";
         continue;
       }
      count=1; 
      init='1';
      for(j=i+1;j<len;j++)
       {
         if(str[j]!=init)
          {
           count++;
           init=str[j];
          }
       }
      cout<<"Game #"<<tcase++<<": "<<count<<"\n";
    }
   return 0;
 }        
