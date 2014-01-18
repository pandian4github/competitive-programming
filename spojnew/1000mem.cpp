#include<iostream>
#include<conio.h>
using namespace std;
struct listrecord
 {
   int data;
   struct listrecord* next;
 };  
typedef struct listrecord* list;
list insert(list l,int x)
 {
   list temp,temp1,newn;
   if(l==NULL)
    {
      l=new listrecord;
      l->data=x;
      l->next=l;
    }  
   else
    {
      temp=l;
      while(temp->next!=l)
        temp=temp->next;
      newn=new listrecord;
      newn->data=x;
      temp->next=newn;
      newn->next=l;
    }
   return l;
 } 
list deletenode(list l,list t)
 {
   list temp=l,temp1;
   while(temp->next!=t)
     temp=temp->next;

   if(temp->next==l)
    {
      temp->next=l->next;
      delete l;
      return l->next;
    }  
   temp1=temp->next;
   temp->next=t->next;
   delete temp1;
   return l;
 }  
                
int answer(list l)
 {
   list temp=l;
   while(temp->next!=temp)
    {
      deletenode(l,temp->next);
    }
   return temp->data;
 }     
int main()
 {
   int i;
   list l=NULL;
   int n;
   cin>>n;
   for(i=1;i<=n;i++)
     l=insert(l,i);
   cout<<"\n\n"<<answer(l);
   getch();
   return 0;
 }    
   
