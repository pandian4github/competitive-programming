#include<stdio.h>
#include<utility>
#include<iostream>
#include<map>
using namespace std;
int main()
{
    int t,i,temp,count;
    char str[1001];
    scanf("%d",&t);
    pair<char,char> p;
    p=make_pair(56,56);
    map<pair<char,char>,char> mp;
   // char a='|',b='\',c='-',d=

    p=make_pair('|','\\');
    mp[p]='L';
    p=make_pair('\\','-');
    mp[p]='L';
    p=make_pair('-','/');
    mp[p]='L';
    p=make_pair('/','|');
    mp[p]='L';

    p=make_pair('|','/');
    mp[p]='R';
    p=make_pair('/','-');
    mp[p]='R';
    p=make_pair('-','\\');
    mp[p]='R';
    p=make_pair('\\','|');
    mp[p]='R';

    p=make_pair('|','-');
    mp[p]='F';
    p=make_pair('-','|');
    mp[p]='F';
    p=make_pair('\\','/');
    mp[p]='F';
    p=make_pair('/','\\');
    mp[p]='F';
        
    while(t--)
    {
      scanf("%s",str);
      printf("Start State: %c\n",str[0]);
      for(i=1;i<strlen(str);i++)
      {
        temp=str[i];
        p=make_pair(str[i-1],str[i]);
        printf("%c",mp[p]);
        count=0;
        while(str[i+1]==temp && str[i+1]!='\0')
        {
          count++;
          i++;
        }
        printf("%d",count);
      }
      printf("\n");
    }
    return 0;
}
        
