#include<stdio.h>
#include<string.h>
#include<vector>
using namespace std;
int combination(int n,int a)
 {
   int c=1;   
   if(n==a)
    return 1;
   c=n*combination(n-1,a);
   c=c/combination((n-a),1);
   return c;
 }  
int main()
 {
   char str[26];
   int arr[26];
   int i,len,j,count,sum,now,temp,prev;
   vector<bool> vec(26);
   while(1)
    {
      scanf("%s",str);
      if(strcmp(str,"bye")==0)
        break;
      len=strlen(str);
      count=0;
      sum=1;
      for(i=0;i<26;i++)
        vec[i]=false;
      for(i=0;i<len;i++)
        arr[i]=str[i]-48;
      prev=arr[0];    
      for(i=1;i<len;i++)
       {
         now=arr[i];
         if(now>=prev)
          {
            vec[i]=true;
            prev=now;
          }
         else
          {
            temp=i;
            for(i=i+1;i<len;i++)
             {
                now=now+arr[i];
                if(now>=prev)
                 {
                   vec[temp]=true;
                   prev=now;
                   break;
                 } 
             }
          }
       }
      for(i=1;i<len;i++)
        if(vec[i])
          count++;
      for(i=1;i<=count;i++)
        sum=sum+combination(count,i);
      printf("%d\n",sum);
    }
   return 0;
 }            
