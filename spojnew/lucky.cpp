//#include<iostream>
//using namespace std;
#include<stdio.h>
//#include<conio.h>
struct ListRecord
 {
   int data;
   struct ListRecord* next;
 };
typedef struct ListRecord* list; 
list insert(list l,int d)
 {
   if(l==NULL)
    {
      l=new ListRecord;
      l->data=d;
      l->next=l;
    }
   else
    {
      list temp=l;
      while(temp->next!=l)
        temp=temp->next;
      list newn=new ListRecord;
      newn->data=d;
      temp->next=newn;
      newn->next=l;
    }
   return l;
 }
list deletenode(list l,int n)
 {
   list temp=l;
   int i;
   for(i=1;i<n-1;i++)        
     temp=temp->next;
   list temp1=temp->next;
   temp->next=temp1->next;
   delete temp1;
   return temp->next;
 }   
list findmin(list l)
 {
   list temp=l->next,ans=l;
   int min=l->data;
   while(temp!=l)
   {
    if(temp->data<min)
     {
       min=temp->data;
       ans=temp;
     }
    temp=temp->next; 
   }
   return ans;
 } 
void print(list l)
 {
   list temp=l;
   while(temp->next!=l)
    {
     printf(" %d",temp->data);
     temp=temp->next;
    }
   printf(" %d\n",temp->data); 
 }
int main()
 {
   int t,m,i,n,k,j;
   scanf("%d",&t);
   list l=NULL,min;
   for(i=1;i<=t;i++)
    {
     l=NULL;
     scanf("%d%d%d",&m,&n,&k);
     for(j=1;j<=m;j++)
       l=insert(l,j);
     for(j=1;j<=m-k;j++)
       l=deletenode(l,n);
     min=findmin(l);
     printf("Case #%d:",i);
     print(min);
    }
//   getch();
   return 0;
 }       
       


