#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct kitty
 {
   char a[50];
   int no;
   struct kitty* next;
  };
 typedef struct kitty* List;  
List Insert(List l,char na[],int n)
 {
   List new,t=l;
   if(l==NULL)
    {
      l=(List)malloc(sizeof(struct kitty));
      l->no=n;
      strcpy(l->a,na);
      l->next=NULL;
     }
   else
    {
      while(t->next!=NULL)
        t=t->next;
       new=(List)malloc(sizeof(struct kitty));
       new->no=n;
       strcpy(new->a,na);
       new->next=NULL;
       t->next=new;
      }
    return l;
  }    
  
  
         
void Print(List l)
 {
   int i,le,j;
   char c;  
   le=strlen(l->a);
  for(j=0;j<le;j++)
  {
    for(i=0;i<l->no;i++)
      printf("%s",l->a);
     c=l->a[0];
    for(i=0;i<le-1;i++) 
       l->a[i]=l->a[i+1];    
    l->a[i]=c;
    printf("\n");  
  }
   
 }       
      
void main()
 {
   char name[50];
   int n;
   
   List l=NULL;
   scanf("%s%d",name,&n);
   while(1)
    {
      l=Insert(l,name,n);
      scanf("%s",name);
      if(!strcmp(name,"."))
        break;
      scanf("%d",&n);  
    }
   while(l!=NULL)
    {
      Print(l);
      l=l->next;
    }
      
  }    
