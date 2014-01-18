#include<stdio.h>
#include<stdlib.h>
struct square
 {
   int s;
   struct square* next;
  };
 typedef struct square* List;  
List Insert(List l,int n)
 {
   List new,t=l;
   if(l==NULL)
    {
      l=(List)malloc(sizeof(struct square));
      l->s=n;
      l->next=NULL;
     }
   else
    {
      while(t->next!=NULL)
        t=t->next;
       new=(List)malloc(sizeof(struct square));
       new->s=n;
       new->next=NULL;
       t->next=new;
      }
    return l;
  }   
  
int Number(int n)
 {
   int i,j,k,l,s=0;
   for(i=0;i<n;i++)
    for(j=0;j<n;j++)
     {
       k=j;
       l=i;
       while(1)
        {
          if(k<n&&l<n)
           {
            s++;
            k++;
            l++;
           }
         else
          break;
        }
     }
   return s;
 }   
             
 int main()
  {
    int n,s;
    List l=NULL;
    while(1)
     {
       scanf("%d",&n);
       if(n==0)
        break;
       s=Number(n);
       l=Insert(l,s);
     }
   while(l!=NULL)
    {
      printf("%d\n",l->s);
      l=l->next;
    }
   return 0;
 }            
   
