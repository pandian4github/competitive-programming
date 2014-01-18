#include<string.h>
#include<iostream>
using namespace std;
struct listrecord
 {
   char data;
   int val;
 };
             
int main()
 {
   long int n,i,j,len,p,k,add,sub,mul,div;
   cin>>n;
   char post,pre,*str;
   listrecord list[251];
   for(i=0;i<n;i++)
    {
      str=new char[251];
      cin>>str;
      len=strlen(str);
      for(j=0;j<len;j++)
        {
          list[j].data=str[j];
          list[j].val=1;
        }  
      for(j=0;j<len;j++)
       {
         if(str[j]==')')
          {
            add=sub=mul=div=0;
            for(k=j;str[k]!='(';k--)
             {
                      if(str[k]=='+')
                       {
                          add=1;
                          continue;
                       }
                      if(str[k]=='-')
                       {
                          sub=1;
                          continue;
                       }
                      if(str[k]=='*')
                       {
                          mul=1;
                          continue;
                       } 
                      if(str[k]=='/')
                       {
                          div=1;
                          continue;
                       }
             }  
               if(j==len-1&&k==0)
                {
                  list[0].val=list[j].val=0;
                  break;
                }  
                            
               if(k==0) 
                {
                  post=str[j+1];
                  switch(post)
                              {
                                case '+' : list[k].val=list[j].val=0;
                                           break;
                                case '-' : list[k].val=list[j].val=0;
                                           break;
                                case '*' : if(add+sub==0)
                                            list[k].val=list[j].val=0;
                                           break;
                                case '/' : if(add+sub==0)
                                            list[k].val=list[j].val=0;
                                           break;
                                case ')' : list[k].val=list[j].val=0;
                                           break;
                               }
                  continue;
                }               
               pre=str[k-1];
               switch(pre)
                {
                  case '+' : list[k].val=list[j].val=0;
                             break;
                  case '-' : if(add+sub==0)
                               list[k].val=list[j].val=0;
                             break;
                  case '*' : if(add+sub==0)
                               list[k].val=list[j].val=0;
                             break;
                  case '/' : if(add+sub+mul+div==0)
                               list[k].val=list[j].val=0;
                             break;
                  case '(' : post=str[j+1];
                             switch(post)
                              {
                                case '+' : list[k].val=list[j].val=0;
                                           break;
                                case '-' : list[k].val=list[j].val=0;
                                           break;
                                case '*' : if(add+sub==0)
                                            list[k].val=list[j].val=0;
                                           break;
                                case '/' : if(add+sub==0)
                                            list[k].val=list[j].val=0;
                                           break;
                                case ')' : list[k].val=list[j].val=0;
                                           break;
                               }
                             break;                                                                     
                }
               
               for(p=k;p<=j;p++)
                 str[p]='.';                    
          }
       } 
     for(j=0;j<len;j++)
       if(list[j].val)
         cout<<list[j].data;
     cout<<"\n";    
//     delete[] list;
     delete[] str; 
    }
   return 0;
 }
