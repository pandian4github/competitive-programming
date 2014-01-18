#include<stdio.h>
#include<stdlib.h>
struct area
 {
  float ar;
  struct area *next;
 }; 
struct area* Insert(float q,struct area* a)
 {
   struct area* new;
   struct area* t;
   t=a;
   if(a==NULL)
    {
      a=(struct area*)malloc(sizeof(struct area));
      a->ar=q;
      a->next=NULL;
    }
   else
    {
      new=(struct area*)malloc(sizeof(struct area));
      new->ar=q;
      while(t->next!=NULL)
       t=t->next;
      t->next=new;
      new->next=NULL;
    }
    return a;
 }     
      
        
 
int main()
 {
  struct area *a;
  int n;
  float f;
  a=NULL;
  scanf("%d",&n);
  while(n!=0)
  {
   f=(n*n)/(2*3.142857);
   a=Insert(f,a);
   scanf("%d",&n);
  }
  while(a!=NULL)
   {
    printf("%0.2f\n",a->ar);
    a=a->next;
   }  
   return 0;
  }   
																					

