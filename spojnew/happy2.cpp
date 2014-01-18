#include<iostream>
using namespace std;
struct BTree
 {
   int data;
   struct BTree *left;
   struct BTree *right;
 };
typedef struct BTree* Tree;
int q;
Tree Insert(int n,Tree t)
 {
   if(t==NULL)
    {
      t=new BTree;
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

void destroy(Tree t)
 {
   Tree temp;
   while(t->left!=NULL)
     {
       destroy(t->left);
       destroy(t->right);
       temp=t;
       delete temp;
     }
 }      
int main()
 {
   long int n,num,c=0,i,j,s,d;
   Tree t=NULL;
   cin>>n;
   for(j=0;j<n;j++)
    {
     t=NULL;
     q=1;
     c=0;
     cin>>num;
     while(1)
      {
       s=0;
       t=Insert(num,t);
       while(num!=0)
       {
        d=num%10;
        s=s+(d*d);
        num=num/10;
       }
       c++;
       if(s==1)
       {
         cout<<c<<"\n";
         break;
       }
       else
       {
        if(q==0)
         {
           cout<<"-1\n";
           break;
         }
        else
          num=s;
       }       
      }
     destroy(t); 
    }  
   l:return 0;
 }        

