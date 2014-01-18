#include<iostream>
using namespace std;
#include<string.h>
void print(int arr[],int p)
 {
  int i;
  cout<<"\n";
  for(i=0;i<p;i++)
    cout<<"  "<<arr[i];
  cout<<"\n";
 }   
int main() 
 {
   int t,len,i;
   scanf("%d",&t);
   char str[100000];
   int arr[100000],p,p1,count,arr1[100000];
   while(t>0)
    {
      p=0;
      count=0;
      p1=0;
      t--;
      scanf("%s",str);
      len=strlen(str);
      while(1)
       {
        p=0;
        for(i=0;i<len-1;i++)
         if(str[i]=='G')
           if(str[i+1]=='B')
             arr[p++]=i;
//        print(arr,p);     
        if(p==0)
          break;
        count++;  
        for(i=0;i<p;i++)
         {
          str[arr[i]]='B';       
          str[arr[i]+1]='G';
          if(i!=0&&str[i-1]=='G')
            arr1[p1++]=i-1;
          if(i!=len-1&&str[i+2]=='B')
            arr1[p1++]=i+1;  
         }
        p=p1;
        for(i=0;i<p1;i++)
          arr[i]=arr1[i];
  //      print(arr,p);  
       }
      printf("%d\n",count);
    }
   return 0;
 }     
          
              
           
