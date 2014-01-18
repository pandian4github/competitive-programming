#include<stdio.h>
#include<stdlib.h>
struct Life
 { 
   int no;
   struct Life* next;
 };
typedef struct Life* List;
List Insert(List l,int n)
 {
    List new,t=l;
   if(l==NULL)
    {
      l=(List)malloc(sizeof(struct Life));
      l->no=n;
      l->next=NULL;
    }
   else
    {
      new=(List)malloc(sizeof(struct Life));
      new->no=n;
      new->next=NULL;
      while(t->next!=NULL)
       t=t->next;
      t->next=new;
    }
   return l;
 }        
int main()
 {
   List l=NULL;
   int n;
   while(1)
    {
      scanf("%d",&n);
      if(n==42)
       break;
      else
       l=Insert(l,n);
    }
   while(l!=NULL)
    {
      printf("%d\n",l->no);
      l=l->next;
    }    
   return 0;
 }
         
