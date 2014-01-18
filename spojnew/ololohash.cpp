#include<iostream>
//#include<conio.h>
using namespace std;
class hash
 {
   public :
   int status;
   hash* h[26];
   hash();
 };     
hash::hash()
 {
   int i;
   for(i=0;i<26;i++)
     h[i]=NULL;
   status=0;  
 }    
void recur(hash *head,int str[],int pos,int &p)
 {
   int i;
   if(head!=NULL)
    {
     if(head->status==1)
       {
        p=pos;
        return;
       } 
     for(i=0;i<26;i++)
       if(head->h[i]!=NULL)
       {
        str[pos]=i;
        recur(head->h[i],str,pos+1,p);
        if(p!=-1)
          return;
       }
    }
 }    
int main()
 {
   int j,k,n,ic;
   hash* head;
   head=new hash;
   hash* temp=head;
   char str[10];
   int str1[10];
   scanf("%d",&n);
   for(j=0;j<n;j++)
    {
     scanf("%s",str);
     temp=head;
     for(k=0;str[k]!='\0';k++)
      {
       ic=(int)str[k]-48;
       if(temp->h[ic]==NULL)
        {
         temp->h[ic]=new hash;
         temp=temp->h[ic];
        }
       else
         temp=temp->h[ic];
      }
     temp->status=1-temp->status; 
    }    
   int pp=-1;
   recur(head,str1,0,pp);
   for(j=0;j<pp;j++)
     printf("%d",str1[j]);
//   getch(); 
   return 0; 
 }   

