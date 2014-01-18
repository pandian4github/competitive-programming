#include<iostream>
using namespace std;
#include<string.h>
int main()
 {
   char str[21];
   int arr[21]={0},arr2[21]={0},len,i,j,c,a,b;
   int p,p1;
   long int pr;
   while(1)
    {
      for(i=0;i<21;i++)
        arr[i]=arr2[i]=0;
      scanf("%s",str);
      if(str[0]=='*')
        break;
      p=0;  
      p1=0;
      len=strlen(str);  
      for(i=0;i<len;i++)
       if(str[i]=='Y')
         arr[p++]=i+1;
       else
         arr2[p1++]=i+1;  
      pr=1;
      for(j=2;j<=20;j++)
       {
        c=0;
        for(i=0;i<p;i++)
          if(arr[i]%j==0)
             {
              arr[i]=arr[i]/j;
              c=1;
             }
        if(c==1)
          pr=pr*j;
       }
      for(i=0;i<p;i++)
        pr=pr*arr[i];
//      cout<<pr<<"\n";                    
      c=0;
      for(i=0;i<p1;i++)
       if(pr%arr2[i]==0)
         {
          printf("-1\n");
          c=1;
          break;
         }   
      if(c==0)
        printf("%d\n",pr);
    }
   return 0;
 }        
                      
        
