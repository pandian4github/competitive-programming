#include<iostream>
using namespace std;
struct listrecord
 {
   int data;
   struct listrecord* next;
 };
typedef struct listrecord* list;
list insert(int x,list l)
 {
   if(l==NULL)
    {
      l=new listrecord;
      l->data=x;
      l->next=NULL;
    }
   else
    {
      list temp=l,temp1;
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
  cout<<"\n";
  while(temp!=NULL)
   {
     cout<<"  "<<temp->data;
     temp=temp->next;
   }
  cout<<"\n"; 
 }    
int isprime(int num)
 {
   int i;
   for(i=2;i<=num/2;i+=2)
      if(num%i==0) 
        return 0;
   return 1;
 }       
void printprime(list l)
 {
   list temp;
   while(l!=NULL)
    {
      if(isprime(l->data))
        cout<<l->data<<"\n";
      temp=l;
      l=l->next;               
      delete temp;
    }
 }

void deletelist(list l)
 {
   list temp;
   while(l!=NULL)
    {
      temp=l;
      l=l->next;
      delete temp;
    }
 }         
int main()
 {
   int t;
   list temp,l3=NULL;
   int i,j;
   cin>>t;
   list l1=NULL,l2=NULL;
   long int a,b;
   for(i=0;i<t;i++)
    {
      l1=l2=l3=NULL;
      cin>>a>>b;
      if(a==1&&b==1)
        continue;
      if(a==1)
        a=2;  
      if(b-a<=5)
       {
        for(j=a;j<=b;j++)
          if(isprime(j))
            cout<<j<<"\n";
        cout<<"\n";    
        continue;    
       }     
          if(a%2==0)
            {
             if(a==2)
               l1=insert(2,l1);
             j=a+1;
            } 
          else
            {
             if(a==1)
               {
                l1=insert(2,l1);
                j=3;
               } 
             else  
              j=a;
            }    
          for(;j<=b;j+=2)
            l1=insert(j,l1);
         
      l3=l1;
      if(l1->data==2)
       {    
         l2=insert(2,l2);
         l1=l1->next;
       }
      if(l1->data==3)
       {
         l2=insert(3,l2);
         l1=l1->next;
       }
            
      if(l1->data%3==0)
         l1=l1->next;
      else
       if(l1->next!=NULL&&l1->next->data%3==0)
         {
          l2=insert(l1->data,l2);
          l1=l1->next;
          l1=l1->next;
         }
       while(1)
        {
         if(l1==NULL)
           break;
         l2=insert(l1->data,l2);
         l1=l1->next;
         if(l1==NULL)
           break;
         l2=insert(l1->data,l2);
         l1=l1->next;
         if(l1==NULL)
           break;
         l1=l1->next;
        }
     display(l2); 
     printprime(l2);
     deletelist(l3);
     deletelist(l2);
     cout<<"\n";
    }
   return 0; 
  } 
       
       
                
       
                     
              
             
