#include<iostream>
using namespace std;
struct listrecord
 {
   int data;
   struct listrecord *next;
 };
typedef struct listrecord* list;   
list insert(int x,list l)
 {
   list temp,temp1;
   temp=l;
   if(l==NULL)
     {
       l=new listrecord;
       l->data=x;
       l->next=NULL;
     } 
   else
    {
      while(temp->next!=NULL)
         temp=temp->next;
      temp1=new listrecord;
      temp1->data=x;
      temp1->next=NULL;
      temp->next=temp1;
    }
  return l;  
 }     
void display(list l)
 {
   list temp=l;
   while(temp!=NULL)
    {
      cout<<temp->data;
      temp=temp->next;
    }
 }     

int main()
 {
      list l1,l2;
      l1=l2=NULL;
      int asc;
      char c;
      cin>>c;
      while(1)
       {
         asc=(int)c;
         cout<<"\n\n"<<asc;
         if(c=='\n')
           break;
         l1=insert(asc,l1);
         cin>>c;
       }  
      display(l1);
      
      return 0;
 }  
