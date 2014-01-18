#include<iostream>
//#include<conio.h>
using namespace std;
struct bst
 {
   int data;
   struct bst* left;
   struct bst* right;
 };
typedef struct bst* tree;  
void preorder(tree t)
 {
   if(t!=NULL)
    {
      cout<<t->data<<" ";
      preorder(t->left);
      preorder(t->right);
    }
 }        
void postorder(tree t)
 {
   if(t!=NULL)
    {
      postorder(t->left);
      postorder(t->right);
      cout<<t->data<<" ";
    }
 }        
tree insert(int x,tree t)
 {
   tree temp;
   if(t==NULL)
    {
      t=new bst;
      t->data=x;
      t->left=t->right=NULL;
    }
   else
    if(x<t->data)
      t->left=insert(x,t->left);
    else
     if(x>t->data)
       t->right=insert(x,t->right);
   return t;
 }           
int main()
 {
   tree t;
   t=NULL;
   int n;
   cin>>n;
   int i;
   int a;
   char str[5];
   for(i=0;i<n;i++)
    {
      cin>>a;
      t=insert(a,t);
    }
   cin>>str;   
   if(!strcmp(str,"pre"))
     preorder(t);
   else
     postorder(t);
  // getch();
   return 0;
 }      
