#include<iostream>
//#include<conio.h>
using namespace std;
struct tree
 {
   int data;
   struct tree* left;
   struct tree* right;
 }; 
typedef struct tree* tr;
tr insert(tr t,int n)
 {
   if(t==NULL)
    {
      t=new tree;
      t->data=n;
      t->left=t->right=NULL;
    }
   else
    if(n<t->data)
      t->left=insert(t->left,n);
    else
      if(n>t->data)
        t->right=insert(t->right,n);
      else
       ;
   return t;
 }          
tr findmin(tr t)
 {
   if(t->left==NULL)
     return t;
   return findmin(t->left);
 }    
tr deletef(tr t,int n)
 {
   if(t==NULL)
     return t;
   if(n<t->data)
     t->left=deletef(t->left,n);
   else
    if(n>t->data)
      t->right=deletef(t->right,n);
    else
      if(t->left&&t->right)
       {
         tr temp=findmin(t->right);
         t->data=temp->data;
         t->right=deletef(t->right,t->data);       
       }               
      else
       {
         if(t->left==NULL)
           t=t->right;
         else  
          if(t->right==NULL)
            t=t->left;  
       }
   return t;
 }            
void nofriends(tr t,int &x)
 {
   if(t==NULL)
     return;
   x++;
   nofriends(t->left,x);
   nofriends(t->right,x);
 }  
    
int main()
 {
   int n,i,j,ele;
   cin>>n;
   tr t=NULL;
   int arr[n],count[n];
   for(i=0;i<n;i++)
    {
      cin>>arr[i]>>count[i];
      for(j=0;j<count[i];j++)
       {
         cin>>ele;
         t=insert(t,ele);
       }
    }
   for(i=0;i<n;i++)
     t=deletef(t,arr[i]);
   int tot=0;
   nofriends(t,tot);
   cout<<tot;
 //  getch();
   return 0;
 }        
