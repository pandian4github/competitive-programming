#include<iostream>
using namespace std;
//#include<conio.h>
#include<map>
struct nodes
 {
//   long long int clic;
//   long long int len;
   map<long long int,long long int> m;
   struct nodes* next;
 };
typedef struct nodes* list;
list insert(list l,long long int c,long long int le)
 {
   list temp=l;
   int c1=0;
   if(l==NULL)
    {
      l=new nodes;
      l->m[c]=le;
  //    l->len=le;
      l->next=NULL;
      return l;
    }
   if(c>l->clic)
    {
      list newn=new nodes;
      newn->clic=c;
      newn->len=le;
      newn->next=l;
      temp=l;
      while(temp!=NULL)
       {
         temp->clic+=le;
         temp=temp->next;
       } 
      return newn;
    }
   while(temp->next!=NULL)
    {
      if(temp->next->clic<c)
       {
        c1=1;
        break;
       } 
      temp=temp->next;  
    }       
   if(c1)
    {
     list newn=new nodes;
     newn->clic=c;
     newn->len=temp->len+le;
     newn->next=temp->next;
     temp->next=newn;
     temp=newn->next;
     while(temp!=NULL)
      {
        temp->len+=le;
        temp=temp->next;
      } 
     return l;
    } 
   else     
    {
     list newn=new nodes;
     newn->clic=c;
     newn->len=le;
     newn->next=NULL;
     temp->next=newn;
     return l;
    }
 }   
long long int calculate(list l,long long int k)
 {
   list temp=l;
   long long int i=0,tot=0;
   while(temp!=NULL&&i<k)
    {
     tot+=temp->len;
     temp=temp->next;
     i++;
    }
   return tot;
 }   
/*void print(list l,int j)
 {
   list temp=l;
   cout<<" List "<<j+1<<" : ";
   while(temp!=NULL)
    {
     cout<<"\n  clic  =  "<<temp->clic<<"  length  =  "<<temp->len<<"\n";
     temp=temp->next;
    } 
 }*/  
int main()
 {
   long long int t,i,j;
   long long int n,m,q,u,c,l,k,tot;
   scanf("%lld",&t);
   for(i=1;i<=t;i++)
    {
      scanf("%lld%lld%lld",&n,&m,&q);
      list li[n];
      for(j=0;j<n;j++)
        li[j]=NULL;
      for(j=0;j<m;j++)
       {
         scanf("%lld%lld%lld",&u,&c,&l);
         li[u-1]=insert(li[u-1],c,l);
       }
      tot=0; 
      printf("Case #%lld:\n",i);
      for(j=0;j<q;j++)
       {
         tot=0;
         scanf("%lld",&k);
         for(l=0;l<n;l++)
           tot+=calculate(li[l],k);  
         printf("%lld\n",tot);  
       }
    }
//   getch();
   return 0;
 }     
          
     
