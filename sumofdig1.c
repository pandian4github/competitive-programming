#include<stdlib.h>
#include<math.h>
#include<stdio.h>
long long int Ordsum(long long int,long long int);
struct Sum
 {
   long long int sum;
   struct Sum *next;
 };
typedef struct Sum* List;
List Insert(long long int n,List l)
 {
   List t=l;
   if(l==NULL)
    {
     l=(List)malloc(sizeof(struct Sum));
     l->sum=n;
     l->next=NULL;
    }
    else
    { 
     while(t!=NULL)
      t=t->next;
     t=(List)malloc(sizeof(struct Sum));
     t->sum=n;
     t->next=NULL;
    } 
   return l;
 }
void Print(List l)
 {
  while(l!=NULL)
   {
    printf("%lld\n",l->sum);
    l=l->next;
   }
 }   
long long int presum(int a)
 {
   switch(a)
    {
     case 2 : return 855;
     case 3 : return 12600;
     case 4 : return 166500;
     case 5 : return 2070000;
     case 6 : return 24750000;
     case 7 : return 288000000;
     case 8 : return 3285000000;
    } 
 }   
   
   
long long int Difsum(long long int x,long long int y,int d1,int d2)
 {
   long long int s=0;
   int i;
   s=s+Ordsum(x,(pow(10,d1)-1));
   s=s+Ordsum(y,pow(10,d2-1));
   for(i=d1+1;i<d2;i++)
    s=s+presum(i);
   return s;
 }   

long long int Ordsum(long long int x,long long int y)
 {
   long long int i,j;
   long long int s=0;
   for(i=x;i<=y;i++)
    {
     j=i;
     while(j!=0)
     {
      s=s+j%10;
      j=j/10;
     }
    } 
   return s;
 }     
int main()
 {
   long long int a,b,t1,t2,su;
   int d1,d2;
   List l=NULL;
   scanf("%lld%lld",&a,&b);
   while(1)
    {
      d1=d2=0;
      for(t1=a;t1!=0;t1/=10)
       d1++;
      for(t2=b;t2!=0;t2/=10)
       d2++;
      if(d1==d2)
         su=Ordsum(a,b);
      else
       if(d1+1==d2)
        su=Ordsum(a,pow(10,d1)-1)+Ordsum(pow(10,d1),b);   
      else
         su=Difsum(a,b,d1,d2);
      l=Insert(su,l);
      scanf("%lld%lld",&a,&b);
      if(a==-1&&b==-1)
       break;   
    }
   Print(l);
   return 0; 
 
 }          
   
