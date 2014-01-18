//#include<conio.h>
#include<string.h>
#include<iostream>
using namespace std;
int main()
 {
   long long len;
   int asc,l,ascn,i,j,k,c;
   long long arr[5001],s[5001];
   char str[5001];
//   long long int n=0;
   while(1)
    {
       cin>>str;
       if(str[0]=='0')       
         {
          if(str[1]=='\0')
           break;
          cout<<"0\n";
          continue;
         }  
       c=0;  
       len=strlen(str);
       for(i=1;i<len;i++)
         if(str[i]=='0')
           if((int)str[i-1]>50)
            {
              c=1;
//              ans[n++]=0;
              cout<<"0\n";
              continue;
            }  
       if(c)
         continue;         
       j=0;
       for(i=0;i<len-1;i++)
        {
          asc=(int)str[i];
          ascn=(int)str[i+1];          
          if(asc==49)
             {
              if(str[i+1]!='0'&&str[i+2]!='0')
                arr[j++]=i;
             }  
          else
           if(asc==50)
              if(ascn<=54)
               {
                 if(str[i+1]!='0'&&str[i+2]!='0')
                   arr[j++]=i; 
               }   
        }
       arr[j]=-1;   
       for(k=j-1;k>=0;k--)
         s[k]=0;
       s[j]=1; 
       l=j-1;
       for(k=j-1;k>=0;k--)
        {
          if(arr[k]+1==arr[k+1])
           s[l--]=s[l+1]+s[l+2];
          else
           s[l--]=2*s[l+1];
        } 
       //ans[n++]=s[0]; 
       cout<<s[0]<<"\n";
    }
 //   for(i=0;i<n;i++)
 //     cout<<ans[i]<<"\n";
//  getch();
    return 0;
   
 }

