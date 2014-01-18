#include<string.h>
#include<iostream>
using namespace std;
struct listrecord
 {
   char data;
   int val;
   struct listrecord* next;
 };
typedef struct listrecord* list;  
void makezero(list l,int pos)
 {
   int i;
   list temp;
   for(i=0;i<pos;i++)
     temp=temp->next;
   temp->val=0;
 }    
list insert(list l,char x)
 {
   int add;
   list temp,temp1;
 //  cout<<". .";
      // cin>>add;

   if(l=NULL)
    {
   //   cout<<". .";
  //    l=new listrecord;
      cin>>add;

      l->data=x;
      l->val=1;
      l->next=NULL;
    }
   else
    {
     temp=l;
     while(temp->next!=NULL)
       temp=temp->next;
     temp1=new listrecord;
     temp1->data=x;
     temp1->next=NULL;
     temp1->val=1;
     temp->next=temp1;
    }
   return l;
 } 
void deletelist(list l)
 {
   list temp;
   while(l!=NULL)
    {
      temp=l;
      l=l->next;
      delete temp;
    } 
 }             
void display(list l)
 {
   while(l!=NULL)
    {
      if(l->val)
        cout<<l->data;
      l=l->next;
    }
 }       
int main()
 {
   int n,i,j,len,k,add,sub,mul,div;
   cin>>n;
   list l=NULL;
   char pre,*str;
   for(i=0;i<n;i++)
    {
      str=new char[50];
      cin>>str;
      len=strlen(str);
      l=NULL;
//      cout<<len<<"\n\n";
//      cin>>add;

      for(j=0;j<len;j++)
  //      l=insert(l,str[j]);
      cin>>add;
   
      for(j=0;j<len;j++)
       {
         if(str[j]==')')
          {
            if(j==strlen(str)-1)
             {
               makezero(l,0);
               makezero(l,j);
               break;
             }  
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
               pre=str[k-1];
               switch(pre)
                {
                  case '+' : makezero(l,k);
                             makezero(l,j);
                             break;
                  case '-' : if(add+sub+mul+div==0)
                              {
                                makezero(l,k);
                                makezero(l,j);       
                              }
                             break;
                  case '*' : if(add+sub!=0)
                              {
                               makezero(l,k);
                               makezero(l,j);             
                              }
                             break;
                  case '/' : if(add+sub+mul+div==0)
                              {
                                makezero(l,k);
                                makezero(l,j);       
                              }
                             break;
                }
               str[k]=str[j]='.';
                                   

                  
                 
               
          }
       } 
     display(l);
     deletelist(l); 
     delete[] str; 
    }
   return 0;
 }
