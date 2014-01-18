#include<stdio.h>
#include<iostream>
#include<map>
#include<string.h>
using namespace std;
int main()
{
    int i,count=0,k,first,last,p,q,prev,j;
    char str[1000002],c;
    char st[5];
    i=0;
    while((c=getchar())!='\n')
      str[i++]=c;
    str[i]='\0';
    cout<<str;
    scanf("%d",&k);
    int mp[26]={0};
    for(i=0;i<k;i++)
    {
      scanf("%s",st);
      mp[st[0]-97]=i+1;
      mp[st[1]-97]=-(i+1);
    }
//    for(i=0;i<26;i++)
//      printf("%d  ",mp[i]);
    p=0;
    q=0;
    prev=0;
    for(i=0;i<strlen(str);i++)
    {
//      printf("p : %d q : %d\n",p,q);
 //     printf("count : %d\n",count);
 //     printf("i : %d mp[] : %d\n",i,mp[str[i]-97]);
 //     printf("prev : %d \n\n",prev);
      if(!(str[i]>=97 && str[i]<=122))
        continue;
      if(mp[str[i]-97]==0)
        {
         if(p<q)
           count+=p;
         else
           count+=q;
         p=0;
         q=0;
         prev=0;
         continue;
        }
      if(mp[str[i]-97]==prev)
        p++;
      else
        if(mp[str[i]-97]+prev==0)
          q++;
         else
         { 
           if(p<q)
             count+=p;
           else
             count+=q;
           p=1;
           q=0;
           prev=mp[str[i]-97];
         }
    }
  //  printf("count : %d p : %d q : %d\n",count,p,q);
    if(p<q)
      count+=p;
    else
      count+=q;
    printf("%d\n",count);
   // scanf("%d",&i);
    return 0;
}
