#include<stdlib.h>
#include<stdio.h>
struct BTree
 {
   int data;
   struct BTree *left;
   struct BTree *right;
 };
typedef struct BTree* Tree;
int q=1;
Tree Insert(int n,Tree t)
 {
   if(t==NULL)
    {
      t=(Tree)malloc(sizeof(struct BTree));
      t->data=n;
      t->left=t->right=NULL;
    }
  else
   if(n<t->data)
    t->left=Insert(n,t->left);
  else
    if(n>t->data)
      t->right=Insert(n,t->right);    
    else

      {
       q=0;
       return NULL;
      } 
  return t;
 }       
         
int main()
 {
   int n,c=0,i,s,d;
   Tree t=NULL;
   scanf("%d",&n);
   while(1)
    {
     s=0;
     t=Insert(n,t);
     while(n!=0)
     {
      d=n%10;
      s=s+(d*d);
      n=n/10;
     }
     c++;
     
     if(s==1)
      {
        printf("%d\n",c);
        goto l;
      }
     else
      {
        if(q==0)
         {
           printf("-1\n");
           goto l;
         }
        else
          n=s;
       }       
    }
   l:return 0;
 }        
